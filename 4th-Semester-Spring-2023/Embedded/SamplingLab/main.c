//******************************************************************************

//  MSP430FR235x Demo - SAC-L3, DAC Buffer Mode

//

//  Description: Configure SAC-L3 for DAC Buffer Mode. Use the 12 bit DAC to

//  output positive ramp. The OA is set in buffer mode to improve DAC output

//  drive strength. Internal 2.5V reference is selected as DAC reference.

//  Observe the output of OA0O pin with oscilloscope.

//  ACLK = n/a, MCLK = SMCLK = default DCODIV ~1MHz.

//

//                MSP430FR235x

//             -------------------

//         /|\|                   |

//          | |                   |

//          --|RST     DAC12->OA0O|--> oscilloscope

//            |                   |

//            |                   |

//            |                   |

//            |                   |

//            |                   |

//

//   Darren Lu

//   Texas Instruments Inc.

//   Oct. 2016

//   Built with IAR Embedded Workbench v6.50 & Code Composer Studio v6.2

//******************************************************************************

#include <msp430.h>




void gpioInit();

void adcInit();

void sacInit();

void timerInit();







unsigned int DAC_data=0;

unsigned int ADC_Result = 0;




int main(void)

{

  WDTCTL = WDTPW + WDTHOLD;                 // Stop watch dog timer




  gpioInit();




  PM5CTL0 &= ~LOCKLPM5;                     // Disable the GPIO power-on default high-impedance mode

                                            // to activate previously configured port settings




  sacInit();

  timerInit();




  adcInit();







  while(1){

      ADCCTL0 |= ADCENC | ADCSC;                           // Sampling and conversion start

      __bis_SR_register(LPM0_bits | GIE);                  // LPM0, ADC_ISR will force exit

      __no_operation();                                    // For debug only

      DAC_data = ADC_Result;

      __delay_cycles(10);

  }

}







void gpioInit()

{

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state

    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P1SEL0 |= BIT1;                           // Select P1.1 as OA0O function

    P1SEL1 |= BIT1;                           // OA is used as buffer for DAC




    // Configure ADC A5 pin

    P1SEL0 |= BIT5;

    P1SEL1 |= BIT5;

}




void sacInit()

{

    // Configure reference module

    PMMCTL0_H = PMMPW_H;                      // Unlock the PMM registers

    PMMCTL2 = INTREFEN | REFVSEL_2;           // Enable internal 2.5V reference

    while(!(PMMCTL2 & REFGENRDY));            // Poll till internal reference settles




    SAC0DAC = DACSREF_1 + DACLSEL_2 + DACIE;  // Select int Vref as DAC reference

    SAC0DAT = DAC_data;                       // Initial DAC data

    SAC0DAC |= DACEN;                         // Enable DAC




    SAC0OA = NMUXEN + PMUXEN + PSEL_1 + NSEL_1;//Select positive and negative pin input

    SAC0OA |= OAPM_0;                            // Select low speed and low power mode

    SAC0PGA = MSEL_1;                          // Set OA as buffer mode

    SAC0OA |= SACEN + OAEN;                    // Enable SAC and OA

}




void timerInit()

{

    // Use TB2.1 as DAC hardware trigger

    TB2CCR0 = 100-1;                           // PWM Period/2

    TB2CCTL1 = OUTMOD_6;                       // TBCCR1 toggle/set

    TB2CCR1 = 50;                              // TBCCR1 PWM duty cycle

    TB2CTL = TBSSEL__SMCLK | MC_1 | TBCLR;     // SMCLK, up mode, clear TBR

}




void adcInit()

{

    // Configure ADC12

    ADCCTL0 |= ADCSHT_2 | ADCON;                             // ADCON, S&H=16 ADC clks

    ADCCTL1 |= ADCSHP;                                       // ADCCLK = MODOSC; sampling timer

    ADCCTL2 &= ~ADCRES;                                      // clear ADCRES in ADCCTL

    ADCCTL2 |= ADCRES_2;                                     // 12-bit conversion results

    ADCMCTL0 |= ADCINCH_5;                                   // A5 ADC input select; Vref=AVCC

    ADCIE |= ADCIE0;                                         // Enable ADC conv complete interrupt

}










#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)

#pragma vector = SAC0_SAC2_VECTOR

__interrupt void SAC0_ISR(void)

#elif defined(__GNUC__)

void __attribute__ ((interrupt(SAC0_SAC2_VECTOR))) SAC0_ISR (void)

#else

#error Compiler not supported!

#endif

{

  switch(__even_in_range(SAC0IV,SACIV_4))

  {

    case SACIV_0: break;

    case SACIV_2: break;

    case SACIV_4:

        //DAC_data++;

        DAC_data &= 0xFFF;

        SAC0DAT = DAC_data;                 // DAC12 output positive ramp

        break;

    default: break;

  }

}










// ADC interrupt service routine

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)

#pragma vector=ADC_VECTOR

__interrupt void ADC_ISR(void)

#elif defined(__GNUC__)

void __attribute__ ((interrupt(ADC_VECTOR))) ADC_ISR (void)

#else

#error Compiler not supported!

#endif

{

    switch(__even_in_range(ADCIV,ADCIV_ADCIFG))

    {

        case ADCIV_NONE:

            break;

        case ADCIV_ADCOVIFG:

            break;

        case ADCIV_ADCTOVIFG:

            break;

        case ADCIV_ADCHIIFG:

            break;

        case ADCIV_ADCLOIFG:

            break;

        case ADCIV_ADCINIFG:

            break;

        case ADCIV_ADCIFG:

            ADC_Result = ADCMEM0;

            P1OUT ^= BIT0;

            __bic_SR_register_on_exit(LPM0_bits);            // Clear CPUOFF bit from LPM0

            break;

        default:

            break;

    }

}