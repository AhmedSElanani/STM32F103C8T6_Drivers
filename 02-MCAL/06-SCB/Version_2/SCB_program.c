/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 OCT 2020										  */
/* Version	: V02												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MSCB_voidSet_VectorTableBaseOffset (void)
{
	SCB->VTOR = (SCB_FLASH_BASE | SCB_VECTORTABLE_BASE);
}
//***************************************************************************************************************
void MSCB_voidSet_SWInterruptPriorityGrouping (u32 Copy_u32Interrupt_SW_Grouping)
{
	SCB->AIRCR = Copy_u32Interrupt_SW_Grouping;
	Global_u8Interrupt_SW_Grouping = (Copy_u32Interrupt_SW_Grouping>>8);
}
//***************************************************************************************************************
