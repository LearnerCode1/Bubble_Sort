#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    srand(time(NULL));  
    clock_t start, end;
    double cpu_time_used;

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }

    // printf("Unsorted Array:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d\t", arr[i]);
    // }
    // printf("\n");

    start = clock();  

    MergeSort(arr, 0, n - 1);  

    end = clock();  

    // printf("Sorted Array:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d\t", arr[i]);
    // }
    // printf("\n");

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", cpu_time_used);

    return 0;
}
