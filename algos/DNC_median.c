#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right, int pivot) {
    int pivotIndex;
    for (pivotIndex = left; pivotIndex <= right; pivotIndex++) {
        if (arr[pivotIndex] == pivot) {
            break;
        }
    }
    swap(&arr[pivotIndex], &arr[right]);

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

int findMedian(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int n = right - left + 1;
    int numGroups = (n + 4) / 5;

    int middle[numGroups];
    for (int i = 0; i < numGroups; i++) {
        int groupLeft = left + 5 * i;
        int groupRight = groupLeft + 4;
        if (groupRight > right) {
            groupRight = right;
        }

        for (int j = groupLeft + 1; j <= groupRight; j++) {
            int key = arr[j];
            int k = j - 1;
            while (k >= groupLeft && arr[k] > key) {
                arr[k + 1] = arr[k];
                k--;
            }
            arr[k + 1] = key;
        }

        middle[i] = arr[(groupLeft + groupRight) / 2];
    }

    int medianOfMedians = findMedian(middle, 0, numGroups - 1, numGroups / 2);

    int pos = partition(arr, left, right, medianOfMedians);

    if (pos - left == k) {
        return arr[pos];
    } else if (pos - left > k) {
        return findMedian(arr, left, pos - 1, k);
    } else {
        return findMedian(arr, pos + 1, right, k - (pos - left + 1));
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int median = findMedian(arr, 0, n - 1, k);
    printf("Median: %d\n", median);

    return 0;
}
