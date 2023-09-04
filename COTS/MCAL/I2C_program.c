/*
 * I2C_program.c
 *
 *  Created on: Aug 7, 2023
 *      Author: hp
 */
#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "I2C_interface.h"
#include "I2C_private.h"


void		I2C_Master_voidInit(void){
		TWBR_REG=32;
		TWAR_REG=40;
		SET_BIT(TWCR_REG,TWEN);
		SET_BIT(TWCR_REG,TWEA);
}

void		      I2C_Slave_voidInit(u8 I2C_Address){
	TWBR_REG=32;
	SET_BIT(TWAR_REG,TWGCE);
	SET_BIT(TWCR_REG,TWEA);

	SET_BIT(TWCR_REG,TWEN);
	TWAR_REG=I2C_Address<<1;

}

I2C_Error_State I2C_Master_enuSendStartCond(void){
	    I2C_Error_State ERROR=I2C_OK;
		SET_BIT(TWCR_REG,TWINT);
		SET_BIT(TWCR_REG,TWSTA);

		while (!(TWCR_REG & (1<<TWINT)));

		if ((TWSR_REG & 0xF8) != I2C_SC_ACK){
			ERROR=I2C_SC_ERROR;
		}
		return ERROR;
}
I2C_Error_State   I2C_Master_enuSendRepeatedStartCond(void){
    	I2C_Error_State ERROR=I2C_OK;
		SET_BIT(TWCR_REG,TWINT);
		SET_BIT(TWCR_REG,TWSTA);

		while (!(TWCR_REG & (1<<TWINT)));

		if ((TWSR_REG & 0xF8) != I2C_RSC_ACK){
			ERROR=I2C_RSC_ERROR;
		}
		return ERROR;
}

I2C_Error_State   I2C_Master_enuSendSlaveAddressWithRead(u8 I2C_Address){
	    I2C_Error_State ERROR=I2C_OK;
	    TWDR_REG= I2C_Address<<1 | 1;
	    CLR_BIT(TWCR_REG,TWSTA);
		SET_BIT(TWCR_REG,TWINT);
	    while (!(TWCR_REG & (1<<TWINT)));
		if ((TWSR_REG & 0xF8) != I2C_MT_SLA_R_ACK){
			ERROR=I2C_MT_SLA_R_ERROR;
		}
		return ERROR;

}
I2C_Error_State   I2C_Master_enuSendSlaveAddressWithWrite(u8 I2C_Address){
		I2C_Error_State ERROR=I2C_OK;
	    TWDR_REG= I2C_Address<<1 & 0;
	    CLR_BIT(TWCR_REG,TWSTA);
		SET_BIT(TWCR_REG,TWINT);
	    while (!(TWCR_REG & (1<<TWINT)));
	  		if ((TWSR_REG & 0xF8) != I2C_MT_SLA_W_ACK){
	  			ERROR=I2C_MT_SLA_W_ERROR;
	  		}
	  	return ERROR;
}
I2C_Error_State   I2C_Master_enuSendu8Data(u8 I2C_Data){
		I2C_Error_State ERROR=I2C_OK;
		TWDR_REG = I2C_Data;
		SET_BIT(TWCR_REG,TWINT);
		while (!(TWCR_REG & (1<<TWINT)));
		  		if ((TWSR_REG & 0xF8) != I2C_MT_DATA_ACK){
		  			ERROR=I2C_MT_DATA_ERROR;
		  		}
	return ERROR;
}
I2C_Error_State   I2C_Master_enuReadu8Data(u8* I2C_Data){
	    I2C_Error_State ERROR=I2C_OK;
	    *I2C_Data = TWDR_REG;
		SET_BIT(TWCR_REG,TWINT);
		SET_BIT(TWCR_REG,TWEN);
		while (!(TWCR_REG & (1<<TWINT)));
		  		if ((TWSR_REG & 0xF8) != I2C_MR_DATA_ACK){
		  			ERROR=I2C_MR_DATA_ERROR;
		  		}
	return ERROR;
}
void   I2C_Master_enuSendStopCond(void){
	SET_BIT(TWCR_REG,TWSTO);
	SET_BIT(TWCR_REG,TWINT);
}

I2C_Error_State   I2C_Slave_enuReadu8Data(u8* I2C_Data){
	I2C_Error_State Local_enuError= I2C_OK;
		/*		Turn off the flag  */
		SET_BIT(TWCR_REG,TWEA);
		SET_BIT(TWCR_REG,TWINT);
		/*		Polling on the flag*/
		while (!(TWCR_REG &  (1<<TWINT)));
		if ((TWSR_REG & 0xF8)!=I2C_SR_DATA_ACK)
		{
			Local_enuError= I2C_SR_DATA_ERROR;
		}
		else
		{
			*I2C_Data =TWDR_REG;
		}
		return Local_enuError;
}

