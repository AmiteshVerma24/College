// Online C compiler to run C program online
#include <stdio.h>
#define max 6
struct queue {
    int front;
    int rear;
    int arr[max]
};

struct queue q;

int isFull(){
    if ((q.rear+1)%max == 0){
        return 1;
    }
    return 0;
}

void push(int x){
    // If empty
    if (q.rear == -1 && q.front ==-1){
        q.rear = q.front = 0;
    }
    // If full
    else if (isFull() == 1){
        printf("QUEUE IS FULL");
    }
    // Other cases
    else{
        q.rear = (q.rear+1)%max;
    }
    q.arr[q.rear] = x;
}

void pop(){
    // Is empty
    if (q.front == -1 && q.rear == -1){
        printf("CANT POP, QUEUE EMPTY");
    }
    // If only one element
    else if (q.rear == q.front){
        q.rear = q.front = -1;
    }
    // Other cases
    else{
        q.front = (q.front+1)%max;
    }
}

void display(){
    for (int i = q.front ; i <= q.rear ; i = (i+1)%max){
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    // Write C code here
    q.rear = q.front = -1;
    push(2);
    display();
    push(4);
    display();
    push(9);
    display();
    push(18);
    display();
    pop();
    display();
    return 0;
}