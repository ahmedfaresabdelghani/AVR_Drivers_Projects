/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : EXTI            ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
/*Global pointer to function to hold INT0 ISR address*/
void(*EXTI_pvInt0Func)(void)=NULL;


void EXTI_voidInt0Init(void)
{
	/*1-Check sense control */
#if INT0_SENSE == Low_LEVEL
	/*set sense control for INT0 to falling edge */
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE == ON_CHANGE
	/*set sense control for INT0 to falling edge */
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE == FALLING_EDGE
	/*set sense control for INT0 to falling edge */
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == RISING_EDGE
	/*set sense control for INT0 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "wrong INT0_SENSE configuration option"
#endif
	/*2- Check if peripheral interrupt enable initial state*/
#if INT0_INITIAL_STATE == ENABLED
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE configuration option"
#endif
}
/***************************************************************************/

void EXTI_voidInt1Init(void)
{
	/*1-Check sense control */
#if INT0_SENSE == Low_LEVEL
	/*set sense control for INT0 to falling edge */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INT0_SENSE == ON_CHANGE
	/*set sense control for INT0 to falling edge */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#elif INT0_SENSE == FALLING_EDGE
	/*set sense control for INT0 to falling edge */
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT0_SENSE == RISING_EDGE
	/*set sense control for INT0 to falling edge */
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#else
#error "wrong INT0_SENSE configuration option"
#endif
	/*2- Check if peripheral interrupt enable initial state*/
#if INT0_INITIAL_STATE == ENABLED
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE configuration option"
#endif
}
/***************************************************************************/

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense,u8 Copy_u8Int)
{
	u8 Local_u8ErrorState =OK;
	if(Copy_u8Int==INT0)
	{
		switch(Copy_u8Sense)
		{
		case Low_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);
			break;
		case ON_CHANGE:
			CLR_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			CLR_BIT(MCUCR,MCUCR_ISC00);

			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC01);
			SET_BIT(MCUCR,MCUCR_ISC00);
			break;
		default: Local_u8ErrorState=NOK;
		}
		return Local_u8ErrorState;
	}
	else if(Copy_u8Int==INT1)
	{
		switch(Copy_u8Sense)
		{
		case Low_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC11);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			break;
		case ON_CHANGE:
			CLR_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC11);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC11);
			SET_BIT(MCUCR,MCUCR_ISC10);
			break;
		default: Local_u8ErrorState=NOK;
		}
		return Local_u8ErrorState;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
/***************************************************************************/

u8 EXTI_u8IntEnableControl(u8 Copy_u8Int,u8 Copy_u8IntControl)
{
	u8 Local_u8ErrorState =OK;

	if(Copy_u8Int==INT0)
	{
		if(Copy_u8IntControl==ENABLED)
		{
			SET_BIT(GICR,GICR_INT0);
		}
		else if(Copy_u8IntControl==DISABLED)
		{
			CLR_BIT(GICR,GICR_INT0);
		}
		else
		{
			Local_u8ErrorState=NOK;
		}

	}
	else if(Copy_u8Int==INT1)
	{
		if(Copy_u8IntControl==ENABLED)
		{
			SET_BIT(GICR,GICR_INT1);
		}
		else if(Copy_u8IntControl==DISABLED)
		{
			CLR_BIT(GICR,GICR_INT1);
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;

}
/***************************************************************************/
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func) (void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/***************************************************************************/
u8 EXTI_u8DisableInterrupt(u8 Copy_u8InterruptNum)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8InterruptNum==INT0||Copy_u8InterruptNum==INT1)
	{
		CLR_BIT(GICR,Copy_u8InterruptNum);
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}
/***************************************************************************/
u8 EXTI_u8EnableInterrupt(u8 Copy_u8InterruptNum)
{
	u8 Local_ErrorState=OK;
	if(Copy_u8InterruptNum==INT0||Copy_u8InterruptNum==INT1)
	{
		SET_BIT(GICR,Copy_u8InterruptNum);
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}
/***************************************************************************/
/*ISR of INT0*/
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	if(EXTI_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		//Do nothing
	}
}


