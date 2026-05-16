#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *insertBegin(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    return head;
}

struct node *insertEnd(int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct node *insertIndex(int indexVal, int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(indexVal == 1)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    struct node *temp = head;
    int i = 1;

    while(i < indexVal - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

void search(int item)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == item)
        {
            printf("Item found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Item not found\n");
}

struct node *reverse()
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void display()
{
    struct node *temp = head;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int val, ch, pos;

    do
    {
        printf("\n1) Insert beginning");
        printf("\n2) Insert end");
        printf("\n3) Insert position");
        printf("\n4) Search");
        printf("\n5) Reverse");
        printf("\n6) Display");
        printf("\n7) Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBegin(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertIndex(pos, val);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                search(val);
                break;

            case 5:
                reverse();
                printf("List reversed\n");
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Wrong choice\n");
        }

    } while(ch != 7);
    return 0;
}