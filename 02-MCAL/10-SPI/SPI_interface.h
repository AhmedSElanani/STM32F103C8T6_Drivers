/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 16 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MSPI1_voidInit 				  (void);
void MSPI1_voidSendReceiveSynchronous (u8 Copy_u8DataToTransmit, u8* Copy_pu8DataToReceive);
void MSPI1_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_ptr)(u8));
void MSPI2_voidInit 				  (void);
void MSPI2_voidSendReceiveSynchronous (u8 Copy_u8DataToTransmit, u8* Copy_pu8DataToReceive);
void MSPI2_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_ptr)(u8));

#endif
//***************************************************************************************************************
