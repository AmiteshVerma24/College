#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define VERTICES 9
int findMinVertex(int distance_array[],bool visited[]){
    int min = 999;
    int min_index;
    for(int i = 0 ; i < VERTICES ; i++){
        if(visited[i] == false && distance_array[i] <= min){
            min = distance_array[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[VERTICES][VERTICES], int start_vertex){
    // Will hold the distance between the starting vertex and all the vertices
    int distance_array[VERTICES];
    // This will mark whether or not a given vertice is visited
    bool visited[VERTICES];
    // Initially all are unvisited and distance is unknown
    for(int i = 0 ; i < VERTICES; i++){
        distance_array[i] = 999;
        visited[i] = false;
    }
    // As the starting vertex distance from it self is zero
    distance_array[start_vertex] = 0;

    for(int i = 0 ; i < VERTICES ; i++){
        int min_index = findMinVertex(distance_array,visited);
        visited[min_index] = true;
        for(int j = 0 ; j < VERTICES ; j++){
            if(visited[j] == false && graph[min_index][j] != 0 && distance_array[min_index] + graph[min_index][j] < distance_array[j]){
                distance_array[j] = distance_array[min_index] + graph[min_index][j];
            }
        }
    }
    for (int i = 0; i < VERTICES; i++)
        printf("%d \t\t\t\t %d\n", i, distance_array[i]);

}

int main()
{
    int graph[VERTICES][VERTICES] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
    return 0;
}