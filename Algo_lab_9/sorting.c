#include <stdio.h>

void fillSort (int n, int s, int a[], int sort[])
{
    for (int i = 0; i < s; i++)
    {
        sort[i] = 0;
    }
    printf("The sorting matrix is: ");
    for (int i = 0; i < s; i++)
    {
        printf("%d ", sort[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        sort[a[i]] += 1;
    }
    for (int i = 1; i < s; i++)
    {
        sort[i] += sort[i - 1];
    }
    printf("The sorting matrix is: ");
    for (int i = 0; i < s; i++)
    {
        printf("%d ", sort[i]);
    }
    printf("\n");
}

void stableSort (int n, int s, int a[], int sort[])
{
    int sorted[n];
    for (int i = n - 1; i >= 0; i--)
    {
        sorted[sort[a[i]] - 1] = a[i];
        sort[a[i]]--;
    }
    printf("Stable Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sorted[i]);
    }
    printf("\n");
}

void unStableSort (int n, int s, int a[], int sort[])
{
    int sorted[n];
    for (int i = 0; i < n; i++)
    {
        sorted[sort[a[i]] - 1] = a[i];
        sort[a[i]]--;
    }
    printf("Unstable Sort\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sorted[i]);
    }
    printf("\n");
}

int main ()
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
    int k = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > k)
        {
            k = a[i];
        }
    }
    printf("k = %d\n", k);
    int s = k + 1;
    int sort[s];
    fillSort(n, s, a, sort);
    int sort1[s];
    for (int i = 0; i < s; i++)
    {
        sort1[i] = sort[i];
    }
    stableSort(n, s, a, sort1);
    unStableSort(n, s, a, sort);
}