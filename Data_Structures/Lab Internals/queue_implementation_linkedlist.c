
// Write a program to Implement the Queue data structure using Singly Linked list. Search through the list. Display the elements of the stack.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * head = NULL;

struct node * create_node(data){
    struct node * new_node = (struct node *)(malloc(sizeof(struct node)));
    new_node->data = data;
    return new_node;
}

void push(data){
    struct node * new_node = create_node(data);
    if(head == NULL){
        head = new_node;
    }else{
        new_node->next = head;
        head = new_node;
    }
    
}
void pop(){
    if(head == NULL){
        printf("The queue is empty.\n");
    }
    else if (head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node * temp1 = NULL;
        struct node * temp2 = head;
        while (temp2->next != NULL)  
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = NULL;
        free(temp2);
    }
}

int top(){
    if(head == NULL){
        printf("The stack is empty.\n");
        return 0;
    }
    struct node * temp = head;
    while (temp->next != NULL)  
    {
        temp = temp->next;
    }
    return temp->data;
}

void print(){
    struct node * temp = head;
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    
}

int main(){ 
    int isContinue = 1;
    int value, node_value;
    while (isContinue == 1)
    {   
        int choice;
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Enqueue.\n 2. Dequeue.\n 3. Display.\n 4. Peek.\n 5. Exit.\nEnter your choice: ");
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
                print();
                break;
            case 4:
                printf("TOP ELEMENT.");
                int num = top();
                if(num != 0){
                    printf("Element at top is %d.\n",num);
                }
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