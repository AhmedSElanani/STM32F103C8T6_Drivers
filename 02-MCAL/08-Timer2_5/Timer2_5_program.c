/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 13 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer2_5_interface.h"
#include "Timer2_5_private.h"
#include "Timer2_5_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MTimer2_voidInit (void)
{
	#if (TIMER2_ENABLE == 1)
		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM2->CR1 = (0x4);		//DIR = 0, URS =1
		#elif(TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM2->CR1 = (0x14);		//DIR = 1, URS =1
		#endif
	
		/*	Set Prescaler	*/
		TIM2->PSC =  TIM2_PRESCALER;
		
		/*	Generate UEV	*/
		(TIM2->EGR) =  (0x1);			//UG = 1
	#endif
}
//***************************************************************************************************************
void MTimer2_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER2_ENABLE == 1)
		(TIM2->CR1) &= ~(0x2);			//UDIS = 0
		(TIM2->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM2->CNT)  =  0 ;
			(TIM2->ARR)  =  Copy_u16Ticks;

		#elif (TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM2->CNT)  =  Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM2->EGR) =  (0x1);			//UG = 1

		(TIM2->SR)   =  (0x0);			//UIF = 0
		(TIM2->CR1) |=  (0x9);			//CEN = 1, OPM = 1

		while(!((TIM2->SR)&(0x1))); 	//POLL UIF
		(TIM2->SR)   =  (0x0);			//UIF = 0
	#endif
}
//***************************************************************************************************************
void MTimer2_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void))
{
	#if (TIMER2_ENABLE == 1)
		TIMER2_Callback = Copy_ptr;		//Set Callback

		(TIM2->CR1)   |=  (0x84);		//UDIS = 0, URS = 1, ARPE = 1
		(TIM2->CR1)   &=  ~(0x8); 		//OPM = 0
		(TIM2->DIER)  |=  (0x1);		//UIE = 1

		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM2->CNT)  =  0 ;
			(TIM2->ARR)  =  Copy_u16Ticks;
		#elif (TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM2->ARR)  =  0 - Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM2->EGR) =  (0x1);			//UG = 1

		(TIM2->SR)   =  (0x0);
		(TIM2->CR1) |=  (0x1);			//CEN = 1
	#endif
}
//***************************************************************************************************************
void MTimer2_voidStopTimer (void)
{
	#if (TIMER2_ENABLE == 1)
		(TIM2->CR1)	  &=  ~(0x1);		//CEN = 1
		(TIM2->DIER)  &=  ~(0x1);		//UIE = 0
		(TIM2->SR)     =   (0x0);		//UIF = 0
	#endif
}
//***************************************************************************************************************
u16 MTimer2_u16GetRemainingTime (void)
{
	static volatile u16 Local_u16RemainingTime = 0;

	#if (TIMER2_ENABLE == 1)
		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			Local_u16RemainingTime = (u16)((TIM2->ARR)-(TIM2->CNT));
		#elif (TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			Local_u16RemainingTime = (u16)(TIM2->CNT);
		#endif
	#endif

	return (Local_u16RemainingTime);
}
//***************************************************************************************************************
void MTimer3_voidInit (void)
{
	#if (TIMER3_ENABLE == 1)
		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM3->CR1 = (0x4);		//DIR = 0, URS =1
		#elif (TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM3->CR1 = (0x14);		//DIR = 1, URS =1
		#endif

		/*	Set Prescaler	*/
		TIM3->PSC =  TIM3_PRESCALER;

		/*	Generate UEV	*/
		(TIM3->EGR) =  (0x1);			//UG  = 1

	#endif
}
//***************************************************************************************************************
void MTimer3_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER3_ENABLE == 1)
		(TIM3->CR1) &= ~(0x2);			//UDIS = 0
		(TIM3->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM3->CNT)  =  0 ;
			(TIM3->ARR)  =  Copy_u16Ticks;

		#elif (TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM3->CNT)  =  Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM3->EGR) =  (0x1);			//UG = 1

		(TIM3->SR)   =  (0x0);			//UIF = 0
		(TIM3->CR1) |=  (0x9);			//CEN = 1, OPM = 1

		while(!((TIM3->SR)&(0x1))); 	//POLL UIF
		(TIM3->SR)   =  (0x0);			//UIF = 0
	#endif
}
//***************************************************************************************************************
void MTimer3_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void))
{
	#if (TIMER3_ENABLE == 1)
		TIMER3_Callback = Copy_ptr;		//Set Callback

		(TIM3->CR1)   |=  (0x84);		//UDIS = 0, URS = 1, ARPE = 1
		(TIM3->CR1)   &=  ~(0x8); 		//OPM = 0
		(TIM3->DIER)  |=  (0x1);		//UIE = 1

		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM3->CNT)  =  0 ;
			(TIM3->ARR)  =  Copy_u16Ticks;
		#elif(TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM3->ARR)  =  0 - Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM3->EGR) =  (0x1);			//UG = 1

		(TIM3->SR)   =  (0x0);
		(TIM3->CR1) |=  (0x1);			//CEN = 1
	#endif
}
//***************************************************************************************************************
void MTimer3_voidStopTimer (void)
{
	#if (TIMER3_ENABLE == 1)
		(TIM3->CR1)	  &=  ~(0x1);		//CEN = 1
		(TIM3->DIER)  &=  ~(0x1);		//UIE = 0
		(TIM3->SR)     =   (0x0);		//UIF = 0
	#endif
}
//***************************************************************************************************************
u16 MTimer3_u16GetRemainingTime (void)
{
	static volatile u16 Local_u16RemainingTime = 0;

	#if (TIMER3_ENABLE == 1)
		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			Local_u16RemainingTime = (u16)((TIM3->ARR)-(TIM3->CNT));
		#elif (TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			Local_u16RemainingTime = (u16)(TIM3->CNT);
		#endif
	#endif

	return (Local_u16RemainingTime);
}
//***************************************************************************************************************
void MTimer4_voidInit (void)
{
	#if (TIMER4_ENABLE == 1)
		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM4->CR1 = (0x4);		//DIR = 0, URS =1
		#elif (TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM4->CR1 = (0x14);		//DIR = 1, URS =1
		#endif
	
		/*	Set Prescaler	*/
		TIM4->PSC =  TIM4_PRESCALER;
		
		/*	Generate UEV	*/
		(TIM4->EGR) =  (0x1);		//UG = 1
	#endif
}
//***************************************************************************************************************
void MTimer4_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER4_ENABLE == 1)
		(TIM4->CR1) &= ~(0x2);			//UDIS = 0
		(TIM4->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM4->CNT)  =  0 ;
			(TIM4->ARR)  =  Copy_u16Ticks;

		#elif (TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM4->CNT)  =  Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM4->EGR) =  (0x1);			//UG = 1

		(TIM4->SR)   =  (0x0);			//UIF = 0
		(TIM4->CR1) |=  (0x9);			//CEN = 1, OPM = 1

		while(!((TIM4->SR)&(0x1))); 	//POLL UIF
		(TIM4->SR)   =  (0x0);			//UIF = 0
	#endif
}
//***************************************************************************************************************
void MTimer4_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void))
{
	#if (TIMER4_ENABLE == 1)
		TIMER4_Callback = Copy_ptr;		//Set Callback

		(TIM4->CR1)   |=  (0x84);		//UDIS = 0, URS = 1, ARPE = 1
		(TIM4->CR1)   &=  ~(0x8); 		//OPM = 0
		(TIM4->DIER)  |=  (0x1);		//UIE = 1

		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM4->CNT)  =  0 ;
			(TIM4->ARR)  =  Copy_u16Ticks;
		#elif (TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM4->ARR)  =  0 - Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM4->EGR) =  (0x1);			//UG = 1

		(TIM4->SR)   =  (0x0);
		(TIM4->CR1) |=  (0x1);			//CEN = 1
	#endif
}
//***************************************************************************************************************
void MTimer4_voidStopTimer (void)
{
	#if (TIMER4_ENABLE == 1)
		(TIM4->CR1)	  &=  ~(0x1);		//CEN = 1
		(TIM4->DIER)  &=  ~(0x1);		//UIE = 0
		(TIM4->SR)     =   (0x0);		//UIF = 0
	#endif
}
//***************************************************************************************************************
u16 MTimer4_u16GetRemainingTime (void)
{
	static volatile u16 Local_u16RemainingTime = 0;

	#if (TIMER4_ENABLE == 1)
		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			Local_u16RemainingTime = (u16)((TIM4->ARR)-(TIM4->CNT));
		#elif (TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			Local_u16RemainingTime = (u16)(TIM4->CNT);
		#endif
	#endif

	return (Local_u16RemainingTime);
}
//***************************************************************************************************************
void MTimer5_voidInit (void)
{
	#if (TIMER5_ENABLE == 1)
		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM5->CR1 = (0x4);		//DIR = 0, URS =1
		#elif (TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM5->CR1 = (0x14);		//DIR = 1, URS =1
		#endif
	
		/*	Set Prescaler	*/
		TIM5->PSC =  TIM5_PRESCALER;
		
		/*	Generate UEV	*/
		(TIM5->EGR) =  (0x1);			//UG = 1
	#endif
}
//***************************************************************************************************************
void MTimer5_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER5_ENABLE == 1)
		(TIM5->CR1) &= ~(0x2);			//UDIS = 0
		(TIM5->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM5->CNT)  =  0 ;
			(TIM5->ARR)  =  Copy_u16Ticks;

		#elif (TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM5->CNT)  =  Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM5->EGR) =  (0x1);			//UG = 1

		(TIM5->SR)   =  (0x0);			//UIF = 0
		(TIM5->CR1) |=  (0x9);			//CEN = 1, OPM = 1

		while(!((TIM5->SR)&(0x1))); 	//POLL UIF
		(TIM5->SR)   =  (0x0);			//UIF = 0
	#endif
}
//***************************************************************************************************************
void MTimer5_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void))
{
	#if (TIMER5_ENABLE == 1)
		TIMER5_Callback = Copy_ptr;		//Set Callback

		(TIM5->CR1)   |=  (0x84);		//UDIS = 0, URS = 1, ARPE = 1
		(TIM5->CR1)   &=  ~(0x8); 		//OPM = 0
		(TIM5->DIER)  |=  (0x1);		//UIE = 1

		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM5->CNT)  =  0 ;
			(TIM5->ARR)  =  Copy_u16Ticks;
		#elif (TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM5->ARR)  =  0 - Copy_u16Ticks;
		#endif

		/*	Generate UEV	*/
		(TIM5->EGR) =  (0x1);			//UG = 1

		(TIM5->SR)   =  (0x0);
		(TIM5->CR1) |=  (0x1);			//CEN = 1
	#endif
}
//***************************************************************************************************************
void MTimer5_voidStopTimer (void)
{
	#if (TIMER5_ENABLE == 1)
		(TIM5->CR1)	  &=  ~(0x1);		//CEN = 1
		(TIM5->DIER)  &=  ~(0x1);		//UIE = 0
		(TIM5->SR)     =   (0x0);		//UIF = 0
	#endif
}
//***************************************************************************************************************
u16 MTimer5_u16GetRemainingTime (void)
{
	static volatile u16 Local_u16RemainingTime = 0;

	#if (TIMER5_ENABLE == 1)
		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			Local_u16RemainingTime = (u16)((TIM5->ARR)-(TIM5->CNT));
		#elif (TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			Local_u16RemainingTime = (u16)(TIM5->CNT);
		#endif
	#endif

	return (Local_u16RemainingTime);
}
/*
*********************************************************************************************************
*                                           	ISR'S
*********************************************************************************************************
*/
void TIM2_IRQHandler (void)
{
	/*CLEAR INTERRUPT FLAG*/
	(TIM2->SR)   =  (0x0);

	if(TIMER2_Callback)
	{
		TIMER2_Callback();
	}
}
//***************************************************************************************************************
void TIM3_IRQHandler(void)
{
	/*CLEAR INTERRUPT FLAG*/
	(TIM3->SR)   =  (0x0);

	if(TIMER3_Callback)
	{
		TIMER3_Callback();
	}
}
//***************************************************************************************************************
void TIM4_IRQHandler(void)
{
	/*CLEAR INTERRUPT FLAG*/
	(TIM4->SR)   =  (0x0);

	if(TIMER4_Callback)
	{
		TIMER4_Callback();
	}
}
//***************************************************************************************************************
