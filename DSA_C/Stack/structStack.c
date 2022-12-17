#include<stdio.h>
#define max 5
// Defining the stack DATA STRUCTURE
struct stack {
    int top;
    int arr[max];
};
// Creating stack tyoe object
struct stack s;
// Overflow condition
int isOverflow()
{
    if (s.top >= max - 1) {
        return 1;
    } else {
        return 0;
    }
}
// Underflow condition
int underFlow()
{
    if (s.top < 0) {
        return 1;
    } else {
        return 0;
    }
}
// Push value to stack
void push()
{
    if (isOverflow()) {
        printf("THE STACK IS FULL. CAN'T ENTER! \n");
        return;
    } else {
        int num;
        printf("Enter the number to be pushed: ");
        scanf("%d", &num);
        s.arr[++s.top] = num;
    }
}
// Pop items from stack
void pop()
{
    if (underFlow()) {
        printf("THE STACK IS EMPTY! \n");
        return;
    } else {
        s.top -= 1;
    }
}
// To display the stack
void display()
{
    printf("THE STACK IS: \n");
    for ( int i = 0; i <= s.top; i++) {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}
// Main function
void main()
{
    s.top = -1;

    for(int i = 0 ; i < 6 ; i++) {
        push();
        display();
    }
    for(int i = 0 ; i < 10 ; i++){
        display();1
        
        pop();
    }
}