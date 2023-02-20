#include<stdio.h>
#include<stdlib.h>
// Structure to define the node of the linked list
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
// Initializing the head node of the doubly linked list
struct node * head = NULL;
struct node * tail = NULL;
int number_of_nodes = 0;
// Method to check is the doubly linked list is empty or not
int isEmpty(){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}
// Method to create a new node
struct node * create_new_node(int value){
    // New node in heap memory
    struct node * new_node_address = (struct node *)malloc(sizeof(struct node));
    // Setting up the data, prev and next
    new_node_address->data = value;
    new_node_address->prev = NULL;
    new_node_address->next = NULL;
    // Returning the address
    return new_node_address;

}
// Method to insert node at start in the doubly linked list
int insert_at_start(int data){
    // Creating a new node
    struct node * new = create_new_node(data);
    // Cheacking if the linked list is empty or not
    if(isEmpty() == 1){
        printf("Doubly linked list empty!\nInserting the head node.\n");
        head = new;
        tail = new;
        return 1;
    }else{
        printf("Inserting node with value %d at start.\n",data);
        // Linking the newly created node with the linked list
        head->prev = new;
        new->next = head;
        head = new;
        return 1;
    }
    return 0;
}
// Method to insert node at end in the doubly linked list
int insert_at_end(int data){
    // Creating a new node
    struct node * new = create_new_node(data);
    // Cheacking if the linked list is empty or not
    if(isEmpty() == 1){
        printf("Doubly linked list empty!\nInserting the head node.\n");
        head = new;
        tail = new;
        return 1;
    }else{
        printf("Inserting node with value %d at end.\n",data);
        // Linking the newly created node with the linked list
        tail->next = new;
        new->prev = tail;
        tail = new;
        return 1;
    }
    return 0;
}
// Method to insert node after a node with particular value
int insert_after(int data, int value){
    // Creating a new node
    struct node * new = create_new_node(data);
    // Cheacking if the linked list is empty or not
    if(isEmpty() == 1){
        printf("Can't find any node to compare with as DLL is empty.\nInsertion failed.\n");
        return 0;
    }else{
        // Node for traversing
        struct node * temp = head;
        // Traversing to find the required node
        while(temp != NULL){
            // If we found the node
            if(temp->data == data){
                printf("Node found performing insertion operation after node with value %d.",temp->data);
                // Linking the new nodes
                new->prev = temp;           // 5 <- 6      7
                new->next = temp->next;     // 5 <- 6 ->   7
                temp->next->prev = new;     // 5 <- 6 <->  7
                temp->next = new;           // 5 <-> 6 <-> 7
            }
        }
    }
    return 0;
}
// Method to search for an element in DLL
int search_by_value(int value){
    // When the DLL is empty
    if (isEmpty() == 1){
        printf("The DLL is empty can't perform search operation.\n");
        return 0;
    }
    else{
        // Temp variable to traverse the linked list
        struct node * temp = head;
        while (temp != NULL){
            // If we found the element
            if (temp->data == value){
                printf("%d exists in the double linked list.\n",value);
                return 1;
            }
            temp = temp->next;
        }
    }
    printf("%d does not exist in the double linked list.\n",value);
    return 0;
}
// Method to print the DLL
void print_linked_list(){
    // If DLL is empty 
    if (isEmpty() == 1){
        printf("DLL is empty.\n");
        return;
    }
    // Temp variable for traversing the linked list
    struct node * temp = head;
    // Traversing and printing the linked list
    printf("NULL");
    while(temp != NULL){
        printf(" <--> %d",temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}
// Method to print the DLL in reverse
void print_linked_list_reverse(){
    // If DLL is empty 
    if (isEmpty() == 1){
        printf("DLL is empty.\n");
        return;
    }
    // Temp variable for traversing the linked list
    struct node * temp = tail;
    // Traversing and printing the linked list
    printf("NULL");
    while(temp != NULL){
        printf(" <--> %d",temp->data);
        temp = temp->prev;
    }
    printf(" <--> NULL\n");
}
// Method to delete node from the start
int delete_from_start(){
    // Base condition
    if(isEmpty() == 1){
        printf("The double linked list is empty can't delete element.\n");
        return 0;
    }
    // If oly one element
    else if(head == NULL && tail == NULL){
        printf("Node deleted is %d.\n",head->data);
        // Temp variable
        struct node * temp_head = head;
        // Free the memory of the node pointed at head and tail
        free(temp_head);
        // Updating the head and tail as null
        head = NULL;
        tail = NULL;
    }
    else{
        printf("Node deleted is %d.\n",head->data);
        // Temp variable
        struct node * temp_head = head;
        // Making head point to next
        head = head->next;
        head->prev = NULL;
        // Free the memory of the node pointed at head
        free(temp_head);
        return 1;
    }
    return 0;
}
// Method to delete element by value
int delete_by_value(value){
    // Base condition
    if (isEmpty() == 1){
        printf("The DLL is empty can't perform delete operation.\n");
        return 0;
    }
    // If only one element and that is to be deleted
    else if(head->data == value && head == tail){
        free(head);
        head = NULL;
        tail = NULL;
    }
    // Search and delete
    else{
        // Temp for traversing the list
        struct node * temp = head;
        while(temp != NULL){
            if(temp->data == value){
                printf("Node deleted is %d.\n",value);
                // Linking the previous and next of the found node
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return 1;
            }
            temp = temp->next;
        }
    }
    printf("Node %d does not exist in DLL hence can't be deleted.\n",value);
    return 0;

}
// Method to delete node from the end
int delete_from_end(){
    // Base condition
    if(isEmpty() == 1){
        printf("The double linked list is empty can't delete element.\n");
        return 0;
    }
    // If only one element
    else if(head == NULL && tail == NULL){
        printf("Node deleted is %d.\n",tail->data);
        // Temp variable
        struct node * temp_head = head;
        // Free the memory of the node pointed at head and tail
        free(temp_head);
        // Updating the head and tail as null
        head = NULL;
        tail = NULL;
    }
    else{
        printf("Node deleted is %d.\n",tail->data);
        // Temp variable
        struct node * temp_tail = tail;
        // Making tail point to prev
        tail = tail->prev;
        tail->next = NULL;
        // Free the memory of the node pointed at head
        free(temp_tail);
        return 1;
    }
    return 0;
}

int main(){
    // Variables for menu driven program
    int isContinue = 1;
    int value, node_value;
    while (isContinue == 1)
    {   
        int choice;
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Insert at beginning.\n 2. Insert after a given value.\n 3. Insert at the end.\n 4. Delete at the beginning.\n 5. Delete node by its value.\n 6. Delete at the end.\n 7. Print the double linked list.\n 8. Print the double linked list in reverse order.\n 9. Search element in linked list.\n 10. Exit.\nEnter your choice: ");
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
                delete_from_start();
                break;
            case 5:
                printf("Enter the value of node to be deleted: ");
                scanf("%d",&value);
                delete_by_value(value);
                break;
            case 6:
                delete_from_end();
                break;
            case 7:
                print_linked_list();
                break;
            case 8:
                print_linked_list_reverse();
                break;
            case 9:
                printf("Enter the value of node to be searched: ");
                scanf("%d",&value);
                search_by_value(value);
                break;
            case 10:
                isContinue = 0;
                printf("EXITED THE LOOP!\n");
                break;
            default:
                break;
        }
    }  
}