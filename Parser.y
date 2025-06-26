%{
#include "common.h"
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
function :   BASIC ID '(' ')' block   { printf("\t\t| function\t: BASIC ID ( ) block\n"); };

block   :   '{' blockM1 decls stmts blockM2 '}'
{
    printf("\t\t| block\t: {decls stmts}\n");

};

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

decls   :   decls decl          { printf("\t\t| decls\t: decls decl\n"); }
        | /*empty*/           { printf("\t\t| decls\t: null\n"); }
;

decl    :   type ID ';'         { int width;
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

type    :   BASIC                 { printf("\t\t| type\t: BASIC\n"); $$.basic.type = $1.basic.type; }
;

stmts   :   stmts stmt            { printf("\t\t| stmts\t: stmts stmt\n");}
        |   /*empty*/             { printf("\t\t| stmts\t: null\n");}
;

stmt    :   IF '(' bool ')' stmt             { printf("\t\t| stmt\t: IF (bool) stmt\n");}
stmt    :   IF '(' bool ')' stmt ELSE stmt   { printf("\t\t| stmt\t: IF (bool) stmt ELSE stmt\n"); }
stmt    :   WHILE '(' bool ')' stmt          { printf("\t\t| stmt\t: WHILE (bool) stmt\n"); }
stmt    :   DO stmt WHILE '(' bool ')' ';'   { printf("\t\t| stmt\t: DO stmt WHILE (bool) ;\n"); }
stmt    :   block                            { printf("\t\t| stmt\t: block\n"); }
;

bool    :   bool OR join                     { printf("\t\t| bool\t: bool OR join\n"); }
bool    :   join                             { printf("\t\t| bool\t: join\n"); }
;

join    :   join AND equal                { printf("\t\t| join\t: join AND equal\n"); }
join    :   equal                         { printf("\t\t| join\t: equal\n"); }
;

equal   :   equal EQ  rel          		{ printf("\t\t| equal\t: equal EQ rel\n"); }
equal   :   equal NEQ rel          		{ printf("\t\t| equal\t: equal NEQ rel\n"); }
equal   :   rel                             	{ printf("\t\t| equal\t: rel\n"); }
;

rel     :   expr LT expr   	{ printf("\t\t| rel\t: expr LT expr\n"); }

rel     :   expr LE expr   	{ printf("\t\t| rel\t: expr LE expr\n"); }
rel     :   expr GT expr   	{ printf("\t\t| rel\t: expr GT expr\n"); }
rel     :   expr GE expr   	{ printf("\t\t| rel\t: expr GE expr\n"); }
rel     :   expr               { printf("\t\t| rel\t: expr\n"); }
;


/* 赋值语句 */
stmt    :   ID '=' expr ';'  {
    // 查找符号表
    struct Symbol * p;
    p = LookUpAllSymbolList( TheSymbolList, $1.id.name );
    // ID 不存在
    if( p == NULL ) {
        // 符号不存在
        char msg[128];
        sprintf(msg, "变量 \"%s\" 未定义", $1.id.name);
        yyerror(msg);
        return 0;
    }
    // ID 存在
    // 四元式
    int qaddr = GenQuadruple( OIntEvaluation, $3.expr.addr, 0, p->addr, $3.expr.str, "", $1.id.name);
    //归约
    printf("\t\t| stmt\t: ID = expr ;\n");
};



/* 算术表达式 */
expr    :   expr '+' term  {
    //类型推导
    int type = MAX($1.term.type, $3.term.type);
    int width = TYPE_WIDTH(type);
    //创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    //生成四元式
    int OpCode = (type == FLOAT ? OFloatAdd : OIntAdd);
    int qaddr = GenQuadruple( OpCode, $1.term.addr, $3.term.addr, addr, $1.term.str, $3.term.str, str);
    //归约
    printf("\t\t| expr\t: expr + term\n");
    strcpy( $$.expr.str, str);
    $$.expr.type = type;
    $$.expr.addr = addr;
    $$.expr.width = width;
};

expr    :   expr '-' term  {
    //类型推导
    int type = MAX($1.term.type, $3.term.type);
    int width = TYPE_WIDTH(type);
    //创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    //生成四元式
    int OpCode = (type == FLOAT ? OFloatSub : OIntSub);
    int qaddr = GenQuadruple( OpCode, $1.term.addr, $3.term.addr, addr, $1.term.str, $3.term.str, str);
    //归约
    printf("\t\t| expr\t: expr - term\n");
    strcpy( $$.expr.str, str);
    $$.expr.type = type;
    $$.expr.addr = addr;
    $$.expr.width = width;
};

expr    :   term  {
    printf("\t\t| expr\t: term\n");
    strcpy( $$.expr.str, $1.term.str );
    $$.expr.type = $1.term.type;
    $$.expr.addr = $1.term.addr;
    $$.expr.width = $1.term.width;
};

term    :   term '*' factor  {
    // 类型推导
    int type = MAX($1.term.type, $3.factor.type);
    int width = TYPE_WIDTH(type);
    // 创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    // 生成四元式
    int OpCode = (type == FLOAT ? OFloatMultiply : OIntMultiply);
    int qaddr = GenQuadruple( OpCode, $1.term.addr, $3.factor.addr, addr, $1.term.str, $3.factor.str, str);
    // 归约
    printf("\t\t| term\t: term * factor\n");
    strcpy( $$.term.str, str);
    $$.term.type = type;
    $$.term.addr = addr;
    $$.term.width = width;
};

term    :   term '/' factor {
    // 类型推导
    int type = MAX($1.term.type, $3.factor.type);
    int width = TYPE_WIDTH(type);
    // 创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    // 生成四元式
    int OpCode = (type == FLOAT ? OFloatDivide : OIntDivide);
    printf("OpCode = %d\n", OpCode);
    int qaddr = GenQuadruple( OpCode, $1.term.addr, $3.factor.addr, addr, $1.term.str, $3.factor.str, str);
    // 归约
    printf("\t\t| term\t: term / factor\n");
    strcpy( $$.term.str, str);
    $$.term.type = type;
    $$.term.addr = addr;
    $$.term.width = width;
};

term    :   factor {
    printf("\t\t| term\t: factor\n");
    strcpy( $$.term.str, $1.factor.str );
    $$.term.type = $1.factor.type;
    $$.term.addr = $1.factor.addr;
    $$.term.width = $1.factor.width;
};

factor  :   '-' factor %prec UMINUS {
    // 创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, $2.factor.width);
    // 生成四元式
    GenQuadruple( OUMINUS, $2.factor.addr, 0, addr, $2.factor.str, "", str);
    // 归约
    printf("\t\t| factor\t: -factor\n");
    strcpy( $$.factor.str, str);
    $$.factor.type  = $2.factor.type;
    $$.factor.addr  = addr;
    $$.factor.width = $2.factor.width;
};

factor  :   ID {
    printf("\t\t| factor\t: ID\n");
    // 查找符号表
    struct Symbol * p;
    p = LookUpAllSymbolList( TheSymbolList, $1.id.name );
    // 符号存在
    if( p != NULL ) {
        // 从符号表中获取值进行归约
        strcpy( $$.factor.str, p->name );
        $$.factor.type  = p->type;
        $$.factor.addr  = p->addr;
        $$.factor.width = p->width;
    }
    else {
        // 符号不存在
        char msg[128];
        sprintf(msg, "变量 \"%s\" 未定义", $1.id.name);
        yyerror(msg);
        /*容错归约*/
        strcpy( $$.factor.str, "no_id_defined" );
        $$.factor.type = INT;
        $$.factor.addr = -1;
        $$.factor.width = INT_WIDTH;
        }
};

factor  :   CONST {
    printf("\t\t| factor\t: CONST\n");
    // 查找常量表
    struct ConstElem * p;
    p = LookUpConstList( $1.constval.type, $1.constval.value, $1.constval.width );
    // 该常量不存在, 则添加到常量表
    if( p == NULL )
        p = AddToConstList( $1.constval.str, $1.constval.type, $1.constval.value, $1.constval.width );
    // 归约
    strcpy( $$.factor.str, $1.constval.str );
    $$.factor.type  = $1.constval.type;
    $$.factor.addr  = p->addr;
    $$.factor.width = p->width;
};

factor  :   '(' expr ')' {
    printf("\t\t| factor\t: (expr)\n" );
    strcpy( $$.factor.str, $2.expr.str );
    $$.factor.type  = $2.expr.type;
    $$.factor.addr  = $2.expr.addr;
    $$.factor.width = $2.expr.width;
};
%%
