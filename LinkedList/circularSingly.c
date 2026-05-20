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
    struct  node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void insertAtBegin(int val)
{
    struct node *newnode=createNode(val);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        return;
    }
    struct node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    head=newnode;
}

void insertAtEnd(int val)
{
    struct node *newnode=createNode(val);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        return;
    }
    struct node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    struct node *last = head;

    // Only one node
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Node deleted\n");
        return;
    }
    while (last->next != head)
    {
        last = last->next;
    }
    head = head->next;

    last->next = head;

    free(temp);

    printf("Node deleted\n");

}
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

   while(temp->next!=head)
   {
       printf("%d ->",temp->data);
       temp=temp->next;
   }
    printf("%d -> ", temp->data);
   printf("HEAD");
}
int main()
{
    int choice, val;

    while (1)
    {
        printf("\nCIRCULAR LINKED LIST MENU\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtBegin(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;

            case 3:
                deleteBegin();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}