#include "nrf24l01.h"
#include"STD_TYPES.h"
#include <util/delay.h>
#include "USART_interface.h"
#define TIME_GAP    500
#include "PORT_interface.h"
#include "DIO_interface.h"
uint8_t ascending_number = 0X00;

void main(void){
    PORT_voidInit();
	USART_voidinit();
	nrf24_device(TRANSMITTER, RESET);     //initializing nrf24l01+ as a transmitter using one simple function
	u8 DATA=3;
	while(1){
		 DATA=USART_voidreceivedata();
		 USART_voidsenddata(DATA);

		_delay_ms(TIME_GAP);
		while(nrf24_transmit(&DATA, 1, NO_ACK_MODE) == TRANSMIT_FAIL){
			USART_voidsenddata('F');
			_delay_ms(10);
			USART_voidsenddata('a');
			_delay_ms(10);
			USART_voidsenddata('i');
			_delay_ms(10);
			USART_voidsenddata('l');
			_delay_ms(10);
		}//wait until payload is loaded into TX buffer
		while(nrf24_transmit_status() == TRANSMIT_IN_PROGRESS);
		USART_voidsenddata('S');
		_delay_ms(10);
		USART_voidsenddata('E');
		_delay_ms(10);
		USART_voidsenddata('N');
		_delay_ms(10);
		USART_voidsenddata('T');
		_delay_ms(10);


	}
}
