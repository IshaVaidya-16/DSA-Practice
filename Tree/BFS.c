#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *left,*right;
};

struct node *createNode(int val){
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
struct node *queue[10000];

void BFS(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        int levelSize=rear-front;
        for(int i=0;i<levelSize;i++)
        {
            struct node *newnode=queue[front++];
            printf("%d ",newnode->val);
            if(newnode->left!=NULL)
            {
                queue[rear++]=newnode->left;
            }
            if(newnode->right!=NULL)
            {
                queue[rear++]=newnode->right;
            }
        }
    }
}

int main()
{
    struct node *root=createTree();
    printf("BFS traversal : \n");
    BFS(root);
    return 0;
}