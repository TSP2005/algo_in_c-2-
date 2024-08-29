#include <stdio.h>

void merge(int n, int a[], int start, int mid, int end, int * count)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int b[n];
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
            (* count) += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        b[k] = a[j];
        k++;
        j++;
    }
}

void inv(int n, int a[], int start, int end, int * count)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);
        inv(n, a, start, mid, count);
        inv(n, a, mid + 1, end, count);
        merge(n, a, start, mid, end, count);
    }
}

int main()
{
    int n;
    printf("Enter the sizes of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    int a[n];
    printf("Array 1: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int count = 0;
    inv(n, a, 0, n - 1, &count);
    printf("The number of inversions are %d", count);
}