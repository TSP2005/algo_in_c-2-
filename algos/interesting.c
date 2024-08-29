#include <stdio.h>

int interesting_pairs(int n, int m, int a[], int b[])
{
    int count = 0;
    int t = m + n;
    int c[t];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        if (a[i] > b[j])
        {
            c[k] = b[j];
            j++;
            k++;
            count += (n - i);
        }
    }
    if (i == n)
    {
        while (j < m)
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    if (j == m)
    {
        while (i < n)
        {
            c[k] = a[i];
            k++;
            i++;
        }
    }
    return count;
}

int main()
{
    int n, m;
    printf("Enter the sizes of the 2 sorted arrays: ");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of the sorted arrays\n");
    int a[n], b[m];
    printf("Array 1: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array 2: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("The given sorted arrays are\n");
    printf("Array 1: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Array 2: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    int count = interesting_pairs(n, m, a, b);
    printf("The number of interesting pairs are %d", count);
}