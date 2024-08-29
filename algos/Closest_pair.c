#include <stdio.h>
#include <math.h>

void sort (int n, int a[][2], int start, int end);
void combine (int n, int a[][2], int start, int mid, int end);
float distance(int n, int a[][2]);

int main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    int a[n][2];
    printf("Enter the number points (x, y): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    printf("The given points are\n");
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", a[i][0], a[i][1]);
    }
    printf("\n");

    sort (n, a, 0, n - 1);

    printf("The points sorted wrt to their x co-ordinates are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", a[i][0], a[i][1]);
    }
    printf("\n");

    float d1 = distance(n, a);
    printf("The distance bewtween the 2 points is %f", d1);
}

void sort (int n, int a[][2], int start, int end)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);
        sort (n, a, start, mid);
        sort (n, a, mid + 1, end);
        combine (n, a, start, mid, end);
    }
}

void combine (int n, int a[][2], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int b[n][2];
    while (i <= mid && j <= end)
    {
        if (a[i][0] <= a[j][0])
        {
            b[k][0] = a[i][0];
            b[k][1] = a[i][1];
            k++;
            i++;
        }
        else
        {
            b[k][0] = a[j][0];
            b[k][1] = a[j][1];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k][0] = a[i][0];
        b[k][1] = a[i][1];
        k++;
        i++;
    }
    while (j <= end)
    {
        b[k][0] = a[j][0];
        b[k][1] = a[j][1];
        k++;
        j++;
    }
    for (int p = start; p <= end; p++)
    {
        a[p][0] = b[p][0];
        a[p][1] = b[p][1];
    }
}

float distance(int n, int a[][2])
{
    float d = sqrt(pow(a[1][0] - a[0][0], 2) + pow(a[1][1] - a[0][1], 2));
    return d;
}