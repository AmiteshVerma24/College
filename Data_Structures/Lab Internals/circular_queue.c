// Write a program to demonstrate round robin processor scheduling using circular queue (array implementation) with suitable inputs. Program should have options to add, remove and display elements of the queue. 

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
struct queue{
    int queue[MAX_SIZE];
    int front;
    int rear;
    int no_of_elements;
};
struct queue q;
void enqueue(int data){
    if(q.front == -1 && q.rear == -1){
        printf("%d is to inserted.\n",data);
        q.front = 0;
        q.rear = 0;
        q.queue[q.rear] = data;
        q.no_of_elements++;
    }else if(q.front == (q.rear+1)%MAX_SIZE){
        printf("The queue is full can't insert.\n");
        return;
    }else{
        q.rear = (q.rear+1)%MAX_SIZE;
        q.queue[q.rear] = data;
        q.no_of_elements++;
    }
    printf("no of elements are %d",q.no_of_elements);
}
void dequeue(){
    if(q.front == -1 && q.rear == -1){
        printf("Can't delete the queue is empty.\n");
        return;
    }else if (q.front == q.rear){
        printf("%d is to deleted.\n",q.queue[q.front]);
        q.front = -1;
        q.rear = -1;
        q.no_of_elements--;
    }else{
        printf("%d is to deleted.\n",q.queue[q.front]);
        q.front = (q.front+1)%MAX_SIZE;
        q.no_of_elements--;
    }
}
void display(){
    if(q.front == -1 && q.rear == -1){
        printf("The queue is empty.\n");
        return;
    }else{
        int temp = q.front;
        for(int i = 0 ; i < q.no_of_elements ; i++){
            printf("%d  ",q.queue[temp]);
            temp = (temp+1)%MAX_SIZE;
        }
    }
}
int main(){
     q.front = -1;
    q.rear = -1;
    q.no_of_elements = 0;
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