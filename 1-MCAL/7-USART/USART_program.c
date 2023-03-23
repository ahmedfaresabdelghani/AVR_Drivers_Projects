/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : USART          ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"
#include "USART_config.h"

void USART_voidInit(void)
{
	/*USART Control and Status Register C*/
	/*USART mode select Asynchronous*/
	CLR_BIT(UCSRC,UCSRC_UMSELn0);
	CLR_BIT(UCSRC,UCSRC_UMSELn1);
	/*Parity disable*/
	CLR_BIT(UCSRC,UCSRC_UPMn0);
	CLR_BIT(UCSRC,UCSRC_UPMn1);
	/*Stop bit select : 1 stop bit*/
	CLR_BIT(UCSRC,UCSRC_USBSn);
	/*Disable the double USART Transmission speed*/
	CLR_BIT(UCSRA,UCSRA_U2X);
	/*Character size 8 bits*/
	SET_BIT(UCSRC,UCSRC_UCSZn0);
	SET_BIT(UCSRC,UCSRC_UCSZn1);
	/*Baud rate 9600:UBRR=51*/
	UBRRL=51;
	/*enable the receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	/*enable the transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);
}
/**********************************************************************************************/
void USART_voidSend(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0); //Polling wait until transmit data buffer is empty
	UDR=Copy_u8Data;
}
/**********************************************************************************************/
u8 USART_u8Receive(void)
{
	CLR_BIT(UCSRA,UCSRA_UDRE);
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);//wait until transmit data is finished
	return UDR;
}

