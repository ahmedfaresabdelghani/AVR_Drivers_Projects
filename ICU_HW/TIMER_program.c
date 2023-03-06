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
static void (*ICU_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*choose Fast PWM mode*/
	SET_BIT(TCCR0A,TCCR0A_WGM00);
	SET_BIT(TCCR0A,TCCR0A_WGM01);
	/*output compare match interrupt enable
	 * SET_BIT(TIMSK0,TIMSK0_OCIE0A);*/

	/*set compare match value to 64 for duty cycle 25%*/
	OCR0A=64;
	/*clear on compare match , set on top*/
	CLR_BIT(TCCR0A,6);
	SET_BIT(TCCR0A,7);
	/*prescaler division by 8*/
	CLR_BIT(TCCR0B,TCCR0B_CS00);
	SET_BIT(TCCR0B,TCCR0B_CS01);
	CLR_BIT(TCCR0B,TCCR0B_CS02);
}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8value)
{
	OCR0A=Copy_u8value;
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
/***************************************************************************/
void TIMER1_voidInit(void)
{

	/*Setting the non-inverting Compare output mode in Fast PWM*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	/*Setting the Waveform Generation Mode*/
	//CLR_BIT(TCCR1A,TCCR1A_WGM10);
	//SET_BIT(TCCR1A,TCCR1A_WGM11);
	//SET_BIT(TCCR1B,TCCR1B_WGM12);
	//SET_BIT(TCCR1B,TCCR1B_WGM13);
	/*Setting the normal mode */
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	/*Setting Prescaler and Clock selection*/
	TCCR1B&=PRESCALER_MASK;
	TCCR1B|=DIV_BY_8;
}
/***************************************************************************/
void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1=Copy_u16Value;
}
/***************************************************************************/
u16 TIMER1_voidReadTimerValue(void)
{
	return TCNT1;
}
/***************************************************************************/
void TIMER1_voidSetICR(u16 Copy_u16TopValue)
{
	ICR1=Copy_u16TopValue;
}
/***************************************************************************/
void TIMER1_voidSetChannelACompareMatch(u16 Copy_u16TopValue)
{
	OCR1A=Copy_u16TopValue;
}
/***************************************************************************/
void TIMER1_voidSetChannelBCompareMatch(u16 Copy_u16TopValue)
{
	OCR1B=Copy_u16TopValue;
}
/***************************************************************************/
void ICU_voidInit(void)
{
	/*set the trigger source to rising edge Initially */
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*Enable input capture interrupt */
	SET_BIT(TIMSK1,TIMSK1_ICIE1);
}
/***************************************************************************/
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8Edge==ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}
/***************************************************************************/
void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK1,TIMSK1_ICIE1);

}
/***************************************************************************/
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK1,TIMSK1_ICIE1);

}
/***************************************************************************/
u16 ICU_u16ReadInputCapture(void)
{
	return ICR1;
}
/***************************************************************************/
u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvCallBackFunc==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		ICU_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	return Local_u8ErrorState;

}
/***************************************************************************/
/*TIMER 0 Compare match A*/
void __vector_14 (void)__attribute__((signal));
void __vector_14 (void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
/***************************************************************************/
/*ICU ISR*/
void __vector_10 (void)__attribute__((signal));
void __vector_10 (void){
	if(ICU_pvCallBackFunc!=NULL){
		ICU_pvCallBackFunc();
	}
}

