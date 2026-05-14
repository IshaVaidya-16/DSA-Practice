#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int val)
{
    struct node  *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *createTree()
{
    int val;
    printf("enter value (-1 for no child):");
    scanf("%d",&val);
    if(val==-1)
    {
        return NULL;
    }
    struct node *newnode=createNode(val);
    printf("enter left child of %d: ",val);
    newnode->left=createTree();
    printf("enter right child of %d: ",val);
    newnode->right=createTree();
    return newnode;
}


bool hasPathSum(struct node *newnode,int targetSum)
{
    if(newnode==NULL)
    {
        return true;
    }
    if(newnode->left && newnode->right==NULL)
    {
        if(newnode->data==targetSum)
        {
           return true;      
         }
        else
        {
           return false;
        }
    }
    int remainingSum=targetSum-newnode->data;
    return hasPathSum(newnode->left,remainingSum)|| hasPathSum(newnode->right,remainingSum);
}

int main()
{
    struct node *root=createTree();
    int targetSum;
    printf("enter target sum:");
    scanf("%d",&targetSum);
    if(hasPathSum(root,targetSum))
    {
        printf("there is a path with the given sum");
    }
    else
    {
        printf("there is NO path with the given sum");
    }
return 0;
}