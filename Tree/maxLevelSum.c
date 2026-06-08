#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *right,*left;
};

struct node *queue[10000];

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->val=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *createTree()
{
    int val;
    printf("enter value (-1 if no node):");
    scanf("%d",&val);
    if(val==-1)
    {
        return NULL;
    }
    struct node *newnode=createNode(val);
    printf("enter left child of %d:\n",val);
    newnode->left=createTree();
    printf("enter right child of %d:\n",val);
    newnode->right=createTree();
    return newnode;
}
int returnMax(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int front=0,rear=0;
    queue[rear++]=root;
    int maxSum=root->val;
    int level=1;
    int bestLevel=1;
    while(front<rear)
    {
        int size=rear-front;
        int sum=0;
        for(int i=0;i<size;i++)
        {
            struct node *newnode=queue[front++];
            sum+=newnode->val;
            if(newnode->left!=NULL)
            {
                queue[rear++]=newnode->left;
            }
            if(newnode->right!=NULL)
            {
                queue[rear++]=newnode->right;
            }
        }
        if(sum>maxSum)
        {
            maxSum=sum;
            bestLevel=level;
        }
        level++;
    }
    return bestLevel;
}
int main()
{
    struct node *root=createTree();
    int maxLevel=returnMax(root);
    printf("level with maximum sum is %d",maxLevel);
    return 0;
}