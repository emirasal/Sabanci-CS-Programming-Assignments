%{
#include <stdio.h>
int yylex();
void yyerror (const char *s)
{
  return;
}
%}

%token tSTRING tGET tSET tFUNCTION tPRINT tIF tRETURN tADD tSUB tMUL tDIV tINC tGT tLT tEQUALITY tDEC tLEQ tGEQ tIDENT tNUM

%start program


%%

program : '[' statements ']'
;

statements : 
           | statements statement
; 

statement : set
          | if
          | print
          | increment
          | decrement
          | return
          | expression
;

set : '[' tSET ',' tIDENT ',' expression ']'
;

if : '[' tIF ',' condition ',' thenElse ']'
   | '[' tIF ',' condition ',' thenElse thenElse ']'
;

condition : '[' tGT ',' expression ',' expression ']'
          | '[' tEQUALITY ',' expression ',' expression ']'
          | '[' tLEQ ',' expression ',' expression ']'
          | '[' tGEQ ',' expression ',' expression ']'
          | '[' tLT ',' expression ',' expression ']'
;

thenElse : '[' statements ']'
;

print : '[' tPRINT ',' expression ']'
;

increment : '[' tINC ',' tIDENT ']'
;

decrement : '[' tDEC ',' tIDENT ']'
;

expression : tNUM
           | tSTRING
           | get
           | function
           | operator
           | condition
;

get : '[' tGET ',' tIDENT ']'
    | '[' tGET ',' tIDENT ',' '[' functionExpression ']' ']'
;

functionExpression : 
                   | functionExpression ',' expression
                   | expression
;

function : '[' tFUNCTION ',' '[' functionParameters ']' ',' '[' statements ']' ']'
;

functionParameters: 
                  | functionParameters ',' tIDENT
                  | tIDENT
;

operator : '[' tADD ',' expression ',' expression ']'
         | '[' tSUB ',' expression ',' expression ']'
         | '[' tMUL ',' expression ',' expression ']'
         | '[' tDIV ',' expression ',' expression ']'
;

return : '[' tRETURN ']'
       | '[' tRETURN ',' expression ']'
;

%%


int main ()
{
  if (yyparse()) {
    printf("ERROR\n");
    return 1;
  }
  else {
    printf("OK\n");
    return 0;
  }
}