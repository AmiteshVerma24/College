#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stack[100];
int top = -1;

void push(int num){
    top++;
    stack[top] = num;
}
int pop(){
    int temp = stack[top];
    top--;
    return temp;
}
int main(){
    char exp[100];
    char *e;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    int n1,n2,n3;
    e = exp;
    while(*e != '\0'){
        if(isdigit(*e)){
            push(*e-48);
        }
        else{
            n1 = pop();
            n2 = pop();
            switch (*e){
            case '+':
                
                n3 = n1+n2;
                break;
            case '-':

                n3 = n2-n1;
                break;
            case '*':
            
                n3 = n1*n2;
                break;
            case '/':

                n3 = n2/n1;
                break;
            default:
                break;
            }
            push(n3);
        }
        e++;
    }
    printf("%d",pop());
}
