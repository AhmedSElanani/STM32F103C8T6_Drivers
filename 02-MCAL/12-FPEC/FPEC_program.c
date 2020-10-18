/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 OCT 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void FPEC_voidUnlockFPEC (void)
{
	//CHECK BSY FLAG
	while( GET_BIT((FPEC->SR ),0) );

	//CHECK THAT FPEC AND CR ARE LOCKED
	if( GET_BIT((FPEC->CR),7) )
	{
		//UNLOCK FPEC AND CR
		FPEC->KEYR = KEY1;
		FPEC->KEYR = KEY2;
	}
}
//***************************************************************************************************************
void FPEC_voidEraseAppArea (void)
{
	for(u8 i=0; i<FPEC_NUMBEROFPAGES; i++)
	{
		FPEC_voidFlashPageErase(i);
	}

	/*Alternate Method*/
	//Mass Erase
}
//***************************************************************************************************************
void FPEC_voidFlashPageErase (u8 Copy_u8PageNumber)
{
	//CHECK BSY FLAG
	while( GET_BIT((FPEC->SR ),0) );

	//SET PER
	SET_BIT((FPEC->CR),1);

	//SELECT THE PAGE TO ERASE
	FPEC->AR = ((u32)((Copy_u8PageNumber*FPEC_PAGESIZE)+(FPEC_STARTADDRESS)));

	//SET STRT
	SET_BIT((FPEC->CR),6);

	//CHECK BSY FLAG
	while( GET_BIT((FPEC->SR ),0) );

	//CHECK EOP FLAG
	while( !(GET_BIT((FPEC->SR ),5)) );

	//CLEAR EOP FLAG
	SET_BIT((FPEC->SR),5);

	//RESET PER
	CLR_BIT((FPEC->CR),1);
}
//***************************************************************************************************************
void FPEC_voidFlashWrite (u32 Copy_u32Address, volatile u16* Copy_u16Data, u8 Copy_u8Length)
{
	//CHECK BSY FLAG
	while( GET_BIT((FPEC->SR ),0) );

	//SET PG
	SET_BIT((FPEC->CR),0);

	//WRITE THE DATA TO THE DESIRED ADDRESS
	for(u8 i=0; i<Copy_u8Length; i++, Copy_u32Address += 2)
	{
		*((volatile u16*)(Copy_u32Address)) = Copy_u16Data[i];
	
		//CHECK BSY FLAG
		while( GET_BIT((FPEC->SR ),0) );

		//CHECK EOP FLAG
		while( !(GET_BIT((FPEC->SR),5)) );

		//RESET EOP FLAG
		SET_BIT( (FPEC->SR),5);
	}
	
	//RESET PG
	CLR_BIT((FPEC->CR),0);
}
//***************************************************************************************************************
