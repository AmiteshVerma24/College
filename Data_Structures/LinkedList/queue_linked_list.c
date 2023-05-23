#include<stdio.h>
#include<stdlib.h>

// Creating the structure of node
struct node {
    // Data
    int data;
    // Address of next node
    struct node * next;
};
// Pointer to head node of the linked list
struct node * head = NULL;
// Variable to keep track of number of nodes
int number_of_nodes = 0;
// Method to create a new node and return it
struct node * create_node(int data){
    // Creating a new node in heap memory using malloc
    struct node * new_node_address = (struct node *)(malloc(sizeof(struct node)));
    // Assigning the data to new node
    new_node_address->data = data;
    // Returning the address of the newly created node
    return new_node_address;
}
// Inserting a new node at start
void insert_at_start(int data){
    // if the Linked List is empty -> Update the head node
    if(head == NULL){
        // Creating the new node
        struct node * temp = create_node(data);
        // Assigning the next address as null because this node is to be inserted at end
        temp->next = NULL;
        // As the linked list was empty we need to update head
        head = temp;
    }
    // else insert the node at start
    else{
        // Creating the new node to be inserted
        struct node * new_node = create_node(data);
        // Making the next of the new node to point to the head of the current linked list so as to update the 
        new_node->next = head;
        // Updating the head as the new node is inserted at the start
        head = new_node;
    }
    // Incrementing number of nodes
    number_of_nodes++;
}

// Deleting the node at end
void delete_at_end(){
    // If the Linked List is empty -> can't delete element
    if(head == NULL){
        printf("Linked list empty so no element can be deleted!\n");
    }
    // Else if the linked list has only one element and that has to be deleted
    else if(head->next == NULL){
        printf("Element deleted:- %d\nUpdated head to null as the deleted element was head\n",head->data);
        // Free memory of head
        free(head);
        // Again making head to point to NULL
        head =  NULL;
    }
    // Else travering to the end of linked list and deleting the node
    else{
        // Temporary node to traverse the linked list
        struct node * first = head;
        struct node * second = NULL;
        // Traversing to the end of linked list
        while (first->next != NULL){
            second = first;
            first = first->next;
        }
        printf("Element deleted:- %d\n",first->data);
        second->next = NULL;
        free(first);
        number_of_nodes--;
        return;
    }
}
// Printing the linked list
void print_linked_list(){
    // Checking if the linked list is empty or not
    if(head == NULL){
        printf("The linked list is empty!\n");
        return;
    }
    // Traversing and printing the elements of linked list
    struct node * temp = head;
    while(temp != NULL){
        printf("%d --> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search for an element by value
int search_by_value(int value){
    // If linked list is empty
    if(head == NULL){
        printf("Linked list is empty can't traverse\n");
        return 0;
    }
    // Else searching for an element
    else{
        // Temporary variable which will be used to traverse
        struct node * temp = head;
        // Traversing the linked list
        while (temp != NULL)
        {   
            if(temp->data == value){
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0; 
}
// Main function
int main(){
    // Variables for menu driven program
    int isContinue = 1;
    int value, node_value;
    while (isContinue == 1)
    {   
        int choice;
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Search\n 5. Is Empty\n 6. Print queue\n 7. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                insert_at_start(value);
                break;
            case 2:
                delete_at_end();
                break;
            case 3:
                printf("Element at top of queue is:- %d", head->data);
                break;
            case 4:
                printf("Enter the value to be searched:- ");
                scanf("%d",&value);
                search_by_value(value);
                break;
            case 5:
                if (head == NULL){
                    printf("The queueis empty.\n");
                }else{
                    printf("The queue is not empty.\n");
                }
                break;
            case 6:
                print_linked_list();
                break;
            case 7:
                isContinue = 0;
                break;
            default:
                break;
        }
    }  
}