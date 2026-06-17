#include<stdio.h>
void bucketSort(int arr[],int n){
    int bucket[101]={0};
    for(int i=0;i<n;i++)
    {
        bucket[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<=100;i++)
    {
        while(bucket[i]>0)
        {
            arr[index++]=i;
            bucket[i]--;
        }
    }
}
void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[102],n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bucketSort(arr,n);
    printarr(arr,n);
    return 0;
}