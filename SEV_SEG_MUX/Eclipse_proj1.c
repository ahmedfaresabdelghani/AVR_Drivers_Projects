#include<avr/io.h>
#include<util/delay.h>
#include "BIT_MATH.h"
#include"STD_TYPES.h"
void main()
{
	DDRD = 0xff;
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	u8 sevensegarr[10]={
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111,

	};
	while(1)
	{
		for(u8 i=0; i<10;i++)
		{
		for(u8 x=0;x<100;x++){
			PORTD=sevensegarr[i];
			CLR_BIT(PORTC,0);
			_delay_ms(10);
			SET_BIT(PORTC,0);
			PORTD=sevensegarr[9-i];
			CLR_BIT(PORTC,1);
			_delay_ms(10);
			SET_BIT(PORTC,1);
		}
		}
	}
}
