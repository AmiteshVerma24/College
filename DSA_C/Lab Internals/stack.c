#include<stdio.h>
#include<stdlib.h>
#define max 6

struct stack{
    int arr[max];
    int top;
};

struct stack s;

void push(){
    if(s.top >= max-1){
        printf("STACK FULL");
        exit(0);
    }
    int num;
    printf("Enter the number to be pushed: ");
    scanf("%d",&num);
    s.arr[++s.top] = num;
}

int pop(){
    if (s.top < 0){
        printf("STACK EMPTY CAN'T POP");
        exit(0);
    }
    return s.arr[s.top--];
}

void display(){
    for (int i = 0; i < s.top+1; i++){
        printf(" %d ",s.arr[i]);
    }
    printf("\n");
}

int main(){
    s.top = -1;
    push();
    push();
    display();
    pop();
    push();
    push();
    push();
    push();
    push();
    push();
    display();
}
