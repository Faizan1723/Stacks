#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;

int is_empty()
{
    if(top==-1)
        return 1;
    else 
        return 0;
}
void push(char data)
{
    if(top==MAX-1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    top=top+1;
    stack[top]=data;
}
char pop()
{
    char value;
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        exit(1);
    }
    value=stack[top];
    top=top-1;
    return value;
}
int match_char(char a,char b)
{
    if(a=='[' && b==']')
        return 1;
    else if(a=='{' && b=='}')
        return 1;
    else if(a=='(' && b==')')
        return 1;    
    else
        return 0;
}
int check_balance(char* s)
{
    char temp;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
        {
            push(s[i]);
        }
        if(s[i]==']' || s[i]=='}' || s[i]==')')
        {
            if(is_empty())
            {
                printf("RIGHT BRACKETS ARE MORE THAN LEFT BRACKETS\n");
                return 0;
            }
            else
            {
                temp=pop();
                if(!match_char(temp,s[i]))
                {
                    printf("MISMATCHED BRACKETS\n");
                    return 0;
                }
            }
        }
    }
    if(is_empty())
    {
        printf("BRACKETS ARE WELL BALANCED\n");
        return 1;
    }
    else
    {
        printf("LEFT BRACKETS ARE MORE THAN RIGHT BRACKETS\n");
        return 0;
    }
}
int main()
{
    int check;
    char exp[MAX];
    printf("ENTER THE ALGEBRIC EXPRESSION:-\n");
    gets(exp);
    check=check_balance(exp);
    if(check)
        printf("VALID EXPRESSION\n");
    else
        printf("INVALID EXPRESSION");
    
    return 0;
}