/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 13 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef Timer2_5_INTERFACE_H
#define Timer2_5_INTERFACE_H


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MTimer2_voidInit 				 (void);
void MTimer2_voidSetBusyWait		 (u16 Copy_u16Ticks);
void MTimer2_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void));
void MTimer2_voidStopTimer 			 (void);
u16  MTimer2_u16GetRemainingTime     (void);

void MTimer3_voidInit 				 (void);
void MTimer3_voidSetBusyWait 		 (u16 Copy_u16Ticks);
void MTimer3_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void));
void MTimer3_voidStopTimer 			 (void);
u16  MTimer3_u16GetRemainingTime     (void);

void MTimer4_voidInit 				 (void);
void MTimer4_voidSetBusyWait		 (u16 Copy_u16Ticks);
void MTimer4_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void));
void MTimer4_voidStopTimer 			 (void);
u16  MTimer4_u16GetRemainingTime     (void);

void MTimer5_voidInit 				 (void);
void MTimer5_voidSetBusyWait		 (u16 Copy_u16Ticks);
void MTimer5_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void));
void MTimer5_voidStopTimer 			 (void);
u16  MTimer5_u16GetRemainingTime     (void);

#endif
//***************************************************************************************************************
