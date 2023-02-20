/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : TIMER          ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;
void TIMER0_voidInit(void)
{
	/*choose CTC mode*/
	CLR_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	/*output compare match interrupt enable*/
	SET_BIT(TIMSK0,TIMSK0_OCIE0A);
	/*set compare match value to 250*/
	OCR0A=250;

	/*prescaler division by 8*/
	CLR_BIT(TCCR0B,TCCR0B_CS00);
	SET_BIT(TCCR0B,TCCR0B_CS01);
	CLR_BIT(TCCR0B,TCCR0B_CS02);
}

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pvCallBackFunc==NULL){
		 Local_u8ErrorState=NULL_POINTER;
	 }

	 else{
		 TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;

	 }
	return Local_u8ErrorState;
}

void __vector_14 (void)__attribute__((signal));
void __vector_14 (void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
