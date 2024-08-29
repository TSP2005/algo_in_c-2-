#include <stdio.h>
#include <limits.h>

int min(int n, int a[], int start, int end, int * min_2)
{
    if (start == end)
    {
        return a[start];
    }
    else
    {
        int mid = start + ((end - start) / 2);
        int m1 = min(n, a, start, mid, min_2);
        int m2 = min(n, a, mid + 1, end, min_2);
        if (m1 < m2)
        {
            if (* min_2 > m2 && * min_2 > m1)
            * min_2 = m2;
            return m1;
        }
        else
        {
            if (* min_2 > m1 && * min_2 > m2)
            * min_2 = m1;
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
    int min_2 = INT_MAX;
    int minimum = min(n, a, 0, n - 1, &min_2);
    printf("%d is the minimum element in the array.\n", minimum);
    printf("%d is the second minimum element in the array.\n", min_2);
}