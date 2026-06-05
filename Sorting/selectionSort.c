#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection(int arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            
        if(arr[j]<arr[min])
        {
            min=j;
        }
    }
    swap(&arr[min],&arr[i]);
}
}

void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int i,arr[100],n;
    printf("enter n:");
    scanf("%d",&n);
    printf("enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection(arr,n);
    printf("Sorted elements:\n");
    printarr(arr,n);
    return 0;
}