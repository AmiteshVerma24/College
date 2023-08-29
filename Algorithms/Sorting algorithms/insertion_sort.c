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
        a[i] = rand() % 10;
    }
}


void insertion_sort(int a[], int size)
{   
    int hole;
    int value;
    for(int i = 1 ; i < size ; i++){
        hole = i;
        value = a[hole];
        while(hole > 0 && a[hole - 1] > value){
            a[hole] = a[hole - 1];
            hole = hole - 1;
        }
        a[hole] = value;
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
    insertion_sort(arr, size);
    end = clock();
    printf("\nArray after sorting is:- ");
    print_array(arr, size);
    total_t = (end - start) / 1000;                        // We get the answer in milli seconds
    printf("\nTime taken to sort array is: %lf", total_t);
    printf("\n==============================================================================\n");
}