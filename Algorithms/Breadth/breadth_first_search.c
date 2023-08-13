#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define VERTICES 7

struct graph{
    bool adjacency_list[VERTICES][VERTICES];
    int number_of_vertices;
};

struct graph * Create_Graph(){
    struct graph * graph = (struct graph *)(malloc(sizeof(struct graph)));
    graph->number_of_vertices = VERTICES;
    for(int i = 0 ; i < VERTICES ; i++){
        for(int j = 0 ; j < VERTICES ; j++){
            graph->adjacency_list[i][j] = false;
        }
    }
    return graph;
}

void addEdge(int source, int destination, struct graph * g){
    g->adjacency_list[source][destination] = true;
}

void print_graph(struct graph * g){
    printf("\nThe graph is:-\n");
    for(int i = 0 ; i < g->number_of_vertices ; i++){
        for(int j = 0 ; j < g->number_of_vertices ; j++){
            printf("%d ",g->adjacency_list[i][j]);
        }
        printf("\n");
    }
}

void breadth_first_search(struct graph * g, int start_vertex){
    // Queue
    int queue[VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = start_vertex;
    // Visited list
    bool visited_list[VERTICES];
    for(int i = 0 ; i < VERTICES ; i++){
        visited_list[i] = false;
    }
    // Marking the starting vertex as visited
    visited_list[start_vertex] = true;
    // Temp variable
    int visit_node;
    printf("\nBREADTH FIRST SEARCH:-\n");
    while(front < rear){
        visit_node = queue[front++];
        printf("%d ",visit_node);
        for(int i = 0 ; i < g->number_of_vertices ; i++){
            if(g->adjacency_list[visit_node][i] == true && visited_list[i] == false){
                queue[rear++] = i;
                visited_list[i] = true;
            }
        }
    }
}



int main(){
    struct graph * g = Create_Graph();
    /*  0 1 1 0 0 0 0 
        0 0 0 1 0 0 0 
        0 0 0 1 0 0 1 
        0 0 0 0 1 1 0 
        0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 */
    addEdge(0, 1, g);
    addEdge(0, 2, g);
    addEdge(1, 3, g);
    addEdge(2, 3, g);
    addEdge(3, 4, g);
    addEdge(3, 5, g);
    addEdge(2, 6, g);
    print_graph(g);
    breadth_first_search(g,0);
    return 0;
}

