#include <stdio.h>

int max_Subarray_sum (int n, int a[], int start, int end);
int cross_Sum (int n, int a[], int start, int mid, int end);


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
    int maxSum = max_Subarray_sum(n, a, 0, n - 1);
    printf("%d is the max subarray sum.", maxSum);
}

int max_Subarray_sum (int n, int a[], int start, int end)
{
    if (start == end)
    {
        return a[start];
    }
    int mid = start + ((end - start) / 2);
    int L = max_Subarray_sum(n, a, start, mid);
    int R = max_Subarray_sum(n, a, mid + 1, end);
    int C = cross_Sum(n, a, start, mid, end);
    return (L > R) ? ((C > L) ? C : L) : ((C > R) ? C : R);
}

int cross_Sum (int n, int a[], int start, int mid, int end)
{
    int ls, rs;
    ls = a[mid];
    rs = a[mid + 1];
    int maxLs, maxRs;
    maxLs = a[mid];
    maxRs = a[mid + 1];
    for (int i = mid - 1; i >= start; i--)
    {
        ls += a[i];
        if (ls > maxLs)
        {
            maxLs = ls;
        }
    }
    for (int i = mid + 2; i <= end; i++)
    {
        rs += a[i];
        if (rs > maxRs)
        {
            maxRs = rs;
        }
    }
    return (maxRs + maxLs);
}