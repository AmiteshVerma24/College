#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define VERTICES 7

struct graph{
    int vertex;
    bool adjacency_list[VERTICES][VERTICES];
};

struct graph * Create_Graph(){
    struct graph * g = (struct graph *)malloc(sizeof(struct graph));
    for(int i = 0; i < VERTICES ; i++){
        for(int j = 0 ; j < VERTICES ; j++){
            g->adjacency_list[i][j] = false;
        }
    }
    return g;
}
void addEdge(int source, int destination, struct graph * g){
    g->adjacency_list[source][destination] = true;
}
void bfs(struct graph * g, int start_vertex){
    // Declaring the queue
    int queue[VERTICES];
    int front = 0 , rear = 0;
    // Declaring the visited array
    bool visited[VERTICES];
    for(int i = 0 ; i < VERTICES ; i++){
        visited[i] = false;
    }
    // Initially pushing the starting vertex and marking it as visited
    queue[rear++] = start_vertex;
    visited[start_vertex] = true;
    // BFS algo
    while(front < rear){
        int temp = queue[front++];
        printf("%d, ",temp);
        for(int i = 0 ; i < VERTICES ; i++){
            if(g->adjacency_list[temp][i] == true && visited[i] == false){
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}
void print_graph(struct graph * g){
    printf("\nThe graph is:-\n");
    for(int i = 0 ; i < VERTICES ; i++){
        for(int j = 0 ; j < VERTICES ; j++){
            printf("%d ",g->adjacency_list[i][j]);
        }
        printf("\n");
    }
}
int main(){
    struct graph * g = Create_Graph();
    addEdge(0, 1, g);
    addEdge(0, 2, g);
    addEdge(1, 3, g);
    addEdge(2, 3, g);
    addEdge(3, 4, g);
    addEdge(3, 5, g);
    addEdge(2, 6, g);
    print_graph(g);
    bfs(g,0);
    return 0;
}