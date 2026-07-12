#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    printf("\nelement pushed");
}

void pop()
{
    if(top==NULL)
    {
        printf("stack underflow");
        return;
    }
    struct node *temp=top;
    printf("\nelement popped: %d",top->data);
    top=top->next;
    free(temp);
}

void peek()
{
    if(top==NULL)
    {
        return;
    }
    else{
    printf("Peek: %d",top->data);
}
}

void display()
{
    struct node *temp=top;
    if(temp==NULL)
    {
        printf("empty");
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch,val;
    while(1)
    {
        printf("\n1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
        printf("enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter val:");
            scanf("%d",&val);
            push(val);
            break;
            
            case 2:
            pop();
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
            printf("invalid choice!!");
        }
        
    }
    return 0;
}