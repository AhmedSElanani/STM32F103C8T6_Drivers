/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 8 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
/* Options: RCC_HSE_CRYSTAL
			RCC_HSE_RC
			RCC_HSI			
			RCC_PLL				*/
#define RCC_CLOCK_TYPE 		(RCC_HSE_CRYSTAL)


/* Note: Select Value only if you have PLL as input Clock Source	*/
#if (RCC_CLOCK_TYPE == RCC_PLL)
	/* Options: RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_CRYSTAL_DIV_2
				RCC_PLL_IN_HSE_CRYSTAL
				RCC_PLL_IN_HSE_RC_DIV_2
				RCC_PLL_IN_HSE_RC				*/
	#define RCC_PLL_INPUT 		(RCC_PLL_IN_HSE_DIV_2)

	/* Options: 2 to 16	*/
	#define RCC_PLL_MUL_VAL 	(4)
#endif	/* End of PLL Configuration	*/

#endif	/* End of Configuration	*/
//***************************************************************************************************************
