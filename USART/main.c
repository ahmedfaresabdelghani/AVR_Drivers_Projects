#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"
#include <util/delay.h>
#include "USART_interface.h"
void main(void){
	/*Checking UART connection using PUTTY*/

	PORT_voidInit();
	USART_voidInit();
	u8 Local_u8Data=0;
	while(1)
	{
		Local_u8Data=USART_u8Receive();
		if(Local_u8Data=='1')
		{
			DIO_u8SetPinValue('C',0,DIO_u8PIN_HIGH);
		}
		else if (Local_u8Data=='2')
		{
			DIO_u8SetPinValue('C',1,DIO_u8PIN_LOW);
		}
		USART_voidSend('D');
	}
}
