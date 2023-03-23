// Write C program to perform the following operations with respect to Doubly Linked List

// Insertion at the front
// Delete based on position
// Print the contents in the order of insertion
// Print the content in the reverse order of insertion
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
int no_of_nodes = 0;
struct node * head = NULL;
struct node * tail = NULL;

struct node * create_node(int data){
    struct node * new_node = (struct node *)(malloc(sizeof(struct node)));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data;
    return new_node;
}
void insert_at_front(int data){
    struct node * new_node = create_node(data);
    printf("%d is inserted at head.\n",data);
    if(head == NULL && tail == NULL){
        head = new_node;
        tail = new_node;
    }else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    no_of_nodes++;
    printf("No of nodes is %d\n",no_of_nodes);
}
void delete_by_position(int pos){
    if(pos > no_of_nodes){
        printf("Node does not exist\n");
        return;
    }
    struct node * temp = head;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("To be deleted: %d\n",temp->data);
}
void print_in_order(){
    struct node * temp = head;
    printf("NULL <--> ");
    while(temp != NULL){
        printf("%d <--> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void print_in_reverse(){
    struct node * temp = tail;
    printf("NULL <--> ");
    while(temp != NULL){
        printf("%d <--> ",temp->data);
        temp = temp->prev;
    }
    printf("NULL");
}

int main(){ 
    int isContinue = 1;
    int value, node_value, pos;
    while (isContinue == 1)
    {   
        int choice;
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Insert at head.\n 2. Delete by position.\n 3. Display in order.\n 4. Display in reverse order.\n 5. Exit.\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                insert_at_front(value);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d",&pos);
                delete_by_position(pos);
                break;
            case 3:
                print_in_order();
                break;
            case 4:
                print_in_reverse();
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

