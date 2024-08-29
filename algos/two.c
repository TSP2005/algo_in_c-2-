#include <stdio.h>
#include <limits.h>

int minimum = INT_MAX;

void min(int value)
{
    if (value < minimum)
    {
        minimum = value;
    }
}

int max(int n, int a[], int start, int end, int * count)
{
    if (start == end)
    {
        return a[start];
    }
    else
    {
        int mid = start + ((end - start) / 2);
        int p1 = max(n, a, start, mid, count);
        int p2 = max(n, a, mid + 1, end, count);
        if (p1 > p2)
        {
            min(p2);
            ++ *count;
            return p1;
        }
        else
        {
            min(p1);
            ++ *count;
            return p2;
        }
    }
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
    int count = 0;
    int maximum = max(n, a, 0, n - 1, &count);
    printf("%d is the maximum element.\n%d is the minimum element.\nThe number of comparisions are %d.", maximum, minimum, count);
}