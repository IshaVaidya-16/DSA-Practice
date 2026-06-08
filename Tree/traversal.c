#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int item;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->item=val;
    return newnode;
}

void inorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    inorder(newnode->left);
    printf("%d ",newnode->item);
    inorder(newnode->right);
    
}

void preorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return ;
    }
    printf("%d ",newnode->item);
    preorder(newnode->left);
    preorder(newnode->right);
}

void postorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    postorder(newnode->left);
    postorder(newnode->right);
    printf("%d ",newnode->item);
}

struct node* insertLeft(struct node *new,int val)
{
    new->left=createNode(val);
    return new->left;
}

struct node* insertRight(struct node *new,int val)
{
    new->right=createNode(val);
    return new->right;
}
struct node *createTree()
{
    int val;
    printf("enter value (-1 for no node) :");
    scanf("%d",&val);
    
    if(val==-1)
    {
        return NULL;
    }
    struct node *newnode=createNode(val);
    printf("\nenter left child: %d",val);
    newnode->left=createTree();
    
    printf("\nenter right child: %d",val);
    newnode->right=createTree();
    
    return newnode;
}
int main()
{
    int choice;
    struct node *root=createTree();
    do
    {
        printf("\n1)inorder\n2)preorder\n3)postorder\n4)exit\n");
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("inorder series: ");
            inorder(root);
            break;
            
            case 2:
            printf("preorder series: ");
            preorder(root);
            break;
            
            case 3:
            printf("postorder series: ");
            postorder(root);
            break;
            
            case 4:
            default:
            printf("wrong choice!");
            break;
            
        }
    }
    while(choice!=5);
    return 0;
}