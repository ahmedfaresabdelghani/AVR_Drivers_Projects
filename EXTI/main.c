#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
void INT0_ISR(void);
void main(void)
{
	PORT_voidInit();
	EXTI_voidInt0Init();
	EXTI_u8Int0SetCallBack(&INT0_ISR);
	GIE_voidEnable();
	while(1)
	{

	}
}

void INT0_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
}
