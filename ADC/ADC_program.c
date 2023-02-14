/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : ADC            ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_config.h"

void ADC_voidInit(void)
{
	/*AVCC as reference voltage */

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*Activate Left Adjust Result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Set prescaler to divide by 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);


	/*Enable ADC Peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}


u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	/*Clear MUX bits in ADMUX Register */

	ADMUX&=0b11110000;

	/*set the required channel to the mux bits*/

	ADMUX|=Copy_u8Channel;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Polling (busy waiting ) until the conversion complete flag is set */
	while (GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	/*return the result in ADCH (Most significant 8 Bits)*/
	return ADCH;
}
