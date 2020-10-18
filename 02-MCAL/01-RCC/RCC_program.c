/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 8 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MRCC_voidInitSysClock (void)
{
	#if(RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)
		RCC_CR   = 0x00010080;									/* Enable HSE with no bypass + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x00020000)));						/* Check HSE is Ready */
		RCC_CFGR = 0x00000001;									/* HSE selected as system clock */

	#elif(RCC_CLOCK_TYPE == RCC_HSE_RC)
		RCC_CR   = 0x00050080;									/* Enable HSE with no bypass + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x00020000)));						/* Check HSE is Ready */
		RCC_CFGR = 0x00000001;									/* Enable HSE with no bypass + (Default Trimming = 0) */

	#elif(RCC_CLOCK_TYPE == RCC_HSI)
		RCC_CR   = 0x00000081;									/* Enable HSI + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x00000002)));						/* Check HSI is Ready */
		RCC_CFGR = 0x00000000;									/* HSI selected as system clock */

	#elif(RCC_CLOCK_TYPE == RCC_PLL)
		#if(RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2)				/* PLL INPUT CLOCK: (HSI/2) */
			RCC_CR   = 0x00000081;								/* Enable HSI + (Default Trimming = 0) */
			RCC_CFGR = 0x00000000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2)	/* PLL INPUT CLOCK: (HSE/2) */
			RCC_CR   = 0x00010080;								/* Enable HSE with no bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00030000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL)			/* PLL INPUT CLOCK: (HSE) */
			RCC_CR   = 0x00010080;								/* Enable HSE with no bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00010000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_DIV_2)			/* PLL INPUT CLOCK: (HSE/2) */
			RCC_CR   = 0x00050080;								/* Enable HSE with bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00030000;

		#elif(RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_)				/* PLL INPUT CLOCK: (HSE) */
			RCC_CR   = 0x00050080;								/* Enable HSE with bypass + (Default Trimming = 0) */
			RCC_CFGR = 0x00010000;
		#endif


		#if(RCC_PLL_MUL_VAL == 2)						/* PLL Multiplier =  (2) */
			RCC_CFGR |= 0x00000000;

		#elif(RCC_PLL_MUL_VAL == 3)						/* PLL Multiplier =  (3) */
			RCC_CFGR |= 0x00040000;

		#elif(RCC_PLL_MUL_VAL == 4)						/* PLL Multiplier =  (4) */
			RCC_CFGR |= 0x00080000;

		#elif(RCC_PLL_MUL_VAL == 5)						/* PLL Multiplier =  (5) */
			RCC_CFGR |= 0x000C0000;

		#elif(RCC_PLL_MUL_VAL == 6)						/* PLL Multiplier =  (6) */
			RCC_CFGR |= 0x00100000;

		#elif(RCC_PLL_MUL_VAL == 7)						/* PLL Multiplier =  (7) */
			RCC_CFGR |= 0x00140000;

		#elif(RCC_PLL_MUL_VAL == 8)						/* PLL Multiplier =  (8) */
			RCC_CFGR |= 0x00180000;

		#elif(RCC_PLL_MUL_VAL == 9)						/* PLL Multiplier =  (9) */
			RCC_CFGR |= 0x001C0000;

		#elif(RCC_PLL_MUL_VAL == 10)					/* PLL Multiplier =  (10) */
			RCC_CFGR |= 0x00200000;

		#elif(RCC_PLL_MUL_VAL == 11)					/* PLL Multiplier =  (11) */
			RCC_CFGR |= 0x00240000;

		#elif(RCC_PLL_MUL_VAL == 12)					/* PLL Multiplier =  (12) */
			RCC_CFGR |= 0x00280000;

		#elif(RCC_PLL_MUL_VAL == 13)					/* PLL Multiplier =  (13) */
			RCC_CFGR |= 0x002C0000;

		#elif(RCC_PLL_MUL_VAL == 14)					/* PLL Multiplier =  (14) */
			RCC_CFGR |= 0x00300000;

		#elif(RCC_PLL_MUL_VAL == 15)					/* PLL Multiplier =  (15) */
			RCC_CFGR |= 0x00340000;

		#elif(RCC_PLL_MUL_VAL == 16)					/* PLL Multiplier =  (16) */
			RCC_CFGR |= 0x00380000;
		#endif

		/* The PLL configuration (selection of HSI oscillator divided by 2 or HSE oscillator for PLL
		   input clock, and multiplication factor) must be done before enabling the PLL. Once the PLL
		   enabled, these parameters cannot be changed.	*/
		RCC_CR   |= 0x01000080;							/* Enable PLL + (Default Trimming = 0) */
		while(!((RCC_CR)&(0x02000000)));				/* Check PLL is Ready */
		RCC_CFGR |= 0x00000002;							/* PLL selected as system clock */

	#else
		//#error("You Chose Wrong Clock Type")			/* Return Error */
	#endif
}
//***************************************************************************************************************
void MRCC_voidEnableClock (u8 Copy_u8BusID, u8 Copy_u8PerID)
{
	if(Copy_u8PerID <= 31)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	SET_BIT(RCC_AHBENR  ,Copy_u8PerID);		break;
			case RCC_APB1:	SET_BIT(RCC_APB1ENR ,Copy_u8PerID);		break;
			case RCC_APB2:	SET_BIT(RCC_APB2ENR ,Copy_u8PerID);		break;
		  //default	     :	#error("You Chose wrong Bus ") 			break;	/* Return Error */
		}
	}
	else
	{
		//#error("Pin must be between (0) and (31) ")		/* Return Error */
	}
}
//***************************************************************************************************************
void MRCC_voidDisableClock (u8 Copy_u8BusID, u8 Copy_u8PerID)
{
	if(Copy_u8PerID <= 31)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB :	CLR_BIT(RCC_AHBENR  ,Copy_u8PerID);		break;
			case RCC_APB1:	CLR_BIT(RCC_APB1ENR ,Copy_u8PerID);		break;
			case RCC_APB2:	CLR_BIT(RCC_APB2ENR ,Copy_u8PerID);		break;
		  //default	     :	#error("You Chose wrong Bus ") 			break;	/* Return Error */
		}
	}
	else
	{
		//#error("Pin must be between (0) and (31) ")		/* Return Error */
	}
}
//***************************************************************************************************************
