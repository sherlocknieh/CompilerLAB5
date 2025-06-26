#include <stdio.h>     // for printf, sprintf
#include <stdlib.h>    // for malloc, free
#include <string.h>    // for strcpy, memset



#define CHAR     1
#define INT      2
#define FLOAT    3
#define BOOL     4

#define CHAR_WIDTH  1
#define INT_WIDTH   4
#define FLOAT_WIDTH 8
#define BOOL_WIDTH  1

#define ID_MAX_LEN  64



/**********************公用变量声明**********************/
extern int error_flag;                  // 失败标记
extern int line_num;                    // 当前行号
extern FILE *yyin;                      // 输入文件指针, 具体定义在 Flex 生成的 lex.yy.c 中


/**********************公用函数声明**********************/
int yylex(void);
int yyparse(void);
void yyerror(char * err_msg);


/*****************************符号表结构定义*******************************/
/*符号节点*/
struct Symbol {
    char name[ ID_MAX_LEN + 1 ]; /*符号名(例如变量名)长度不超过 ID_MAX_LEN 个字符*/
    int  type;      /*类型名，例如 int, 这个程序只处理简单类型，在实际的编译器中，这里要建立树结构*/
    int  addr;      /*为该变量分配的空间的首地址*/
	int  width;     /*该变量的宽度，即占用多少个字节*/
    struct Symbol * next;  /*指向下一个标识符*/
};

/*符号表*/
typedef struct SymbolList {
    struct Symbol * head;   /*指向符号表（用链表实现）的第一个结点，没有头结点,初始化为NULL*/
    struct SymbolList * prev;   /*上一层的符号表*/
    int beginaddr;              /*该符号表中分配给变量和临时变量空间的开始地址*/
    int endaddr;                /*该符号表中分配给变量和临时变量空间的结束地址*/
}* SymbolListPtr;


/*符号表操作*/
SymbolListPtr CreateSymbolList( SymbolListPtr PrevList, int StartAddr ); /*创建符号表*/
struct Symbol * LookUpSymbolList( SymbolListPtr List, char * IdName ); /*查找符号*/
struct Symbol * LookUpAllSymbolList( SymbolListPtr List, char * IdName ); /*在所有上级符号表中查找符号*/
struct Symbol * AddToSymbolList( SymbolListPtr List, char * IdName, int IdType, int Width ); /*添加符号*/
int NewTemp( SymbolListPtr List, char Name[], int Width ); /*添加临时变量*/
void DestroySymbolList( SymbolListPtr List );  /*销毁符号表*/
void PrintSymbolList( SymbolListPtr List );    /*打印符号表*/





/*****************************常量表结构定义*******************************/
/*常量值*/
union ConstVal {
        char    ch;    /*存放字符常量*/
        int     n;     /*存放整型常量，或true=1，false=0 */
        double  f;     /*存放浮点数常量*/
};	

/*常量节点*/
struct ConstElem {
    char str[ID_MAX_LEN + 1 ]; /*该变量用于存储常数的文本形式，演示的时候用的,实际的编译系统不需要*/	   
    int type; /*用来存放类型名，例如int*/
    union ConstVal value;
    int  addr;      /*为该常量分配的空间的首地址*/
	int  width;     /*该变量的宽度，即占用多少个字节*/
    struct ConstElem * next;  /*指向下一个常量*/
};

/*常量表*/
struct ConstList{
    struct ConstElem * head;  /*指向常量表（用链表实现）的第一个结点，没有头结点,初始化为NULL*/
    int beginaddr;  /*该符号表中分配给常量空间的开始地址*/
    int endaddr;    /*该符号表中分配给常量空间的结束地址*/
};



/*常量表操作函数*/
void CreateConstList( int StartAddr );
void PrintConstList(void); /*打印常量表*/
void DestroyConstList( void ); /*销毁常量表*/
struct ConstElem * LookUpConstList( int ConstType, union ConstVal ConstValue, int Width );
struct ConstElem * AddToConstList( char * Str, int ConstType, union ConstVal ConstValue, int Width );





/*****************************四元式表结构定义*******************************/
/* 操作码定义 */
/* 整型加减乘除 */
#define OIntAdd          1001
#define OIntSub          1002
#define OIntMultiply     1003
#define OIntDivide       1004

/* 浮点数加减乘除 */
#define OFloatAdd        1011
#define OFloatSub        1012
#define OFloatMultiply   1013
#define OFloatDivide     1014

/* 赋值语句 a=b*/
#define OIntEvaluation   1021
#define OFloatEvaluation 1022
#define OCharEvaluation  1023
#define OBoolEvaluation  1024

/* goto 语句 */
#define OGoto            1031

/* if a op b goto 语句 */
#define OGTGoto          1041
#define OGEGoto          1042
#define OLTGoto          1043
#define OLEGoto          1044
#define OEQGoto          1045
#define ONEQGoto         1046

/*类型转换运算符*/
#define OCharToInt       1051
#define OCharToFloat     1052
#define OIntToFloat      1053
#define OIntToChar       1054
#define OFloatToChar     1055
#define OFloatToInt      1056
#define OCharToBool      1057
#define OIntToBool       1058
#define OFloatToBool     1059
#define OBoolToChar      1060
#define OBoolToInt       1061
#define OBoolToFloat     1062 


/*四元式*/
struct Quadruple {
    int op; /*运算符*/
    int arg1; /*存放第一个参数的地址，可能是变量、临时变量的地址*/
    int arg2;
    int arg3; /*存放第三个参数的地址，可能是变量、临时变量的地址，还可能是四元式的地址(Goto 的地址参数)*/
};

/*四元式表*/
struct QuadTable {
    int startaddr; /*四元式开始存放的地址,比如100*/
    struct Quadruple * base; /*指向一块内存，用来存放多个四元式，从base[0]开始存放*/
    int size; /*base中可以存放的四元式的个数*/
    int len; /*base[len]是下一个四元式要存放的空间*/
};

/*四元式操作函数*/
void CreateQuadTable(int StartAddr);    /*创建四元式表*/
void DestroyQuadTable( void );          /*销毁四元式表*/
void WriteQuadTableToFile( const char * FileName ); /*将四元式表输出到文件*/
int Gen(int Op, int Arg1, int Arg2, int Arg3); /*生成一个四元式到四元式表，并返回它的地址*/





/****************************属性栈元素结构定义******************************/
union ParseStackNodeInfo{
    struct {
        char name[ID_MAX_LEN + 1 ]; 
    }id;  /*标识符:终结符ID的综合属性*/

    struct {
	   char str[ID_MAX_LEN + 1 ]; /*该变量用于存储常数的文本形式，演示的时候用的,实际的编译系统不需要*/	   
       int type; /*用来存放类型名，例如INT*/
	   union ConstVal value; /*常量：终结符CONST的信息*/
	   int width;
	} constval; /*终结符const的综合属性*/

    struct {
        int type; /*用来存放类型名，例如INT*/
    }basic; /*基本数据类型：终结符BASIC的综合属性*/

	struct {
	   char str[ID_MAX_LEN + 1 ]; /*该变量用于存储变量名、临时变量名或常数的文本形式，演示的时候用的,实际的编译系统不需要*/
	   int type;
	   int addr;
	   int width;
	} factor, term, expr;/*非终结符factor, term, expr的综合属性*/
    /*其它文法符号的属性记录可以在下面继续添加*/
};

#define YYSTYPE union ParseStackNodeInfo 
/*****************************************************************************/
