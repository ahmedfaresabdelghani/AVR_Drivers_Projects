#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"GIE_interface.h"
#include"TIMER_interface.h"
#include "CLCD_interface.h"

static u16 PeriodTicks=0;
static u16 OnTicks=0;
void ICU_HW(void);
void main(void){
	/*PB0 ICP1 Input PWM
	 *PD6 T0 PWM Output
	 * 	*/
	PORT_voidInit();
	ICU_voidInit();
	ICU_u8SetCallBack(&ICU_HW);
	TIMER1_voidInit();
	TIMER0_voidInit();
	GIE_voidEnable();
	CLCD_voidInit();

	while(1)
	{
		/*wait until Period ticks and on ticks are measured*/
		while((PeriodTicks==0)&&(OnTicks==0));
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Period T=");
		CLCD_voidsendnumber(PeriodTicks);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("On T=");
		CLCD_voidsendnumber(OnTicks);
	}
}

void ICU_HW(void)
{
	static u16 Reading1, Reading2, Reading3;
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==1)
	{
		Reading1=ICU_u16ReadInputCapture();
	}
	else if (Local_u8Counter==2)
	{
		Reading2=ICU_u16ReadInputCapture();
		PeriodTicks=Reading2-Reading1;
		ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);
	}
	else if(Local_u8Counter==3)
	{
		Reading3=ICU_u16ReadInputCapture();
		OnTicks=Reading3-Reading2;
		ICU_voidDisableInterrupt();
	}

}
