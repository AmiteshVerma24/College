#include<LPC214x.h>
void wait(){
    TOTCR = 1;
    while(!(TOTC == TOMR0));
}
int main(void){
    TOMR0 = 0x00000100;
    TOMCR = 0x2
    while(1){
        IODIR0 = 0xFFFFFFFF;
        IOPIN0 =~ IOPIN0;
        wait();S
    }
}