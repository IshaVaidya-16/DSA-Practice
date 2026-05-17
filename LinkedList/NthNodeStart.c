#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBegin(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

int nNode(int n)
{
    int count = 1;
    struct node *temp = head;

    while (temp != NULL)
    {
        if (count == n)
        {
            return temp->data;
        }

        count++;
        temp = temp->next;
    }

    return -1;
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
    int ch, val;

    do
    {
        printf("\n1) Insert\n2) Nth Node\n3) Display\n4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBegin(val);
                break;

            case 2:
            {
                int n;
                printf("Enter n: ");
                scanf("%d", &n);

                int res = nNode(n);

                if (res != -1)
                    printf("%dth node is: %d\n", n, res);
                else
                    printf("Node not found\n");

                break;
            }

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Wrong choice\n");
        }

    } while (ch != 4);

    return 0;
}