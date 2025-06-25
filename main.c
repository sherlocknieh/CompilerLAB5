#include "common.h"


int main()
{
    yyin = fopen("code-input.txt", "r");   // 打开输入文件
    char destfile[] = "code-output.txt";   // 输出文件路径

    printf("[INFO] 创建常量表,假设从地址3000开始分配空间\n");
    CreateConstList(3000);
    
    printf("[INFO] 创建符号表,假定从地址2000开始分配空间\n");
    TopSymbolList = CreateSymbolList( NULL, 2000 );
    
    printf("[INFO] 创建四元式表,假定四元式从地址100开始存放\n");
    CreateQuadTable(100);

    printf("[INFO] 开始解析\n");
    printf("词法分析 \t\t 语法分析\n");
    yyparse();

    PrintConstList();

    printf("[INFO] 把四元式表写入 %s 文件\n", destfile);
    WriteQuadTableToFile( destfile );
    DestroyQuadTable();

    printf("[INFO] 销毁符号表\n");
    DestroySymbolList(TopSymbolList);
    printf("[INFO] 销毁常量表\n");
    DestroyConstList();

    printf("[INFO] 关闭输入文件\n");
    fclose(yyin);

    if( CompileFailed == 0 ) 
	    printf("[INFO] 翻译成功\n");
	else
	    printf("[INFO] 翻译失败\n" );

    return 0;
}

