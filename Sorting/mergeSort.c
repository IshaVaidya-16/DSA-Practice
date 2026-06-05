#include<stdio.h>

void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    
    for(int i=0;i<n1;i++)
    {
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        
            arr[k]=l[i];
            i++;
            k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
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
    mergeSort(arr,0,n-1);
    printf("Sorted elements:\n");
    printarr(arr,n);
    return 0;
}