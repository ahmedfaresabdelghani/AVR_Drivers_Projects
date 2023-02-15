#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

void main(void)
{
	u16 Local_u16ADCReading;
	u32 Local_u32Result;
	PORT_voidInit();
	ADC_voidInit();


	while(1)
	{
		Local_u16ADCReading=ADC_u8GetChannelReading(&Local_u32Result);
		DIO_u8SetPortValue(DIO_u8PORTD,Local_u16ADCReading);
	}
}
