#include<avr/io.h>
#include<util/delay.h>
#include "BIT_MATH.h"
#include"STD_TYPES.h"
#include "avr/delay.h"
void main(){/*
	CLR_BIT(DDRC,0);
	CLR_BIT(DDRC,1);
	CLR_BIT(DDRC,2);
	CLR_BIT(DDRC,3);
	CLR_BIT(DDRC,4);
	SET_BIT(PORTC,0);
	SET_BIT(PORTC,1);
	SET_BIT(PORTC,2);
	SET_BIT(PORTC,3);
	SET_BIT(PORTC,4);
	DDRD = 0xff;
	u8 butt_1;
	u8 butt_2;
	u8 butt_3;
	u8 butt_4;
	u8 butt_5;
	u8 i=0;
	u8 c=0;
	while(1)
	{
		PORTD=0;
		butt_1=GET_BIT(PINC,0);
		//blinking 8 LEDs
		if(butt_1==0){
			PORTD=0xff;
			_delay_ms(1000);
			PORTD=0;
			_delay_ms(1000);
		}
		//shifting left LEDs
		butt_2=GET_BIT(PINC,1);

		while(butt_2==0){
			for(i=0;i<8;i++){
				PORTD=1<<i;
				_delay_ms(250);
				butt_2=GET_BIT(PINC,1);
				if(butt_2==1){
					break;
					}
				}
			for(c=6;c>=0;c--){
				butt_2=GET_BIT(PINC,1);
				if(butt_2==1){
					break;
				}
				PORTD=1<<c;
				_delay_ms(250);
				if(c==0){
					break;
				}
							}
		}
		butt_3=GET_BIT(PINC,2);
		if(butt_3==0)
		{	PORTD=0;
			_delay_ms(500);
			for(i=0;i<4;i++)
			{
				SET_BIT(PORTD,i);
				SET_BIT(PORTD,7-i);
				_delay_ms(500);
			}
		}
		butt_4=GET_BIT(PINC,3);
				if(butt_4==0){
					PORTD=0;
					_delay_ms(500);
					for(i=3;i>-1;i--)
					{
					SET_BIT(PORTD,i);
					SET_BIT(PORTD,7-i);
					_delay_ms(500);
					if(i==0){
										break;
									}
						}
				}
				butt_5=GET_BIT(PINC,4);
				if(butt_5==0){
					PORTD=0;
					_delay_ms(500);
					for(i=0;i<4;i++)
					{
					 SET_BIT(PORTD,i);
					 SET_BIT(PORTD,7-i);
					 _delay_ms(500);

					}
					for(i=3;i>-1;i--)
					{
					CLR_BIT(PORTD,i);
					CLR_BIT(PORTD,7-i);
					_delay_ms(500);
					if(i==0){
						break;
							}
					}

				}
				}*/
	DDRC = 0b00100000;

	while(1)
	{
		SET_BIT(PORTC,5);
		_delay_ms(1000);
		CLR_BIT(PORTC,5);
		_delay_ms(1000);
	}


}

