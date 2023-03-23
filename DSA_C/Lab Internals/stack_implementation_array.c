
// Write a program to illustrate maintaining the books in a pile. The books are placed in a stack. The books can be removed from the top position only. The books are represented by book id. Use Array implementation. Display the appropriate messages in case of exceptions. 

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 4

int stack[MAX_SIZE];
int top = -1;

void pop(){
    if(top < 0){
        printf("The stack is empty.\n");
    }else{
        printf("%d popped from the stack.",stack[top]);
        top--;
    }
}

void push(int data){
    top++;
    if(top < MAX_SIZE){
        stack[top] = data;
        printf("%d Pushed into the stack.\n",data);
    }else{
        printf("The stack is full.\n");
        return;
    }
}

void display(){
    if(top >= 0){
        for(int i = 0; i <= top ; i++){
            printf("%d\n",stack[i]);
        }
    }else{
        printf("The stack is empty.\n");
    }
    
}

void peek(){
    if(top < 0){
        printf("The stack is empty.\n");
    }else{
        printf("The element at top is %d.\n",stack[top]);
    }
}


int main(){ 
    int isContinue = 1;
    int value, node_value;
    while (isContinue == 1)
    {   
        int choice;
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Push.\n 2. Pop.\n 3. Display.\n 4. Top.\n 5. Exit.\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("TOP ELEMENT.");
                peek();
                break;
            case 5:
                isContinue = 0;
                break;
            default:
                printf("INVALID CHOICE");
                break;
        }
    }
}