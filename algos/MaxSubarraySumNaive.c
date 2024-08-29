#include <stdio.h>

int maxSubarraySum(int n, int a[])
{
    int curMax = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += a[j];
            curMax = (s > curMax) ? s : curMax;
        }
    }
    return curMax;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int maxSum = maxSubarraySum(n, a);
    printf("%d is the maximum subarray sum.", maxSum);
}