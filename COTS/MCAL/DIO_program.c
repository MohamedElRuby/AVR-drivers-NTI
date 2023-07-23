#include "../Libary/BIT_MATH.h"
#include "../Libary/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"


void   DIO_init (){

	DDRA_reg= CONC_BIT(DIO_u8_PORTA_PIN_DIR_7,DIO_u8_PORTA_PIN_DIR_6,DIO_u8_PORTA_PIN_DIR_5,DIO_u8_PORTA_PIN_DIR_4,DIO_u8_PORTA_PIN_DIR_3,DIO_u8_PORTA_PIN_DIR_2,DIO_u8_PORTA_PIN_DIR_1,DIO_u8_PORTA_PIN_DIR_0);
	DDRB_reg= CONC_BIT(DIO_u8_PORTB_PIN_DIR_7,DIO_u8_PORTB_PIN_DIR_6,DIO_u8_PORTB_PIN_DIR_5,DIO_u8_PORTB_PIN_DIR_4,DIO_u8_PORTB_PIN_DIR_3,DIO_u8_PORTB_PIN_DIR_2,DIO_u8_PORTB_PIN_DIR_1,DIO_u8_PORTB_PIN_DIR_0);
	DDRC_reg= CONC_BIT(DIO_u8_PORTC_PIN_DIR_7,DIO_u8_PORTC_PIN_DIR_6,DIO_u8_PORTC_PIN_DIR_5,DIO_u8_PORTC_PIN_DIR_4,DIO_u8_PORTC_PIN_DIR_3,DIO_u8_PORTC_PIN_DIR_2,DIO_u8_PORTC_PIN_DIR_1,DIO_u8_PORTC_PIN_DIR_0);
	DDRD_reg= CONC_BIT(DIO_u8_PORTD_PIN_DIR_7,DIO_u8_PORTD_PIN_DIR_6,DIO_u8_PORTD_PIN_DIR_5,DIO_u8_PORTD_PIN_DIR_4,DIO_u8_PORTD_PIN_DIR_3,DIO_u8_PORTD_PIN_DIR_2,DIO_u8_PORTD_PIN_DIR_1,DIO_u8_PORTD_PIN_DIR_0);
}


void	DIO_voidSetPinDirection	(u8 PortId,u8 PinId,u8 Direction){
	if( (PortId <= 7) && (PortId<= PORTD) ){



		if(Direction==DIO_u8_OUTPUT){
			switch(PortId){
			case PORTA: SET_BIT(DDRA_reg,PinId); break;
			case PORTB: SET_BIT(DDRB_reg,PinId); break;
			case PORTC: SET_BIT(DDRC_reg,PinId); break;
			case PORTD: SET_BIT(DDRD_reg,PinId); break;
			}

		}else if (Direction==DIO_u8_INPUT){
			switch(PortId){
			case PORTA: CLR_BIT(DDRA_reg,PinId); break;
			case PORTB: CLR_BIT(DDRB_reg,PinId); break;
			case PORTC: CLR_BIT(DDRC_reg,PinId); break;
			case PORTD: CLR_BIT(DDRD_reg,PinId); break;
			}

	}
}
}

void	DIO_voidSetPinValue	(u8 PortId,u8 PinId,u8 Value){
	if( (PortId <= 7) && (PortId<= PORTD) ){



			if(Value==DIO_u8_HIGH){
				switch(PortId){
				case PORTA: SET_BIT(PORTA_reg,PinId); break;
				case PORTB: SET_BIT(PORTB_reg,PinId); break;
				case PORTC: SET_BIT(PORTC_reg,PinId); break;
				case PORTD: SET_BIT(PORTD_reg,PinId); break;
				default: break;
				}

			}else if(Value==DIO_u8_LOW){
				switch(PortId){
				case PORTA: CLR_BIT(PORTA_reg,PinId); break;
				case PORTB: CLR_BIT(PORTB_reg,PinId); break;
				case PORTC: CLR_BIT(PORTC_reg,PinId); break;
				case PORTD: CLR_BIT(PORTD_reg,PinId); break;
				default: break;

				}

		}
	}

}

u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId){
	if( (PortId <= 7) && (PortId<= PORTD) ){
					switch(PortId){
					case PORTA: return ( GET_BIT(PORTA_reg,PinId) ); break;
					case PORTB: return GET_BIT(PORTA_reg,PinId); break;
					case PORTC: return GET_BIT(PORTA_reg,PinId); break;
					case PORTD: return GET_BIT(PORTA_reg,PinId); break;
					default: break;
		}
	}else{

	}

}


void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction){
	switch(PortId){
					case PORTA: DDRA_reg=Direction; break;
					case PORTB: DDRB_reg=Direction; break;
					case PORTC: DDRC_reg=Direction; break;
					case PORTD: DDRD_reg=Direction; break;

					default: break;
	}
}
void	DIO_voidSetPortValue		(u8 PortId,u8 Value){
	switch(PortId){
						case PORTA: PORTA_reg=Value; break;
						case PORTB: PORTB_reg=Value; break;
						case PORTC: PORTC_reg=Value; break;
						case PORTD: PORTD_reg=Value; break;

						default: break;
		}
}

