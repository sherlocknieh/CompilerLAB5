%{ 
#include "common.h"
int CompileFailed = 0;            /*编译失败标记*/
SymbolList TopSymbolList = NULL;  /*符号表指针*/
struct ConstList ConstList;       /*常量表*/
struct QuadTable QuadTable;       /*四元式表*/
%}


%token BASIC
%token CONST
%token ID

%token IF
%token ELSE
%token WHILE
%token DO
%token BREAK

%token LT
%token LE
%token GT
%token GE

%token EQ
%token NEQ

%token OR
%token AND

%right '='
%left '+' '-'
%left '*' '/'
%right '!' UMINUS


%%
program : block   { printf("\t\t\t block -> program \n"); } 
;

block   : '{' blockM1 decls stmts blockM2 '}'   { printf("\t\t\t {decls stmts} -> block \n"); } 
;

blockM1 :   { TopSymbolList = CreateSymbolList( TopSymbolList, TopSymbolList->endaddr ); }
;

blockM2 :   { SymbolList env;
				PrintSymbolList( TopSymbolList); 
				env = TopSymbolList->prev;
				DestroySymbolList( TopSymbolList ); 
				TopSymbolList = env;                 
			}
;

decls   : decl decls          { printf("\t\t\t decl decls -> decls \n"); }
        | /*empty*/           { printf("\t\t\t null -> decls \n"); }
;

decl    : type ID ';'         { int width;
                                printf("\t\t\t type ID; -> decl \n",$2.id.name); 
								switch( $1.basic.type ) {
                                    case CHAR  : width = CHAR_WIDTH;  break;
                                    case INT   : width = INT_WIDTH;   break;
                                    case FLOAT : width = FLOAT_WIDTH; break;
                                    case BOOL  : width = BOOL_WIDTH;  break;
                                    default    : width = -1; break;
                                }
                                AddToSymbolList( TopSymbolList, $2.id.name, $1.basic.type, width );
                              }
;

type    : BASIC                 { printf("\t\t\t BASIC -> type \n"); $$.basic.type = $1.basic.type; }
;

stmts   : stmt stmts            { printf("\t\t\t stmt stmts -> stmts \n");}
        | /*empty*/             { printf("\t\t\t null ->  stmts \n");}
;

stmt    : ID '=' expr ';'                  { printf("\t\t\t id = expr; -> stmt \n"); }
        | IF '(' bool ')' stmt             { printf("\t\t\t if (bool) stmt -> stmt \n");}
        | IF '(' bool ')' stmt ELSE stmt   { printf("\t\t\t if (bool) stmt esle stmt -> stmt \n"); }
        | WHILE '(' bool ')' stmt          { printf("\t\t\t while (bool) stmt -> stmt \n"); }
        | DO stmt WHILE '(' bool ')' ';'   { printf("\t\t\t do stmt while (bool) -> stmt \n"); }
        | BREAK  ';'                       { printf("\t\t\t break; -> stmt \n"); }
        | block                            { printf("\t\t\t block -> stmt \n"); }
;

bool    : bool OR join                     { printf("\t\t\t bool OR join -> bool \n"); }
        | join                             { printf("\t\t\t join -> bool \n"); }  
;

join    : join AND equality                { printf("\t\t\t join AND equality -> join \n"); } 
        | equality                         { printf("\t\t\t equality -> join \n"); } 
;

equality : equality EQ  rel          		{ printf("\t\t\t equality EQ rel -> equality \n"); }
         | equality NEQ rel          		{ printf("\t\t\t equality NEQ rel -> equality \n"); }
         | rel                             	{ printf("\t\t\t rel -> equality \n"); }
		 ;
 
rel   :  expr LT expr   	{ printf("\t\t\t expr LT expr -> rel  \n"); }
      |  expr LE expr   	{ printf("\t\t\t expr LE expr -> rel  \n"); }
      |  expr GT expr   	{ printf("\t\t\t expr GT expr -> rel  \n"); }
      |  expr GE expr   	{ printf("\t\t\t expr GE expr -> rel  \n"); }
      |  expr               { printf("\t\t\t expr -> rel  \n"); }
;


expr  : expr  '+' term    { printf("\t\t\t expr + term -> expr \n"); 

    // 类型检查与结果类型推导
    $$.expr.type = ($1.expr.type == FLOAT || $3.term.type == FLOAT) ? FLOAT : INT;
    
    // 生成临时变量
    char temp_name[ID_MAX_LEN];
    sprintf(temp_name, "t%d", NewTemp(TopSymbolList, "", $$.expr.type));
    
    // 根据类型选择操作码
    int opcode = ($$.expr.type == FLOAT) ? OFloatAdd : OIntAdd;
    
    // 生成四元式
    $$.expr.addr = Gen(opcode, $1.expr.addr, $3.term.addr, 
                      GetTempAddr(temp_name),
                      $1.expr.str, $3.term.str, temp_name);
    
    // 更新属性
    strcpy($$.expr.str, temp_name);
    $$.expr.width = ($1.expr.type == FLOAT) ? FLOAT_WIDTH : INT_WIDTH;
}


      | expr  '-' term    { printf("\t\t\t expr - term -> expr \n"); 
	  
	  
	                      }
 
      | term              { printf("\t\t\t term -> expr \n");
							strcpy( $$.expr.str, $1.term.str );
							$$.expr.type = $1.term.type;
							$$.expr.addr = $1.term.addr;
							$$.expr.width = $1.term.width;	
	  
	                      }
;

term  : term  '*' factor  { printf("\t\t\t term*factor -> term \n"); }

      | term  '/' factor  { printf("\t\t\t term/factor -> term \n"); }

      | factor            { printf("\t\t\t factor -> term \n");
							strcpy( $$.term.str, $1.factor.str );
							$$.term.type = $1.factor.type;
							$$.term.addr = $1.factor.addr;
							$$.term.width = $1.factor.width;	
	                      }
;

factor: '(' expr ')'      { printf("\t\t\t (expr) -> factor \n" );
							strcpy( $$.factor.str, $2.expr.str );
							$$.factor.type  = $2.expr.type;
							$$.factor.addr  = $2.expr.addr;
							$$.factor.width = $2.expr.width;
                          }

      	| ID              { 
	                        struct SymbolElem * p;
							printf("\t\t\t id -> factor \n"); 
							p = LookUpAllSymbolList( TopSymbolList, $1.id.name );
							if( p != NULL ) {
								strcpy( $$.factor.str, p->name );
								$$.factor.type  = p->type;
								$$.factor.addr  = p->addr;
								$$.factor.width = p->width;
							}							    
							else {
							    yyerror( "变量名没有定义" );
								strcpy( $$.factor.str, "no_id_defined" ); /*容错处理*/
								$$.factor.type = INT;
								$$.factor.addr = -1;
								$$.factor.width = INT_WIDTH;							    
							}
	                      }

      | CONST             {                        
							struct ConstElem * p; 
							    printf("\t\t\t CONST -> factor \n");

								p = LookUpConstList( $1.constval.type, $1.constval.value, $1.constval.width );
								if( p== NULL )
                                    p = AddToConstList( $1.constval.str, $1.constval.type, $1.constval.value, $1.constval.width );

								strcpy( $$.factor.str, $1.constval.str );
								$$.factor.type  = $1.constval.type;
								$$.factor.addr  = p->addr;
								$$.factor.width = p->width;
                          }
; 
%%
