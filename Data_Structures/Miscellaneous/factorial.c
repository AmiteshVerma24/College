#include<stdio.h>

int factorialRecursive(int n) {
    if (n>=1)
        return n*factorialRecursive(n-1);
    else
        return 1;
}

int main() {
    int n;
    
    printf("Enter a positive integer: ");
    
    scanf("%d",&n);
    printf("Factorial of %d = %d", n, factorialRecursive(n));
    return 0;
}


