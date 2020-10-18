/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 26 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


//GLOBAL VARIABLES
static  void (*volatile SysTick_Callback)(void) =  0;
static  volatile u8 Callback_Mode				=  0;

//STRUCTURE TO HOLD SysTick REGISTERS
typedef struct 
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
} SysTick_TypeDef;

//POINTER TO THIS STRUCTURE 
#define SysTick 							((volatile SysTick_TypeDef*)(0xE000E010))

//SYSTICK INPUT CLOCK SOURCE
#define	SYSTICK_CLOCKSOURCE_AHB				(0)
#define	SYSTICK_CLOCKSOURCE_AHB_DIV8		(1)

//SYSTICK INPUT CLOCK SOURCE
#define	SYSTICK_CALLBACK_MODE_SINGLE		(0)
#define	SYSTICK_CALLBACK_MODE_PERIODIC		(1)


#endif
//***************************************************************************************************************
