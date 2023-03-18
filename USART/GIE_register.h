/*************************************************/
/*************************************************/
/***********   Author  : Ahmed Fares  ************/
/***********   Layer   : MCAL         ************/
/***********   SWC     : GIE          ************/
/***********   Version : 1.00         ************/
/*************************************************/
/*************************************************/
#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_
/* *((volatile u8*)address) */
#define SREG          *((volatile u8*)0x5F) //FLAGS register
#define SREG_I        7


#endif