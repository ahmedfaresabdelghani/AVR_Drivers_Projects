/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : DIO            ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
/* first * is for derefrencing (to set the value of : PIN , PORT and DDR) 
the next * for type casting (instead of declaring a variable with a pointer data type and consume a memory location)*/ 
#define PORTD   *((volatile u8*)0x2B)
#define DDRD    *((volatile u8*)0x2A)
#define PIND    *((volatile u8*)0x29)

#define PORTC   *((volatile u8*)0x28)
#define DDRC    *((volatile u8*)0x27)
#define PINC    *((volatile u8*)0x26)

#define PORTB   *((volatile u8*)0x25)
#define DDRB    *((volatile u8*)0x24)
#define PINB    *((volatile u8*)0x23)

#endif