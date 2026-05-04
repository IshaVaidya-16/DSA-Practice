#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int *arr;
    int top, capacity;
};

void stackInit(struct stack *s, int capacity)
{
    s->capacity = capacity;
    s->top = -1;
    s->arr = malloc(s->capacity * sizeof(int));
}

void resize(struct stack *s)
{
    s->capacity *= 2;
    s->arr = realloc(s->arr, s->capacity * sizeof(int));
    printf("stack resized to capacity %d\n", s->capacity);
}

void push(struct stack *s, int value)
{
    if(s->top == s->capacity - 1)
    {
        resize(s);
    }
    s->arr[++s->top] = value;
    printf("%d pushed to stack\n", value);
}

void pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("%d popped\n", s->arr[s->top--]); 
}

void peek(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", s->arr[s->top]);
}

void display(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void freeStack(struct stack *s)
{
    free(s->arr);
}

int main()
{
    struct stack s; 
    int choice, val;

    stackInit(&s, 2);

    while(1)
    {
        printf("\n1) push\n2) pop\n3) peek\n4) display\n5) exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(&s, val);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                peek(&s);
                break;

            case 4:
                display(&s);
                break;

            case 5:
                freeStack(&s);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}