/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 13 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef Timer2_5_PRIVATE_H
#define Timer2_5_PRIVATE_H


/*
*********************************************************************************************************
*                                           TYPE DEFINITIONS
*********************************************************************************************************
*/
/*	STRUCTURE TO HOLD TIMER2_5 REGISTERS	*/
typedef struct 
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 Reserved_1;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 Reserved_2;
	volatile u32 DCR;
	volatile u32 DMAR;
} Timer2_5_TypeDef;


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/*	POINTERS TO THE TYPE TIMER2_5_TYPEDEF	*/ 
#define TIM2 					((volatile Timer2_5_TypeDef*)(0x40000000))
#define TIM3 					((volatile Timer2_5_TypeDef*)(0x40000400))
#define TIM4 					((volatile Timer2_5_TypeDef*)(0x40000800))
#define TIM5 					((volatile Timer2_5_TypeDef*)(0x40000C00))


/*	CONFIGURATION OPTIONS*/
#define TIM2_5_DIRECTION_UP 	(0)
#define TIM2_5_DIRECTION_DOWN 	(1)


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/
static void (*volatile TIMER2_Callback)(void) = 0 ;
static void (*volatile TIMER3_Callback)(void) = 0 ;
static void (*volatile TIMER4_Callback)(void) = 0 ;
static void (*volatile TIMER5_Callback)(void) = 0 ;

#endif
//***************************************************************************************************************
