#include <msp430fr2355.h>
#include <stdbool.h>
#include <string.h>

// half a second at 1Mhz
#define BLINK_CYCLES 2000000L

int main(void) 
{
    // stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;
    
    // allow changes to port registers
    PM5CTL0 &= ~LOCKLPM5;

    P1DIR |= BIT0;  // set pin 1.0 as output
    P1OUT &= ~BIT0; // clear pin 1.0 (make it low)

    P4DIR |= BIT0; // set pin 4.6 as output
    P4OUT |= BIT6; // set pin 4.6 (make it high)

    while (true)
    {
        __delay_cycles(BLINK_CYCLES);
        P1OUT ^= BIT0; // toggle pin 1.0
        P4OUT ^= BIT6; // toggle pin 4.6
    }



}
