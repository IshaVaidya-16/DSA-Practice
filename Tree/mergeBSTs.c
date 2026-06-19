#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *createnode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int val)
{
    if(root==NULL)
    {
        return createnode(val);
    }
    if(root->data>val)
    {
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct node *createBST()
{
    int val;
    struct node *root=NULL;
    while(1)
    {
    printf("enter val(-1 if no node):");
    scanf("%d",&val);
    if(val==-1)
    {
       break;
    }
    root=insert(root,val);
    }
    return root;
}

void inorderInsert(struct node *root,struct node **merged)
{
    if(root==NULL)
    {
        return;
    }
    inorderInsert(root->left,merged);
    *merged=insert(*merged,root->data);
    inorderInsert(root->right,merged);
}

struct node *merge(struct node *newnode1,struct node *newnode2)
{
    struct node *merged=newnode2;
    inorderInsert(newnode1,&merged);
    return merged;
}

int main()
{
    printf("enter first tree:\n");
    struct node *newnode1=createBST();
    printf("enter second tree:\n");
    struct node *newnode2=createBST();
    printf("first tree\n");
    inorder(newnode1);
    printf("\nsecond tree\n");
    inorder(newnode2);
    struct node *root=merge(newnode1,newnode2);
    printf("\nmerged tree is :\n");
    inorder(root);
    printf("\nBST created");
    return 0;
}