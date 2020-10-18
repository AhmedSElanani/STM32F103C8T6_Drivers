/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 14 Sep 2020										  */
/* Version	: V02												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "Timer2_5_interface.h"

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
	/*	Set row pins	*/
	MGPIO_voidSetPinMode (LEDMRX_ROW0_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW1_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW2_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW3_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW4_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW5_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW6_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_ROW7_PIN, OUTPUT_GP_PP_2MHZ);
	
	/*	Set column pins	*/
	MGPIO_voidSetPinMode (LEDMRX_COL0_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL1_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL2_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL3_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL4_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL5_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL6_PIN, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (LEDMRX_COL7_PIN, OUTPUT_GP_PP_2MHZ);
	
	/*	Disable the display at the beginning	*/
	DisableAllCols();

	/*	Initialize Timer_2 at the beginning	*/
	MTimer2_voidInit ();
}
//***************************************************************************************************************
void HLEDMRX_voidDisplayFrame(const u8* const Value_u8Data)
{
	u8 Local_u8Id = 0;

	while(Local_u8Id < 8)
	{
		ActivateColumn(Value_u8Data, Local_u8Id++);
	}
}
//***************************************************************************************************************
void HLEDMRX_voidDisplayAnimation(const u8* const Value_u8Data, const u16 Copy_u16Length, const u32 Copy_u32Delay)
{
	volatile u16 Local_u16Offset  = 0;
	volatile u32 Local_u32Counter = 0;

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
	DisableAllCols();
}
//***************************************************************************************************************
void DisableAllCols(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,GPIO_PIN_HIGH);
}
//***************************************************************************************************************
void SetRowValues(u8 Copy_u8Data)
{
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN,GET_BIT(Copy_u8Data,0));
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN,GET_BIT(Copy_u8Data,1));
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN,GET_BIT(Copy_u8Data,2));
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN,GET_BIT(Copy_u8Data,3));
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN,GET_BIT(Copy_u8Data,4));
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN,GET_BIT(Copy_u8Data,5));
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN,GET_BIT(Copy_u8Data,6));	
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN,GET_BIT(Copy_u8Data,7));
}
//***************************************************************************************************************
void ActivateColumn(const u8* const Value_u8Data, u8 Copy_u8ID)
{
	/*	Write the row values*/
	SetRowValues(Value_u8Data[Copy_u8ID]);

	/*	Activate one column only*/
	switch (Copy_u8ID)
	{
		case 0: MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,GPIO_PIN_LOW); break;
		case 1: MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,GPIO_PIN_LOW); break;
		case 2: MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,GPIO_PIN_LOW); break;
		case 3: MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,GPIO_PIN_LOW); break;
		case 4: MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,GPIO_PIN_LOW); break;
		case 5: MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,GPIO_PIN_LOW); break;
		case 6: MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,GPIO_PIN_LOW); break;
		case 7: MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,GPIO_PIN_LOW); break;
	}

	/*	Delay for */
	MTimer2_voidSetBusyWait(LEDMRX_TICKS_DELAY);

	/*	Disable all columns */
	DisableAllCols();
}
//***************************************************************************************************************
