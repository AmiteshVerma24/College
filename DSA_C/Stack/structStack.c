#include<stdio.h>
#define max 5
// Defining the stack DATA STRUCTURE
struct stack {
    int top;
    char arr[max];
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
void push(char ch)
{
    if (isOverflow()) {
        printf("THE STACK IS FULL. CAN'T ENTER! \n");
        return;
    } else {
        s.arr[++s.top] = ch;
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
        printf("%c ", s.arr[i]);
    }
    printf("\n");
}
// Main function
void main()
{
    char str[] = "{]()";
    int flag = 0;
    s.top = -1;
    for (int i = 0 ; i < max ; i++) {
        display();
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }
        else if (str[i] == ')'){
            if (s.arr[s.top] != '('){
                flag += 1;
            }
            else{
                pop();
            }
        }
         else if (str[i] == ']'){
            if (s.arr[s.top] != '['){
                flag += 1;
            }
            else{
                pop();
            }
        }
        else{
            if (s.arr[s.top] != '{'){
                flag += 1;
            }
            else{
                pop();
            }
        }
    }
    if (s.arr[s.top] == -1){
        printf("VALID\n");
    }
    else{
        flag += 1;
    }
    if (flag != 0){
        printf("INVALID\n");
    }
}
// for (int i = 0 ; i < max ; i++)
// {
//     if (s.arr[i] == '(' || s.arr[i] == '{' || s.arr[i] == '[') {
//         printf("%c \n",s.arr[i]);
//         push(s.arr[i]);
//     }
// }