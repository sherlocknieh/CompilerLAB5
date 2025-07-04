#include "common.h"


/**********************全局公用变量**********************/
SymbolListPtr TheSymbolList = NULL;  // 全局符号表指针
struct ConstList TheConstList;             // 全局常量表
struct QuadTable TheQuadTable;             // 全局四元式表
int error_flag = 0;                     // 编译失败标记
int line_num = 1;                       // 当前行号



/**************Flex & Bison 要求的函数*****************/
int yywrap(){ return 1; }       // 词法分析器结束函数
void yyerror(char * err_msg)    // 自定义报错函数
{
    error_flag = line_num;
    printf("[ERROR] 第 %d 行: %s\n", line_num, err_msg);
    //exit(1);
}



/**********************符号表操作**********************/
SymbolListPtr CreateSymbolList( SymbolListPtr PrevList, int StartAddr )
{
    SymbolListPtr list;
    list = (SymbolListPtr) malloc( sizeof(struct SymbolList) );
    memset( list, 0, sizeof( struct SymbolList ) );
    list->prev = PrevList;
	list->endaddr = list->beginaddr = StartAddr;
    return list;
}

struct Symbol * LookUpSymbolList( SymbolListPtr List, char * IdName )
{
    struct Symbol * p;
    if( List==NULL ) return NULL;
    for( p = List->head; p!=NULL; p = p->next ) 
        if( strcmp( p->name, IdName ) == 0 ) break;
    return p;
}

struct Symbol * LookUpAllSymbolList( SymbolListPtr List, char * IdName )
{
    SymbolListPtr env;

    struct Symbol * p;
    env = List;
    while( env!=NULL ) {
        p = LookUpSymbolList( env, IdName );
        if(  p != NULL ) return p; /*找到该符号*/
        env = env->prev;
    }
    return NULL;
}

struct Symbol * AddToSymbolList( SymbolListPtr List, char * IdName,int IdType, int Width )
{
    struct Symbol * p;

    p = (struct Symbol *) malloc( sizeof(struct Symbol) );

    strcpy( p->name, IdName );
    p->type = IdType;
	p->width = Width;
	p->addr = List->endaddr;
	List->endaddr += Width;

    p->next = List->head;  /*将该标识符添加到符号表表头*/
    List->head = p;

    return p;    
}

void DestroySymbolList( SymbolListPtr List )
{
    struct Symbol * p, *q;
    
    if( List == NULL) return;
    p = List->head;
    while( p!=NULL ) {
        q = p->next; free(p); p=q;
    }
    free(List);    
}

void PrintSymbolList( SymbolListPtr List )
{
    struct Symbol * p;
    printf("\n*********************当前符号表***********************\n");
    if( List ==NULL ) return ;
    for( p=List->head; p!=NULL; p=p->next ) {
        printf("变量名:%s \t类型:", p->name);
		switch( p->type ) {
            case CHAR : printf("char");  break;
            case INT  : printf("int");   break;
            case FLOAT: printf("float"); break;
            case BOOL : printf("bool");  break;
		}
        printf(" \t地址:%d \t宽度:%d\n", p->addr, p->width );
	}
    printf("*****************共占用%2d个字节空间*******************\n\n", List->endaddr - List->beginaddr);
}

int NewTemp( SymbolListPtr List, char Name[], int Width )  /*创建临时变量*/
{
    static int TempID = 1;
    sprintf( Name, "T%d", TempID++ );   // 通过 Name 参数把临时变量名返回给调用者
    int addr = List->endaddr;           // 占用符号表的地址空间
    List->endaddr += Width;             // 但是实际不加入符号表
    return addr;                        // 返回它在表中的地址
}



/**********************常量表操作**********************/
void CreateConstList( int StartAddr )
{ 
	TheConstList.head = NULL;
	TheConstList.endaddr = TheConstList.beginaddr = StartAddr;
}

void DestroyConstList( void )
{struct ConstElem * p, *q;
    
    p = TheConstList.head;
    while( p!=NULL ) {
        q = p->next; free(p); p=q;
    }
	memset( &TheConstList, 0, sizeof(struct ConstList) );
}

void PrintConstList(void)
{
    struct ConstElem * p;
    printf("\n***********************常量表*************************\n");
    for( p=TheConstList.head; p!=NULL; p=p->next ) {
	    printf("常量:%s  \t类型:", p->str);
		switch( p->type ) {
            case CHAR : printf("char");  break;
            case INT  : printf("int");   break;
            case FLOAT: printf("float"); break;
            case BOOL : printf("bool");  break;
		}
        printf(" \t地址:%d \t宽度:%d\n", p->addr, p->width );
	}
    printf("******************共占用%2d个字节空间******************\n\n", TheConstList.endaddr - TheConstList.beginaddr);
}

struct ConstElem * LookUpConstList( int ConstType, union ConstVal ConstValue, int Width )
{
    struct ConstElem * p;
    for( p = TheConstList.head; p!=NULL; p = p->next ) 
        if( p->type == ConstType && memcmp( &p->value,&ConstValue, Width) == 0 )  break;
    return p;
}

struct ConstElem * AddToConstList( char * Str, int ConstType, union ConstVal ConstValue, int Width )
{
    struct ConstElem * p;
    p = (struct ConstElem *) malloc( sizeof(struct ConstElem) );

    strcpy( p->str, Str );
    p->type = ConstType;
    p->value = ConstValue;
	p->width = Width;

	p->addr = TheConstList.endaddr;
	TheConstList.endaddr += Width;

    p->next = TheConstList.head;  /*将该常量添加到常量表表头*/
    TheConstList.head = p;

    return p;    
}



/**********************四元式表操作**********************/
void CreateQuadTable(int StartAddr)
{
    TheQuadTable.startaddr = StartAddr; 
    TheQuadTable.size = 1000; /* 一开始假设可以存放1000个四元式*/
    TheQuadTable.base = ( struct Quadruple *)malloc( TheQuadTable.size * sizeof(struct Quadruple) );
    TheQuadTable.len = 0;
}

void DestroyQuadTable( void )
{
    TheQuadTable.startaddr = 0; 
    TheQuadTable.size = 0;
    if( TheQuadTable.base != NULL) free(TheQuadTable.base); 
    TheQuadTable.len = 0;   
}

void WriteQuadTableToFile( const char * FileName )
{
    FILE * fp;
    struct Quadruple * ptr;
    int i,op;
    char str1[1000], str2[1000], ch;
    fp = fopen( FileName, "w" );
    if( fp==NULL ) return;
    for( i=0, ptr = TheQuadTable.base; i < TheQuadTable.len; i++,ptr++ ) {
        fprintf(fp, "%5d:  ", TheQuadTable.startaddr + i);
        op = ptr->op;
        switch( op ) {
            case OUMINUS        : sprintf(str1, "[%d] = -[%d]", ptr->result, ptr->arg1); 
                                  sprintf(str2, "%s\t=\t-%s", ptr->namer, ptr->name1); 
                                  break;
            case OIntAdd        :
            case OIntSub        :
            case OIntMultiply   :
            case OIntDivide     :
            case OFloatAdd      :
            case OFloatSub      :
            case OFloatMultiply :
            case OFloatDivide   : if( op==OIntAdd || op==OFloatAdd) ch = '+';
                                  if( op==OIntSub || op==OFloatSub) ch = '-';
                                  if( op==OIntMultiply || op==OFloatMultiply) ch = '*';
                                  if( op==OIntDivide || op==OFloatDivide) ch = '/';
                                  sprintf(str1,"[%d] = [%d] %c [%d]", ptr->result, ptr->arg1, ch, ptr->arg2);
                                  sprintf(str2, "%s\t=\t%s\t%c\t%s", ptr->namer, ptr->name1, ch, ptr->name2);
                                  break;
            case OIntEvaluation   :
            case OFloatEvaluation :
            case OCharEvaluation  :
            case OBoolEvaluation  : sprintf(str1,"[%d] = [%d]", ptr->result, ptr->arg1);
                                    sprintf(str2, "%s\t=\t%s", ptr->namer, ptr->name1);
                                    break;
            case OGoto            : sprintf(str1,"Goto %d", ptr->result);
                                    sprintf(str2, "Goto %s", ptr->namer);
                                    break;
            case OGTGoto  : sprintf(str1,"if [%d]>[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->result );
                            sprintf(str2, "if %s > %s Goto %s", ptr->name1, ptr->name2, ptr->namer);
                            break;
            case OGEGoto  : sprintf(str1,"if [%d]>=[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->result );
                            sprintf(str2, "if %s >= %s Goto %s", ptr->name1, ptr->name2, ptr->namer);
                            break;
            case OLTGoto  : sprintf(str1,"if [%d]<[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->result );
                            sprintf(str2, "if %s < %s Goto %s", ptr->name1, ptr->name2, ptr->namer);
                            break;
            case OLEGoto  : sprintf(str1,"if [%d]<=[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->result );
                            sprintf(str2, "if %s <= %s Goto %s", ptr->name1, ptr->name2, ptr->namer);
                            break;
            case OEQGoto  : sprintf(str1,"if [%d]==[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->result );
                            sprintf(str2, "if %s == %s Goto %s", ptr->name1, ptr->name2, ptr->namer);
                            break;
            case ONEQGoto : sprintf(str1,"if [%d]<>[%d] Goto %d", ptr->arg1, ptr->arg2, ptr->result );
                            sprintf(str2, "if %s != %s Goto %s", ptr->name1, ptr->name2, ptr->namer);
                            break;

            case OCharToInt   : sprintf(str1, "[%d] = (int) [%d]",   ptr->result, ptr->arg1 );
                                sprintf(str2, "%s = (int) %s", ptr->namer, ptr->name1);
                                break;
            case OCharToFloat : sprintf(str1, "[%d] = (float) [%d]", ptr->result, ptr->arg1 );  
                                sprintf(str2, "%s = (float) %s", ptr->namer, ptr->name1);
                                break;
            case OIntToFloat  : sprintf(str1, "[%d] = (float) [%d]", ptr->result, ptr->arg1 );
                                sprintf(str2, "%s = (float) %s", ptr->namer, ptr->name1);
                                break;
            case OIntToChar   : sprintf(str1, "[%d] = (char) [%d]",  ptr->result, ptr->arg1 ); 
                                sprintf(str2, "%s = (char) %s", ptr->namer, ptr->name1);
                                break;
            case OFloatToChar : sprintf(str1, "[%d] = (char) [%d]",  ptr->result, ptr->arg1 );  
                                sprintf(str2, "%s = (char) %s", ptr->namer, ptr->name1);
                                break;
            case OFloatToInt  : sprintf(str1, "[%d] = (int) [%d]",   ptr->result, ptr->arg1 );  
                                sprintf(str2, "%s = (int) %s", ptr->namer, ptr->name1);
                                break;
            case OCharToBool   : sprintf(str1, "[%d] = (bool) [%d]",  ptr->result, ptr->arg1 );  
                                 sprintf(str2, "%s = (bool) %s", ptr->namer, ptr->name1);
                                 break;
            case OIntToBool    : sprintf(str1, "[%d] = (bool) [%d]",  ptr->result, ptr->arg1 );  
                                 sprintf(str2, "%s = (bool) %s", ptr->namer, ptr->name1);
                                 break;
            case OFloatToBool  : sprintf(str1, "[%d] = (bool) [%d]",  ptr->result, ptr->arg1 );  
                                 sprintf(str2, "%s = (bool) %s", ptr->namer, ptr->name1);
                                 break;
            case OBoolToChar   : sprintf(str1, "[%d] = (char) [%d]",  ptr->result, ptr->arg1 );  
                                 sprintf(str2, "%s = (char) %s", ptr->namer, ptr->name1);
                                 break;
            case OBoolToInt    : sprintf(str1, "[%d] = (int) [%d]",   ptr->result, ptr->arg1 );  
                                 sprintf(str2, "%s = (int) %s", ptr->namer, ptr->name1);
                                 break;
            case OBoolToFloat  : sprintf(str1, "[%d] = (float) [%d]", ptr->result, ptr->arg1 );  
                                 sprintf(str2, "%s = (float) %s", ptr->namer, ptr->name1);
                                 break;

            default: yyerror("程序错误：出现不认识的运算符！"); strcpy(str1, "error: Unknown operator");break;
        }
        // 生成 40 - strlen(str1) 个空格
        int i = strlen(str1);
        for(; i < 30; i++ ) {
            strcat(str1, " ");
        }
        fprintf(fp,"%s |       %s\n",str1, str2);
    }

    fclose(fp);
}

int GenQuadruple( int Op, int Arg1, int Arg2, int result, char name1[], char name2[], char namer[] )
{
    struct Quadruple * ptr; 
    int incr = 100;
    if( TheQuadTable.len >= TheQuadTable.size ) {
        ptr = realloc( TheQuadTable.base, TheQuadTable.size+incr );
        if( ptr==NULL ) return -1;
        TheQuadTable.base = ptr;
        TheQuadTable.size += incr;
    }
    ptr = & TheQuadTable.base[TheQuadTable.len];

    ptr->op = Op;
    ptr->arg1 = Arg1;
    ptr->arg2 = Arg2;
    ptr->result = result;
    strcpy(ptr->name1, name1);
    strcpy(ptr->name2, name2);
    strcpy(ptr->namer, namer);
    TheQuadTable.len++;

    return TheQuadTable.len - 1;
}

