#include<stdio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node *left;
    struct node *right;
};

struct node *createNode(int item)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->item=item;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *createTree()
{
    int val;
    printf("Enter value (-1 for no node):");
    scanf("%d",&val);
    if(val==-1)
    {
        return NULL;
    }
    struct node *newnode=createNode(val);
    printf("enter left child of %d",val);
    newnode->left=createTree();
    printf("enter right child of %d",val);
    newnode->right=createTree();
    return newnode;
}
int isFullBinary(struct node *newnode)
{
    if(newnode==NULL)
    {
        return 1;
    }
    if(newnode->left==NULL && newnode->right==NULL)
    {
        return 1;
    }
    if(newnode->left!=NULL && newnode->right!=NULL)
    {
        return isFullBinary(newnode->left) && isFullBinary(newnode->right);
    }
    return 0;
}

void inorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return ;
    }
    inorder(newnode->left);
    printf("%d ",newnode->item);
    inorder(newnode->right);
}

int main()
{
    printf("build tree:\n");
    struct node *newnode=createTree();
    printf("inorder traversal:\n");
    inorder(newnode);
    if(isFullBinary(newnode))
    {
        printf("The tree is a full binary tree.\n");
    }
    else
    {
        printf("The tree is not a full binary tree.\n");
    }
    return 0;
}