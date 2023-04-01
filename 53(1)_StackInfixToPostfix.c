/*  
    ALGORITHM :-
    - SCAN THE EXPRESSION FROM LEFT TO RIGHT AND FOR EACH SYMBOL DO THE FOLLOWING:
    1> IF THE SYMBOL IS AN OPERAND THEN PRINT THE SYMBOL ON THE SCREEN.
    2> IF THE SYMBOL IS LEFT PARENTHESIS THEN PUSH IT ONTO THE STACK.
    3> IF THE SYMBOL IS A RIGHT PARENTHESIS THEN
        A) POP ALL THE OPERATORS FROM THE STACK UPTO THE FIRST LEFT PARENTHESIS AND STORE THE OPERTORS IN THE POSTFIX ARRAY.
        B) DICARD BOTH LEFT AND RIGHT THE PARENTHESES.
    4> IF SYMBOL IS AN OPERATOR THEN
        A) IF THE OPERATORS IN THE STACK HAVE HIGHER OR EQUAL PRECEDENCE THAN THE CURRENT OPERATOR THEN
            -> POP THE OPERATORS OUT OF THE STACK AND STORE ALL THE OPERATORS IN THE POST FIX ARRAY AND PUSH THE CURRENT
               OPERATOR ONTO THE STACK.
        ELSE
            -> PUSH THE CURRENT OPERATOR ONTO THE STACK.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

void push(char c)
{
    if(top==MAX-1)
    {
        printf("STACK OVERFLOW\n");
        return ;
    }
    top++;
    stack[top]=c;
}
char pop()
{
    char c;
    if(top==-1)
    {
        printf("STACK UNDERFLOW\n");
        exit(1) ;
    }
    c=stack[top];
    top--;
    return c;
}
int is_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
int space(char c)
{
    if(c==' ' || c=='\t')
        return 1;
    else 
        return 0;
}
void infix_to_postfix()
{
    int i,j=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while((next=pop())!='(')
                    postfix[j++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!is_empty() && precedence(stack[top]) >= precedence(symbol))
                        postfix[j++]=pop();
                    push(symbol);
                    break;
            default:
                postfix[j++]=symbol;
            }
        }
    }
    while (!is_empty())
        postfix[j++]=pop();
    postfix[j]='\0';
    
}
void print()
{
    int i=0;
    printf("THE EQUVALENT POSTFIX FORM OF THE EXPRESSION IS:-\n");
    // for(i=0;i<strlen(postfix);i++)
    //     printf("%c",postfix[i]);
    while (postfix[i])
    {
        printf("%c",postfix[i++]);
    }
    printf("\n");
}
int main()
{   
    printf("ENTER THE INFIX EXPRESSION:-\n");
    gets(infix);

    infix_to_postfix();
    print();
    return 0;
}
