/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:USART                   ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"USART_interface.h"
#include"USART_private.h"
#include"USART_config.h"
#include"USART_register.h"

void USART_voidinit(void){
 u8 Local_u8UCSR0C=0;
	/*1 stop bit*/
    CLEAR_BIT(Local_u8UCSR0C,UCSR0C_USBS0);
    /*no parity*/
    CLEAR_BIT(Local_u8UCSR0C,UCSR0C_UPM00);
    CLEAR_BIT(Local_u8UCSR0C,UCSR0C_UPM01);
    CLEAR_BIT(Local_u8UCSR0C,UCSR0C_UMSEL00);
    CLEAR_BIT(Local_u8UCSR0C,UCSR0C_UMSEL01);

    /*8 data bits*/
    SET_BIT(Local_u8UCSR0C,UCSR0C_UCSZ00);
    SET_BIT(Local_u8UCSR0C,UCSR0C_UCSZ01);
    CLEAR_BIT(UCSR0B,UCSR0B_UCSZ02);
    UCSR0C=Local_u8UCSR0C;
    CLEAR_BIT(UCSR0A,UCSR0A_U2X0);
    /*4900BPS*/
    UBRR0=103;
    /*receive  enable*/
    SET_BIT(UCSR0B,UCSR0B_RXEN0);
    /*transmit  enable*/
       SET_BIT(UCSR0B,UCSR0B_TXEN0);
}


void USART_voidsenddata(u8 copy_u8data){
	while(GET_BIT(UCSR0A,UCSR0A_UDRE0)==0);
	UDR0=copy_u8data;
}
u8 USART_voidreceivedata(void){
	while(GET_BIT(UCSR0A,UCSR0A_RXC0)==0);
	return UDR0;
}



