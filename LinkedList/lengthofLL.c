#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
void insert(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void display()
{
    struct node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        count=count+1;
        temp=temp->next;
    }
    printf("NULL");
    printf("\nnumber of nodes: %d",count);
}

int main()
{
    int n,val;
    printf("enter n :");
    scanf("%d",&n);
    printf("enter n nodes:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        insert(val);
    }

    printf("enter element to insert:");
    scanf("%d",&val);
    insert(val);
    display();
    return 0;
}

