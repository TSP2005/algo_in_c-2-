#include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter the sizes of the 2 arrays: ");
    scanf("%d %d", &n1, &n2);
    int a[n1], b[n2];
    printf("Enter the elements of the arrays");
    printf("array 1:");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("array 2:");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("The given 2 arrays are: \n");
    printf("array 1:");
    for (int i = 0; i < n1; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    printf("array 2:");
    for (int i = 0; i < n2; i++)
    {
        printf("%d", b[i]);
    }
    printf("\n");
    
}