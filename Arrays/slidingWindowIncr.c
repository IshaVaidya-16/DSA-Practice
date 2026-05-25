#include <stdio.h>

int countIncreasingSubarrays(int arr[], int n)
{
    int len = 1, count = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[i - 1])
        {
            len++;
        }
        else
        {
            count += len * (len - 1) / 2;
            len = 1;
        }
    }

    count += len * (len - 1) / 2;

    return count;
}

int main()
{
    int n, arr[100];

    printf("enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int result = countIncreasingSubarrays(arr, n);
    printf("\nCount = %d\n", result);

    return 0;
}