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

    for(int i = 0; i < n-1; i++) {
       int min = i;
       for(int j=i+1;j<n;j++){
        if(arr[j] < arr[min]){
            min = j;
        }
       }

       swap(&arr[min], &arr[i]);
    }

    end = clock();



    // printf("\nSorted Array");
    // for(int i=0;i<n;i++){
    //     printf("%d\t", arr[i]);
    // }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %lf", cpu_time_used);

}
