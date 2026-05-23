#include<stdio.h>
#include<stdlib.h>
#define max 100
struct node {
    int data;
    struct node *left,*right;
};

struct queue
{
    struct node *arr[max];
    int front,rear;
};

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void initQ(struct queue *q)
{
    q->front=-1;
    q->rear=-1;
}

int isEmpty(struct queue *q)
{
    return q->front==-1;
}

void enqueue(struct queue *q,struct node *newnode)
{
    if(q->rear==max-1)
    {
        printf("queue overflow");
        return;
    }
    if(q->front==-1)
    {
        q->front=0;
    }
    q->arr[++q->rear]=newnode;
}

struct node *dequeue(struct queue *q)
{
    if(isEmpty(q))
    {
        return NULL;
    }
    struct node *temp=q->arr[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else{
    q->front++;
    }
    return temp;
}

struct node *buildTree()
{
    int val;
    printf("enter val (-1 for null):");
    scanf("%d",&val);
    if(val==-1)
    {
        return NULL;
    }
    struct node *newnode=createNode(val);
    newnode->data=val;
    printf("enter left child of %d",newnode->data);
    newnode->left=buildTree();
    printf("enter right child of %d",newnode->data);
    newnode->right=buildTree();
    return newnode;
}

void levelOrder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    struct queue q;
    initQ(&q);
    enqueue(&q,newnode);
    printf("level order traversal:");
    while(!isEmpty(&q))
    {
        struct node *curr=dequeue(&q);
        printf("%d ",curr->data);
        if(curr->left)
        {
            enqueue(&q,curr->left);
        }
        if(curr->right)
        {
            enqueue(&q,curr->right);
        }
    }
}

int main()
{
    struct node *root=buildTree();
    levelOrder(root);
    return 0;
}
