/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 19 Aug 2020										  */
/* Version	: V02												  */
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
void MGPIO_voidSetPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if((Copy_u8Mode==0x10) || (Copy_u8Mode==0x11))	//INPUT PULL_UP OR PULL_DOWN IS SELECTED
			{
				CLR_BIT(GPIOA_ODR  ,Copy_u8Pin);
				GPIOA_ODR |= (((Copy_u8Mode)&(0x1)) << Copy_u8Pin);
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
				GPIOB_ODR |= (((Copy_u8Mode)&(0x1)) << Copy_u8Pin);
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
				GPIOC_ODR |= (((Copy_u8Mode)&(0x1)) << Copy_u8Pin);
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
void MGPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if( Copy_u8Value == GPIO_PIN_LOW )	
			{
				GPIOA_BRR = (1<<Copy_u8Pin);
			}
			else										
			{
				if( Copy_u8Value == GPIO_PIN_HIGH )	
				{	
					GPIOA_BSR = (1<<Copy_u8Pin);		
				}
			}
			break;
		
		case GPIOB:
			if( Copy_u8Value == GPIO_PIN_LOW )	
			{
				GPIOB_BRR = (1<<Copy_u8Pin);
			}
			else										
			{
				if( Copy_u8Value == GPIO_PIN_HIGH )	
				{	
					GPIOB_BSR = (1<<Copy_u8Pin);		
				}
			}
			break;
		
		case GPIOC:
			if( Copy_u8Value == GPIO_PIN_LOW )	
			{
				GPIOC_BRR = (1<<Copy_u8Pin);
			}
			else										
			{
				if( Copy_u8Value == GPIO_PIN_HIGH )	
				{	
					GPIOC_BSR = (1<<Copy_u8Pin);		
				}
			}
			break;
		
		//default: //#error;	
	}
}
//***************************************************************************************************************
u8 MGPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8PinValue = 0;
	
	switch(Copy_u8Port)
	{
		case GPIOA:
			Local_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8Pin);
			break;
		
		case GPIOB:
			Local_u8PinValue = GET_BIT(GPIOB_IDR,Copy_u8Pin);
			break;
		
		case GPIOC:
			Local_u8PinValue = GET_BIT(GPIOC_IDR,Copy_u8Pin);
			break;
		
		//default: //#error;	
	}
	
	return Local_u8PinValue;
}
//***************************************************************************************************************
void MGPIO_voidTogglePin (u8 Copy_u8Port, u8 Copy_u8Pin)
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
void MGPIO_voidLockPin (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	volatile u32* Local_u32LockRegister = 0;

	switch(Copy_u8Port)
	{
		case GPIOA:
			Local_u32LockRegister = (u32*)(&GPIOA_LCK);
			break;
		
		case GPIOB:
			Local_u32LockRegister = (u32*)(&GPIOB_LCK);
			break;
		
		case GPIOC:
			Local_u32LockRegister = (u32*)(&GPIOC_LCK);
			break;
		
		//default: //#error;
	}
	if(Local_u32LockRegister)
	{
		/* Set the Corresponding Bit */
		SET_BIT( (*Local_u32LockRegister),Copy_u8Pin);
			
		/* Write the LOCK key sequence*/
		SET_BIT( (*Local_u32LockRegister),16);
		CLR_BIT( (*Local_u32LockRegister),16);
		SET_BIT( (*Local_u32LockRegister),16);
		GET_BIT( (*Local_u32LockRegister),16);
		GET_BIT( (*Local_u32LockRegister),16);	
	}
}
//***************************************************************************************************************
