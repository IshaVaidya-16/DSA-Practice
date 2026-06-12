#include<stdio.h>
#include<stdlib.h>
void input(int arr[],int n)
{
   
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int findMax(int arr[],int n)
{
    int maxx=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxx)
        {
            maxx=arr[i];
        }
    }
    return maxx;
}

void countSort(int arr[],int n)
{
    int maxEle=findMax(arr,n);
    int newarr[maxEle+1];
    for(int i=0;i<=maxEle;i++)
    {
        newarr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        newarr[arr[i]]++;
    }
    int k=0;
    for(int i=0;i<=maxEle;i++)
    {
        while(newarr[i]>0)
        {
            arr[k++]=i;
            newarr[i]--;
        }
    }
}

int main()
{
    int n;
     printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    input(arr, n);

    countSort(arr, n);

    printf("Sorted array:\n");
    printarr(arr, n);

    return 0;
} 