#include<stdio.h>

void main(){
    int c = 10;
    int * ptr;
    ptr = &c;
    printf("%d --> %d", c, ptr);
}