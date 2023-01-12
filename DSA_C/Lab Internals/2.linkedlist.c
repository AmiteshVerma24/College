// Online C compiler to run C program online
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};

struct node * head = NULL;

void insertAtHead(struct node* head, struct node new, int num){
    new.next = head;
    head = &new;
}

void display(){
    struct node temp;
    while (temp.next != NULL){
        printf("%d ", temp.data);
        temp = temp.next;
    }
}

void main(){
    struct node n1;
    struct node n2;
    insertAtHead(head,n1,10);
    insertAtHead(head , n2 , 20);
    display();
}