#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

void insertAtEnd(int val)
{
    struct node *newnode = createNode(val);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


struct node *getMiddle(struct node *head)
{
    if (head == NULL)
        return head;

    struct node *slow = head;
    struct node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct node *merge(struct node *left, struct node *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    struct node *result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

struct node *mergeSort(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct node *middle = getMiddle(head);

    struct node *nextToMiddle = middle->next;

    middle->next = NULL;

    struct node *left = mergeSort(head);

    struct node *right = mergeSort(nextToMiddle);

    struct node *sortedList = merge(left, right);

    return sortedList;
}


int main()
{
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertAtEnd(val);
    }

    printf("\nOriginal List:\n");
    display(head);

    head = mergeSort(head);

    printf("\nSorted List:\n");
    display(head);

    return 0;
}