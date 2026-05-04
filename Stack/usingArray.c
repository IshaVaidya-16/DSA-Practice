#include<stdio.h>
#define max 100
int arr[max];
int top=-1;
void push(int n)
{
    if(top==max-1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        arr[top]=n;
        printf("element added");
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    top--;
    printf("element popped");
}

void display()
{
    if(top==-1)
    {
        printf("Stack underflow. Nothing to print");
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n;
    int choice;
    do{
    printf("\n1)push\n2)pop\n3)display\n");
    
    printf("enter choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    printf("enter number:");
    scanf("%d",&n);
    push(n);
        break;
    
        case 2:
        pop();

        case 3:
        printf("elements in stack are:");
        display();
        break;

    default:
    printf("wrong choice");
    break;

    }
}while(choice!=4);

return 0;
}


