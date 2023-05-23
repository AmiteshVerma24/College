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
// Inserting a new node just after a given node
void insert_after(int data, int node_value){
    // Here node_value refers to the value of node after which the new node is to be entered
    // Creating the new node to be inserted
    struct node * new_node = create_node(data);
    // Traversing the linked list to find the node
    struct node * temp = head;
    while(temp != NULL){
        if(temp->data == node_value){
            // Now this insertion can be broken down into
            // 1. Linking the new_node with the next node of the searched node
            new_node->next = temp->next;
            // 2. Updating the next of the searched node to the newly created node
            temp->next = new_node;
            // Incrementing number of nodes
            number_of_nodes++;
            return;
        }
        temp = temp->next;
    }
    printf("The node after which new node was to inserted not found!\n");
}

// Inserting a new node at end
void insert_at_end(int data){
    // if the Linked List is empty -> Update the head node
    if(head == NULL){
        // Creating the new node
        struct node * temp = create_node(data);
        // Assigning the next address as null because this node is to be inserted at end
        temp->next = NULL;
        // As the linked list was empty we need to update head
        head = temp;
    }
    // else traverse to end of linked list and insert the new node
    else{
        // Temp variable to traverse the end of linked list
        struct node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        // Creating new node to insert
        struct node * new_node = create_node(data);
        // Assigning the next address as null because this node is to be inserted at end
        new_node->next = NULL;
        // Connecting the tail of the linked list with the new node
        temp->next = new_node;
    }
    // Incrementing number of nodes
    number_of_nodes++;
}
// Deleting the node at start
void delete_at_beginning(){
    // If the Linked List is empty -> can't delete element
    if(head == NULL){
        printf("Linked list empty so no element can be deleted!\n");
    }
    // Else if the linked list has only one elemet
    else if(head->next == NULL){
        printf("Element deleted:- %d\nUpdated head to null as the deleted element was head\n",head->data);
        // Free memory of head
        free(head);
        // Again making head to point to NULL
        head =  NULL;
    }
    // Else deleting the element at starting
    else{
        // Pointer to point to the head
        struct node * temp = head;
        // Updating the head
        head = head->next;
        // Deallocating the memory for deleted element
        free(temp);
    }
    // Decrementing the count
    number_of_nodes--;
}
// Deleting a searched node
void delete_by_value(int data){
    // If the Linked List is empty -> can't delete element
    if(head == NULL){
        printf("Linked list empty so no element can be deleted!\n");
    }
    // Else if the linked list has only one elemet
    else if(head->data == data){
        printf("Element deleted:- %d\nUpdated head to null as the deleted element was head\n",head->data);
        // Free memory of head
        free(head);
        // Again making head to point to NULL
        head =  NULL;
    }
    // Else traversing to find the element and delete
    else{
        // Temporary variable which will be used to traverse and here we will need two of them
        struct node * first = head;
        struct node * second = NULL;
        // Traversing the linked list
        while (first->next != NULL)
        {   
            if(first->data == data){
                // Linking the node previous to the node to be deleted with the next of the node to be deleted
                printf("Element found hence %d will be deleted\n",first->data);
                second->next = first->next;
                free(first);
                number_of_nodes--;
                return;
            }
            second = first;
            first = first->next;
        }
        printf("Element does not exist in linked list hence can't be deleted\n");
    }
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
        printf("What would you like to do?\n 1. Insert at beginning.\n 2. Insert after a given value.\n 3. Insert at the end.\n 4. Delete at the beginning.\n 5. Delete node by its value.\n 6. Delete at the end.\n 7. Print the linked list.\n 8. Search element in linked list.\n 9. Exit.\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                insert_at_start(value);
                break;
            case 2:
                printf("Enter the data of node after which new node is to be inserted:- ");
                scanf("%d",&node_value);
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                insert_after(value,node_value);
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                insert_at_end(value);
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                printf("Enter the value of node to be deleted: ");
                scanf("%d",&value);
                delete_by_value(value);
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                print_linked_list();
                break;
            case 8:
                printf("Enter the value of node to be searched: ");
                scanf("%d",&value);
                if(search_by_value(value) == 1){
                    printf("Element %d exits in linked list.\n",value);
                }else{
                    printf("Element %d does not exits in linked list.\n",value);
                }
                break;
            case 9:
                isContinue = 0;
                printf("EXITED THE LOOP!\n");
                break;
            default:
                break;
        }
    }  
}