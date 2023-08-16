// Importing the modules
#include<stdio.h>
#include<NUC1xx.h>
#include<Driver/Drv_SYS.h>
#include<Driver/Drv_GPIO.h>
#include<Driver/Drv_ADC.h>
// Main function
int main(void){
    // This is to unlock and use the system control registers
    UNLOCKREG();
    Drv_SYS_Open(48000000);                 // Makes syte to run at 48MHz
    LOCKRED();

    DrvGPIO_Open(E_GPB,11,E_IO_OUTPUT);     // We make the GPIO PIN 11 as output pin

    while(1){                               
        Drv_GPIO_ClearBit(E_GPB,11);        
        Drv_SYS_Delay(100000);
        Drv_GPIO_SetBit(E_GPB,11);
        Drv_SYS_Delay(100000);
    }
}