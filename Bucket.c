#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InsertionSort(float arr[], int n){
    for(int i=1; i<n; i++){
        float key = arr[i];  
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BucketSort(float arr[], int n){
    float newArr[n][n];
    int bucketSizes[n]; 

    for(int i=0; i<n; i++){
        bucketSizes[i] = 0;
    }

    for(int i=0; i<n; i++){
        int bucketIndex = arr[i] * n; 
        newArr[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    for(int i=0; i<n; i++){
        if(bucketSizes[i] > 0){
            InsertionSort(newArr[i], bucketSizes[i]);
        }
    }

    int index = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<bucketSizes[i]; j++){
            arr[index++] = newArr[i][j];  
        }
    }
}

int main() {
    srand(time(NULL));  
    clock_t start, end;
    double cpu_time_used;

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d float numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);  
    }

    start = clock(); 

    BucketSort(arr, n);  

    end = clock(); 

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f\t", arr[i]);
    }
    printf("\n");

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", cpu_time_used);

    return 0;
}
