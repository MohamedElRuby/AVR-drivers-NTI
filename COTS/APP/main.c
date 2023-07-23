#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "../MCAL/DIO_interface.h"
#include "../MCAL/DIO_config.h"
#include "../MCAL/DIO_register.h"


void main (){
	//DIO_voidSetPinDirection(PORTA,4,DIO_u8_PORTA_PIN_DIR_4);
	DIO_init();
    DIO_voidSetPinValue(PORTA,4,DIO_u8_HIGH);



}




