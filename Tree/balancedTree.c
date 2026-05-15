#include<stdio.h>
#include<stdlib.h>

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

int height(struct node *newnode)
{
    if(newnode==NULL)
    {
        return 0;
    }
    int leftHeight=height(newnode->left);
    int rightHeight=height(newnode->right);

if(leftHeight>rightHeight)
{
    return leftHeight + 1;
}
else{
    return 1+ rightHeight;
}
}

int isBalanced(struct node *newnode)
{
    if(newnode==NULL)
    {
        return 1;
    }
    int leftHeight=height(newnode->left);
    int rightHeight=height(newnode->right);
    int difference=leftHeight-rightHeight;
    if (difference<-1 || difference>1)
    {
        return 0;
    }
    return isBalanced(newnode->left) && isBalanced(newnode->right);
}

void inorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    inorder(newnode->left);
    printf("%d ",newnode->data);
    inorder(newnode->right);
}

int main()
{
    struct node *newnode=createTree();
    printf("inorder traversal: ");
    inorder(newnode);
    printf("\n");
    if(isBalanced(newnode))
    {
        printf("the tree is balanced\n");
    }
    else
    {
        printf("the tree is not balanced\n");
    }
    return 0;
}
