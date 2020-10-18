/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 22 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/* EXTI LINES */
#define		EXTI_LINE_0			((u8)(0))
#define		EXTI_LINE_1			((u8)(1))
#define		EXTI_LINE_2			((u8)(2))
#define		EXTI_LINE_3			((u8)(3))
#define		EXTI_LINE_4			((u8)(4))
#define		EXTI_LINE_5			((u8)(5))
#define		EXTI_LINE_6			((u8)(6))
#define		EXTI_LINE_7			((u8)(7))
#define		EXTI_LINE_8			((u8)(8))
#define		EXTI_LINE_9			((u8)(9))
#define		EXTI_LINE_10		((u8)(10))
#define		EXTI_LINE_11		((u8)(11))
#define		EXTI_LINE_12		((u8)(12))
#define		EXTI_LINE_13		((u8)(13))
#define		EXTI_LINE_14		((u8)(14))
#define		EXTI_LINE_15		((u8)(15))

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MEXTI_voidInit(void);
void MEXTI_voidEnable_EXTI_Line(u8 copy_u8Line);
void MEXTI_voidDisable_EXTI_Line(u8 copy_u8Line);
void MEXTI_voidSW_Trigger_EXTI_Line(u8 copy_u8Line);
u8   MEXTI_voidCheckPending_EXTI_Line(u8 copy_u8Line);
void MEXTI_voidClearPending_EXTI_Line(u8 copy_u8Line);
void MEXTI_voidSetCallback(u8 copy_u8Line, void (*Copy_ptr)(void));

#endif
//***************************************************************************************************************
