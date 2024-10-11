#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[low], &arr[right]);  
    return right;  
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);  
        QuickSort(arr, pivotIndex + 1, high); 
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

    QuickSort(arr, 0, n - 1); 

    end = clock();  

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", cpu_time_used);

    return 0;
}
