#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include"TIMER_interface.h"
#include <util/delay.h>
//void PWM(void);
u8 Local_u8Counter=0;
void main(void){
	PORT_voidInit();
	//TIMER0_voidInit();
	//TIMER0_u8SetCallBack(&PWM);
	GIE_voidEnable();
	TIMER1_voidInit();
	TIMER1_voidSetICR(20000);
	ADC_voidInit();
	u16 Local_u16Iterator=0;
	u16 Local_u16MappedValue;
	u16 Local_u16ADCOutputVal;
	u32 Local_u32ADCOutputVolt;
	while(1)
	{
		/*PWM T1 channel A PB1 pin*/
		/*ADC0 PC0 */
		ADC_u8StartConversionSynch(&Local_u32ADCOutputVolt,&Local_u16ADCOutputVal);
		Local_u16MappedValue=ADC_s32Mapping(0,1023,750,2500,Local_u16ADCOutputVal);
		TIMER1_voidSetChannelACompareMatch(1500);
	}
}
/*PWM T1 PD5 pin*/
/*for(Local_u16Iterator=750;Local_u16Iterator<2500;Local_u16Iterator++)
		{
			TIMER1_voidSetChannelACompareMatch(Local_u16Iterator);
			_delay_ms(10);
		}
 */

/*
		for(Local_u8Counter=0;Local_u8Counter<255;Local_u8Counter++)
		{
			TIMER0_voidSetCompMatchValue(Local_u8Counter);
			_delay_ms(20);
		}
		for(Local_u8Counter=255;Local_u8Counter>0;Local_u8Counter--)
		{
			TIMER0_voidSetCompMatchValue(Local_u8Counter);
			_delay_ms(20);
		}
 */

/*void PWM(void){

	static u8 Local_u8Counter=0;

	Local_u8Counter++;
	if(Local_u8Counter==5){

		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_LOW);

	}
	else if(Local_u8Counter==10){

			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW);

		}
	else if(Local_u8Counter==15){

			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_LOW);

		}
	else if(Local_u8Counter==20)
	{
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);

		Local_u8Counter=0;
	}
}
 */
