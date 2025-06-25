%{
#include "common.h"
#include "y.tab.h"
int LineNo = 1;
%}


integer  [0-9]+
id       [a-zA-Z_]([a-zA-Z_]|[0-9])*
number   [0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?
comment  [\/][\*]([^\*])*[\*]([^\*\/](([^\*])*)[\*]|[\*])*(\/)
character "'"."'"


%%
[" "\t]+   { /*空白符*/ }
"\n"       { LineNo++; }
{comment}  { printf("注释: %s\n", yytext); }

do         {  printf("%s -> DO\n", yytext); return (DO);    }
if         {  printf("%s -> IF\n", yytext); return (IF);    }
else       {  printf("%s -> ELSE\n", yytext); return (ELSE);  }
while      {  printf("%s -> WHILE\n", yytext); return (WHILE); }	
break      {  printf("%s -> BREAK\n", yytext); return (BREAK); }

"<"        {  printf("%s -> LT\n", yytext); return (LT);  }
">"        {  printf("%s -> GT\n", yytext); return (GT);  }
"<="       {  printf("%s -> LE\n", yytext); return (LE);  }
">="       {  printf("%s -> GE\n", yytext); return (GE);  }
"=="       {  printf("%s -> EQ\n", yytext); return (EQ);  }
"!="       {  printf("%s -> NEQ\n", yytext); return (NEQ); }
"||"       {  printf("%s -> OR\n", yytext); return (OR);  }
"&&"       {  printf("%s -> AND\n", yytext); return (AND); }

char       { printf("%s -> BASIC\n", yytext); yylval.basic.type=CHAR;   return (BASIC); }
int        { printf("%s -> BASIC\n", yytext); yylval.basic.type=INT;    return (BASIC); }
float      { printf("%s -> BASIC\n", yytext); yylval.basic.type=FLOAT;  return (BASIC); }
bool       { printf("%s -> BASIC\n", yytext); yylval.basic.type=BOOL;   return (BASIC); }

true        { printf("%s -> CONST\n", yytext);
		      strcpy(yylval.constval.str, yytext); /*str用于演示用*/
			  yylval.constval.type = BOOL;
			  memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
			  yylval.constval.value.n = 1;
			  yylval.constval.width = BOOL_WIDTH;
			  return CONST; 
			}

false       { printf("%s -> CONST\n", yytext);
			  strcpy(yylval.constval.str, yytext); /*str用于演示用*/
			  yylval.constval.type = BOOL;
			  memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
			  yylval.constval.value.n = 0;
			  yylval.constval.width = BOOL_WIDTH;
			  return CONST;
			}

{character} { printf("%s -> CONST\n", yytext);
			  yylval.constval.str[0] = yytext[1]; yylval.constval.str[1]='\0';  /*str用于演示用*/
			  yylval.constval.type = CHAR;
			  memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
			  yylval.constval.value.ch = yytext[1];
			  yylval.constval.width = CHAR_WIDTH;
			  return CONST; 
			}

{integer}   { printf("%s -> CONST\n", yytext); 
			  strcpy(yylval.constval.str, yytext); /*str用于演示用*/
			  yylval.constval.type = INT; 
			  memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
			  sscanf( yytext, "%d",&yylval.constval.value.n);
			  yylval.constval.width = INT_WIDTH;
			  return CONST; 
			}

{number}    { printf("%s -> CONST\n", yytext);
			  strcpy(yylval.constval.str, yytext);  /*str用于演示用*/
			  yylval.constval.type = FLOAT;
			  memset( &yylval.constval.value, 0, sizeof( yylval.constval.value) );
			  sscanf( yytext, "%lf", &yylval.constval.value.f );
			  yylval.constval.width = FLOAT_WIDTH;
			  return CONST; 
			} 

{id}       {  printf("%s -> ID\n", yytext);
			  strncpy( yylval.id.name, yytext, ID_MAX_LEN );
			  yylval.id.name[ID_MAX_LEN]='\0'; return (ID); }

.          { printf("%c -> %c\n", yytext[0], yytext[0]); 
			  return yytext[0]; }
%%
