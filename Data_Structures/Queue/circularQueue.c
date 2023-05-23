// Online C compiler to run C program online
#include <stdio.h>
#define max 6
struct queue {
    int front;
    int rear;
    int arr[max];
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
    printf("Rear: %d, Front: %d\n",q.rear,q.front);
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
    printf("Rear: %d, Front: %d\n",q.rear,q.front);
}

void display(){
    for (int i = q.front ; i <= q.rear ; i = (i+1)%max){
        printf("%d ", q.arr[i]);
    }
    printf("Rear: %d, Front: %d\n",q.rear,q.front);
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
}