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
#define PIND    *((volatile u8*)0x29)

#define PORTC   *((volatile u8*)0x28)
#define PINC    *((volatile u8*)0x26)

#define PORTB   *((volatile u8*)0x25)
#define PINB    *((volatile u8*)0x23)

#endif