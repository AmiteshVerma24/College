#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void copy_content(int original[] , int to_copy[] , int size , int start_index){
    for(int i = start_index ; i < start_index + size ; i++){
        to_copy[i] = original[i];
    }
}

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
        a[i] = rand() % s;
    }
}

void merge(int arr[], int arr1[], int arr2[], int size1, int size2)
{
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    while(index1 < size1 && index2 < size2){

        if(arr1[index1] < arr2[index2]){
            arr[index++] = arr1[index1++];
        }
        else{
            arr[index++] = arr2[index2++];
        }
    }
    while(index1 < size1){
        arr[index++] = arr1[index1++];
    }
    while(index2 < size2){
        arr[index++] = arr2[index2++];
    }
}

void merge_sort(int a[], int s)
{
    if(s < 2){
        return;
    }
    int mid = s/2;
    int left[mid];
    int right[s-mid];
    int index = 0;
    int i = 0;
    while(index < mid){
        left[i++] = a[index++];
    }
    i = 0;
    while(index < s){
        right[i++] = a[index++];
    }
    merge_sort(left, mid);
    merge_sort(right, s - mid);
    merge(a , left , right , mid, s - mid);
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
    merge_sort(arr, size);
    end = clock();
    printf("\nArray after sorting is:- ");
    print_array(arr, size);
    total_t = (end - start) / 1000;                        // We get the answer in milli seconds
    printf("\nTime taken to sort array is: %lf", total_t);
    printf("\n==============================================================================\n");
}