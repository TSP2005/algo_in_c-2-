#include <stdio.h>

void profitsforEachDay(int c, int n, int a[], int p[], int r)
{
    for (int i = 0; i < c; i++)
    {
        p[i] = a[i + 1] - a[i] - r;
    }
}

int maxSubarraySum(int c, int p[])
{
    int MSA = p[0];
    int MSF = p[0];
    for (int i = 1; i < c; i++)
    {
        MSA = (MSA > (MSF + p[i]) ? (p[i] > MSA ? p[i] : MSA) : (MSF + p[i]) > p[i] ? (MSF + p[i]) : p[i]);
        MSF = ((MSF + p[i]) > p[i]) ? (MSF + p[i]) : p[i];
    }
    return MSA;
}

int main()
{
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    int a[n];
    int r;
    printf("Enter the rent per day: ");
    scanf("%d", &r);
    printf("Enter the prices for each day: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The given price chart is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d is the rent per each day.\n", r);
    int c = n - 1;
    int p[c];
    profitsforEachDay(c , n, a, p, r);
    int MSA = maxSubarraySum(c , p);
    printf("%d is the maximum attainable profit.\n", MSA);
}