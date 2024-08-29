#include <stdio.h>

struct MaxAndSecondMax {
    int max;
    int secondMax;
};

struct MaxAndSecondMax findMaxAndSecondMax(int a[], int start, int end) {
    struct MaxAndSecondMax result;

    if (start == end) {
        result.max = a[start];
        result.secondMax = -1;  // Indicate that secondMax is not available
    } else if (start == end - 1) {
        if (a[start] > a[end]) {
            result.max = a[start];
            result.secondMax = a[end];
        } else {
            result.max = a[end];
            result.secondMax = a[start];
        }
    } else {
        int mid = start + (end - start) / 2;
        struct MaxAndSecondMax left = findMaxAndSecondMax(a, start, mid);
        struct MaxAndSecondMax right = findMaxAndSecondMax(a, mid + 1, end);

        // Find the maximum of both subproblems
        result.max = (left.max > right.max) ? left.max : right.max;

        // Find the second maximum using comparisons
        if (left.max > right.max) {
            result.secondMax = (left.secondMax > right.max) ? left.secondMax : right.max;
        } else {
            result.secondMax = (right.secondMax > left.max) ? right.secondMax : left.max;
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    struct MaxAndSecondMax result = findMaxAndSecondMax(a, 0, n - 1);

    printf("The given array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Maximum: %d\n", result.max);
    printf("Second Maximum: %d\n", result.secondMax);

    return 0;
}
