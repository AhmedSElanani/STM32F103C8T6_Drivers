/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 14 Sep 2020										  */
/* Version	: V02												  */
/******************************************************************/
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
/* 	Please define Delay after each column in Ticks	*/
#define		LEDMRX_TICKS_DELAY					(2000UL)	//Gives more than (60 Frames/Sec)

/* 	Please define ROW_PIN pair in the form:		GPIOx,PINx	*/
#define		LEDMRX_ROW0_PIN						GPIOA,PIN0
#define		LEDMRX_ROW1_PIN						GPIOA,PIN1
#define		LEDMRX_ROW2_PIN						GPIOA,PIN2
#define		LEDMRX_ROW3_PIN						GPIOA,PIN3
#define		LEDMRX_ROW4_PIN						GPIOA,PIN4
#define		LEDMRX_ROW5_PIN						GPIOA,PIN5
#define		LEDMRX_ROW6_PIN						GPIOA,PIN6
#define		LEDMRX_ROW7_PIN						GPIOA,PIN7

/* 	Please define ROW_PIN pair in the form:		GPIOx,PINx	*/
#define		LEDMRX_COL0_PIN						GPIOB,PIN0
#define		LEDMRX_COL1_PIN						GPIOB,PIN1
#define		LEDMRX_COL2_PIN						GPIOB,PIN5
#define		LEDMRX_COL3_PIN						GPIOB,PIN6
#define		LEDMRX_COL4_PIN						GPIOB,PIN7
#define		LEDMRX_COL5_PIN						GPIOB,PIN8
#define		LEDMRX_COL6_PIN						GPIOB,PIN9
#define		LEDMRX_COL7_PIN						GPIOB,PIN10


#endif
//***************************************************************************************************************



