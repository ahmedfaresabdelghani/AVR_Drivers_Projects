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
#define OCOR0B          	*((volatile u8*)0x48)   /*output compare register 0B*/

#define TIMSK0				*((volatile u8*)0x6E)   /*timer mask*/
#define TIMSK0_TOIE0    	0                       /*overflow interrupt enable*/
#define TIMSK0_OCIE0A		1						/*output compare 0 A interrupt enable*/
#define TIMSK0_OCIE0B		2						/*output compare 0 B interrupt enable*/

#define TCCR1A				*((volatile u8*)0x80)	/*TIMER 1A Control Register 16 bit PWM*/
#define TCCR1A_WGM10		0						/*Waveform Generation Mode*/
#define TCCR1A_WGM11		1						/*Waveform Generation Mode*/
#define TCCR1A_COM1B0		4						/*Compare Output Mode for Channel B*/
#define TCCR1A_COM1B1		5						/*Compare Output Mode for Channel B*/
#define TCCR1A_COM1A0		6						/*Compare Output Mode for Channel A*/
#define TCCR1A_COM1A1		7						/*Compare Output Mode for Channel A*/

#define TCCR1B				*((volatile u8*)0x81)	/*TIMER 1B Control Register 16 bit PWM*/
#define TCCR1B_CS10			0					    /*Clock Select*/
#define TCCR1B_CS11			1						/*Clock Select*/
#define TCCR1B_CS12			2						/*Clock Select*/
#define TCCR1B_WGM12		3						/*Waveform Generation Mode*/
#define TCCR1B_WGM13		4						/*Waveform Generation Mode*/

#define TCNT1				*((volatile u16*)0x84)	/*TCNT1H and TCNT1L – Timer/Counter1*/

#define ICR1				*((volatile u16*)0x86) 	/*Input Capture Register for setting the Top value*/

#define OCR1A				*((volatile u16*)0x88)	/*Output Compare RegisterA for generating an Output Compare interrupt*/
#define OCR1B				*((volatile u16*)0x8A)	/*Output Compare RegisterB for generating an Output Compare interrupt*/


#endif
