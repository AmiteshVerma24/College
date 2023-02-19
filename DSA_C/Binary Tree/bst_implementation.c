#include<stdio.h>
#include<stdlib.h>

// Structure to define the node of the BST
struct node {
    int data;
    struct node * left_node;
    struct node * right_node;
};
// Setting up the root of the BST as NULL initially(It is the identity of bst)
struct node * root = NULL;
// Method to create new nodes of the BST
struct node * create_new_node(int value){
    // Creating new node 
    struct node * new_node_address = (struct node *)malloc(sizeof(struct node));
    // Setting up the data and addresses initially
    new_node_address->data = value;
    new_node_address->left_node = NULL;
    new_node_address->right_node = NULL;
    // Returning the new node address from heap memory
    return new_node_address;
}
// Method to check if BST is empty or not
int isEmpty(){
    if(root == NULL){
        return 1;
    }else{
        return 0;
    }
}
// Method to find the minimum value in right subtree of a given node
struct node * minimum_right_subtree(struct node * current){
    // Traversing and finding the least value node
    struct node * current_node = current->right_node;
    while(current_node->left_node != NULL){
        current_node = current_node->left_node;
    }
    return current_node;
}
// Insert method to insert new leafs to the BST
int insertNode(int value){
    // Creating the new node
    struct node * new_node_address = create_new_node(value);
    // Checking if the BST is empty or not
    if (isEmpty() == 1){
        printf("The BST is empty setting up the root node.\n");
        root = new_node_address;
        return 1;
    }
    // For all other cases we have to traverse and then insert
    else{
        // Temporary variable to traverse the BST
        struct node * current_node = root;
        // We will traverse until we find the end of the BST
        while(current_node != NULL){
            // Checking for left subtree
            if (value < current_node->data){
                // Checking the case where we have reached an end so insertion happens
                if(current_node->left_node == NULL){
                    current_node->left_node = new_node_address;
                    return 1;
                }
                // Updating the current node
                current_node = current_node->left_node;
            }
            // Checking the right subtree
            else{
                // Checking the case where we have reached an end so insertion happens
                if (current_node->right_node == NULL){
                    current_node->right_node = new_node_address;
                    return 1;
                }
                // Updating the current node
                current_node = current_node->right_node;
            }
        }
    }
    return 0;
}
// Method to search for an element in the BST
int search_by_value(int value){
    // Checking if the BST is empty or not
    if (isEmpty() == 1){
        printf("The BST is empty can't search for elements.\n");
        return 0;
    }
    // Traversing the BST to find the value
    else{
        // Temporary variable to traverse
        struct node * current_node = root;
        // Traversing
        while(current_node != NULL){
            // Checking on left subtree
            if (value < current_node->data){
                current_node = current_node->left_node;
            }
            // Cheking on right subtree
            else if(value > current_node->data){
                current_node = current_node->right_node;
            }
            // Case where we find the value
            else{
                return 1;
            }
        }
    }
    return 0;
}
// Method to delete a node from the BST
int delete_by_value(int value){
    //  Checking if the BST is empty or not
    if (isEmpty() == 1){
        printf("The BST is empty hence can't delete.\n");
        return 1;
    }
    // For all other conditions
    struct node * current_node = root;
    struct node * parent_node = NULL;
    // Traversing the linked list
    while (current_node != NULL){
        // Left subtree
        if (value < current_node->data){
            parent_node = current_node;
            current_node = current_node->left_node;
        }
        // Right subtree
        else if (value > current_node->data){
            parent_node = current_node;
            current_node = current_node->right_node;
        }
        // When we have found the node to be deleted
        else{
            // Case 1: When the node is a leaf node
            if(current_node->left_node == NULL && current_node->right_node == NULL){
                // If current_node->data < parent_node->data, then delete the left_node of parent_node
                if(current_node->data < parent_node->data){
                    // Update the BST
                    printf("Node to be deleted: %d\n",current_node->data);
                    parent_node->left_node = NULL;
                    // Deallocating memory in the heap
                    free(current_node);
                    return 1;
                }
                // If current_node->data > parent_node->data, then delete the right_node of parent_node
                else{
                    // Update the BST
                    printf("Node to be deleted: %d\n",current_node->data);
                    parent_node->right_node = NULL;
                    // Deallocating the memory in heap
                    free(current_node);
                    return 1;
                }
            }
            // Case 2.1: When the node has one child
            else if(current_node->left_node == NULL){       // When current node has right subtree
                    // When current_node is left node of parent_node
                    if(current_node->data < parent_node->data){
                        // Updating the link
                        parent_node->left_node = current_node->right_node;
                        // Deallocating the memory in heap
                        free(current_node);
                        return 1;
                    }
                    // When current_node is right node of parent_node
                    else{
                        // Updating the link
                        parent_node->right_node = current_node->right_node;
                        // Deallocating the memory in heap
                        free(current_node);
                        return 1;
                    }
            }
            // Case 2.2: When the node has one child
            else if(current_node->right_node == NULL){       // When current node has left subtree
                    // When current_node is left node of parent_node
                    if(current_node->data < parent_node->data){
                        // Updating the link
                        parent_node->left_node = current_node->left_node;
                        // Deallocating the memory in heap
                        free(current_node);
                        return 1;
                    }
                    // When current_node is right node of parent_node
                    else{
                        // Updating the link
                        parent_node->right_node = current_node->left_node;
                        // Deallocating the memory in heap
                        free(current_node);
                        return 1;
                    }
            }
            // Case 3: When the node to be deleted has two child
            else{
                // Find the minimum value node in the right subtree
                struct node * minimum_node_right_subtree = minimum_right_subtree(current_node);
                // Temporary variable to store the value of current node
                int temp = current_node->data;
                // Changing the data of current node
                current_node->data = minimum_node_right_subtree->data;
                // Changing the data of minimum node in right subtree
                minimum_node_right_subtree->data = temp;
                // Now again calling the delete method
                printf("%d\n",minimum_node_right_subtree->data);
                delete_by_value(minimum_node_right_subtree->data);
                return 1;
            }
        }

    }
    return 0;
}

// Method to display the BST in preorder form
void pre_order_form(struct node * root_node){
    // Checking if the BST is empty or not
    if(root_node == NULL){
        return;
    }
    // For cases where the BST is not empty
    printf(" %d ",root_node->data);
    pre_order_form(root_node->left_node);
    pre_order_form(root_node->right_node);
}
// Method to display the BST in postorder form
void post_order_form(struct node * root_node){
    // Checking if the BST is empty or not
    if(root_node == NULL){
        return;
    }
    // For cases where the BST is not empty
    post_order_form(root_node->left_node);
    post_order_form(root_node->right_node);
    printf(" %d ",root_node->data);
}
// Method to display the BST in preorder form
void in_order_form(struct node * root_node){
    // Checking if the BST is empty or not
    if(root_node == NULL){
        return;
    }
    // For cases where the BST is not empty
    in_order_form(root_node->left_node);
    printf(" %d ",root_node->data);
    in_order_form(root_node->right_node);
}
// Main method
int main(){
    int choice, value, isContinue = 1;
    while (isContinue == 1)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("What would you like to do?\n 1. Insert node.\n 2. Delete node.\n 3. Search by value.\n 4. Print in pre order format.\n 5. Print in post order format.\n 6. Print in in order format.\n 7. Exit.\n 8. Enter your choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted:- ");
            scanf("%d",&value);
            insertNode(value);
            break;
        case 2:
            printf("Enter the value to be deleted:- ");
            scanf("%d",&value);
            if(delete_by_value(value) == 1){
                printf("DELETION SUCCESSFUL\n");
            }else{
                printf("%d not deleted\n",value);
            }
            break;
        case 3:
            printf("Enter the value to be searched:- ");
            scanf("%d",&value);
            if(search_by_value(value) == 1){
                printf("%d exists in the BST.\n",value);
            }else{
                printf("%d does not exist in the BST.\n",value);
            }
            break;
        case 4:
            printf("\nBST in preorder form is:-  ");
            pre_order_form(root);
            break;
        case 5:
            printf("\nBST in postorder form is:-  ");
            post_order_form(root);
            break;
        case 6:
            printf("\nBST in inorder form is:-  ");
            in_order_form(root);
            break;
        case 7:
            printf("Exiting the loop.\n");
            isContinue = 0;
        default:
            break;
        }
    }
    
}