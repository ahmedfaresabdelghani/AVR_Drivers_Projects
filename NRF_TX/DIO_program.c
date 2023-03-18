/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: MCAL                 ****************************/
/**********************      SWC:DIO                     ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_register.h"
#include"DIO_private.h"
#include"DIO_interface.h"
#include"DIO_config.h"
u8 DIO_U8SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction){
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<=DIO_u8PIN7){
		if(Copy_u8Direction==DIO_u8PIN_INPUT){
			switch(Copy_u8Port){
			case DIO_u8PORTD:CLEAR_BIT(DDRD,Copy_u8Pin);break;
			case DIO_u8PORTB:CLEAR_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC:CLEAR_BIT(DDRC,Copy_u8Pin);break;
			default :Local_u8ErrorState=1;
			}
		}
		else if(Copy_u8Direction==DIO_u8PIN_OUTPUT){
			switch(Copy_u8Port){
			case DIO_u8PORTD:SET_BIT(DDRD,Copy_u8Pin);break;
			case DIO_u8PORTB:SET_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC:SET_BIT(DDRC,Copy_u8Pin);break;
			default :Local_u8ErrorState=1;
			}
		}
		else{
			Local_u8ErrorState=1;
		}

	}
	else{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}
u8 DIO_U8SetPortirection(u8 Copy_u8Port,u8 Copy_u8Direction){
	u8 Local_u8ErrorState=0;
	switch (Copy_u8Port){
	case DIO_u8PORTD: DDRD = Copy_u8Direction; break;
	case DIO_u8PORTB: DDRB =Copy_u8Direction; break;
	case DIO_u8PORTC: DDRC =Copy_u8Direction; break;
	default:Local_u8ErrorState=1;

	}


	return Local_u8ErrorState;

}
u8 DIO_U8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Vlaue){
	u8 Local_u8ErrorState=0;
	if(Copy_u8Pin<=DIO_u8PIN7){
			if(Copy_u8Vlaue==DIO_u8PIN_LOW){
				switch(Copy_u8Port){
				case DIO_u8PORTD:CLEAR_BIT(PORTD,Copy_u8Pin);break;
				case DIO_u8PORTB:CLEAR_BIT(PORTB,Copy_u8Pin);break;
				case DIO_u8PORTC:CLEAR_BIT(PORTC,Copy_u8Pin);break;
				default :Local_u8ErrorState=1;
				}
			}
			else if(Copy_u8Vlaue==DIO_u8PIN_HIGH)
			{
				switch(Copy_u8Port){
				case DIO_u8PORTD:SET_BIT(PORTD,Copy_u8Pin);break;
				case DIO_u8PORTB:SET_BIT(PORTB,Copy_u8Pin);break;
				case DIO_u8PORTC:SET_BIT(PORTC,Copy_u8Pin);break;
				default :Local_u8ErrorState=1;
				}
			}
			else{
				Local_u8ErrorState=1;
			}

		}
		else{
			Local_u8ErrorState=1;
		}

	return Local_u8ErrorState;

}
u8 DIO_U8SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value){
	u8 Local_u8ErrorState=0;
	switch (Copy_u8Port){
		case DIO_u8PORTD: PORTD =Copy_u8Value; break;
		case DIO_u8PORTB: PORTB =Copy_u8Value; break;
		case DIO_u8PORTC: PORTC =Copy_u8Value; break;
		default:Local_u8ErrorState=1;

		}
	return Local_u8ErrorState;

}
u8 DIO_U8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8* Copy_u8Value ){
	u8 Local_u8ErrorState=0;
	if(Copy_u8Value!=NULL&&Copy_u8Pin<=DIO_u8PIN7){
		switch(Copy_u8Port){
		case DIO_u8PORTD: *Copy_u8Value=GET_BIT(PIND ,Copy_u8Pin);break;
        case DIO_u8PORTB: *Copy_u8Value=GET_BIT(PINB ,Copy_u8Pin);break;
        case DIO_u8PORTC:*Copy_u8Value=GET_BIT(PINC  ,Copy_u8Pin);break;
        default:Local_u8ErrorState=1;
		}
	}
	else{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}
