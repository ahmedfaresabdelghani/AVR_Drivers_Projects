/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********   Layer : HAL            ************/
/***********   HWC : CLCD             ************/
/***********   Version : 1.00         ************/
/***********   DATE : 1/28/2023       ************/
/*************************************************/
/*************************************************/

#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/*set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/* Sending upper command bits */
	DIO_u8SetPortValue(CLCD_DATA_PORT,(Copy_u8Command >>4));
	/*Send Enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	/*sending lower command bits*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,(Copy_u8Command));

	/*Send Enable pulse*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(3);
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*set RS pin to HIGH for Data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/*set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*Send upper Data bits to data port pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,(Copy_u8Data>>4));
	/*Send Enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(3);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	/*sending lower data bits to data port pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,(Copy_u8Data));
		/*Send Enable pulse*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(3);
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}
void CLCD_voidInit(void)
{
	/*wait more than 15ms*/
	_delay_ms(35);

	CLCD_voidSendCommand(0x33);
	CLCD_voidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	CLCD_voidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	CLCD_voidSendCommand(0x0c);	/* Display on cursor off */
	CLCD_voidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	CLCD_voidSendCommand(0x01);	/* Clear display screen */


}
void CLCD_voidSendString(const char* Copy_pcString)
{
	s8 Local_s8Counter=0;
	while(Copy_pcString[Local_s8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_s8Counter]);
		Local_s8Counter++;
	}
}
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Adress;
	if(Copy_u8XPos==0)
	{	/*Location is at first line*/
		Local_u8Adress=Copy_u8YPos;
	}
	else if (Copy_u8XPos==1)
	{	/*Location is at second line*/
		Local_u8Adress=Copy_u8YPos + 0x40;
	}
	/*set bit number 7 for set DDRAM Address command then send the command*/
	CLCD_voidSendCommand(Local_u8Adress + 128);
}
void CLCD_voidSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0,Local_u8Iterator;
	/*Calculate CGRAM Adress whose each block is 8 bytes*/
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	/*Set CG RAM address command to LCD , setting bit 6 to 1 and clearing bit 7*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);
	/*Write Pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/*Go back to DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	/*Display the Pattern Written in the CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);



}
void CLCD_PrintNumber(s32 Copy_s32Number)
{
	s16 Local_s16Array[33]={};
	u8 	Local_u8Iterator=0;
	while(Copy_s32Number>0)
	{
		Local_s16Array[Local_u8Iterator]=Copy_s32Number%10;
		Copy_s32Number/=10;
		Local_u8Iterator++;
	}
	for(;Local_u8Iterator>=0;Local_u8Iterator--)
	{
		CLCD_voidSendData(Local_s16Array[Local_u8Iterator]+'0');
	}
}
