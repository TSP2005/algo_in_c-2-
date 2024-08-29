#include <stdio.h>

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
        int maximum = (p1 > p2) ? p1 : p2;
        ++ *count;
        return maximum;
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
    printf("%d is the maximum element.\nThe number of comparisions are %d.", maximum, count);
}