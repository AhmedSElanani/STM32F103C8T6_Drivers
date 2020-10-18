/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 19 Aug 2020										  */
/* Version	: V02												  */
/******************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*
*********************************************************************************************************
*                                           PRIVATE MACROS
*********************************************************************************************************
*/
/* Registers Definitions */
				/* GPIOA Registers  */
#define		GPIOA_CRL			(*((volatile u32*)(0x40010800)))		
#define		GPIOA_CRH			(*((volatile u32*)(0x40010804)))		
#define		GPIOA_IDR			(*((volatile u32*)(0x40010808)))		 
#define		GPIOA_ODR			(*((volatile u32*)(0x4001080C)))		
#define		GPIOA_BSR			(*((volatile u32*)(0x40010810)))		
#define		GPIOA_BRR			(*((volatile u32*)(0x40010814)))		
#define		GPIOA_LCK			(*((volatile u32*)(0x40010818)))	
	
				/* GPIOB Registers  */
#define		GPIOB_CRL			(*((volatile u32*)(0x40010C00)))		
#define		GPIOB_CRH			(*((volatile u32*)(0x40010C04)))		
#define		GPIOB_IDR			(*((volatile u32*)(0x40010C08)))		
#define		GPIOB_ODR			(*((volatile u32*)(0x40010C0C)))		
#define		GPIOB_BSR			(*((volatile u32*)(0x40010C10)))		
#define		GPIOB_BRR			(*((volatile u32*)(0x40010C14)))		
#define		GPIOB_LCK			(*((volatile u32*)(0x40010C18)))	
	
				/* GPIOC Registers  */
#define		GPIOC_CRL			(*((volatile u32*)(0x40011000)))		
#define		GPIOC_CRH			(*((volatile u32*)(0x40011004)))		
#define		GPIOC_IDR			(*((volatile u32*)(0x40011008)))		
#define		GPIOC_ODR			(*((volatile u32*)(0x4001100C)))		
#define		GPIOC_BSR			(*((volatile u32*)(0x40011010)))		
#define		GPIOC_BRR			(*((volatile u32*)(0x40011014)))		
#define		GPIOC_LCK			(*((volatile u32*)(0x40011018)))		

#endif
//***************************************************************************************************************
