/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : PORT            ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_
/* first * is for derefrencing (to set the value of : PIN , PORT and DDR) 
the next * for type casting (instead of declaring a variable with a pointer data type and consume a memory location)*/ 


#define DDRC    *((volatile u8*)0x27)

#define PORTC   *((volatile u8*)0x28)


#define DDRD    *((volatile u8*)0x2A)

#define PORTD   *((volatile u8*)0x2B)

#define DDRB    *((volatile u8*)0x24)

#define PORTB   *((volatile u8*)0x25)

#endif