#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"



void GIE_voidEnable(void){
	SET_BIT(SREG,7);
}

void GIE_voidDisable(void){
	CLR_BIT(SREG,7);

}
