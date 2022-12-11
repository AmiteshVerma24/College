#include<stdio.h>
// Declaring max size of stack
#define MAXSIZE 10
int stackArray[MAXSIZE];
// Variable to hold top of stack
int top = -1;

// Push function to push new element to stack
void push(int x){
    top = top + 1;
    if (top <= MAXSIZE-1){
        stackArray[top] = x;
    } else{
        printf(" \nThe stack is full \n");
    }
}
// Pop function to remove an element
void pop(){
    if (top != -1){
        top = top - 1;
    }else{
        printf("\n The stack is empty can't remove element \n");
    }
}
// Top to return top element
void Top(){
    printf("\n The top Element is: %d \n", stackArray[top]);
}
// Helper function to check if the stack is empty or not
void isEmpty(){
    if (top == -1){
        printf("\n THE STACK IS EMPTY \n");
    }else{
        printf("\n THE STACK IS NOT EMPTY \n");
    }
}
// Function to print the stack
void print(){
    if (top != -1){
        printf("\nThe stack is: \n");
        for (int i = 0 ; i <= top ; i++){
            printf("%d ", stackArray[i]);
        }
    }else{
        printf("\nThe stack is empty\n");
    }
}
// Main function
int main(){
    // Performing push and pop function
    push(80);           // 80
    push(72);           // 80 72
    push(2);            // 80 72 2
    push(64);           // 80 72 2 64
    printf("Stack before first pop: ");
    print();
    pop();              // 80 72 2 
    printf("\nStack after first pop: ");
    print();
    push(10);           // 80 72 2 10
    push(27);           // 80 72 2 10 27
    printf("Stack before second pop: ");
    print();
    pop();              // 80 72 2 10 
    printf("\nStack after second pop: ");
    print();
    return 0;
}
