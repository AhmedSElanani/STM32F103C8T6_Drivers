/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 22 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
//ALTERNATE FUNCTION EXTI INPUT SOURCE GPIOS
#define	AFIO_EXTI_PA			((u8)(0))
#define	AFIO_EXTI_PB			((u8)(1))
#define	AFIO_EXTI_PC			((u8)(2))

//ALTERNATE FUNCTION EXTI INPUT SOURCE LINES
#define	AFIO_EXTI_LINE_0		((u8)(0))
#define	AFIO_EXTI_LINE_1		((u8)(1))
#define	AFIO_EXTI_LINE_2		((u8)(2))
#define	AFIO_EXTI_LINE_3		((u8)(3))
#define	AFIO_EXTI_LINE_4		((u8)(4))
#define	AFIO_EXTI_LINE_5		((u8)(5))
#define	AFIO_EXTI_LINE_6		((u8)(6))
#define	AFIO_EXTI_LINE_7		((u8)(7))
#define	AFIO_EXTI_LINE_8		((u8)(8))
#define	AFIO_EXTI_LINE_9		((u8)(9))
#define	AFIO_EXTI_LINE_10		((u8)(10))
#define	AFIO_EXTI_LINE_11		((u8)(11))
#define	AFIO_EXTI_LINE_12		((u8)(12))
#define	AFIO_EXTI_LINE_13		((u8)(13))
#define	AFIO_EXTI_LINE_14		((u8)(14))
#define	AFIO_EXTI_LINE_15		((u8)(15))

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MAFIO_voidSetEXTILine (u8 copy_u8EXTILine, u8 copy_u8GPIO_EXTISource);

#endif
//***************************************************************************************************************
