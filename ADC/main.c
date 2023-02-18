#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "util/delay.h"

void main(void)
{
	u16 Local_u16ADCReading;
	u32 Local_u32Result;
	u32 temp;
	PORT_voidInit();
	ADC_voidInit();
	CLCD_voidInit();


	while(1)
	{	CLCD_voidSendCommand(1);
		//Local_u16ADCReading=ADC_u16GetChannelReading(&Local_u32Result);
		ADC_u8StartConversionSynch(&Local_u32Result,&Local_u16ADCReading);
		//temp=Local_u32Result/10;
		CLCD_voidGoToXY(0,0);
			CLCD_voidsendnumber(Local_u32Result);
			CLCD_voidGoToXY(1,0);
			CLCD_voidsendnumber(Local_u16ADCReading);
			if(150<=Local_u32Result)
			{
				DIO_u8SetPinValue('C',DIO_u8PIN1,DIO_u8PIN_LOW);
			}
			else
			{
				DIO_u8SetPinValue('C',DIO_u8PIN1,DIO_u8PIN_HIGH);
			}
			_delay_ms(1000);
	}
}
