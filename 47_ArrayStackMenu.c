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
    printf("THE ELEMENTS OF THE STACK ARE:\n");
    for(int i=top;i>=0;i--)
    {
        
        printf("%d ",stack_arr[i]);
        printf("\n");
    }
}
int main()
{
    int data,choice;
    while(1)
    {
        printf("\n1.PUSH\n2.POP\n3.PRINT THE ELEMENTS OF THE STACK\n4.QUIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);
    
        switch (choice)
        {
        case 1:
            printf("ENTER THE ELEMENT TO BE PUSHED: ");
            scanf("%d",&data);
            printf("\n");
            push(data);
            break;
        case 2:
            data=pop();
            printf("THE ELEMENT DELETED IS %d\n",data);
            break;
        case 3:
            print();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}