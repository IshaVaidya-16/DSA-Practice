#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    int first;
    struct node **next;
};

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->first=0;
    newnode->next=NULL;
    return newnode;
}

void preorder(struct node *newnode)
{
    if(newnode==NULL)
    {
        return;
    }
    printf("%d ",newnode->data);
    for(int i=0;i<newnode->first;i++)
    {
        preorder(newnode->next[i]);
    }
}

int main()
{
    int n;
    printf("enter n:");
    scanf("%d",&n); 
    struct node *newnode[n+1];

    for(int i=1;i<=n;i++)
    {
        int val;
        printf("enter value of node %d:",i);
        scanf("%d",&val);
        newnode[i]=createNode(val);
    }

    for(int i=1;i<=n;i++)
    {
        int childcount;
        printf("enter number of children of node %d:",newnode[i]->data);
        scanf("%d",&childcount);

        newnode[i]->first= childcount;
        newnode[i]->next=malloc(childcount*sizeof(struct node *));
        for(int j=0;j<childcount;j++)
    {
        int childIndex;
        printf("enter child index:");
        scanf("%d",&childIndex);
        newnode[i]->next[j]=newnode[childIndex];
    }
    }
    printf("preorder traversal:");
    preorder(newnode[1]);
    return 0;

}