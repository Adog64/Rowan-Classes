#include <msp430.h> //115200, No jumper change

char result[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!'};

void uart_init(void);
void port_init();

void main(void)
{

    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;

    port_init();
    int m=0;
    uart_init();
    __delay_cycles(5);                // Wait for ADC Ref to settle
    int acount = 0;
    while(1){
      if(m == 0) 
      {
        __delay_cycles(200);
        // then conver the Fahrenheit integer to an ASCII char array
        //  while(result[acount]!='\0')
        //{
        while((UCA1IFG & UCTXIFG)==0);                  //Wait Unitl the UART transmitter is ready //UCTXIFG
          UCA1TXBUF = result[acount] ;                   //Transmit the received data.
        acount = (acount < 13) ? acount + 1 : 0;
    }//while
  }//main
}

 

 

void uart_init(void){
    // Configure UART
    UCA1CTLW0 |= UCSWRST;

    /*UCA1CTLW0 |= UCSSEL__ACLK;//UCSSEL__SMCLK;
    UCA1BRW = 3;//8;                             // 9600
    UCA1MCTLW = 0X92;//0xD600;*/
    UCA1CTLW0 |= UCSSEL__SMCLK;
    UCA1BRW = 8;                             // 115200
    UCA1MCTLW = 0xD600;
    UCA1CTLW0 &= ~UCSWRST;                    // Initialize eUSCI
    UCA1IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt ??
}

 

void port_init(){
    P1DIR |= BIT0;
    P1OUT |= BIT0;
    P4SEL0 |= BIT2 | BIT3;                    // set 2-UART pin as second function
    P4SEL1 &= ~BIT2;                    // set 2-UART pin as second function
    P4SEL1 &= ~ BIT3;                    // set 2-UART pin as second function

}

 