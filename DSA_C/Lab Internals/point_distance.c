#include<stdio.h>
#include<math.h>
struct point{
    int x;
    int y;
};

float distance(struct point p1, struct point p2){
    return sqrt((p2.y-p1.y)*(p2.y-p1.y) + (p2.x - p1.x)*(p2.x - p1.x));
}

void main(){
    int x, y;
    struct point p1, p2;
    printf("Enter the x coordinate of first point: ");
    scanf(" %d", &x);
    printf("Enter the y coordinate of first point: ");
    scanf(" %d", &y);
    p1.x = x;
    p1.y = y;
    printf("Enter the x coordinate of second point: ");
    scanf(" %d", &x);
    printf("Enter the y coordinate of second point: ");
    scanf(" %d", &y);
    p2.x = x;
    p2.y = y;
    printf("The distance between the points is %f",distance(p1,p2));
}