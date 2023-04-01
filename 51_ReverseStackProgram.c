#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};

void push(struct node** top1,int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    
    temp->link=*top1;
    *top1=temp;
}
int pop(struct node** top1)
{
    int val;
    struct node* temp=*top1;
    *top1=(*top1)->link;
    val=temp->data;
    free(temp);
    temp=NULL;
    return val;
}
void reverse_stack(struct node** top)
{
    struct node* top1=NULL;
    struct node* top2=NULL;

    while (*top!=NULL)
    {
        push(&top1,pop(top));
    }
    while (top1!=NULL)
    {
        push(&top2,pop(&top1));
    }
    while (top2!=NULL)
    {
        push(top,pop(&top2));
    }
}
int main()
{
    struct node* top=NULL;
    struct node* ptr;

    push(&top,1);
    push(&top,2);
    push(&top,3);
    printf("ORIGINAL STACK:-\n");
    ptr=top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    reverse_stack(&top);
    ptr=top;
    printf("\nREVERSED STACK:-\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}