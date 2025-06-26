%{
#include "common.h"     // 公共头文件，包含各种常量, yylval 结构定义和其它数据结构
#include "y.tab.h"      // Bison 生成的头文件，包含 token 编码定义和 yylval 的声明
%}


integer     [0-9]+
id          [a-zA-Z_]([a-zA-Z_]|[0-9])*
number      [0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?
comment     [\/][\*]([^\*])*[\*]([^\*\/](([^\*])*)[\*]|[\*])*(\/)
character   "'"."'"


%%
{comment}   {    /*注释*/     }
[" "\t]+    {    /*空白符*/   }
"\n"        {    line_num++;    }
"//".*      
if          {    printf("IF \t: %s\t|\n", yytext);    return (IF);    }
else        {    printf("ELSE \t: %s\t|\n", yytext);  return (ELSE);  }
while       {    printf("WHILE \t: %s\t|\n", yytext); return (WHILE); }    
break       {    printf("BREAK \t: %s\t|\n", yytext); return (BREAK); }
do          {    printf("DO \t: %s\t|\n", yytext);    return (DO);    }

"||"        {    printf("OR \t: %s\t|\n", yytext);  return (OR);    }
"&&"        {    printf("AND \t: %s\t|\n", yytext); return (AND);   }
"<"         {    printf("LT \t: %s\t|\n", yytext);  return (LT);    }
">"         {    printf("GT \t: %s\t|\n", yytext);  return (GT);    }
"<="        {    printf("LE \t: %s\t|\n", yytext);  return (LE);    }
">="        {    printf("GE \t: %s\t|\n", yytext);  return (GE);    }
"=="        {    printf("EQ \t: %s\t|\n", yytext);  return (EQ);    }
"!="        {    printf("NEQ \t: %s\t|\n", yytext); return (NEQ);   }

char        {    printf("BASIC \t: %s\t|\n", yytext); yylval.basic.type=CHAR;   return (BASIC);    }
int         {    printf("BASIC \t: %s\t|\n", yytext); yylval.basic.type=INT;    return (BASIC);    }
float       {    printf("BASIC \t: %s\t|\n", yytext); yylval.basic.type=FLOAT;  return (BASIC);    }
bool        {    printf("BASIC \t: %s\t|\n", yytext); yylval.basic.type=BOOL;   return (BASIC);    }

true        {
                printf("CONST \t: %s\t|\n", yytext);
                strcpy(yylval.constval.str, yytext);
                yylval.constval.type = BOOL;
                memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
                yylval.constval.value.n = 1;
                yylval.constval.width = BOOL_WIDTH;
                return CONST; 
            }

false       {
                printf("CONST \t: %s\t|\n", yytext);
                strcpy(yylval.constval.str, yytext);
                yylval.constval.type = BOOL;
                memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
                yylval.constval.value.n = 0;
                yylval.constval.width = BOOL_WIDTH;
                return CONST;
            }

{character} {
                printf("CONST \t: %s\t|\n", yytext);
                yylval.constval.str[0] = yytext[1]; yylval.constval.str[1]='\0';
                yylval.constval.type = CHAR;
                memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
                yylval.constval.value.ch = yytext[1];
                yylval.constval.width = CHAR_WIDTH;
                return CONST; 
            }

{integer}   {
                printf("CONST \t: %s \t|\n", yytext); 
                strcpy(yylval.constval.str, yytext);
                yylval.constval.type = INT; 
                memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
                sscanf( yytext, "%d",&yylval.constval.value.n);
                yylval.constval.width = INT_WIDTH;
                return CONST; 
            }

{number}    {
                printf("CONST \t: %s\t|\n", yytext);
                strcpy(yylval.constval.str, yytext);
                yylval.constval.type = FLOAT;
                memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
                sscanf( yytext, "%lf", &yylval.constval.value.f );
                yylval.constval.width = FLOAT_WIDTH;
                return CONST;
            }

{id}        {
                printf("ID \t: %s\t|\n", yytext);
                strncpy( yylval.id.name, yytext, ID_MAX_LEN );
                yylval.id.name[ID_MAX_LEN]='\0'; return (ID);
            }

.           {    printf("%c \t: %c\t|\n", yytext[0], yytext[0]); return yytext[0];    }
%%
