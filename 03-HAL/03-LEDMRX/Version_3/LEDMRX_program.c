/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 17 Sep 2020										  */
/* Version	: V03												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "Timer2_5_interface.h"

#include "STP_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void HLEDMRX_voidInit(void)
{
	/*	Initialize Columns Values */
	u8 Local_u8Columns = 0xFF;

	/*	Initialize STP Pins	*/
	HSTP_voidInit();

	/*	Disable the display at the beginning	*/
	HSTP_voidSendSynchronous (&Local_u8Columns, 1);

	/*	Initialize Timer_2 at the beginning	*/
	MTimer2_voidInit ();
}
//***************************************************************************************************************
void HLEDMRX_voidDisplayFrame(const u8* const Value_u8Data)
{
	u8 Local_u8RCId = 0;
	u8 Local_u8RowsColumns[2];
	
	while(Local_u8RCId < 8)
	{
		Local_u8RowsColumns[0] = (0xFF)&(~(1<<(Local_u8RCId)));		//Set Columns Value
		Local_u8RowsColumns[1] = Value_u8Data[(Local_u8RCId)];		//Set Rows Value
		
		HSTP_voidSendSynchronous (Local_u8RowsColumns, 2);			//Send Rows and Columns Values
		MTimer2_voidSetBusyWait(LEDMRX_TICKS_DELAY);				//Delay 
		
		Local_u8RCId++;
	}
	
	/*	Disable the display at the beginning	*/
	Local_u8RowsColumns[0] = 0xFF;									//Set Columns Value
	HSTP_voidSendSynchronous (Local_u8RowsColumns, 1);
}
//***************************************************************************************************************
void HLEDMRX_voidDisplayAnimation(const u8* const Value_u8Data, const u16 Copy_u16Length, const u32 Copy_u32Delay)
{
	u16 Local_u16Offset  = 0;
	u32 Local_u32Counter = 0;

	while(Copy_u16Length >= Local_u16Offset + 8)
	{
		Local_u32Counter++;
		HLEDMRX_voidDisplayFrame(Value_u8Data + Local_u16Offset);

		if(Local_u32Counter == Copy_u32Delay)
		{
			Local_u32Counter = 0;
			Local_u16Offset++ ;
		}
	}
}
//***************************************************************************************************************
void HLEDMRX_voidTurnOffDisplay(void)
{
	static u8 Local_u8Columns = 0xFF;
	HSTP_voidSendSynchronous (&Local_u8Columns, 1);
}
//***************************************************************************************************************
