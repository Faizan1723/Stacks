/*
    ALGORITHM:-
    - SACN THE SYMBOLS OF THE GIVEN POSTFIX EXPRESSION FROM LEFT TO RIGHT AND FOR EACH SYMBOL DO THE FOLLOWING:-
    1> IF THE SYMBOL IS AN OPERAND THEN 
            PUSH IT ONTO THE STACK.
    2> IF THE SYMBOL IS AN OPERATOR THEN
        A) POP TWO SYMBOLS OUT OF THE STACK AND APPLY THE OPERATORS ON THE SYMBOLS.
        B) PUSH THE RESULT ON THE STACK.
    3> AFTER SCANNING ALL THE SYMBOLS OF THE POSTFIX EXPRESSION,POP THE REMAINING SYMBOLS OF THE STACK AND PRINT IT ON SCREEN.
       THE REMAINING SYMBOLS IS THE RESULT OBTAINED AFTRE EVALUATING THE POSTFIX EXPRESSION.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100

int stack[MAX];     //CHANGED
char infix[MAX];
char postfix[MAX];
int top=-1;

void push(int c)    //CHANGED//
{
    if(top==MAX-1)
    {
        printf("STACK OVERFLOW\n");
        return ;
    }
    top++;
    stack[top]=c;
}
int pop()   //CHANGED//
{
    int value;  //CHANGED//
    if(top==-1)
    {   
        printf("STACK UNDERFLOW\n");
        exit(1) ;
    }
    value=stack[top];
    top--;
    return value;
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

int postfix_evaluation()
{
    int a,b,i;
    for(int i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
            push(postfix[i]-'0');
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;    
            }
        }
        
    }
    return pop();
}
int main()
{   
    int result;
    printf("ENTER THE INFIX EXPRESSION:-\n");
    gets(infix);

    infix_to_postfix();

    print();
    result=postfix_evaluation();
    
    printf("THE RESULT OF THE POSTFIX EXPRESSION IS: %d",result);
    return 0;
}
