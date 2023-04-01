#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack_arr[MAX];
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
void prime_fact(int num)
{
    int i=2;
    while(num!=1)
    {
        while (num%i==0)
        {
            push(i);
            num=num/i;
        }
        i++;
    }

    printf("THE PRIME FACTORS OF NO. %d ARE:\n",num);
    while (top!=-1)
    {
        printf("%d\n",pop());
    }  
}
int main()
{
    int n;
    printf("ENTER THE NO. WHOSE PRIME FACTORS ARE NEEDED: ");
    scanf("%d",&n);
    prime_fact(n);
}