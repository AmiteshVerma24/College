#include<stdio.h>
#include<stdlib.h>

struct item{
    int weight;
    int value;
};

void knapsack(int * max_weight, struct item arr[],int length){
    struct item sub_set[length]; 
    // Sorting the items based on value/weight ratio
    for(int i = 0 ; i < length ; i++){
        for(int j = 0 ; j < length - i - 1 ; j++){
            if((arr[j].value/arr[j].weight) < (arr[j+1].value/arr[j+1].weight)){
                int temp_value = arr[j].value;
                int temp_weight = arr[j].weight;

                arr[j].weight = arr[j+1].weight;
                arr[j].value = arr[j+1].value;

                arr[j+1].weight = temp_weight;
                arr[j+1].value = temp_value;
            }
        }
    }
    // Knapsack algorithm
    for(int i = 0; i < length ; i++){
        if(*max_weight - arr[i].weight > 0){
            *max_weight -= arr[i].weight;
            printf("Value: %d, Weight: %d Added\n",arr[i].value,arr[i].weight);
            sub_set[i].value = arr[i].value;
            sub_set[i].weight = arr[i].weight;
        }else{
            float fraction = *max_weight/(float)arr[i].weight;
            *max_weight -= fraction * arr[i].weight;
            printf("Value: %f, Weight: %d Added\n",arr[i].value*fraction,arr[i].weight);
            sub_set[i].value = arr[i].value*fraction;
            sub_set[i].weight = arr[i].weight;
            break;
        }
    }
}
int main(){
    int weight = 50;
    int * weight_ptr = &weight;
    struct item item_array[3];
    item_array[0].value = 60;
    item_array[0].weight = 10;
    item_array[2].value = 100;
    item_array[2].weight = 20;
    item_array[1].value = 120;
    item_array[1].weight = 30;
    knapsack(weight_ptr,item_array,3);
}