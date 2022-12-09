package OOPS_Java;

import java.util.Scanner;

/* Write Java programs
a. To print Fibonacci series without using recursion and using recursion. (concept of
loops, data types)
b. To check prime numbers.
c. To sort an array elements using bubble sort algorithm. */

public class FirstQuestion {
    // Fibonacci series
    public static void Fibonacci(int n) {
        // Variables
        int first = 0, second = 1, third, temp;
        // Printing first two elements
        System.out.println("Fibonacci series: ");
        System.out.format("%d %d ", first, second);
        // Printing rest two elements
        for (int i = 1; i <= n - 2; i++) {
            third = first + second;
            temp = second;
            second = third;
            first = temp;
            System.out.format("%d ", third);
        }
    }

    // Fibonacci using recursion
    public static void FibonacciRecursive(int n) {
        System.out.println("Hello there!");
    }

    // Check whether a number is prime or not
    public static void checkPrime(int n) {
        int check = 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                check++;
            }
        }
        if (check == 0) {
            System.out.format("The given number %d is a prime number.", n);
        } else {
            System.out.println("It is not a prime number");
        }
    }

    // Sort an array using bubble sort
    public static void sortArray() {
        // Scanner object
        Scanner sc = new Scanner(System.in);
        // Asking user the length of array
        int length, num, temp;
        System.out.print("Enter the number of elements in the array: ");
        length = sc.nextInt();
        // Storing values in the array
        int myArr[] = new int[length];
        for (int i = 0; i < length; i++) {
            System.out.format("Enter the %d element of the array: ", i + 1);
            myArr[i] = sc.nextInt();
        }
        // Printing array before sorting
        System.out.print("The unsorted array is: \n");
        for (int i = 0 ; i < length ; i++){
            System.out.print(myArr[i]+" ");
        }
        // Sorting elements
        for (int i = 0; i < length; i++) {
            for (int j = 1; j < length - i; j++) {
                if (myArr[j - 1] > myArr[j]) {
                    // swap elements
                    temp = myArr[j - 1];
                    myArr[j - 1] = myArr[j];
                    myArr[j] = temp;
                }
            }
        }
        // Printing array after sorting
        System.out.print("\nThe sorted array is: \n");
        for (int i = 0 ; i < length ; i++){
            System.out.print(myArr[i]+" ");
        }
    }

    public static void main(String[] args) {
        // Scanner object
        Scanner sc = new Scanner(System.in);
        // Variables
        int choice, num;
        // Asking the user for his/her choice
        System.out.println(
                "What would you like to do? \n 1. Print Fibonacci of a number \n 2. Print Fibonacci using recursion \n 3. Check a number is prime or not \n 4. Sort an array using bubble sort");
        System.out.println("Enter your choice: ");
        choice = sc.nextInt();
        // Using a switch statement to present a menu driven program
        switch (choice) {
            case 1:
                System.out.print("Enter the number of elements in Fibonacci series: ");
                num = sc.nextInt();
                Fibonacci(num);
                break;
            case 2:
                System.out.print("Enter the number of elements in Fibonacci series: ");
                num = sc.nextInt();
                Fibonacci(num);
                break;
            case 3:
                System.out.print("Enter the number which is to be checked: ");
                num = sc.nextInt();
                checkPrime(num);
                break;
            case 4:
                sortArray();
                break;
            default:
                System.out.println("INVALID CHOICE!");
        }

    }
}
