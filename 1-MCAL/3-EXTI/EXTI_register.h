/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : EXTI           ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_
/* *((volatile u8*)address) */
#define GICR          *((volatile u8*)0x3D) //EIMSK	 contains INT0 and INT1
#define GICR_INT0     0
#define GICR_INT1     1
#define GIFR          *((volatile u8*)0x3C) //EIFR	 contains INTF0 and INTF1
#define MCUCR         *((volatile u8*)0x69) //EICRA  contains ISC[00,11]
#define MCUCR_ISC00   0	
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3


#endif