#include <stdio.h>

void merge(int n, int a[], int lb, int mid, int ub, int *count) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[n];
    
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
            (*count) += (mid - i + 1); // Increment count for inversions
        }
        k++;
    }
    
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    
    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }
    
    for (int p = lb; p <= ub; p++) {
        a[p] = b[p];
    }
}

void merge_sort(int n, int a[], int lb, int ub, int *count) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(n, a, lb, mid, count);
        merge_sort(n, a, mid + 1, ub, count);
        merge(n, a, lb, mid, ub, count);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int count = 0; // Initialize inversion count
    merge_sort(n, a, 0, n - 1, &count);
    
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\nThe number of inversions = %d\n", count);
    return 0;
}
