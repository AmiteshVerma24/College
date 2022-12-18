#include<stdio.h>

void main(){
    int num, fac = 1;
    printf("Enter the number whose factorial is to be found out:- ");
    scanf("%d", &num);
    for (int i = 1 ; i <= num ; i++){
        fac *= i;
    }
    printf("The factorial of %d is:- %d", num , fac);
}