#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define VERTICES 5

struct graph{
    int vertex;
    bool adjacency_list[VERTICES][VERTICES];
};

struct graph * Create_Graph(int vertex){
    struct graph * g = (struct graph *)malloc(sizeof(struct graph));
    g->vertex = vertex;
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
    int queue[VERTICES];
    int front = 0 , rear = 0;
    bool visited[VERTICES];
    for(int i = 0 ; i < VERTICES ; i++){
        visited[i] = false;
    }
    queue[rear++] = start_vertex;
    visited[start_vertex] = true;
    while(rear != front){
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
int main(){
    struct graph * g = Create_Graph(4);
    addEdge(0, 1, g);
    addEdge(0, 2, g);
    addEdge(1, 2, g);
    addEdge(2, 0, g);
    addEdge(2, 3, g);
    addEdge(3, 3, g);
    bfs(g,2);
    return 0;
}