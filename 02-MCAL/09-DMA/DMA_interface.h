/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/*	DMA1 CHANNELS	*/
#define DMA1_CHANNEL1		 	(0)
#define DMA1_CHANNEL2 			(1)
#define DMA1_CHANNEL3 			(2)
#define DMA1_CHANNEL4 			(3)
#define DMA1_CHANNEL5 			(4)
#define DMA1_CHANNEL6 			(5)
#define DMA1_CHANNEL7 			(6)


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MDMA_voidInit 				   (void);
void MDMA_voidSetPeripheralAddress (u8 Copy_u8Channel, u32*   Copy_pu32PeripheralAddress);
void MDMA_voidSetMemoryAddress 	   (u8 Copy_u8Channel, u32*   Copy_pu32MemoryAddress);
void MDMA_voidSetNumberOfData 	   (u8 Copy_u8Channel, u16    Copy_u16NumberOfData);
void MDMA_voidSetCallback 	 	   (u8 Copy_u8Channel, void (*Copy_ptr)(void));
void MDMA_voidEnableChannel  	   (u8 Copy_u8Channel);
void MDMA_voidDisableChannel 	   (u8 Copy_u8Channel);


#endif
//***************************************************************************************************************
