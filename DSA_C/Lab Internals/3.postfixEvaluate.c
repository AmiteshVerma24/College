#include<stdio.h>
#include<stdlib.h>
#define max 6

struct stack{
    int arr[max];
    int top;
};

struct stack s;

void push(int num){
    if(s.top >= max-1){
        exit(0);
    }
    s.arr[++s.top] = num;
}

int pop(){
    if (s.top < 0){
        exit(0);
    }
    return s.arr[s.top--];
}

void display(){
    for (int i = 0; i < s.top+1; i++){
        printf(" %d ",s.arr[i]);
    }
    printf("\n");
}

int isEmpty(){
    if (s.top < 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    s.top = -1;
    char exp[] = "23+";

    for (int i = 0; i < 3; i++){
        if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/'){
            int op2 = pop();
            int op1 = pop();
            int result;
            if(exp[i] == '*'){
                result = op2 * op1;
            }else if(exp[i] == '+'){
                result = op2 + op1;
            }else if(exp[i] == '-'){
                result = op2 - op1;
            }else{
                result = op2 / op1;
            }
            push(result);
        }else{
            push(exp[i]);
        }
    }
    printf("%d ", top());
    
}
