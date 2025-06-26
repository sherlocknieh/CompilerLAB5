%{
#include "common.h"
extern SymbolListPtr TheSymbolList;  // 符号表指针
extern struct ConstList TheConstList ;     // 常量表
extern struct QuadTable TheQuadTable;      // 四元式表
%}

%token BASIC
%token CONST
%token ID

%token IF
%token ELSE
%token DO
%token WHILE
%token BREAK

%token LT
%token LE
%token GT
%token GE

%token EQ
%token NEQ

%token OR
%token AND

%left '*' '/' '+' '-'
%right '!'  '=' UMINUS


%%
function : BASIC ID '(' ')' block   { printf("\t\t| function\t: BASIC ID ( ) block\n"); }

block   : '{' blockM1 decls stmts blockM2 '}'   { printf("\t\t| block\t: {decls stmts}\n"); }
;

blockM1 :   {   printf("[INFO] 进入新的作用域, 创建符号表\n");
                TheSymbolList = CreateSymbolList( TheSymbolList, TheSymbolList->endaddr ); }
;

blockM2 :   { SymbolListPtr env;
    PrintSymbolList( TheSymbolList);
    env = TheSymbolList->prev;
    DestroySymbolList( TheSymbolList );
    TheSymbolList = env;
    }
;

decls   : decls decl          { printf("\t\t| decls\t: decls decl\n"); }
        | /*empty*/           { printf("\t\t| decls\t: null\n"); }
;

decl    : type ID ';'         { int width;
                                printf("\t\t| decl\t: type ID ;\n",$2.id.name);
    	switch( $1.basic.type ) {
                                    case CHAR  : width = CHAR_WIDTH;  break;
                                    case INT   : width = INT_WIDTH;   break;
                                    case FLOAT : width = FLOAT_WIDTH; break;
                                    case BOOL  : width = BOOL_WIDTH;  break;
                                    default    : width = -1; break;
                                }
                                AddToSymbolList( TheSymbolList, $2.id.name, $1.basic.type, width );
                              }
;

type    : BASIC                 { printf("\t\t| type\t: BASIC\n"); $$.basic.type = $1.basic.type; }
;

stmts   : stmts stmt            { printf("\t\t| stmts\t: stmts stmt\n");}
        | /*empty*/             { printf("\t\t| stmts\t: null\n");}
;

stmt    : ID '=' expr ';'                  { printf("\t\t| stmt\t: ID = expr ;\n"); }
        | IF '(' bool ')' stmt             { printf("\t\t| stmt\t: IF (bool) stmt\n");}
        | IF '(' bool ')' stmt ELSE stmt   { printf("\t\t| stmt\t: IF (bool) stmt ELSE stmt\n"); }
        | WHILE '(' bool ')' stmt          { printf("\t\t| stmt\t: WHILE (bool) stmt\n"); }
        | DO stmt WHILE '(' bool ')' ';'   { printf("\t\t| stmt\t: DO stmt WHILE (bool) ;\n"); }
        | block                            { printf("\t\t| stmt\t: block\n"); }
;

bool    : bool OR join                     { printf("\t\t| bool\t: bool OR join\n"); }
        | join                             { printf("\t\t| bool\t: join\n"); }
;

join    : join AND equal                { printf("\t\t| join\t: join AND equal\n"); }
        | equal                         { printf("\t\t| join\t: equal\n"); }
;

equal   : equal EQ  rel          		{ printf("\t\t| equal\t: equal EQ rel\n"); }
        | equal NEQ rel          		{ printf("\t\t| equal\t: equal NEQ rel\n"); }
        | rel                             	{ printf("\t\t| equal\t: rel\n"); }
;

rel   :  expr LT expr   	{ printf("\t\t| rel\t: expr LT expr\n"); }
      |  expr LE expr   	{ printf("\t\t| rel\t: expr LE expr\n"); }
      |  expr GT expr   	{ printf("\t\t| rel\t: expr GT expr\n"); }
      |  expr GE expr   	{ printf("\t\t| rel\t: expr GE expr\n"); }
      |  expr               { printf("\t\t| rel\t: expr\n"); }
;


expr  : expr '+' term       { printf("\t\t| expr\t: expr + term\n"); }
      | expr '-' term       { printf("\t\t| expr\t: expr - term\n"); }
      | term            {
                            printf("\t\t| expr\t: term\n");
                            strcpy( $$.expr.str, $1.term.str );
                            $$.expr.type = $1.term.type;
                            $$.expr.addr = $1.term.addr;
                            $$.expr.width = $1.term.width;
                        }
;

term  : term '*' factor  { printf("\t\t| term\t: term * factor\n"); }

      | term '/' factor  { printf("\t\t| term\t: term / factor\n"); }

      | factor { printf("\t\t| term\t: factor\n");
                strcpy( $$.term.str, $1.factor.str );
                $$.term.type = $1.factor.type;
                $$.term.addr = $1.factor.addr;
                $$.term.width = $1.factor.width;}
;

factor  
: '-' factor %prec UMINUS {
    char temp_str[16];
    int temp_addr = NewTemp( TheSymbolList, temp_str, $2.factor.width ); /*新增临时变量*/
    printf("\t\t| factor\t: -factor\n");
    strcpy( $$.factor.str, temp_str);
    $$.factor.type  = $2.expr.type;
    $$.factor.addr  = temp_addr;
    $$.factor.width = $2.expr.width;
}

factor: '(' expr ')'
{
    printf("\t\t| factor\t: (expr)\n" );
    strcpy( $$.factor.str, $2.expr.str );
    $$.factor.type  = $2.expr.type;
    $$.factor.addr  = $2.expr.addr;
    $$.factor.width = $2.expr.width;
};

| ID {
    printf("\t\t| factor\t: ID\n");
    struct Symbol * p;
    p = LookUpAllSymbolList( TheSymbolList, $1.id.name );
    if( p != NULL ) {
        strcpy( $$.factor.str, p->name );
        $$.factor.type  = p->type;
        $$.factor.addr  = p->addr;
        $$.factor.width = p->width;
    }
    else {
        char msg[128];
        sprintf(msg, "变量 \"%s\" 未定义", $1.id.name);
        yyerror(msg);
        /*容错处理*/
        strcpy( $$.factor.str, "no_id_defined" );
        $$.factor.type = INT;
        $$.factor.addr = -1;
        $$.factor.width = INT_WIDTH;
    }
}

| CONST {
    printf("\t\t| factor\t: CONST\n");
    // 查找常量表
    struct ConstElem * p;
    p = LookUpConstList( $1.constval.type, $1.constval.value, $1.constval.width );
    // 该常量不存在, 则添加到常量表
    if( p == NULL )
        p = AddToConstList( $1.constval.str, $1.constval.type, $1.constval.value, $1.constval.width );
    // 归约传值
    strcpy( $$.factor.str, $1.constval.str );
    $$.factor.type  = $1.constval.type;
    $$.factor.addr  = p->addr;
    $$.factor.width = p->width;
}
;
%%
