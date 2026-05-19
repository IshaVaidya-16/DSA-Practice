#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    int first;
    struct node **children;
};

struct node *createNode(int val,int first)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->first=first;
    if(first>0)
    {
        newnode->children=malloc(first*sizeof(struct node));
    }
    else{
newnode->children=NULL;
    }
    return newnode;
}

struct node *buildTree()
{
    int val,first;
    printf("enter node value:");
    scanf("%d",&val);
    printf("enter number of children:");
    scanf("%d",&first);
    struct node *newnode=createNode(val,first);
    for(int i=0;i<first;i++)
    {
        newnode->children[i]=buildTree();
    }
    return newnode;
}

int maxDepth(struct node *newnode)
{
    if(newnode==NULL)
    {
        return 0;
    }
    int maxDepthh=0;
    for(int i=0;i<newnode->first;i++)
    {
        int currDepth=maxDepth(newnode->children[i]);
        if(currDepth>maxDepthh)
        {
            maxDepthh=currDepth;
        }
    }
return maxDepthh+1;
}

int main()
{
    struct node *newnode=buildTree();
    int depth=maxDepth(newnode);
    printf("maximum depth of the tree is:%d\n",depth);
    return 0;
}