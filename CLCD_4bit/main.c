#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "util/delay.h"


void main(void)
{
	/*initialize LCD pins direction*/
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	CLCD_voidInit();
	u8 char1[8]={0b00000000,
			0b00000100,
			0b00000000,
			0b00001110,
			0b00001010,
			0b00011110,
			0b00000000};
	u8 char2[8]={0b00000000,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000111,
			0b00000000};
	u8 char3[8]={0b00000000,
			0b00000000,
			0b00000010,
			0b00000010,
			0b00000010,
			0b00000100,
			0b00001000};
	u8 char4[8]={0b00000000,
			0b00000000,
			0b00000000,
			0b00010101,
			0b00011111,
			0b00010000,
			0b00000000};
	u8 char5[8]={0b00000000,
			0b00000000,
			0b00000000,
			0b00001000,
			0b00001000,
			0b00001111,
			0b00000000};

	while(1)
	{
		u8 Local_u8XPos=0;
		u8 Local_u8Iterator=0;
		for(Local_u8Iterator=0 ; Local_u8Iterator<11 ; Local_u8Iterator=Local_u8Iterator+5)
		{
			CLCD_voidInit();

			switch (Local_u8XPos)
			{
			case 0:
				CLCD_voidSpecialCharacter(char1,0,Local_u8XPos,4+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char2,1,Local_u8XPos,3+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char3,2,Local_u8XPos,2+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char4,3,Local_u8XPos,1+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char5,4,Local_u8XPos,0+Local_u8Iterator);
				_delay_ms(700);
				Local_u8XPos=1;
				break;
			case 1:
				CLCD_voidSpecialCharacter(char1,0,Local_u8XPos,4+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char2,1,Local_u8XPos,3+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char3,2,Local_u8XPos,2+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char4,3,Local_u8XPos,1+Local_u8Iterator);
				CLCD_voidSpecialCharacter(char5,4,Local_u8XPos,0+Local_u8Iterator);
				_delay_ms(700);
				Local_u8XPos=0;
				break;
			default : break;
			}
		}
		CLCD_voidInit();
		CLCD_voidSpecialCharacter(char5,0,Local_u8XPos,-4-6+Local_u8Iterator);
		CLCD_voidSpecialCharacter(char4,1,Local_u8XPos,-3-6+Local_u8Iterator);
		CLCD_voidSpecialCharacter(char3,2,Local_u8XPos,-2-6+Local_u8Iterator);
		CLCD_voidSpecialCharacter(char2,3,Local_u8XPos,-1-6+Local_u8Iterator);
		CLCD_voidSpecialCharacter(char1,4,Local_u8XPos,-6+Local_u8Iterator);
		_delay_ms(700);
	}

}
