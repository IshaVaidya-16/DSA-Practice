#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *createTree()
{
    int val;
    printf("enter val (-1  if no node):");
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

bool isBST(struct node *root,long min,long max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root ->data < min|| root-> data >max)
    {
        return false;
    }
    return isBST(root->left,min, root->data-1) && isBST(root->right,root->data+1,max);
}

int main()
{
    struct node *root=createTree();
    if(isBST(root,INT_MIN,INT_MAX))
    {
        printf("The tree is a binary search tree.\n");
    }
    else
    {
        printf("The tree is not a binary search tree.\n");
    }
    return 0;
}