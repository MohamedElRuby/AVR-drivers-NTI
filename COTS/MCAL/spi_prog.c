#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "SPI_init.h"
#include "SPI_priv.h"
#include "SPI_config.h"


void (*SPI_Read) (void)=NULL;

u8 SPI_buffer;
u8 SPI_Buffer_size;
u8 SPI_Index = 0;
u8 busy_flag = 0;

void SPI_voidSetCallBack( void (*pf) (void) )
{
	SPI_Read = pf;
}

//void __vector_12(void) __attribute__((signal , used));
//void __vector_12(void)
//{
//	SPI_Index++;
//	 if(SPI_Index == SPI_Buffer_size )
//	 {
//		SPI_Buffer_size =0;
//		SPI_Index = 0;
//		SPI_Read();
//		busy_flag=0;
//	 }else{
//	 SPDR = SPI_buffer[SPI_Index];
//	 }
//
//
//}

void SPI_voidSendDataISR(u8 Copy_Data)
{

}

//u8 SPI_u8ReadDataISR(u8 * data,u8 buffer_size,void (*pf)(void))
//{
//	if(busy_flag ==1)
//		{
//		  return 1; // error
//		}
//		else
//		{
//			busy_flag = 1;
//			SPI_Read = pf;
//			SPI_buffer =data;
//			SPI_Buffer_size = buffer_size;
//			SPDR = SPI_buffer[SPI_Index];
//		}
//		return 0 ;
//}


void SPI_u8Send(u8 Copy_Data)
{
	SPDR=Copy_Data;
	while(!GET_BIT(SPSR,7));

}

u8 SPI_u8Recieve(){
	while(!GET_BIT(SPSR,7));
	return SPDR;
}

void SPI_voidMasterInit(void)
{
	//SPI ENABLE
	SET_BIT(SPCR,6);


	//choose msb or msb
#if DATA_ORDER==LSB_FIRST
	SET_BIT(SPCR,5);
#elif DATA_ORDER==MSB_FIRST
	CLR_BIT(SPCR,5);
#endif

	//MASTER SELECT
	SET_BIT(SPCR,4);

	//Clock Polarity
#if CLOCK_POLARITY==IDLE_LOW
	CLR_BIT(SPCR,3);
#elif CLOCK_POLARITY==IDLE_HIGH
	SET_BIT(SPCR,3);
#endif

#if CLOCK_PHASE==ZERO
	CLR_BIT(SPCR,2);
#elif CLOCK_PHASE==ONE
	SET_BIT(SPCR,2);
#endif



}

void SPI_voidSlaveInit(void)
{
	//SPI ENABLE
	SET_BIT(SPCR,6);


	//choose msb or msb
#if DATA_ORDER==LSB_FIRST
	SET_BIT(SPCR,5);
#elif DATA_ORDER==MSB_FIRST
	CLR_BIT(SPCR,5);
#endif

	//SLAVE SELECT
	CLR_BIT(SPCR,4);

	//Clock Polarity
#if CLOCK_POLARITY==IDLE_LOW
	CLR_BIT(SPCR,3);
#elif CLOCK_POLARITY==IDLE_HIGH
	SET_BIT(SPCR,3);
#endif

#if CLOCK_PHASE==ZERO
	CLR_BIT(SPCR,2);
#elif CLOCK_PHASE==ONE
	SET_BIT(SPCR,2);
#endif
}

