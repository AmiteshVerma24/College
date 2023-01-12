// Online C compiler to run C program online
#include <stdio.h>
#define max 6
struct queue {
    int rear;
    int front;
    int arr[max];
};
struct queue q;
int isEmpty(){
    if (q.rear == -1 && q.front == -1){
        return 1;
    }
    return 0;
}
void push(int x){
    // Check empty
    if (isEmpty() == 1){
        q.rear = q.front = 0;
    }
    // Check max
    else if (q.rear == max - 1){
        printf("QUEUE IS FULL\n");
    }
    // Other cases
    else{
        q.rear++;
        
    }
    q.arr[q.rear] = x;
}
void pop(){
    // If empty
    if (isEmpty() == 1){
        printf("EMPTY QUEUE\n");
    }
    // If only one element
    else if (q.front == q.rear){
        q.front = q.rear = -1;
    }
    // Other cases
    else{
        q.front++;
    }
}
void display(){
    for (int i = q.front ; i <= q.rear ; i++){
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}
int main() {
    q.rear = -1;
    q.front = -1;
    push(3);
    display();
    push(4);
    display();
    push(15);
    display();
    pop();
    display();
    return 0;
}






















