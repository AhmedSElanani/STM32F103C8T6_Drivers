/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 5 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void SOS_voidCreateTask     (u8 Copy_u8TaskPriority, u16 Copy_u16TaskID, u32 Copy_u32TaskPeriod, u32 Copy_u32TaskInitialDelay, void (*Copy_ptr) (void));
void SOS_voidStartScheduler (void);
void SOS_voidSuspendTask    (void (*Copy_ptr) (void));
void SOS_voidResumeTask     (void (*Copy_ptr) (void));
void SOS_voidKillTask       (void (*Copy_ptr) (void));

#endif
//***************************************************************************************************************
