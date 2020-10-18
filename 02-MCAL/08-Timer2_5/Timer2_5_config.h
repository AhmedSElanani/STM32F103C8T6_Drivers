/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 13 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef Timer2_5_CONFIG_H
#define Timer2_5_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
#define TIMER2_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define TIMER3_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define TIMER4_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define TIMER5_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE


/* Note: Select Value only if you Enabled TIMER2 */ 
#if (TIMER2_ENABLE == 1)
	#define TIM2_DIRECTION 		(TIM2_5_DIRECTION_UP)		// (TIM2_5_DIRECTION_UP) OR (TIM2_5_DIRECTION_DOWN)
	#define TIM2_PRESCALER 		(7UL)						// FROM (0) UP TO (65535UL) 
#endif	/* End of TIMER2 Configuration	*/


/* Note: Select Value only if you Enabled TIMER3 */ 
#if (TIMER3_ENABLE == 1)
	#define TIM3_DIRECTION 		(TIM2_5_DIRECTION_UP)		// (TIM2_5_DIRECTION_UP) OR (TIM2_5_DIRECTION_DOWN) 
	#define TIM3_PRESCALER 		(7999UL)					// FROM (0) UP TO (65535UL)
#endif	/* End of TIMER3 Configuration	*/


/* Note: Select Value only if you Enabled TIMER4 */ 
#if (TIMER4_ENABLE == 1)
	#define TIM4_DIRECTION 		(TIM2_5_DIRECTION_UP)		// (TIM2_5_DIRECTION_UP) OR (TIM2_5_DIRECTION_DOWN) 
	#define TIM4_PRESCALER 		(0UL)						// FROM (0) UP TO (65535UL) 
#endif	/* End of TIMER4 Configuration	*/


/* Note: Select Value only if you Enabled TIMER5 */ 
#if (TIMER5_ENABLE == 1)
	#define TIM5_DIRECTION 		(TIM2_5_DIRECTION_UP)		// (TIM2_5_DIRECTION_UP) OR (TIM2_5_DIRECTION_DOWN) 
	#define TIM5_PRESCALER 		(0UL)						// FROM (0) UP TO (65535UL) 
#endif	/* End of TIMER5 Configuration	*/


#endif
//***************************************************************************************************************
