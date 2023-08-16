#include <lpc214x.h>
void delay() {
    int i;
    for (i = 0; i < 1000000; i++);   // Delay loop
}
int main() {
    char name[] = "My name is Amitesh"; // String to be transmitted
    int z;

    PINSEL0 = (1 << 0) | (1 << 2); // Configure pins P0.0 (TXD0) and P0.2 (RXD0) for UART0
    U0LCR = 0x3;   // Disable DLAB and set word length to 8 bits meaning 8 bits can be transmitted or recieved

    for(z = 0; z < 9; z++) {
        U0THR = name[z]; // Send a character from the string and display(THR:Transmit Holding Register)
        while(!U0LSR); // Wait until the transmit buffer is empty(LSR:Line Status Register)
        delay(); // Add a delay
    }
    while(1) ; // Infinite loop to keep the program running
}
