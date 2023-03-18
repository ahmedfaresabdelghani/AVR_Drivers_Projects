/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:SPI                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SPI_interface.h"
#include"SPI_config.h"
#include"SPI_private.h"
#include"SPI_register.h"


void SPI_VoidMasterInit(void){
	//select master
	SET_BIT(SPCR,SPCR_MSTR);
	//set the clock divide by 16
	SET_BIT(SPCR,SPCR_SPR0);
	CLEAR_BIT(SPCR,SPCR_SPR1);
	CLEAR_BIT(SPSR,SPSR_SPI2X);
	//SPI enable
	SET_BIT(SPCR,SPCR_SPE);
}
void SPI_VoidSlaveInit(void){
	//select slave
	CLEAR_BIT(SPCR,SPCR_MSTR);
	//SPI enable
	SET_BIT(SPCR,SPCR_SPE);
}
u8 SPI_u8Transceive(u8 Copy_u8SentData,u8* Copy_Pu8ReceviedData ){
	u8 Local_u8ErorState=OK;
	if(Copy_Pu8ReceviedData==NULL){
		Local_u8ErorState=NULL_POINTER;
	}
	else {
		//send data
		SPDR=Copy_u8SentData;
		//busy wating until the end of transmission flag is set
		while(GET_BIT(SPSR,SPSR_SPIF)==0);
		//get the received data
		*Copy_Pu8ReceviedData=SPDR;
	}
	return Local_u8ErorState;
}



