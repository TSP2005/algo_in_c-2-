#include <stdio.h>

int min(int n, int a[], int start, int end)
{
    if (start == end)
    {
        return a[start];
    }
    else
    {
        int mid = start + ((end - start) / 2);
        int m1 = min(n, a, start, mid);
        int m2 = min(n, a, mid + 1, end);
        return (m1 < m2) ? m1 : m2;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
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
    int minimum = min(n, a, 0, n - 1);
    printf("%d is the minimum element in the array.", minimum);
}