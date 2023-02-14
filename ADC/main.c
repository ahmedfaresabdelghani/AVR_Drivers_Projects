#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"

void main(void)
{
	u8 Local_u8ADCReading;
	PORT_voidInit();
	ADC_voidInit();


	while(1)
	{
		Local_u8ADCReading=ADC_u8GetChannelReading(0);
		DIO_u8SetPortValue(DIO_u8PORTD,Local_u8ADCReading);
	}
}
