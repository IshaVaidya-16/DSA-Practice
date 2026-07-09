#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void insertBegin()
{
    int val;
    printf("Enter value to insert:");
    scanf("%d",&val);
    struct node *newnode=createNode(val);
    if(head==NULL)
    {
      head=newnode;
      return;
    }
    newnode->next=head;
    head=newnode;
}

void insertPos(int val,int pos)
{
    struct node *newnode=createNode(val);
    int count=1;
    if(head==NULL && pos==)
    {
        head=newnode;
        return;
    }
    struct node *temp=head;
    while(temp!=NULL && count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

struct node *reverse()
{
    if(head==NULL)
    {
       return NULL;
    }
    struct node *curr=head;
    struct node *prev=NULL;
    struct node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

struct node *findMiddle()
{
    if(head==NULL)
    {
        return NULL;
    }
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void delBegin()
{
    if(head==NULL)
    {
        return;
    }
    struct node *copy=head;
    head=head=next;
    free(copy);
    printf("start node deleted");
}
void deleSpeci(int val)
{
    if(head==NULL)
    {
        return;
    }
    struct node *temp=head;
    struct node *prev=NULL;
    if(temp->data==val)
    {
        head=head->next;
        free(temp);
        return;
    }
    
    while(temp!=NULL && temp->data!=val)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("value not found");
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void deleteEnd()
{
    if(head==NULL)
    {
        return;
    }
    struct node *temp=head;
    struct node *copy=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
        copy=temp->next;
        free(copy)
    
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int choice, val, pos;
    struct node *mid;

    while(1)
    {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Reverse list\n");
        printf("4. Find middle element\n");
        printf("5. Display list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertBegin(NULL);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertPos(val, pos);
                break;

            case 3:
                reverse();
                printf("List reversed successfully\n");
                break;

            case 4:
                mid = findMiddle();

                if(mid != NULL)
                    printf("Middle element: %d\n", mid->data);
                else
                    printf("List is empty\n");

                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}