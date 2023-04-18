# Intro to Embedded Systems Lecture Notes: January 31st, 2023

## POLLING

**Initialize the port**

Output:
```c
    P6DIR |= BIT6;
    P6OUT &= ~BIT6;
```
Input:
```c
    P4DIR &= ~BIT1;
```
Clear LOCKLPM5 (Lock low-power mode) from PMCTL0 (Power management control):
```c
   PMCTL0 &= ~LOCKLPM5;
```

Program the board

**Floating condition: not 1 or 0**
        Fix using pull-up/pull-down resistor
 
## PULL-UP / PULL-DOWN RESISTORS

**Pull-up resesistor**
- Active Low
- Mostly preferrable for MCUs
- Safety -> reduces noise

**Pull-down resistor**
- Active high

## I/O Configuration


| P<sub>x</sub>DIR | P<sub>x</sub>REN | P<sub>x</sub>OUT | Comment        |
|-------|-------|-------|----------------|
|    0  |     0 |     X | Input          |
|    0  |     1 |     0 | Input with PDR |
|    0  |     1 |     1 | Input with PUR |
|    1  |     X |     X | Output         |

## LOW POWER MODE

| SCG<sub>1 | SCG<sub>0 | OSC OFF | CPU OFF | Mode     |
|------|------|---------|---------|----------|
|    0 |    0 |       0 |       0 | Active   |
|    0 |    0 |       0 |       1 | LPM0     |
|    0 |    1 |       0 |       1 | LPM1     |
|    1 |    0 |       0 |       1 | LPM2     |
|    1 |    1 |       0 |       1 | LPM3     |
|    1 |    1 |       1 |       1 | LPM4     | 

## WHEN INTERRUPT HAPPENS
- Processor stops what it's doing
- Stores information to later resume
- Executes interrupt service routine (ISR)
- Restores saved information
- Resumes execution
