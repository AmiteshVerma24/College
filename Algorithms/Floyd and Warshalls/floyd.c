#include<stdio.h>
#include<stdbool.h>
#define vertices 4
#define INF 9999

void printMatrix(int matrix[][vertices]){
    for(int i = 0 ; i < vertices ; i++){
        for(int j = 0 ; j < vertices ; j++){
            if(matrix[i][j] == INF || matrix[i][j] == 0) printf("%s  ", "INF");
            else printf("%d    ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void warshalls(int graph[][vertices] ){
    int matrix[vertices][vertices];
    // Copy content intp matrix for computation
    for(int i = 0 ; i < vertices ; i++){
        for(int j = 0 ; j < vertices ; j++){
            matrix[i][j] = graph[i][j];
        }
    }
    // Warshalls algo
    for(int k = 0 ; k < vertices ; k++){
        for(int i = 0 ; i < vertices ; i++){
            for(int j = 0 ; j < vertices ; j++){
                if((matrix[i][k] + matrix[k][j] < matrix[i][j])){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    printMatrix(matrix);
}

int main(){
    int graph[vertices][vertices] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
    printMatrix(graph);
    warshalls(graph);
}