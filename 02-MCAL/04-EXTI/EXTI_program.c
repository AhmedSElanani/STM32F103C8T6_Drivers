/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 22 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MEXTI_voidInit(void) 
{
	#if (EXTI_LINE0_ENABLE==1)
		#if (EXTI_LINE0_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_0);		
		#endif
		
		#if (EXTI_LINE0_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_0);		
		#endif
	#endif
	
	#if (EXTI_LINE1_ENABLE==1)
		#if (EXTI_LINE1_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_1);		
		#endif
		
		#if (EXTI_LINE1_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_1);		
		#endif
	#endif
	
	#if (EXTI_LINE2_ENABLE==1)
		#if (EXTI_LINE2_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_2);		
		#endif
		
		#if (EXTI_LINE2_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_2);		
		#endif
	#endif
	
	#if (EXTI_LINE3_ENABLE==1)
		#if (EXTI_LINE3_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_3);		
		#endif
		
		#if (EXTI_LINE3_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_3);		
		#endif
	#endif
	
	#if (EXTI_LINE4_ENABLE==1)
		#if (EXTI_LINE4_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_4);		
		#endif
		
		#if (EXTI_LINE4_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_4);		
		#endif
	#endif
	
	#if (EXTI_LINE5_ENABLE==1)
		#if (EXTI_LINE5_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_5);		
		#endif
		
		#if (EXTI_LINE5_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_5);		
		#endif
	#endif
	
	#if (EXTI_LINE6_ENABLE==1)
		#if (EXTI_LINE6_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_6);		
		#endif
		
		#if (EXTI_LINE6_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_6);		
		#endif
	#endif
	
	#if (EXTI_LINE7_ENABLE==1)
		#if (EXTI_LINE7_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_7);		
		#endif
		
		#if (EXTI_LINE7_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_7);		
		#endif
	#endif
	
	#if (EXTI_LINE8_ENABLE==1)
		#if (EXTI_LINE8_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_8);		
		#endif
		
		#if (EXTI_LINE8_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_8);		
		#endif
	#endif
	
	#if (EXTI_LINE9_ENABLE==1)
		#if (EXTI_LINE9_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_9);		
		#endif
		
		#if (EXTI_LINE9_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_9);		
		#endif
	#endif
	
	#if (EXTI_LINE10_ENABLE==1)
		#if (EXTI_LINE10_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_10);		
		#endif
		
		#if (EXTI_LINE10_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_10);		
		#endif
	#endif
	
	#if (EXTI_LINE11_ENABLE==1)
		#if (EXTI_LINE11_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_11);		
		#endif
		
		#if (EXTI_LINE11_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_11);		
		#endif
	#endif
	
	#if (EXTI_LINE12_ENABLE==1)
		#if (EXTI_LINE12_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_12);		
		#endif
		
		#if (EXTI_LINE12_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_12);		
		#endif
	#endif
	
	#if (EXTI_LINE13_ENABLE==1)
		#if (EXTI_LINE13_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_13);		
		#endif
		
		#if (EXTI_LINE13_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_13);		
		#endif
	#endif
	
	#if (EXTI_LINE14_ENABLE==1)
		#if (EXTI_LINE14_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_14);		
		#endif
		
		#if (EXTI_LINE14_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_14);		
		#endif
	#endif
	
	#if (EXTI_LINE15_ENABLE==1)
		#if (EXTI_LINE15_RISINGEDGE_ENABLE==1)
			SET_BIT(EXTI->RSTR, EXTI_LINE_15);		
		#endif
		
		#if (EXTI_LINE15_FALLINGEDGE_ENABLE==1)
			SET_BIT(EXTI->FTSR, EXTI_LINE_15);		
		#endif
	#endif
}
//***************************************************************************************************************
void MEXTI_voidEnable_EXTI_Line(u8 copy_u8Line)
{
	SET_BIT(EXTI->IMR, copy_u8Line);		
}
//***************************************************************************************************************
void MEXTI_voidDisable_EXTI_Line(u8 copy_u8Line)
{
	CLR_BIT(EXTI->IMR, copy_u8Line);		
}
//***************************************************************************************************************
void MEXTI_voidSW_Trigger_EXTI_Line(u8 copy_u8Line)
{
	SET_BIT(EXTI->SWIER, copy_u8Line);		
}
//***************************************************************************************************************
u8 MEXTI_voidCheckPending_EXTI_Line(u8 copy_u8Line)
{
	return ( GET_BIT(EXTI->PR,copy_u8Line) );
}
//***************************************************************************************************************
void MEXTI_voidClearPending_EXTI_Line(u8 copy_u8Line)
{
	EXTI->PR = (1<<copy_u8Line);
}
//***************************************************************************************************************
void MEXTI_voidSetCallback(u8 copy_u8Line, void (*Copy_ptr)(void))
{
	EXTI_Callback[copy_u8Line] =  Copy_ptr;
}
/*
*********************************************************************************************************
*                                        EXTERNAL INTERRUPTS HANDLERS
*********************************************************************************************************
*/
void EXTI0_IRQHandler (void)
{
	MEXTI_voidClearPending_EXTI_Line (EXTI_LINE_0);

	if(EXTI_Callback[0] != 0)
	{
		(EXTI_Callback[0])();
	}
}
//***************************************************************************************************************
void EXTI1_IRQHandler (void)
{
	MEXTI_voidClearPending_EXTI_Line (EXTI_LINE_1);

	if(EXTI_Callback[1] != 0)
	{
		(EXTI_Callback[1])();
	}
}
//***************************************************************************************************************
void EXTI2_IRQHandler (void)
{
	MEXTI_voidClearPending_EXTI_Line (EXTI_LINE_2);

	if(EXTI_Callback[2] != 0)
	{
		(EXTI_Callback[2])();
	}
}
//***************************************************************************************************************
void EXTI3_IRQHandler (void)
{
	MEXTI_voidClearPending_EXTI_Line (EXTI_LINE_3);

	if(EXTI_Callback[3] != 0)
	{
		(EXTI_Callback[3])();
	}
}
//***************************************************************************************************************
void EXTI4_IRQHandler (void)
{
	MEXTI_voidClearPending_EXTI_Line (EXTI_LINE_4);

	if(EXTI_Callback[4] != 0)
	{
		(EXTI_Callback[4])();
	}
}
//***************************************************************************************************************
void EXTI9_5_IRQHandler (void)
{
	for(u8 i=5; i<10; i++)
	{
		if( MEXTI_voidCheckPending_EXTI_Line(i) )
		{
			MEXTI_voidClearPending_EXTI_Line (i);

			if(EXTI_Callback[i] != 0)
			{
				(EXTI_Callback[i])();
			}
		}
	}
}
//***************************************************************************************************************
void EXTI15_10_IRQHandler (void)
{
	for(u8 i=10; i<16; i++)
	{
		if( MEXTI_voidCheckPending_EXTI_Line(i) )
		{
			MEXTI_voidClearPending_EXTI_Line (i);

			if(EXTI_Callback[i] != 0)
			{
				(EXTI_Callback[i])();
			}
		}
	}
}
//***************************************************************************************************************
