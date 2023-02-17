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

void(*ADC_pvISRFunc)(void)=NULL;

void ADC_voidInit(void)
{
	/*ADC voltage reference checking*/
#if ADC_VOLTAGE_REF==AVCC

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_VOLTAGE_REF==AREF

	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_VOLTAGE_REF==INTERNAL

	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "wrong reference voltage selection"
#endif

	/*ADMUX adjust checking*/
#if   ADC_RESOLUTION==EIGHT_BITS

	SET_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_RESOLUTION==TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "wrong Adjust/resoultion selection"
#endif

	/*Setting ADC prescaler */

	ADCSRA&=PRESCALER_MASK;
	ADCSRA|=ADC_PRESCALER;

	/*ADC peripheral enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*checking for Conversion mode*/
#if ADC_CONVERSION==SINGLE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_CONVERSION==AUTO_TRIG
	/*ADC auto trigger enable*/
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	/*enabling ADC interrupt FLAG*/
	SET_BIT(ADCSRA,ADCSRA_ADIE);
	/*preparing ADC to selected trigger source*/
	ADCSRB&=ADC_TRIG_MASK;
	ADCSRB|=ADC_AUTO_TRIG;

	/*start conversion in case of interrupts*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#else
#error "wrong conversion mode"
#endif

}


/*****************************************************************************************************/


u16 ADC_u8GetChannelReading(u32* Copy_pu32ResultVolt)
{
	u16 Local_u16ADCReading;
	u16* Local_pu16ADCL=ADCL;
	/*taking Analog input from selected channel*/
	ADMUX&=MUX_MASK;
	ADMUX|=ADC_CHANNEL_SEL;
#if ADC_CONVERSION==SINGLE
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*wait for conversion to complete*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/*Set down the flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
#endif
	/*Return ADC Reading*/
#if ADC_RESOLUTION==EIGHT_BITS
	Local_u16ADCReading=ADCH;
	*Copy_pu32ResultVolt=(( ((u32)Local_u16ADCReading) * (ADC_MAX_VOLTAGE*1000UL)) / ((u16)ADC_RESOLUTION) );
	return ADCH;
#endif

#if ADC_RESOLUTION==TEN_BITS

	Local_u16ADCReading=(ADCL|(ADCH<<8));
	*Copy_pu32ResultVolt=(( ((u32)Local_u16ADCReading) * (ADC_MAX_VOLTAGE*1000UL)) /(u16)ADC_RESOLUTION);
	return ADC;
#endif
}
