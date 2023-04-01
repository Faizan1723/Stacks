#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* top=NULL;
struct node* push(int data)
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=top;
    top=temp;
}
int pop()
{
    struct node* temp=top;
    top=top->link;
    int value=temp->data;
    free(temp);
    temp=NULL;
    return value;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    int val;
    val=pop();
    printf("THE DELETED ELEMENT IS %d\n",val);
    struct node* ptr=top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}