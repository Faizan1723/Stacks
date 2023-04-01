#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int top=-1;
int stack_arr[MAX];
 
void push(int data)
{
    if(top==MAX-1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}
int pop()
{
    int value;
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}
void print()
{
    if(top==-1)
    {
        printf("STACK UNDERFLOW");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d ",stack_arr[i]);
        printf("\n");
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    
    int data;
    data=pop();
    print();
    return 0;
}