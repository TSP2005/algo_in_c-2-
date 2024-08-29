#include <stdio.h>
#include <limits.h>

int min(int n, int a[], int start, int end, int * maximum)
{
    if (start == end)
    {
        return a[start];
    }
    else
    {
        int mid = start + ((end - start) / 2);
        int m1 = min(n, a, start, mid, maximum);
        int m2 = min(n, a, mid + 1, end, maximum);
        if (m1 < m2)
        {
            if (* maximum < m2)
            * maximum = m2;
            return m1;
        }
        else
        {
            if (* maximum < m1)
            * maximum = m1;
            return m2;
        }
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
    int maximum = INT_MIN;
    int minimum = min(n, a, 0, n - 1, &maximum);
    printf("%d is the minimum element in the array.\n", minimum);
    printf("%d is the maximum element in the array.\n", maximum);
}