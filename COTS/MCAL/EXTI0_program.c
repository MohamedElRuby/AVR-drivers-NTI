#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"

#include "EXTI0_interface.h"
#include "EXTI0_private.h"
#include "EXTI0_config.h"

void (* EXT1_callback_PTR)(void)=NULL;


void EXTI1_voidInit(void){
#if SENSE_MODE == EXTI0_LOW
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif SENSE_MODE == EXTI0_IOC
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif SENSE_MODE == EXTI0_FALLING
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif SENSE_MODE == EXTI0_RISING
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#else
#endif

//CLR_BIT(GICR,7);
//SET_BIT(GIFR,7);

}

void EXTI1_voidEnable(void){
	SET_BIT(GICR,7);

}

void EXTI1_voidDisable(void){
	CLR_BIT(GICR,7);

}

void EXT1_VID_SET_CALL_BACK(void (*PTR)(void)){
	EXT1_callback_PTR=PTR;
}

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optmization
void __vector_2 (void){
EXT1_callback_PTR();
}


