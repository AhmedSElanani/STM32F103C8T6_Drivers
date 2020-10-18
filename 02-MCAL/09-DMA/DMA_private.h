/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


/*
*********************************************************************************************************
*                                           TYPE DEFINITIONS
*********************************************************************************************************
*/
/*	STRUCTURE TO HOLD CHANNEL REGISTERS	*/
typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
} Channel_TypeDef;

/*	STRUCTURE TO HOLD DMA REGISTERS	*/
typedef struct 
{
	volatile u32 			 ISR;
	volatile u32 			 IFCR;
	volatile Channel_TypeDef Channel[7];
} DMA_TypeDef;


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/*	POINTERS TO THE TYPE DMA_TypeDef	*/ 
#define DMA1 					((volatile DMA_TypeDef*)(0x40020000))


/*	GLOBAL INTERRUPT FLAGS	*/
#define DMA1_CGIF1			 	(0x00000001)
#define DMA1_CGIF2			 	(0x00000010)
#define DMA1_CGIF3			 	(0x00000100)
#define DMA1_CGIF4			 	(0x00001000)
#define DMA1_CGIF5			 	(0x00010000)
#define DMA1_CGIF6			 	(0x00100000)
#define DMA1_CGIF7			 	(0x01000000)


/*	CONFIGURATION OPTIONS	*/
#define DMA_CH_MSIZE_8BITS 		(0)
#define DMA_CH_MSIZE_16BITS		(1)
#define DMA_CH_MSIZE_32BITS		(2)

#define DMA_CH_PSIZE_8BITS 		(0)
#define DMA_CH_PSIZE_16BITS		(1)
#define DMA_CH_PSIZE_32BITS		(2)


/*
*********************************************************************************************************
*                                           GLOBAL VARIABLES
*********************************************************************************************************
*/
static  void (*volatile DMA_Callback[7])(void) = { 0 };


#endif
//***************************************************************************************************************
