#include <stdio.h>

void add(int n, int a[], int b[], int sum[])
{
    int temp = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum[i + 1] = (temp + a[i] + b[i]) % 10;
        temp = (temp + a[i] + b[i]) / 10;
    }
    sum[0] = temp;
}

int main()
{
    int n;
    printf("Enter the size of the 2 numbers: ");
    scanf("%d", &n);
    int a[n];
    int b[n];
    printf("Enter the 1st %d-digit number (with spaces between digits): ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the 2nd %d-digit number (with spaces between digits): ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    int sum[n + 1];
    add(n, a, b, sum);
    printf("The given numbers are\n");
    printf("num 1: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    printf("num 2: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", b[i]);
    }
    printf("\n");
    printf("The sum of the given numbers is\n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d", sum[i]);
    }
    printf("\n");
}