#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 4

// Method to print the board
void print_board(bool board[][MAX_SIZE]){
    for(int i = 0 ; i < MAX_SIZE ; i++){
        for(int j = 0 ; j < MAX_SIZE ; j++){
            if(board[i][j] == true){
                printf("%d ",1);
            }else{
                printf("%d ",0);
            }
        }
        printf("\n");
    }
}
// Method to check collision
bool isSafe(bool board[MAX_SIZE][MAX_SIZE], int row, int col){
    // Check vertical
    for(int i = 0 ; i < row ; i++){
        if(board[i][col]) return false;
    }
    // Check left diagonal
    int maxLeft = row < col ? row : col;
    for(int i = 1 ; i <= maxLeft ; i++){
        if(board[row-i][col-i]) return false;
    }
    // Check right diagonal
    int maxRight = row < MAX_SIZE - col - 1 ? row : MAX_SIZE - col - 1;
    for(int i = 1 ; i <= maxRight ; i++){
        if(board[row-i][col+i]) return false;
    }
    return true;
}
// Recursive method to find solution
void queens(bool board[MAX_SIZE][MAX_SIZE], int row){
    if(row == MAX_SIZE){
        print_board(board);
        printf("\n");
    }

    for(int col = 0 ; col < MAX_SIZE ; col++){
        if(isSafe(board,row,col)){
            board[row][col] = true;
            queens(board,row+1);
            board[row][col] = false;
        }
    }
    
}

int main(){
    bool board[MAX_SIZE][MAX_SIZE] = {false};
    queens(board,0);
}