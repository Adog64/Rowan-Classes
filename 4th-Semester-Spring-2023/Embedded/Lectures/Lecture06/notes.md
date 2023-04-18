# Intro to Embedded Systems Lecture Notes: February 2nd, 2023

## Registers

|Reg Name|Function|
|-------|-------|
|P<sub>x</sub>SEL| Function select register
|P<sub>x</sub>DIR | Whether input or output
|P<sub>x</sub>OUT| Output value
|P<sub>x</sub>IN| Input value
|P<sub>x</sub>REN |Pull-up / Pull-down resistor
|P<sub>x</sub>IE | Interrupt enable
|P<sub>x</sub>IFG | Interrupt flag register
|P<sub>x</sub>IES | Interrupt edge select register


## P<sub>x</sub>SEL

|P<sub>x</sub>SEL1|P<sub>x</sub>SEL0| I/O Function
|----|-----|----
|0|0|General purpose I/O
|0|1|ADC
|1|0|Timer
|1|1|Digital Communication (SPI / UART / I<sup>2</sup>C)

## Using P<sub>x</sub>SEL to Modify Behavior of P<sub>1.7</sub>

### GPIO Function
```
P1SEL1 &= ~BIT7;
P1SEL0 &= ~BIT7;
```

### ADC Function
```
P1SEL1 &= ~BIT7;
P1SEL0 |= BIT7;
```

### Timer Function
```
P1SEL1 |= BIT7;
P1SEL0 &= ~BIT7;
```

### SPI (Requires 4 Pins)
```
P1SEL1 |= 0xF0;
P1SEL0 |= 0xF0;
```

## Using P<sub>x</sub>IE, P<sub>x</sub>IFG, and P<sub>x</sub>IES

|Level Triggering | Edge Triggering |
|--|--|
|Signal asserted when high| Signal asseted on positive* edge
|Signal not asserted when low| 

\* positive edge only used when using positive edge triggering. Negative edge triggering also exists



