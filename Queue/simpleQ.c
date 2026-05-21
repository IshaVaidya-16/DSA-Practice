#include<stdio.h>
#include<stdlib.h>

#define size 100
int queue[size];
int rear=-1;
int front=-1;
void insert(int val)
{
    if(rear==size-1)
    {
        printf("queue overflow");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
        rear++;
        queue[rear]=val;
        printf("element inserted");
}

void dequeue()
{
    if(front==-1|| front>rear)
    {
        printf("queue empty to delete");
        return;
    }
    printf("%d removed",queue[front]);
    front++;
    if(front>rear)
    {
        front=rear-1;
    }
}

void display()
{
    if(front==-1)
    {
        printf("queue empty to delete");
        return;
    }
    
    printf("queue:\n");
    
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}

int main()
{
    int val;
      int ch;
    do{
    printf("1)insert\n2)delete\n3)display\n4)exit\n");
  
    printf("enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("enter val:");
        scanf("%d",&val);
        insert(val);
        break;
        
        case 2:
        dequeue();
        break;
        
        case 3:
        display();
        break;
        case 4:
        exit(0);
        
        default:
        printf("wrong val");
    }
    
}while(ch!=4);
return 0;
    
}