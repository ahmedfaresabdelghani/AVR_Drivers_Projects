#include "nrf24l01.h"
#include <util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"CLCD_interfaces.h"
#include"PORT_interface.h"

u8 ReceivedData = '0' ;
u8 c = 0 ;

void main(void){


	PORT_voidInit();
	nrf24_device(RECEIVER, RESET);      //initializing nrf24l01+ as a receiver device with one simple function call


	CLCD_voidInit();

	while (1){

		while(nrf24_receive(&ReceivedData,1) == RECEIVE_FIFO_EMPTY) ;   //poll and receive in one simple function call
		if(ReceivedData == '#'){
			CLCD_voidSendCommand(1);
			c= 0 ;
			continue	;
		}
		CLCD_voidSendData(ReceivedData);
		c++ ;
		if(c ==  16 ){
			CLCD_voidGo_To_X_Y(1, 0);

		}
		else if (c == 33){
			CLCD_voidSendCommand(1);
			c = 0 ;
		}

	}
}
