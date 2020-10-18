/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 16 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


/*
*****************************************************************************************************************
*                               	            FUNCTION DEFINITIONS
*****************************************************************************************************************
*/
void MSPI1_voidInit (void)
{
	#if (SPI1_ENABLE == 1)
		MGPIO_voidSetPinMode (GPIOA,PIN5, OUTPUT_AF_PP_10MHZ);
		MGPIO_voidSetPinMode (GPIOA,PIN7, OUTPUT_AF_PP_10MHZ);
		MGPIO_voidSetPinMode (GPIOA,PIN6, 	INPUT_PULLUP   );
		MGPIO_voidSetPinMode (SPI1_SLAVE, OUTPUT_GP_PP_2MHZ);
		
		SPI1->CR1 = (0x300); 
		
		#if (SPI1_CPHA == SPI1_CPHA_WR)
			SPI1->CR1 |= (0x1); 
		#endif		
		
		#if (SPI1_CPOL == SPI1_CPOL_IDLEHIGH)
			SPI1->CR1 |= (0x2); 
		#endif		
		
		#if (SPI1_MODE == SPI1_MODE_MASTER)
			SPI1->CR1 |= (0x4); 
		#endif		
		
		#if (SPI1_CLOCKPRE)
			SPI1->CR1 |= (SPI1_CLOCKPRE); 
		#endif
		
		#if (SPI1_DATAORDER == SPI1_DATAORDER_LSBFIRST)
			SPI1->CR1 |= (0x80); 
		#endif

		#if (SPI1_DATASIZE == SPI1_DATASIZE_16BITS)
			SPI1->CR1 |= (0x800); 
		#endif

		/*	Enable SPI1 Peripheral	*/
		SPI1->CR1 |= (0x40); 
	#endif	
}
//***************************************************************************************************************
void MSPI1_voidSendReceiveSynchronous (u8 Copy_u8DataToTransmit, u8* Copy_pu8DataToReceive)
{
	#if (SPI1_ENABLE == 1)
		/*	Set Slave_Select_Pin Low	*/
		MGPIO_voidSetPinValue(SPI1_SLAVE,GPIO_PIN_LOW);
		
		/*	Make sure TXE flag is Set	*/
		while(!(GET_BIT(SPI1-> SR,1)));
		
		/*	Send Data	*/
		SPI1-> DR = Copy_u8DataToTransmit;
		
		/*	Wait Busy Flag to finish to wait until the completion of the transfer	*/
		while((GET_BIT(SPI1-> SR,7)));
		
		/*	Make sure RXNE flag is Set	*/
		while(!(GET_BIT(SPI1-> SR,0)));
		
		/*	Write the received Data*/
		*Copy_pu8DataToReceive = SPI1-> DR;
		
		/*	Set Slave_Select_Pin High	*/
		MGPIO_voidSetPinValue(SPI1_SLAVE,GPIO_PIN_HIGH);
	#endif	
}
//***************************************************************************************************************
void MSPI1_voidSendReceiveAsynchronous (u8 Copy_u8DataToTransmit, void (*Copy_ptr)(u8))
{
	#if (SPI1_ENABLE == 1)
		/*	Set the Callback Function	*/
		SPI1_Callback = Copy_ptr;

	/*	Set Slave_Select_Pin Low	*/
		MGPIO_voidSetPinValue(SPI1_SLAVE,GPIO_PIN_LOW);
		
		/*	Make sure TXE flag is Set	*/
		while(!(GET_BIT(SPI1-> SR,1)));
		
		/*	Send Data	*/
		SPI1-> DR = Copy_u8DataToTransmit;
	#endif	
}
//***************************************************************************************************************
void MSPI2_voidInit (void)
{
	#if (SPI2_ENABLE == 1)
		MGPIO_voidSetPinMode (GPIOB,PIN13, OUTPUT_AF_PP_2MHZ);	
		MGPIO_voidSetPinMode (GPIOB,PIN15, OUTPUT_AF_PP_2MHZ);
		MGPIO_voidSetPinMode (GPIOB,PIN14, 	INPUT_PULLUP   );
		MGPIO_voidSetPinMode (SPI2_SLAVE , OUTPUT_GP_PP_2MHZ);
		
		SPI2->CR1 = (0x300); 
		
		#if (SPI2_CPHA == SPI2_CPHA_WR)
			SPI2->CR1 |= (0x1); 
		#endif		
		
		#if (SPI2_CPOL == SPI2_CPOL_IDLEHIGH)
			SPI2->CR1 |= (0x2); 
		#endif		
		
		#if (SPI2_MODE == SPI2_MODE_MASTER)
			SPI2->CR1 |= (0x4); 
		#endif		
		
		#if (SPI2_CLOCKPRE)
			SPI2->CR1 |= (SPI2_CLOCKPRE); 
		#endif
		
		#if (SPI2_DATAORDER == SPI2_DATAORDER_LSBFIRST)
			SPI2->CR1 |= (0x80); 
		#endif

		#if (SPI2_DATASIZE == SPI2_DATASIZE_16BITS)
			SPI2->CR1 |= (0x800); 
		#endif

		/*	Enable SPI2 Peripheral	*/
		SPI2->CR1 |= (0x40); 
	#endif	
}
//***************************************************************************************************************
void MSPI2_voidSendReceiveSynchronous (u8 Copy_u8DataToTransmit, u8* Copy_pu8DataToReceive)
{
	#if (SPI2_ENABLE == 1)
		/*	Set Slave_Select_Pin Low	*/
		MGPIO_voidSetPinValue(SPI2_SLAVE,GPIO_PIN_LOW);
		
		/*	Make sure TXE flag is Set	*/
		while(!(GET_BIT(SPI2-> SR,1)));
		
		/*	Send Data	*/
		SPI2-> DR = Copy_u8DataToTransmit;
		
		/*	Wait Busy Flag to finish to wait until the completion of the transfer	*/
		while((GET_BIT(SPI2-> SR,7)));
		
		/*	Make sure RXNE flag is Set	*/
		while(!(GET_BIT(SPI2-> SR,0)));
		
		/*	Write the received Data*/
		*Copy_pu8DataToReceive = SPI2-> DR;
		
		/*	Set Slave_Select_Pin High	*/
		MGPIO_voidSetPinValue(SPI2_SLAVE,GPIO_PIN_HIGH);
	#endif	
}
//***************************************************************************************************************
void MSPI2_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_ptr)(u8))
{
	#if (SPI2_ENABLE == 1)
		/*	Set the Callback Function	*/
		SPI2_Callback = Copy_ptr;

		/*	Set Slave_Select_Pin Low	*/
		MGPIO_voidSetPinValue(SPI2_SLAVE,GPIO_PIN_LOW);
		
		/*	Make sure TXE flag is Set	*/
		while(!(GET_BIT(SPI2-> SR,1)));
		
		/*	Send Data	*/
		SPI2-> DR = Copy_u8DataToTransmit;
	#endif	
}
/*
*********************************************************************************************************
*                                          		 ISR'S
*********************************************************************************************************
*/
void SPI1_IRQHandler (void)
{
	if( (SPI1_Callback) != 0)
	{
		SPI1_Callback(SPI1-> DR);
	}
}           
//***************************************************************************************************************
void SPI2_IRQHandler (void)
{
	if( (SPI2_Callback) != 0)
	{
		SPI2_Callback(SPI2-> DR);
	}
}            
//***************************************************************************************************************
