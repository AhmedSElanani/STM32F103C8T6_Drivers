/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 22 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//GLOBAL VARIABLES
static  void (*volatile EXTI_Callback[16])(void) = {0};

//STRUCTURE TO HOLD EXTI REGISTERS
typedef struct 
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RSTR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;	
} EXTI_TypeDef;

//POINTER TO THIS STRUCTURE 
#define EXTI ((volatile EXTI_TypeDef*)(0x40010400))

#endif
//***************************************************************************************************************
