#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_array[MAX];
int first=-1;
void push(int data)
{
    int i;
    first+=1;
    for(int i=first;i>0;i--)
    {
        stack_array[i]=stack_array[i-1];
    }
    stack_array[0]=data;
    
}
int pop()
{
    int i,value;
    value=stack_array[0];
    for(i=0;i<first;i++)
    {
        stack_array[i]=stack_array[i+1];
    }
    first-=1;
    return value;
}
void print()
{
    if(first==MAX-1)
        printf("STACK OVERFLOW\n");
    if(first==-1)
        printf("STACK UNDERFLOW\n");
    for (int i=0;i<=first;i++)
    {
        printf("%d ",stack_array[i]);
    }
    printf("\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    
    int value;
    value=pop();
    printf("THE DELETED ELEMENT IS %d\n",value);
    print();
    return 0;    
}