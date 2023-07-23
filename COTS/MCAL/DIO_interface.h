#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


void    DIO_init ();

void	DIO_voidSetPinDirection		(u8 PortId,u8 PinId,u8 Direction);
void	DIO_voidSetPinValue			(u8 PortId,u8 PinId,u8 Value);

u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId);
void	DIO_voidGetPinValue			(u8 PortId,u8 PinId, u8 * ptr);

void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction);
void	DIO_voidSetPortValue		(u8 PortId,u8 Value);

//DIO_voidSetPinValue	(PORTA,PIN0,HIGH); // A0 = 1



#endif
