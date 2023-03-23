#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "util/delay.h"
#include "GIE_interface.h"
//void ADC_NotificationFunc(void);
u16 App_u16ADCReading;
u32 App_u32ADCReading;
void main(void)
{


	PORT_voidInit();
	//ADC_voidInit();
	/*when enabling GIE with Synch ADC start conv func the code didn't work LCD didn't show information*/
	//GIE_voidEnable();

	while(1)
	{
		/*
		//Local_u16ADCReading=ADC_u16GetChannelReading(&Local_u32Result);
		//ADC_u8StartConversionSynch(&App_u32ADCReading,&App_u16ADCReading);
		//temp=Local_u32Result/10;
		CLCD_voidSendCommand(1);
		ADC_u8StartConversionASynch(&App_u32ADCReading,&App_u16ADCReading,&ADC_NotificationFunc);
		CLCD_voidGoToXY(0,0);
		//CLCD_voidsendnumber(App_u32ADCReading);
		CLCD_voidGoToXY(1,0);
		CLCD_voidsendnumber(App_u16ADCReading);
		if(150<=App_u16ADCReading)
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

void ADC_NotificationFunc(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8PIN_HIGH);
*/


DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
_delay_ms(1000);

DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_LOW);

_delay_ms(1000);

/*
		ADC_u8StartConversionASynch(&App_u32ADCReading,&App_u16ADCReading,&ADC_NotificationFunc);
*/
	}
}








/*
void ADC_NotificationFunc(void)
{
	DIO_u8SetPortValue(DIO_u8PORTD,App_u16ADCReading);
}
*/
