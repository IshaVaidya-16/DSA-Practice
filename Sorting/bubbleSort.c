#include<stdio.h>

void bubble(int arr[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Elements sorted\n");
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
    int arr[100],n;
    printf("enter n:");
    scanf("%d",&n);
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble(arr,n);
    printf("Sorted elements are: ");
    printarr(arr,n);
    return 0;
}
