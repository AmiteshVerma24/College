#include<stdio.h>
#include<stdlib.h>

int maximum(int a, int b) { return (a > b) ? a : b; }

int knapsack(int num, int profit[], int weight[], int max){
    int mat[num+1][max+1];
    for(int i = 0 ; i <= num ; i++){
        for(int j = 0 ; j <= max ; j++){
            if(i == 0 || j == 0){
                mat[i][j] = 0;
            }
            else if(weight[i-1] <= j){
                mat[i][j] = maximum(mat[i-1][j], mat[i-1][j-weight[i-1]] + profit[i-1]);
            }
            else{
                mat[i][j] = mat[i-1][j];
            }
        }
    }
    for(int i = 0 ; i < num+1 ; i++){
        for(int j = 0 ; j < max+1 ; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return mat[num][max];
}
int main(){
    int num = 4;
    int max = 8;
    int profit[] = {2,3,4,1};
    int weight[] = {3,4,5,6};
    printf("%d",knapsack(num,profit,weight,max));

}