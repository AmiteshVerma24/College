#include<stdio.h>
#include<NUC1xx.h>
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "Driver/DrvUART.h"

void init_led(){
    // We are selecting Port A(E_GPA) and pin 12,13 and 14 for our Red, Green and Blue LED.
    DrvGPIO_Open(E_GPA, 12, E_OUTPUT);
    DrvGPIO_Open(E_GPA, 13, E_OUTPUT);
    DrvGPIO_Open(E_GPA, 14, E_OUTPUT);
    /*
        NOTE:
        ClrBit: LED OFF(low voltage)
        SetBit: LED ON(high voltage)
    */
    // Initially we are closing all the leds
    DrvGPIO_ClrBit(E_GPA, 12);
    DrvGPIO_ClrBit(E_GPA, 13);
    DrvGPIO_ClrBit(E_GPA, 14);
}

int main(void){
    // Configuring the system
    UNLOCKREG();
    DrvSYS_Open(48000000);          // Here 48000000 is the system clock frequency
    LOCKREG();
    // Initialing the led's
    init_led();
    // Altering the flickring of led
    while(1){
        /*
            DrvSYS_Delay(100000(let us call this value as "VAL"));
            Here delay in sec is calculated as follows:
            DELAY(in sec) = VAL/System Clock Frequency(here 48000000)
        
        */
        // R-1 G-0 B-0
        DrvGPIO_SetBit(E_GPA, 12);
        DrvGPIO_ClrBit(E_GPA, 13);
        DrvGPIO_ClrBit(E_GPA, 14);
        DrvSYS_Delay(50000);
        // R-0 G-1 B-0
        DrvGPIO_ClrBit(E_GPA, 12);
        DrvGPIO_SetBit(E_GPA, 13);
        DrvGPIO_ClrBit(E_GPA, 14);
        DrvSYS_Delay(50000);
        // R-0 G-0 B-1
        DrvGPIO_ClrBit(E_GPA, 12);
        DrvGPIO_ClrBit(E_GPA, 13);
        DrvGPIO_SetBit(E_GPA, 14);
        DrvSYS_Delay(50000);
        // R-1 G-1 B-1
        DrvGPIO_SetBit(E_GPA, 12);
        DrvGPIO_SetBit(E_GPA, 13);
        DrvGPIO_SetBit(E_GPA, 14);
        DrvSYS_Delay(50000);
        // R-0 G-0 B-0
        DrvGPIO_ClrBit(E_GPA, 12);
        DrvGPIO_ClrBit(E_GPA, 13);
        DrvGPIO_ClrBit(E_GPA, 14);
        DrvSYS_Delay(100000);
    }
}