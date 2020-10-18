/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 31 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
/* 	Please define IR NEC Receiver Output Pin in the form:			GPIOX,PINx		*/
#define		IR_NEC_RECEIVER_OUTPUT_PIN								GPIOB,PIN11

/* 	Please define IR NEC Receiver AFIO EXTI Line in the form:		AFIO_EXTI_LINE_x, AFIO_EXTI_PX	*/
#define		IR_NEC_RECEIVER_AFIO_EXTI_LINE							AFIO_EXTI_LINE_11, AFIO_EXTI_PB

/* 	Please define IR NEC Receiver EXTI Line in the form:			EXTI_LINE_x		*/
#define		IR_NEC_RECEIVER_EXTI_LINE								EXTI_LINE_11

/* 	Please define IR NEC Receiver IRQ Number in the form:			NVIC_IRQ_EXTIx	*/
#define		IR_NEC_RECEIVER_NVIC_IRQ_EXTI							NVIC_IRQ_EXTI15_10


#endif
//***************************************************************************************************************



