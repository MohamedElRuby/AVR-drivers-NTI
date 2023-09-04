///*
// * calc.c
// *
// *  Created on: Jul 28, 2023
// *      Author: hp
// */
//
//
//#include "../Libary/BIT_MATH.h"
//#include "../Libary/STD_TYPES.h"
//#include "../MCAL/DIO_interface.h"
//#include "../MCAL/DIO_config.h"
//#include "../MCAL/DIO_register.h"
//#include "../HAL/LCD_interface.h"
//#include "util/delay.h"
//#include "../HAL/Keypad_interface.h"
//
//
//
//void calc (){
//
//	LCD_init();
//	Keypad_init();
//	u8 x = 0xff;
//	u8 y = 0xff;
//	u8 z = 0xff;
//	u8 a= 0xff;
//	u8 first=0;
//	u8 second=0;
//	u8 operator=0;
//	u8 equal=0;
//	while(1){
//
//		while(first==0){
//			x = Keypad_GetKey();
//			if(x != 0xff){
//				LCD_sendChar(x);
//				_delay_ms(1000);
//				first=Keypad_GetNum(x);
//				//LCD_sendChar(first+48);
//	            }
//		}
//
//		while(operator==0){
//					z = Keypad_GetKey();
//					if(z != 0xff){
//						LCD_sendChar(z);
//						_delay_ms(1000);
//						operator=z;
//			            }
//				}
//
//		while(second==0){
//					y= Keypad_GetKey();
//					if(y != 0xff){
//						LCD_sendChar(y);
//						_delay_ms(1000);
//						second=Keypad_GetNum(y);
//			            }
//		}
//
//		while(equal==0){
//					a= Keypad_GetKey();
//					if(a != 0xff){
//						LCD_sendChar('=');
//							switch(operator){
//							case '+': LCD_voidWriteNumber(first+second); break;
//							case '-': LCD_voidWriteNumber(first-second); break;
//							case 'x': LCD_voidWriteNumber(first*second); break;
//							case '/': LCD_voidWriteNumber(first/second); break;
//							default: break;
//
//							}
//					}
//
//		}
//
//
//
//
//
//
//		}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
