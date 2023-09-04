/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "UART_int.h"
#include "UART_config.h"
#include "UART_priv.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void USART_Init( )
{
	
SET_BIT(UCSRB,3); //receive enable
SET_BIT(UCSRB,4); //transmit enable



//CLR_BIT(UBRRH,7); // Register Select
UBRRL=51		;         // Baud rate 9600

}



/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit( u8 data )
{
	while(!GET_BIT(UCSRA,5));
	UDR=data;

}

/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
u8 USART_Receive( )
{
	while(!GET_BIT(UCSRA,7));
	return UDR;
}

