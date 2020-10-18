/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 22 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

//STRUCTURE TO HOLD AFIO REGISTERS
typedef struct 
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
} AFIO_TypeDef;

//POINTER TO THIS STRUCTURE 
#define AFIO ((volatile AFIO_TypeDef*)(0x40010000))	


#endif
//***************************************************************************************************************
