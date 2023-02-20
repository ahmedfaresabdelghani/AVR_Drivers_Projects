/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : TIMER          ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
/* *((volatile u8*)address) */

#define TCCR0A				*((volatile u8*)0x44)   /*Timer0 pin A Control register*/
#define TCCR0A_WGM00		0                       /*waveform generation mode bit0*/
#define TCCR0A_WGM01		1                       /*waveform generation mode bit1*/

#define TCCR0B				*((volatile u8*)0x45)   
#define TCCR0B_CS00			0                       /*prescaler bit 0*/
#define TCCR0B_CS01			1                       /*prescaler bit 1*/
#define TCCR0B_CS02			2                       /*prescaler bit 2*/

#define OCR0A				*((volatile u8*)0x47)   /*Output compare register 0 PIN A*/
#define OCOR0B          	*((volatile u8*)0x48)       /*output compare register 0B*/

#define TIMSK0				*((volatile u8*)0x6E)   /*timer mask*/
#define TIMSK0_TOIE0    0                          /*overflow interrupt enable*/
#define TIMSK0_OCIE0A		1						/*output compare 0 A interrupt enable*/
#endif
