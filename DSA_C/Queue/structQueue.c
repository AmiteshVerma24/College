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
    q.rear = q.front = -1;
    int choice, isContinue = 0;
    while (isContinue == 0){
            printf("What would you like to do? \n 1. Enter a number \n 2. Remove a nnumber \n 3. Display numbers \n 4. EXIT \nEnter your choice:- ");
            scanf("%d",&choice);
            switch (choice){
                case 1:
                    printf("Enter the number:- ");
                    int num;
                    scanf("%d", &num);
                    push(num);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    isContinue = 1;
                    printf("EXITED THE LOOP");
                    break;
                default:
                    printf("INVALID CHOICE");
                    
            }

        }
    return 0;
    return 0;
}






















