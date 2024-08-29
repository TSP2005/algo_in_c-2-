#include <stdio.h>
#include <limits.h>

int second_maximum = INT_MIN;

void max_2(int value)
{
    if (value > second_maximum)
    {
        second_maximum = value;
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
            max_2(p2);
            ++ *count;
            return p1;
        }
        else
        {
            max_2(p1);
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
    printf("%d is the maximum element.\n%d is the second_maximum element.\nThe number of comparisions are %d.", maximum, second_maximum, count);
}