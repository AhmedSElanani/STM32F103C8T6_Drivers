/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 21 Sep 2020										  */
/* Version	: V02												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "Timer2_5_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void HSTP_voidInit (void)
{
	/*	Initialize output pins	*/
	MGPIO_voidSetPinMode (STP_OUTPUT_DS  , OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (STP_OUTPUT_SHCP, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (STP_OUTPUT_STCP, OUTPUT_GP_PP_2MHZ);
	
	/*	Set output pins initially low	*/
	MGPIO_voidSetPinValue(STP_OUTPUT_DS  , GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(STP_OUTPUT_SHCP, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(STP_OUTPUT_STCP, GPIO_PIN_LOW);

	/*	Initialize Timer_2 at the beginning	*/
	MTimer2_voidInit ();
}
//***************************************************************************************************************
void HSTP_voidSendSynchronous (const u8* Copy_pu8SerialData, const u8 Copy_u8NumberofRegisters)
{
	for(s8 i=(Copy_u8NumberofRegisters - 1); i>-1; i--)
	{
		u8 Local_u8Data = Copy_pu8SerialData[i];

		for(s8 j=7; j>-1; j--)
		{
			MGPIO_voidSetPinValue(STP_OUTPUT_DS  , GET_BIT(Local_u8Data, j));		/*	MSB First 	*/
			MGPIO_voidSetPinValue(STP_OUTPUT_SHCP, GPIO_PIN_HIGH);
			MTimer2_voidSetBusyWait(STP_SHCP_DELAY);								/*	Delay for (1usec) */
			MGPIO_voidSetPinValue(STP_OUTPUT_SHCP, GPIO_PIN_LOW);
			MTimer2_voidSetBusyWait(STP_SHCP_DELAY);								/*	Delay for (1usec) */
		}
	}
	
	MGPIO_voidSetPinValue(STP_OUTPUT_STCP, GPIO_PIN_HIGH);
	MTimer2_voidSetBusyWait(STP_STCP_DELAY);										/*	Delay for (1usec) */
	MGPIO_voidSetPinValue(STP_OUTPUT_STCP, GPIO_PIN_LOW);
	MTimer2_voidSetBusyWait(STP_STCP_DELAY);										/*	Delay for (1usec) */
}
//***************************************************************************************************************
