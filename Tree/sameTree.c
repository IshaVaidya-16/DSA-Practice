#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
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

bool isSameTree(struct node *p,struct node *q)
{
    if(p==NULL && q==NULL)
    {
        return true;
    }
    if(p==NULL || q==NULL)
    {
        return false;
    }
    
    if(p->data!=q->data)
    {
        return false;
    }
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

int main()
{
    printf("enter the first tree:");
    printf("\n----------------------\n");
    struct node *p=createTree();
    printf("\nenter the second tree:");
    printf("\n----------------------\n");
    struct node *q=createTree();
    
    bool ans=isSameTree(p,q);
    if(ans==true)
    {
        printf("\n----------------------\n");
        printf("Both trees are same!!");
        
    }
    else
    {
        printf("\n----------------------\n");
        printf("Both trees are NOT same.");
    }
    return 0;
}

