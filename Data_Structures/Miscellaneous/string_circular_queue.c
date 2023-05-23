#include <stdio.h>
#include <string.h>
#define max 6
struct queue {
    int front;
    int rear;
    char arr[max][20];
};

struct queue q;

int isFull(){
    if ((q.rear+1)%max == 0){
        return 1;
    }
    return 0;
}

void APPEND(char * name){
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
    strcpy(q.arr[q.rear], name);
}

void REMOVE(){
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

void DISPLAY(){
    printf("\n");
    for (int i = q.front ; i <= q.rear ; i = (i+1)%max){
        printf("%s ", q.arr[i]);
    }
    printf("\n");
    printf("\n");
}

int main() {
    q.rear = q.front = -1;
    int choice, isContinue = 0;
    while (isContinue == 0){
            printf("What would you like to do? \n 1. Append a name \n 2. Remove a name \n 3. Display names \n 4. EXIT \nEnter your choice:- ");
            scanf("%d",&choice);
            switch (choice){
                case 1:
                    printf("Enter the name:- ");
                    char name[20];
                    scanf("%s", name);
                    APPEND(name);
                    break;
                case 2:
                    REMOVE();
                    break;
                case 3:
                    DISPLAY();
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