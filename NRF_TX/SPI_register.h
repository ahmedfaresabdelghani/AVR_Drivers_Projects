/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:SPI                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H


#define SPCR     			 *((volatile u8*)0x4C)      //SPI control register
#define SPCR_SPR0    			0                       //clock rate select bit1
#define SPCR_SPR1    			1                       //clock rate select bit1
#define SPCR_CPHA    			2                       //clock phase select bit
#define SPCR_CPOL   			3                       //clock polarity select bit
#define SPCR_MSTR   			4                       //master or slave select bit
#define SPCR_DORD               5                       //data order bit
#define SPCR_SPE   			    6                       //SPI enable bit
#define SPCR_SPIE               7                       //SPI interrupt enable


#define SPSR             *((volatile u8*)0x4D)        //SPI status register
#define SPSR_SPI2X        0                           //double clock speed bit
#define SPSR_WCOL         6                           //write colision flag
#define SPSR_SPIF         7                           // SPI interrupt flag


#define SPDR              *((volatile u8*)0x4E)       // SPI data register















#endif
