// Traversal - access each element of the linked list
// Insertion - adds a new element to the linked list
                // 1. Insert at start
                // 2. Insert at end
                // 3. Insert at nth position
// Deletion - removes the existing elements
                // 1. Delete at start
                // 2. Delete at end
                // 3. Delete at nth position
// Search - find a node in the linked list
#include<stdio.h>

typedef struct node{
    int data;               // To hold the data
    struct node *next;      // To hold the  address of next node
} node;

struct node * head;

void insert(struct node n, struct node * head, int data){
    if (head == NULL){
        head= &n;
        n.data = data;
    }
    n.next = head;
    n.data = data;
    head = &n;
}

void main(){
    node n1,n2;
    n1.data = 10;
    n1.next = NULL;

    insert(n2,head,29);

    printf("%d" , n1.data);
}