#include <stdio.h>

int maxSubarraySum(int n, int a[])
{
    int MSA = a[0];
    int MSF = a[0];
    for (int i = 1; i < n; i++)
    {
        MSA = (MSA > (MSF + a[i]) ? (a[i] > MSA ? a[i] : MSA) : (MSF + a[i]) > a[i] ? (MSF + a[i]) : a[i]);
        MSF = ((MSF + a[i]) > a[i]) ? (MSF + a[i]) : a[i];
    }
    return MSA;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
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
    int MSA = maxSubarraySum(n, a);
    printf("%d is the maximum contiguous subarray sum.", MSA);
}