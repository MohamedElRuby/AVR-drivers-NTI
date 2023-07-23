#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

//PORTA
#define PORTA_reg *((volatile u8*) 0x3B)
#define DDRA_reg  *((volatile u8*) 0x3A)
#define PINA_reg  *((volatile u8*) 0x39)

//PORTB
#define PORTB_reg *((volatile u8*) 0x38)
#define DDRB_reg  *((volatile u8*) 0x37)
#define PINAB_reg  *((volatile u8*) 0x36)

//PORTC
#define PORTC_reg *((volatile u8*) 0x35)
#define DDRC_reg  *((volatile u8*) 0x34)
#define PINC_reg  *((volatile u8*) 0x33)

//PORTD
#define PORTD_reg *((volatile u8*) 0x32)
#define DDRD_reg  *((volatile u8*) 0x31)
#define PIND_reg  *((volatile u8*) 0x30)

#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4



#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT 0

#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0










#endif
