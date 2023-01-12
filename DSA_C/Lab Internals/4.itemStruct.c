#include<stdio.h>
#include<math.h>

struct item{
    char name[50];
    int price;
    int code;
};

void main(){
    int num,price,code;
    char name[50];
    printf("Enter the number of items ");
    scanf("%d",&num);
    struct item itemList[num];
    for (int i = 0 ; i < num ; i++){
        printf("Enter details of %d item\n", i+1);
        printf("Enter name: ");
        scanf("%s",name);
        printf("Enter price: ");
        scanf("%d",&price);
        printf("Enter code: ");
        scanf("%d",&code);
        strcpy(itemList[i].name,name);
        itemList[i].price = price;
        itemList[i].code = code;
    }
    printf("ITEMS WITH PRICE GREATER THAN 500 ARE");
    for (int i = 0; i < num; i++)
    {
        if(itemList[i].price >= 500){
            printf("%s \n", itemList->name);
        }
    }
    
}