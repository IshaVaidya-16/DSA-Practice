#include<stdio.h>
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
void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-1+1;
    int n2=right-mid;
    int l[n1],r[n2];

    for(int i=0;i<n1;i++)
    {
        l[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++)
    {
        r[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k++]=l[i++];
        }
        else{
            arr[k++]=r[j++];
        }
    }

    while(i<n1)
    {
        arr[k++]=l[i++];
    }
    while(j<n2)
    {
        arr[k++]=r[j++];
    } 
}

void mergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

struct node *sortedtoBST(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    struct node *root=createNode(arr[mid]);
    root->left=sortedtoBST(arr,start,mid-1);
    root->right=sortedtoBST(arr,mid+1,end);
    return root;
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}


int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    struct node *root=sortedtoBST(arr,0,n-1);
    printf("inorder traversal of BST:");
    inorder(root);
    printf("Arranged in BST");
    return 0;
}