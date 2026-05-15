#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int val) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val, ch;

    do {
        printf("\n1) insert\n2) display\n3) exit\n");
        printf("enter choice: ");
        scanf("%d", &ch);

        switch(ch) {

            case 1:
                printf("enter n: ");
                scanf("%d", &n);

                for(int i = 0; i < n; i++) {
                    printf("enter val: ");
                    scanf("%d", &val);
                    insert(val);
                }
                printf("values inserted successfully\n");
                break;

            case 2:
                display();
                break;

            case 3:
                exit(0);

            default:
                printf("invalid choice\n");
        }

    } while(1);

    return 0;
}