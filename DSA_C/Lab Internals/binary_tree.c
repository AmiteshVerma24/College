// Write a C program to with respect to Binary Search Trees
// Creation and insertion into a Binary Search Tree
// Display the contents of the tree in inorder, postorder and preorder manner.
// Search for a given element in the BST.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * create_node (int data){
    struct node * new = (struct node *)(malloc(sizeof(struct node)));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node * root = NULL;

void insert_to_bst(int data){
    struct node * new_node = create_node(data);
    if(root == NULL){
        printf("The bst is empty, inserting root node %d.\n",data);
        root = new_node;
        return;
    }
    struct node * current_node = root;
    printf("%d is to be inserted.\n",data);
    while(current_node != NULL){
        if(data <= current_node->data){
            if(current_node->left == NULL){
                current_node->left = new_node;
                return;
            }
            current_node = current_node->left;
        }else{
            if(current_node->right == NULL){
                current_node->right = new_node;
                return;
            }
            current_node = current_node->right;
        }
    }
}

void inorder(struct node * current){
    if(current == NULL){
        return;
    }
    inorder(current->left);
    printf("%d ",current->data);
    inorder(current->right);
}

void preorder(struct node * current){
    if(current == NULL){
        return;
    }
    printf("%d ",current->data);
    preorder(current->left);
    preorder(current->right);
}

void postorder(struct node * current){
    if(current == NULL){
        return;
    }
    postorder(current->left);
    postorder(current->right);
    printf("%d ",current->data);
}

void search(int value){
    if(root == NULL){
        printf("The bst is empty can't search.\n");
    }else{
        struct node * current = root;
        while (current != NULL)
        {
            if(value < current->data){
                current = current->left;
            }
            else if(value > current->data){
                current = current->right;
            }
            else{
                printf("The node with value %d exist in bst.\n",current->data);
                return;
            }
        }
        printf("The value %d does not exist in BST.\n",value);
        
    }
}

int main(){
    insert_to_bst(6);
    insert_to_bst(4);
    insert_to_bst(2);
    insert_to_bst(5);
    insert_to_bst(9);
    insert_to_bst(8);
    insert_to_bst(12);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    search(10);
    search(5);
    search(12);
}
//  6  4  2  5  9  8  12  pre 6 2 4 5 8 9 12 
//  2  5  4  8  12  9  6  post 2 4 5 8 9 12 6 
// 2  4  5  6  8  9  12   in 2 4 5 6 8 9 12 