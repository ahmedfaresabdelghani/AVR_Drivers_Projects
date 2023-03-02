#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"GIE_interface.h"
#include"TIMER_interface.h"
#include "EXTI_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

static u16 PeriodTicks=0;
static u16 OnTicks=0;
void ICU_SW(void);
void main(void){
	/*PD6 OC0A output PWM output
	 *PD2 INT0 EXTI input
	 * 	*/
	PORT_voidInit();
	EXTI_u8Int0SetCallBack(&ICU_SW);
	EXTI_voidInt0Init();
	TIMER1_voidInit();
	TIMER0_voidInit();

	GIE_voidEnable();
	CLCD_voidInit();
	while(1)
	{
		/*wait until Period ticks and on ticks are measured*/
		while((PeriodTicks==0)&&(OnTicks==0));
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Period Ticks=");
		CLCD_voidsendnumber(PeriodTicks);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("On Ticks=");
		CLCD_voidsendnumber(OnTicks);
	}
}

void ICU_SW(void)
{
	static u8 Local_u8StateCounter=0;
	Local_u8StateCounter++;

	if(Local_u8StateCounter==1)
	{
		/*First rising Edge*/
		TIMER1_voidSetTimerValue(0);
	}
	else if(Local_u8StateCounter==2)
	{
		PeriodTicks=TIMER1_voidReadTimerValue();
		/*Change trigger to falling Edge*/
		EXTI_u8Int0SetSenseControl(FALLING_EDGE,INT0);
	}
	else if(Local_u8StateCounter==3)
	{
		/*Timer reading is now period ticks + on ticks */
		OnTicks=TIMER1_voidReadTimerValue();
		OnTicks-=PeriodTicks;
		/*Disable INT0 interrupt*/
		EXTI_u8DisableInterrupt(INT0);
	}
}
