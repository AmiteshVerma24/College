#include<LPC214x.h>

void delay(int num){
    int i = 0;
    for(i = 0 ; i < num ; i++);
}
int main(){
    IODIR0 = 0x00000001;
    while(1){
        IOSET0 = 0x0000001;
        delay(500);
        IOCLR0 = 0x00000001;
        delay(500);
    }
}