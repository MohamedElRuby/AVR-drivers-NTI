/*
 * ADC.c
 *
 *  Created on: Jul 29, 2023
 *      Author: hp
 */
#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"

#include "ADC.h"
#include "ADC_priv.h"
#include "ADC_config.h"

void ADC_voidInit (void){
	//refrence bits : Internal Vref turned off
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	// ADC_CHANNEL_NUMBER
	CLR_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);


	CLR_BIT(ADCSRA,4); // ADC Interrupt Flag ( Conversion Complete ) cleared by SW

	//choose prescalar
#if ADC_PRESCALLER==DIVID_BY_2
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
#elif ADC_PRESCALLER==DIVID_BY_4
	  CLR_BIT(ADCSRA,0);
	  SET_BIT(ADCSRA,1);
	  CLR_BIT(ADCSRA,2);
#elif ADC_PRESCALLER==DIVID_BY_8
	  SET_BIT(ADCSRA,0);
	  SET_BIT(ADCSRA,1);
	  CLR_BIT(ADCSRA,2);
#elif ADC_PRESCALLER==DIVID_BY_16
	  CLR_BIT(ADCSRA,0);
	  CLR_BIT(ADCSRA,1);
	  SET_BIT(ADCSRA,2);
#elif ADC_PRESCALLER==DIVID_BY_32
	  SET_BIT(ADCSRA,0);
	  CLR_BIT(ADCSRA,1);
	  SET_BIT(ADCSRA,2);
#elif ADC_PRESCALLER==DIVID_BY_64
	  CLR_BIT(ADCSRA,0);
	  SET_BIT(ADCSRA,1);
	  SET_BIT(ADCSRA,2);
#elif ADC_PRESCALLER==DIVID_BY_128
	  SET_BIT(ADCSRA,0);
	  SET_BIT(ADCSRA,1);
	  SET_BIT(ADCSRA,2);
#else
#endif


}
void ADC_voidInterrputEnable(){
	CLR_BIT(ADCSRA,3); //INTERUPT ENABLE
}

void ADC_voidEnable(){
	SET_BIT(ADCSRA,7); //ENABLE
}

void ADC_voidDisable(){
	CLR_BIT(ADCSRA,7); //DISABLE
}

void ADC_voidStartConversion(){
	SET_BIT(ADCSRA,6);
}


u16 ADC_u16ReadADCInMV(){
	SET_BIT(ADCSRA,6);
	while(!GET_BIT(ADCSRA,4));
	u16 x=ADCL;
	SET_BIT(ADCSRA,4);
	return x;
}


