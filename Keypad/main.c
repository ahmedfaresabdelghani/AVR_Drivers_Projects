/*
 * main.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Fares
 */
#include "STD_Types.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"
#include "KPD_interface.h"


void  main(void) {
	u8 Local_u8key;

	PORT_voidInit();

	CLCD_voidInit();





	while(1){
			do{
		Local_u8key= KPD_u8GetPressedKey();
			}while(Local_u8key== 0xff ) ;
			if(Local_u8key== 13){
				 CLCD_voidSendCommand(1);
			}
			else{
		CLCD_voidSendData(Local_u8key + '0');
			}

	}

}
