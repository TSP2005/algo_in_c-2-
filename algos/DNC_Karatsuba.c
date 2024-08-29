#include <stdio.h>

int karatsuba (int n, )

void multiply(int n, int num1, int num2);

int main()
{
    int n;
    printf("Enter the number of digits: ");
    scanf("%d", &n);
    printf("Enter the numbers (with spaces in-between digits)\n");
    int num1[n];
    int num2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num2[i]);
    }
    printf("The given numbers are\n");
    printf("num1: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", num1[i]);
    }
    printf("\n");
    printf("num1: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", num2[i]);
    }
    printf("\n");
}