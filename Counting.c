#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void CountingSort(int *arr, int n){
    if (n == 0) return; 

    int max = arr[0];
    for(int i = 1; i < n; i++){  
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max+1];  

    for(int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int i = 0;
    for(int j = 0; j <= max; j++){
        while(count[j] > 0){
            arr[i] = j;
            i++;
            count[j]--;
        }
    }
}

void main(){
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;
    
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    int arr[n];  
    
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 10;
        // scanf("%d", &arr[i]);
    }

    start = clock();

    CountingSort(arr, n);

    end = clock();

    // printf("\nSorted Array:\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d\t", arr[i]);
    // }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf\n", cpu_time_used);
}
