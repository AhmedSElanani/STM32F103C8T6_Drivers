/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 26 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MSysTick_voidInit(void);
void MSysTick_voidSetBusyWait(u32 Copy_u32Ticks);
void MSysTick_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void MSysTick_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void MSysTick_voidStopInterval(void);
u32  MSysTick_u32GetElapsedTime(void);
u32  MSysTick_u32GetRemainingTime(void);

#endif
//***************************************************************************************************************
