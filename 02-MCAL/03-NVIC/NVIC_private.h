/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 19 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*
*********************************************************************************************************
*                                      EXTERNAL GLOBAL VARIABLES
*********************************************************************************************************
*/
extern u8 Global_u8Interrupt_SW_Grouping ;


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/* NVIC REGISTERS */
#define NVIC_ISER0						(*((volatile u32*)(0xE000E100)))	/* Enable External Interrupts from 0 to 31 */
#define NVIC_ISER1						(*((volatile u32*)(0xE000E104)))	/* Enable External Interrupts from 32 to 63 */

#define NVIC_ICER0						(*((volatile u32*)(0xE000E180)))	/* Disable External Interrupts from 0 to 31 */
#define NVIC_ICER1						(*((volatile u32*)(0xE000E184)))	/* Disable External Interrupts from 32 to 63 */

#define NVIC_ISPR0						(*((volatile u32*)(0xE000E200)))	/* Set Pending Flag for Interrupts from 0 to 31 */
#define NVIC_ISPR1						(*((volatile u32*)(0xE000E204)))	/* Set Pending Flag for Interrupts from 32 to 63 */

#define NVIC_ICPR0						(*((volatile u32*)(0xE000E280)))	/* Clear Pending Flag for Interrupts from 0 to 31 */
#define NVIC_ICPR1						(*((volatile u32*)(0xE000E284)))	/* Clear Pending Flag for Interrupts from 32 to 63 */

#define NVIC_IABR0						(*((volatile u32*)(0xE000E300)))	/* Shows Active Interrupt from 0 to 31 */
#define NVIC_IABR1						(*((volatile u32*)(0xE000E304)))	/* Shows Active Interrupt from 32 to 63 */

#define NVIC_IPR						((volatile u8*)(0xE000E400))		/* Interrupt Priority registers from 0 to 255 */


#endif
//***************************************************************************************************************
