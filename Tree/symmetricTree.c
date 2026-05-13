#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *left,*right;
};

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
    printf("\nenter val (-1 if no node):");
    scanf("%d",&val);
    if(val==-1)
    {
        return NULL;
    }
    struct node *newnode=createNode(val);
    printf("\nenter left child of %d: ",val);
    newnode->left=createTree();
    printf("\nenter right child of %d: ",val);
    newnode->right=createTree();
    return newnode;

}
bool isMirror(struct node *left,struct node *right)
{
    if(left==NULL && right==NULL)
    {
        return true;
    }
    if(left==NULL || right==NULL)
    {
        return false;
    }
    
    return (left->val==right->val && isMirror(left->left,right->right) && isMirror(left->right,right->left));
}

bool isSymmetricTree(struct node *root)
{
 if(root==NULL)
 {
     return true;
 }
 return isMirror(root->left,root->right);
}

int main()
{
    printf("enter the tree:");
    printf("\n----------------------\n");
    struct node *p=createTree();
    
    bool ans=isSymmetricTree(p);
    if(ans==true)
    {
        printf("\n----------------------\n");
        printf("Tree is symmetric");
        
    }
    else
    {
        printf("\n----------------------\n");
        printf("Tree is NOT symmetric");
    }
    return 0;
}

