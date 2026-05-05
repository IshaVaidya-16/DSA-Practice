#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertatBegin(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void display()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int val, n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter nodes:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertatBegin(val);
    }

    display();

    printf("\nEnter value to insert at beginning: ");
    scanf("%d", &val);

    insertatBegin(val);

    printf("Value inserted\n");
    display();

    return 0;
}