#include <stdio.h>
#include <string.h>
#define max 3

struct employee{
    int age;
    int salary;
    char name[20];
    char id[10];
};

struct queue {
    int front;
    int rear;
    struct employee arr[max];
};

struct queue q;

int isFull(){
    if ((q.rear+1)%max == 0){
        return 1;
    }
    return 0;
}

void APPEND(struct employee emp){
    // If empty
    if (q.rear == -1 && q.front == -1){
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
    q.arr[q.rear] = emp;
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
    if (q.front == -1 && q.rear == -1){
        printf("Queue is empty");
    }else if(q.front <= q.rear){
        int i = q.front;
        while (i <= q.rear){
            printf("Name: %s ", q.arr[i].name);
            printf("ID: %s ", q.arr[i].id);
            printf("Salary: %d ", q.arr[i].salary);
            printf("Age: %d ", q.arr[i].age);
            printf("\n");
            i++;
        }
    }else{
        int i = q.front;
        while (i <= max-1){
            printf("Name: %s ", q.arr[i].name);
            printf("ID: %s ", q.arr[i].id);
            printf("Salary: %d ", q.arr[i].salary);
            printf("Age: %d ", q.arr[i].age);
            printf("\n");
            i++;
        }
        i = 0;
        while (i <= q.rear){
            printf("Name: %s ", q.arr[i].name);
            printf("ID: %s ", q.arr[i].id);
            printf("Salary: %d ", q.arr[i].salary);
            printf("Age: %d ", q.arr[i].age);
            printf("\n");
            i++;
        }
        
    }
    printf("\n");
    printf("\n");
}

int main() {
    q.rear = q.front = -1;
    int choice, isContinue = 0;
    while (isContinue == 0){
            printf("What would you like to do? \n 1. Append an emplyoyee \n 2. Remove an employee \n 3. Display list of employees \n 4. EXIT \nEnter your choice:- ");
            scanf("%d",&choice);
            switch (choice){
                case 1:
                    printf("Enter the name:- ");
                    char nam[20];
                    scanf("%s", nam);
                    printf("Enter the employee ID:- ");
                    char id[10];
                    scanf("%s", id);
                    int age, salary;
                    printf("Enter the age:- ");
                    scanf("%d", &age);
                    printf("Enter the salary:- ");
                    scanf("%d", &salary);
                    struct employee emp;
                    strcpy(emp.name , nam);
                    strcpy(emp.id , id);
                    emp.age = age;
                    emp.salary = salary;
                    APPEND(emp);
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