/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********   Layer : HAL            ************/
/***********   HWC : KEYPAD           ************/
/***********   Version : 1.00         ************/
/***********   DATE : 1/28/2023       ************/
/*************************************************/
/*************************************************/
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT  			DIO_u8PORTD

#define KPD_COLUMN0_PIN 	DIO_u8PIN0
#define KPD_COLUMN1_PIN 	DIO_u8PIN1
#define KPD_COLUMN2_PIN 	DIO_u8PIN2
#define KPD_COLUMN3_PIN  	DIO_u8PIN3

#define KPD_ROW0_PIN    	DIO_u8PIN4
#define KPD_ROW1_PIN    	DIO_u8PIN5
#define KPD_ROW2_PIN        DIO_u8PIN6
#define KPD_ROW3_PIN  	    DIO_u8PIN7


#define KPD_NO_PRESSED_KEY   0xff

#define KPD_ARR_VAL {{1,2,3,112},{4,5,6,113},{7,8,9,13},{90,0,82,115}}


#endif
