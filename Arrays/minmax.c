#include<stdio.h>
#include<stdlib.h>

void minmax(int arr[],int n)
{
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("min : %d ",min);
    printf("\nmax : %d ",max);
}
int main()
{
    int n,arr[100],i;
    printf("enter n:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    minmax(arr,n);
    return 0;
}