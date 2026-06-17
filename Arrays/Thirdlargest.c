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
         for(int i=0;i<n2;i++)
        {
            r[i]=arr[mid+1+i];
        }
        int i=0,j=0,k=left;
        while(i<n1 && j<n2)
        {
            if(l[i]>=r[j])
            {
                arr[k]=l[i];
                i++;
            }
            else{
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
}
int main()
{
    int arr[102],n;
    printf("Enter n:");
    scanf("%d",&n);
    int newarr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printarr(arr,n);
    if(n>=3)
    {
    printf("\nThird largest element is:%d",arr[2]);
    }
    else
    {
        printf("\nThird largest element is:%d",arr[n-1]);
    }
        return 0;
}