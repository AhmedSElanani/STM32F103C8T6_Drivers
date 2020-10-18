/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void HLED_voidInit(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	GPIO_voidSetPinMode  (Copy_u8Port, Copy_u8Pin, OUTPUT_GP_PP_2MHZ);
}
//***************************************************************************************************************
void HLED_voidTurnON(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Polarity)
{
	if(Copy_u8Polarity==LED_ACTIVE_HIGH)
	{
		GPIO_voidSetPinValue (Copy_u8Port, Copy_u8Pin, GPIO_PIN_HIGH);
	}
	else
	{
		if(Copy_u8Polarity==LED_ACTIVE_LOW)
		{
			GPIO_voidSetPinValue (Copy_u8Port, Copy_u8Pin, GPIO_PIN_LOW);
		}
	}
}
//***************************************************************************************************************
void HLED_voidTurnOFF(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Polarity)
{
	if(Copy_u8Polarity==LED_ACTIVE_HIGH)
	{
		GPIO_voidSetPinValue (Copy_u8Port, Copy_u8Pin, GPIO_PIN_LOW);
	}
	else
	{
		if(Copy_u8Polarity==LED_ACTIVE_LOW)
		{
			GPIO_voidSetPinValue (Copy_u8Port, Copy_u8Pin, GPIO_PIN_HIGH);
		}
	}
}
//***************************************************************************************************************
void HLED_voidToggle(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	GPIO_voidTogglePin (Copy_u8Port, Copy_u8Pin);
}
//***************************************************************************************************************
