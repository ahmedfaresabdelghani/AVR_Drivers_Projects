/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:USART                   ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef USART_REGISTER_H
#define USART_REGISTER_H
#define UDR0             *((volatile u8*)0xC6)
#define UCSR0A           *((volatile u8*)0xC0)
#define UCSR0A_MPCM0      0        /*multi processor communication mode*/
#define UCSR0A_U2X0       1        /*double transmission speed*/
#define UCSR0A_UPE0       2        /*parity error check*/
#define UCSR0A_DOR0       3        /*data overrun*/
#define UCSR0A_FE0        4   	   /*frame error*/
#define UCSR0A_UDRE0      5        /*data register empty flag*/
#define UCSR0A_TXC0       6        /*transmission complete flag*/
#define UCSR0A_RXC0       7        /*receive complete flag*/

#define UCSR0C           *((volatile u8*)0xC2)
#define UCSR0C_UCPOL0     0        /*choose clock mode bit*/
#define UCSR0C_UCSZ00     1        /*choose the data size bit 0*/
#define UCSR0C_UCSZ01     2        /*choose the data size bit 1*/
#define UCSR0C_USBS0      3        /*selection the number of the stop bits bit*/
#define UCSR0C_UPM00      4        /*parity mode bit0*/
#define UCSR0C_UPM01      5        /*parity mode bit1*/
#define UCSR0C_UMSEL00    6        /*usart mode selection synch or asynch bit0*/
#define UCSR0C_UMSEL01    7        /*usart mode selection synch or asynch bit1*/

#define UCSR0B           *((volatile u8*)0xC1)
#define UCSR0B_TXB80       0            /*the ninth bit when transmitting 9 bits*/
#define UCSR0B_RXB80       1            /*the ninth bit when receiving 9 bits*/
#define UCSR0B_UCSZ02      2            /*choose the data size bit 2*/
#define UCSR0B_TXEN0       3            /*transmitting circuit enable */
#define UCSR0B_RXEN0       4            /*receiving circuit enable */
#define UCSR0B_UDRIE0      5            /*data register empty interrupt enable*/
#define UCSR0B_TXCIE0      6            /*transmission complete interrupt enable*/
#define UCSR0B_RXCIE0      7            /*receiving complete interrupt enable*/


#define UBRR0            *((volatile u16*)0xC4)









#endif
