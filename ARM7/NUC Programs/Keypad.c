#include<stdio.h>
#include<NUC1xx.h>
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "scankey.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

int32_t main(void){
    // Setup the system
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    // Text for display
    char TEXT0[16] = "This is keypad";
    char TEXT1[16] = "Output:        ";
    // Setup panel
    initial_panel();
    clr_all_panel();
    // Open keypad for taking input
    OpenKeyPad();
    print_lcd(0,TEXT0);
    // Taking input and displaying it on panel
    while(1){
        number = Scankey();
        sprintf(TEXT1+8,%d,number);     // Adding the number at the end of TEXT1 using string buffer
        print_lcd(1,TEXT1);             // Displaying the text on lcd panel
        DrvSYS_Delay(100000);           // Time for which number is displayed
    }
}
