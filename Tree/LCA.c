#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
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
    printf("\nenter left child of %d",val);
    newnode->left=createTree();
    printf("\nenter right child of %d",val);
    newnode->right=createTree();
    return newnode;
}

struct node *findNode(struct node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==key)
    {
        return root;
    }
    struct node *left=findNode(root->left,key);
    struct node *right=findNode(root->right,key);
    if(left!=NULL)
    {
        return left;
    }
    else{
        return right;
    }
}

struct node *LCA(struct node *root,struct node *p,struct node *q)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root==p|| root==q)
    {
        return root;
    }
    struct node *leftLCA=LCA(root->left,p,q);
    struct node *rightLCA=LCA(root->right,p,q);
    if(leftLCA && rightLCA)
    {
        return root;
    }
    if(leftLCA!=NULL)
    {
        return leftLCA;
    }
    else{
        return rightLCA;
    }
}

int main()
{
    struct node *root=createTree();
    int p,q;
    printf("Enter node p:");
    scanf("%d",&p);
    printf("Enter node q:");
    scanf("%d",&q);
    struct node *x=findNode(root,p);
    struct node *y=findNode(root,q);
    if(x == NULL || y == NULL)
    {
        printf("One or both nodes not found\n");
    }
    else
    {
    struct node *answer = LCA(root,x,y);

    if(answer != NULL)
    {
        printf("LCA is %d\n",answer->val);
    }
}
return 0;
}