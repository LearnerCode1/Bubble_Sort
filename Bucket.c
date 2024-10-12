#include<stdio.h>
#include<stdlib.h>

void InsertionSort(float *arr, int n)
{
    for(int i = 1; i < n ; i++)
    {
        float key = arr[i];
        int j = i-1;
        {
            while(j >= 0 && key < arr[j])
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}

void BucketSort(float *arr, int n)
{
   float **Buckets = (float **)malloc(n * sizeof(float *));
   int *bucketIndex = (int *)malloc(n * sizeof(int));

   for (int i = 0; i < n; i++)
   {
      Buckets[i] = (float *)malloc(n * sizeof(float));
      bucketIndex[i] = 0;
   }
    
   for(int i = 0; i < n; i++)
   {
    int x = arr[i]*n;
    Buckets[x%n][bucketIndex[x]++] = arr[i];
   }

   for(int i = 0; i < n; i++)
   {
        InsertionSort(Buckets[i],bucketIndex[i]);
   }

    int k=0;

   for(int i = 0 ; i < n ; i++)
   {
    for(int j = 0 ; j < bucketIndex[i] ; j++)
    {
        arr[k++] = Buckets[i][j];
    }
   }

   for(int i = 0 ; i  < n ; i++)
   {
    free(Buckets[i]);
   }
    free(Buckets);
    free(bucketIndex);
   
}
void main()
{
    int n;
    printf("Enter the size of the Array : ");
    scanf("%d", &n);
    float *a = (float *)malloc(n*sizeof(float));
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter element : ");
        scanf("%f", &a[i]);
    }

    BucketSort(a,n);
    printf("Sorted Array : ");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%f ", a[i]);
    }
    free(a);

}
