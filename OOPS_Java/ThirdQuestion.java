package OOPS_Java;

import java.util.*;

/* Define a Stack class to implement the stack data structure. Include constructors to perform initialization, method push to push an element into the stack, method pop to remove an element from the stack and display method to display the elements of the stack. */

class Stack{
    // Scanner object to take input
    Scanner sc = new Scanner(System.in);
    // 
    int size, top;
    static int arr[] ;
    // Constructor to take input
    public Stack(){
        this.top = -1;
        System.out.print("Enter the size of stack:- ");
        this.size = sc.nextInt();
        arr = new int[size];
    }
    // Is full function
    boolean isFull(){
        if (this.top > size - 1){
            return true;
        }
        return false;
    }
    // Is empty funtion
    boolean isEmpty(){
        if (this.top == -1){
            return true;
        }
        return false;
    }
    // Push function
    void push(int x){
        if (isFull()){
            System.out.println("The stack is full can't enter");
        }else{
            System.out.format("The item added is:- %d \n", x);
            this.top = this.top + 1;
            this.arr[this.top] = x;
        }
    }
    // Pop funtion
    void pop(){
        if(isEmpty()){
            System.out.println("Can't pop element stack is empty");
        }else{
            this.top = this.top - 1;
        }
    }
    // Display funtion
    void display(){
        System.out.print("END->");
        for(int i = 0 ; i <= this.top ; i++){
            System.out.format(" %d ",this.arr[i]);
        }
        System.out.print("<-TOP\n");
    }
}
class ThirdQuestion{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // New stack object
        Stack myStack = new Stack();
        // Choice of user
        int choice, isContinue = 0;
        while (isContinue == 0){
            System.out.print("\nWhat would you like to do? \n 1. PUSH \n 2. POP \n 3. DISPLAY \n 4. EXIT \nEnter your choice:- ");
            choice = sc.nextInt();
            switch (choice){
                case 1:
                    System.out.print("Enter the element to be pushed:- ");
                    int num = sc.nextInt();
                    myStack.push(num);
                    break;
                case 2:
                    myStack.pop();
                    break;
                case 3:
                    myStack.display();
                    break;
                case 4:
                    isContinue = 1;
                    break;
                default:
                    System.out.println("INVALID CHOICE");
                
            }

        }
        
    }
}