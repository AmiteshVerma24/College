#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



void print_array(int a[], int s)
{
    // printf("\n==============================================================================\n");
    for (int i = 0; i < s; i++)
    {
        printf("%d, ", a[i]);
    }
    // printf("\n==============================================================================\n");
}

void random_array(int a[], int s)
{
    int num;
    
    for (int i = 0; i < s; i++)
    {
        a[i] = rand();
    }
}

int partition(int a[], int start , int end){
    int pivot = a[end];
    int pIndex = start;
    int temp  = 0;
    for(int i = start; i < end ; i++){
        if(a[i] < pivot){
            temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    temp = a[end];
    a[end] = a[pIndex];
    a[pIndex] = temp;
    return pIndex;
}

void quick_sort(int a[], int start, int end )
{
    if(start < end){
        int pIndex = partition(a, start, end);
        quick_sort(a,start, pIndex-1);
        quick_sort(a,pIndex+1,end);
    }
}

int main()
{
    clock_t start, end;
    double total_t;
    int size;
    printf("\n==============================================================================\n");
    printf("\nEnter the number of elements in the array:- ");
    scanf("%d", &size);
    int arr[size];
    random_array(arr, size);
    printf("\nArray before sorting is:- ");
    print_array(arr, size);
    start = clock();                                            
    quick_sort(arr,0, size-1);
    end = clock();
    printf("\nArray after sorting is:- ");
    print_array(arr, size);
    total_t = (end - start) / 1000;                        // We get the answer in milli seconds
    printf("\nTime taken to sort array is: %lf", total_t);
    printf("\n==============================================================================\n");
}