#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


struct node
{
    int val;
    struct node *left,*right;
};

struct node *prev=NULL;
int Mindiff=INT_MAX;
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

void inorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    
    inorder(newnode->left);
    if(prev!=NULL)
    {
        int diff=newnode->val-prev->val;
        if(Mindiff>diff)
        {
            Mindiff=diff;
        }
    }
    prev=newnode;
    inorder(newnode->right);
}
int getMinDiff(struct node *newnode)
{
    Mindiff=INT_MAX;
    prev=NULL;
    inorder(newnode);
    return Mindiff;
}
int main()
{
    printf("enter the tree:");
    printf("\n----------------------\n");
    struct node *p=createTree();
    int differ=getMinDiff(p);
    printf("The minimum difference is : %d",differ);
    return 0;
}

