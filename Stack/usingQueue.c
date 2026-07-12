#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void insert(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("node inserted");
}

void dequeue()
{
    if(front==NULL)
    {
        printf("queue empty");
        return;
    }
    struct node *temp=front;
    printf("deleted element: %d\n",front->data);
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);
}

void peek()
{
    if(front==NULL)
    {
        printf("queue empty");
        return;
    }
    printf("peek :%d \n",front->data);
}
void display()
{
    if(front==NULL)
    {
        printf("queue empty");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


int main()
{
    int ch, value;

    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
}