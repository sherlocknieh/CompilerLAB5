#include "common.h"

extern SymbolListPtr TheSymbolList;  // 符号表指针
extern struct ConstList TheConstList ;     // 常量表
extern struct QuadTable TheQuadTable;      // 四元式表

int main()
{
    char inputfile[] = "code.c";      // 输入文件路径
    char destfile[]  = "code.txt";    // 输出文件路径

    printf("\n[INFO] 打开输入文件\t: %s\n", inputfile);
    yyin = fopen(inputfile, "r");
    printf("[INFO] 创建四元式表\t: 地址从 100 开始\n");
    CreateQuadTable(100);

    printf("[INFO] 创建常量表\t: 地址从 1000 开始\n");
    CreateConstList(1000);
    
    printf("[INFO] 创建符号表\t: 地址从 2000 开始\n");
    TheSymbolList = CreateSymbolList( NULL, 2000 );
    

    printf("\n[INFO] 开始解析:\n\n");
    printf("词法分析: \t| 语法分析:\n");

    yyparse();

    
    printf("\n[INFO] 解析结束\n");
    printf("[INFO] 打印常量表\n");
    PrintConstList();

    printf("[INFO] 四元式表已写入 %s 文件\n", destfile);
    WriteQuadTableToFile( destfile );
    
    if( error_flag == 0 ) 
	    printf("[INFO] 翻译成功!\n");
	else {
	    printf("[ERROR] 翻译失败!\n" );
        printf("[ERROR] 第 %d 行出错\n", error_flag);
    }
    return 0;
}

