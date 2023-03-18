/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: HAL                  ****************************/
/**********************      SWC:CLCD                    ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"CLCD_interfaces.h"
#include"CLCD_config.h"
#include"CLCD_privare.h"
#include<util/delay.h>

void CLCD_voidSendCommand(u8 CLCD_u8Command){
	/*set rs to low for command*/
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_RS_CONTROL_PIN, DIO_u8PIN_LOW);
	/*set rw to low for writing*/
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_RW_CONTROL_PIN, DIO_u8PIN_LOW);
	/*set the port value for command*/
	DIO_U8SetPortValue(CLCD_DATA_PORT, CLCD_u8Command>>4);
	/*set enable pin to display*/
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_LOW);

	DIO_U8SetPortValue(CLCD_DATA_PORT, CLCD_u8Command);
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_HIGH);
		_delay_ms(2);
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_LOW);



}
void CLCD_voidSendData(u8 CLCD_u8Data){

	/*set rs to low for data*/

	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_RS_CONTROL_PIN, DIO_u8PIN_HIGH);
	/*set rw to low for writing*/
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_RW_CONTROL_PIN, DIO_u8PIN_LOW);
	/*set the port value for data*/
	DIO_U8SetPortValue(CLCD_DATA_PORT, CLCD_u8Data>>4);
	/*set enable pin to display*/
	DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
		DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_LOW);
		DIO_U8SetPortValue(CLCD_DATA_PORT, CLCD_u8Data);
			/*set enable pin to display*/
			DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_HIGH);
			_delay_ms(2);
				DIO_U8SetPinValue(CLCD_CONTROL_PORT, CLCD_E_CONTROL_PIN, DIO_u8PIN_LOW);


}
void CLCD_voidSend_String(const char*Copy_pcString){
	u8 Local_u8Counter;
	Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0'){
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;

	}






}
void CLCD_voidGo_To_X_Y(u8 Copy_u8Xpos,u8 Copy_u8Ypos){
	u8 Local_u8Postion;
	if(Copy_u8Xpos==0){
		Local_u8Postion=Copy_u8Ypos;

	}
	else if(Copy_u8Xpos==1){
		Local_u8Postion=0x40+Copy_u8Ypos;
	}
	CLCD_voidSendCommand(128+Local_u8Postion);
}
void CLCD_voidDraw_Sympol(u8 *Copy_Pu8Pattren,u8 Copy_u8Block_Num,u8 Copy_u8XPos,u8 Copy_u8YPos){
	u8 Local_u8Address=0;
	u8 Local_u8Counter=0;
	/*CLACULATE CGRAM STARTING BYTE ADDRESS*/
	Local_u8Address=Copy_u8Block_Num*8;
	/*SET THE SCGRAM BY MAKING THE MEMORY POINTER POINT TO THE ADDRESS*/
	CLCD_voidSendCommand(64+Local_u8Address);
	/*STARTING WRITING IN THE SCGRAM ADDRESS BYTE BY BYTE*/
	for( Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++){
		CLCD_voidSendData(Copy_Pu8Pattren[Local_u8Counter]);
	}
	/*RETURN THE POINTER TO DDRAM */
	CLCD_voidGo_To_X_Y(Copy_u8XPos, Copy_u8YPos);
	/*SENDING THE DATA FROM CGRAM TO DDRM*/
	CLCD_voidSendData(Copy_u8Block_Num);
}
void CLCD_voidClear_Display(void){
	/*send command to clear display*/
	CLCD_voidSendCommand(0b00000001);
	_delay_ms(20);

}


void CLCD_voidInit(void){
	/*wait more than 30ms*/
		_delay_ms(40);
		/*function set command :2 lines,5*8 font size and 4bit mode*/
		CLCD_voidSendCommand(0x33);
		/*display the screen on ,display the cursor on,display cursor blinking*/
		CLCD_voidSendCommand(0x32);
		/*clear display*/
		CLCD_voidSendCommand(0x28);
		CLCD_voidSendCommand(0x0c);
		CLCD_voidSendCommand(0x06);
		CLCD_voidSendCommand(0x01);

		_delay_ms(2);


}
