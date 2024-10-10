#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main(){
    srand(time(NULL));
     clock_t start, end;
     double cpu_time_used;
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = rand();
    }
    // printf("UnSorted Array");

    //  for(int i=0;i<n;i++){
    //     printf("%d\t", arr[i]);
    // }
    
    start = clock();

    for(int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
        }

        arr[j + 1] = key;
    }

    end = clock();



    // printf("\nSorted Array");
    // for(int i=0;i<n;i++){
    //     printf("%d\t", arr[i]);
    // }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %lf", cpu_time_used);

}
