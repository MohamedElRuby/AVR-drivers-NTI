/*
* KEYPAD_prog.c
*
* Created: 9/24/2022 9:30:07 PM
*  Author: En.EslamEid
*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "KEYPAD_interface.h"
#include "DIO_interface.h"
#include "DIO_register.h"


u8 KEYs[4][4]={
	{'7','8','9','%'},
	{'4','5','6','x'},
	{'1','2','3','-'},
	{'*','0','=','+'},
};


void KEYPAD_init(){

	DIO_voidSetPinDirection(COL_PORT,C0_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(COL_PORT,C1_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(COL_PORT,C2_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(COL_PORT,C3_PIN,DIO_u8_OUTPUT);

	DIO_voidSetPinDirection(ROW_PORT,R0_PIN,DIO_u8_INPUT);
	DIO_voidSetPinDirection(ROW_PORT,R1_PIN,DIO_u8_INPUT);
	DIO_voidSetPinDirection(ROW_PORT,R2_PIN,DIO_u8_INPUT);
	DIO_voidSetPinDirection(ROW_PORT,R3_PIN,DIO_u8_INPUT);

	DIO_voidSetPinValue(ROW_PORT,R0_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(ROW_PORT,R1_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(ROW_PORT,R2_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(ROW_PORT,R3_PIN,DIO_u8_HIGH);

	DIO_voidSetPinValue(COL_PORT,C0_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(COL_PORT,C1_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(COL_PORT,C2_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(COL_PORT,C3_PIN,DIO_u8_HIGH);



}

u8 KEYPAD_GetKey(){

	u8 volatile value=0;
	for (u8 i=C0_PIN;i<=C3_PIN;i++)
	{
		DIO_voidSetPinValue(COL_PORT,i,DIO_u8_LOW);

		for (u8 j=R0_PIN; j<=R3_PIN;j++)
		{
			if (DIO_u8GetPinValue(ROW_PORT,j)==DIO_u8_LOW)
			{
				_delay_ms(30);
				if (DIO_u8GetPinValue(ROW_PORT,j)==DIO_u8_LOW)
				{

					value= KEYs[ j-R0_PIN  ][ i-C0_PIN ];
					break;
				}
			}
		}

		DIO_voidSetPinValue(COL_PORT,i,DIO_u8_HIGH);
		if (value != 0) break;

	 }

	 return value;
}
