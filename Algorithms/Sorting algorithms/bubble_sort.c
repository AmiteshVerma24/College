#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void bubble_sort(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void print_array(int a[], int s)
{
    printf("\n==============================================================================\n");
    for (int i = 0; i < s; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n==============================================================================\n");
}

void random_array(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        a[i] = rand();
    }
}

int main()
{
    clock_t start, end;
    double total_t;
    int size;
    // Input for array size
    printf("\n==============================================================================\n");
    printf("\nEnter the number of elements in the array:- ");
    scanf("%d", &size);
    int arr[size];
    random_array(arr, size);
    // Printing array before sorting
    printf("\nArray before sorting is:- ");
    print_array(arr, size);
    // Sorting and noting the time
    start = clock();                                            
    bubble_sort(arr, size);
    end = clock();
    // Printing array after sorting
    printf("\nArray after sorting is:- ");
    print_array(arr, size);
    // Calculating total time
    total_t = (end - start) / 1000;                        // We get the answer in milli seconds
    printf("\nTime taken to sort array is: %lf", total_t);
    printf("\n==============================================================================\n");
}
// The clock() returns the number of clock ticks passed since the execution of the program has started
// Clock tics is the smallest interval in the computer's CPU based on which it passes data which is measured
// from the internal quartz clock of the CPU
// Now to convert to seconds we divide by clocks per second which is the number of clock ticks passes in a
// second
// For a 32 bit system clocks per cycle is of order 1000000