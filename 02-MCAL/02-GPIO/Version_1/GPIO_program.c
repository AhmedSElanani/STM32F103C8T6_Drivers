/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 12 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void GPIO_voidSetPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if((Copy_u8Mode==0x10) || (Copy_u8Mode==0x11))	//INPUT PULL_UP OR PULL_DOWN IS SELECTED
			{
				CLR_BIT(GPIOA_ODR  ,Copy_u8Pin);
				GPIOA_ODR |= ((Copy_u8Mode)&(0x1));
				Copy_u8Mode >>= (0x1);
			}
				
			if( (Copy_u8Pin/8) & (!(Copy_u8Pin/16)) )	//(P8 - P15)
			{	
				GPIOA_CRH &= ~( (0xF)         << ((Copy_u8Pin%8)*4) );
				GPIOA_CRH |=  ( (Copy_u8Mode) << ((Copy_u8Pin%8)*4) );
			}
			else										//(P0 - P7)
			{
				GPIOA_CRL &= ~( (0xF)         << (Copy_u8Pin*4) );
				GPIOA_CRL |=  ( (Copy_u8Mode) << (Copy_u8Pin*4) );
			}
			break;
		
		case GPIOB:
			if((Copy_u8Mode==0x10) || (Copy_u8Mode==0x11))	//INPUT PULL_UP OR PULL_DOWN IS SELECTED
			{
				CLR_BIT(GPIOB_ODR  ,Copy_u8Pin);
				GPIOB_ODR |= ((Copy_u8Mode)&(0x1));
				Copy_u8Mode >>= (0x1);
			}
			
			if( (Copy_u8Pin/8) & (!(Copy_u8Pin/16)) )	//(P8 - P15)
			{	
				GPIOB_CRH &= ~( (0xF)         << ((Copy_u8Pin%8)*4) );
				GPIOB_CRH |=  ( (Copy_u8Mode) << ((Copy_u8Pin%8)*4) );
			}
			else										//(P0 - P7)
			{
				GPIOB_CRL &= ~( (0xF)         << (Copy_u8Pin*4) );
				GPIOB_CRL |=  ( (Copy_u8Mode) << (Copy_u8Pin*4) );
			}
			break;
		
		case GPIOC:
			if((Copy_u8Mode==0x10) || (Copy_u8Mode==0x11))	//INPUT PULL_UP OR PULL_DOWN IS SELECTED
			{
				CLR_BIT(GPIOC_ODR  ,Copy_u8Pin);
				GPIOC_ODR |= ((Copy_u8Mode)&(0x1));
				Copy_u8Mode >>= (0x1);
			}
				
			if( (Copy_u8Pin/8) & (!(Copy_u8Pin/16)) )	//(P8 - P15)
			{
				GPIOC_CRH &= ~( (0xF)         << ((Copy_u8Pin%8)*4) );
				GPIOC_CRH |=  ( (Copy_u8Mode) << ((Copy_u8Pin%8)*4) );
			}
			else										//(P0 - P7)
			{
				GPIOC_CRL &= ~( (0xF)         << (Copy_u8Pin*4) );
				GPIOC_CRL |=  ( (Copy_u8Mode) << (Copy_u8Pin*4) );
			}
			break;
		
		//default:  //#error
	}
}
//***************************************************************************************************************
void GPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if( Copy_u8Value == GPIO_PIN_LOW )	
			{
				CLR_BIT(GPIOA_ODR  ,Copy_u8Pin);
			}
			else										
			{
				if( Copy_u8Value == GPIO_PIN_HIGH )	
				{	
					SET_BIT(GPIOA_ODR  ,Copy_u8Pin);		
				}
			}
			break;
		
		case GPIOB:
			if( Copy_u8Value == GPIO_PIN_LOW )	
			{
				CLR_BIT(GPIOB_ODR  ,Copy_u8Pin);
			}
			else										
			{
				if( Copy_u8Value == GPIO_PIN_HIGH )	
				{	
					SET_BIT(GPIOB_ODR  ,Copy_u8Pin);		
				}
			}
			break;
		
		case GPIOC:
			if( Copy_u8Value == GPIO_PIN_LOW )	
			{
				CLR_BIT(GPIOC_ODR  ,Copy_u8Pin);
			}
			else										
			{
				if( Copy_u8Value == GPIO_PIN_HIGH )	
				{	
					SET_BIT(GPIOC_ODR  ,Copy_u8Pin);		
				}
			}
			break;
		
		//default: //#error;	
	}
}
//***************************************************************************************************************
u8 GPIO_voidGetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 GPIO_u8PinValue = 0;
	
	switch(Copy_u8Port)
	{
		case GPIOA:
			GPIO_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8Pin);
			break;
		
		case GPIOB:
			GPIO_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8Pin);
			break;
		
		case GPIOC:
			GPIO_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8Pin);
			break;
		
		//default: //#error;	
	}
	
	return GPIO_u8PinValue;
}
//***************************************************************************************************************
void GPIO_voidTogglePin (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			TOG_BIT(GPIOA_ODR  ,Copy_u8Pin);
			break;
		
		case GPIOB:
			TOG_BIT(GPIOB_ODR  ,Copy_u8Pin);		
			break;
		
		case GPIOC:
			TOG_BIT(GPIOC_ODR  ,Copy_u8Pin);
			break;
		
		//default: //#error;
	}
}
//***************************************************************************************************************
