#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int insertatBegin(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void display(struct node *temp)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int val;

    printf("Insert at beginning \n enter value to insert at beginning:");
    scanf("%d",&val);
    insertatBegin(val);
    printf("value inserted\n");
    display(head);
    return 0;
}