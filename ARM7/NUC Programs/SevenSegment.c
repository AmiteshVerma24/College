#include<stdio.h>
#include<NUC1xx.h>
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "Seven_Segment.h"

void show_seven_segment(int16_t num){

    int8_t digit;
    digit = num / 1000;
    close_seven_segment();
    show_seven_segment(3,digit);
    DrvSYS_Delay(5000);

    num = num - digit * 1000;
    digit = num / 100;
    close_seven_segment();
    show_seven_segment(2,digit);
    DrvSYS_Delay(5000);

    num = num - digit * 100;
    digit = num / 10;
    close_seven_segment();
    show_seven_segment(1,digit);
    DrvSYS_Delay(5000);

    num = num - digit * 10;
    digit = num;
    close_seven_segment();
    show_seven_segment(0,digit);
    DrvSYS_Delay(5000);

}

int32_t main(void){
    // Preparing the system
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    // Calling the seven segment 
    int32_t i = 0;
    while(i < 10000){
        show_seven_segment(i);
        DrvSYS_Delay(50000);
        i++;
    }
}