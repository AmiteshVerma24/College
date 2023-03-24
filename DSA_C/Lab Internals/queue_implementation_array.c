// A call center phone system has to hold the phone calls from customers and provide service based on the arrival time of the calls. Write a C program to simulate this system using queue data structure. Program should have options to add and remove the phone calls in appropriate order for their service. 

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct queue
{
    int queue[MAX_SIZE];
    int rear;
    int front;
};

struct queue q;

void enqueue(int data){
    if(q.front == -1 && q.rear == -1){
        q.front = 0;
        q.rear = 0;
    }else{
        q.rear++;
    }
    q.queue[q.rear] = data;
}

void dequeue(){
    if(q.front == -1 && q.rear == -1){
        printf("The queue is empty.\n");
        return;
    }else if(q.front == q.rear){
        printf("%d is to be deleted from queue.\n",q.queue[q.front]);
        q.front = -1;
        q.rear = -1;
    }else{
        printf("%d is to be deleted from queue.\n",q.queue[q.front]);
        q.front++;
    }
}

void display(){
    if(q.front == -1 && q.rear == -1){
        printf("The queue is empty.\n");
        return;
    }else{
        for (int i = q.front; i <= q.rear; i++)
        {
            printf(" %d ",q.queue[i]);
        }
        printf("\n");
    }
}
int main(){
    q.front = -1;
    q.rear = -1;
    int isContinue = 1;
    int value, node_value;
    while (isContinue == 1)
    {   
        int choice;
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Enqueue.\n 2. Dequeue.\n 3. Display. \n 4. Exit.\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                isContinue = 0;
                break;
            default:
                printf("INVALID CHOICE");
                break;
        }
    }
}