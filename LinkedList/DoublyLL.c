#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;


struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL;
    newnode->data=val;
    return newnode;
}

void insertatBegin(int val)
{
    struct node *newnode=createNode(val); 
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void insertEnd(int val)
{
    struct node *newnode=createNode(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void insertPosition(int pos,int val)
{
    struct node* temp=head;
    struct node *newnode=createNode(val);
    if(pos==1)
    {
        if(head!=NULL)
        {
            head->prev=newnode;
            newnode->next=head;
        }
        head=newnode;
        printf("node inserted ");
        return;
    }
    int count=1;
    for(count=1;count<pos-1 && temp!=NULL;count++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invalid position");
        free(newnode);
        return ;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    
    if(temp->next!=NULL)
    {
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    
    printf("node inserted");
}

void deleteBegin()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("nothing to delete");
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        free(temp);
        printf("node deleted");
        return;
    }
    
    head=head->next;
    head->prev=NULL;
    free(temp);
    
    printf("node deleted");
}

void deleteEnd()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("nothing to delete");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("last node deleted");
        return;
    }
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    printf("last node deleted");
}

void deletePosition(int pos)
{
    struct node* temp=head;
    if(pos==1)
    {
        head=temp->next;
        if(head!=NULL)
    {
        head->prev=NULL;
    }
    free(temp);
    printf("node deleted");
    return;
    }
    for(int i=1;i<pos && temp!=NULL;i++)
    {
        temp=temp->next;
    }
        if(temp==NULL)
        {
           printf("invalid position");
           return;
        }
        if(temp->prev!=NULL)
        {
            temp->prev->next=temp->next;
        }
        free(temp);
        printf("node deleted");
}

void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


int main()
{
    int val,pos,
    ch;
    printf("Doubly Linked List");
    printf("\n-----------------------");
    do
    {
    printf("\n1)insert at beginning\n2)insert at end\n3)insert at posiition\n4)delete begin\n5)delete end\n6)delete at positon\n7)display\n8)exit\n");
     printf("\n-----------------------");
    printf("\nenter choice:");
    
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("enter val:");
        scanf("%d",&val);
        insertatBegin(val);
        printf("value inserted");
        break;
        
        case 2:
        printf("enter val:");
        scanf("%d",&val);
        insertEnd(val);
        printf("value inserted");
        break;
        
        
        case 3:
        
        printf("enter val:");
        scanf("%d",&val);
        printf("enter position:");
        scanf("%d",&pos);
        insertEnd(val);
        printf("value inserted");
        break;
        
        
        case 4:
        deleteBegin();
        break;
        
        case 5:
        deleteEnd();
        break;
        
        case 6:
        int pos;
        printf("enter position:");
        scanf("%d",&pos);
        deletePosition(pos);
        break;
        
        case 7:
        printf("doubly linked list:");
        display();
        break;
        
        
        case 8:
        exit(0);
        break;
        
        case 9:
        default:
        printf("wrong choice");
        break;
    }
    }
    while(ch!=9);
    return 0;
}

