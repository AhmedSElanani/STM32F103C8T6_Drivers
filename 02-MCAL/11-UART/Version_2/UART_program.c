/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Oct 2020										  */
/* Version	: V02												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


/*
*****************************************************************************************************************
*                               	            FUNCTION DEFINITIONS
*****************************************************************************************************************
*/
/*	UART_1 API'S	*/
void MUART1_Init (void)
{
	/* Initialize UART1 Peripheral	*/
	InitUART (UART_1);
}
//***************************************************************************************************************
void MUART1_TransmitChar (u8  Copy_u8Data)
{
	while(!((UART1->SR)&(0x80)));
	UART1->DR = Copy_u8Data;
}
//***************************************************************************************************************
void MUART1_TransmitString (u8 *Copy_pu8Str)
{
	while((*Copy_pu8Str) != '\0')
	{
		MUART1_TransmitChar(*(Copy_pu8Str++));
	}
}
//***************************************************************************************************************
u8 MUART1_ReceiveChar (void)
{
	#if (UART1_ENABLE == 1)
		#if (UART1_RECEIVE_INTERRUPT_ENABLE == 0)
			if((UART1->SR)&(0x20))
		#endif
		{
			Global_u8UART1Buffer[Global_u8UART1Buffer_Index++]  = UART1->DR;
			return 1;
		}
	#endif

	return 0;
}
//***************************************************************************************************************
u8 MUART1_ReadData (void)
{
	static volatile u8 Local_u8Data = 0;

		#if (UART1_ENABLE == 1)
			Local_u8Data = Global_u8UART1Buffer[0];

			if(Local_u8Data)
			{
				for(u8 i = 0; i<Global_u8UART1Buffer_Index; i++)
				{
					Global_u8UART1Buffer[i] = Global_u8UART1Buffer[i+1];
				}

				Global_u8UART1Buffer_Index--;
			}
		#endif

	return Local_u8Data;
}
//***************************************************************************************************************
void MUART1_SetCallback (void (*Copy_ptr)(void))
{
	#if (UART1_ENABLE == 1)
		UART1_Callback = Copy_ptr;
	#endif
}
//***************************************************************************************************************
/*	UART_2 API'S	*/
void MUART2_Init (void)
{
	InitUART (UART_2);
}
//***************************************************************************************************************
void MUART2_TransmitChar (u8  Copy_u8Data)
{
	while(!((UART2->SR)&(0x80)));
	UART2->DR = Copy_u8Data;
}
//***************************************************************************************************************
void MUART2_TransmitString(u8 *Copy_pu8Str)
{
	while((*Copy_pu8Str) != '\0')
	{
		MUART2_TransmitChar(*(Copy_pu8Str++));
	}
}
//***************************************************************************************************************
u8 MUART2_ReceiveChar (void)
{
	#if (UART2_ENABLE == 1)
		#if (UART2_RECEIVE_INTERRUPT_ENABLE == 0)
			if((UART2->SR)&(0x20))
		#endif
		{
			Global_u8UART2Buffer[Global_u8UART2Buffer_Index++]  = UART2->DR;
			return 1;
		}
	#endif

	return 0;
}
//***************************************************************************************************************
u8 MUART2_ReadData (void)
{
	static volatile u8 Local_u8Data = 0;

	#if (UART2_ENABLE == 1)
		Local_u8Data = Global_u8UART2Buffer[0];

		if(Local_u8Data)
		{
			for(u8 i = 0; i<Global_u8UART2Buffer_Index; i++)
			{
				Global_u8UART2Buffer[i] = Global_u8UART2Buffer[i+1];
			}

			Global_u8UART2Buffer_Index--;
		}
	#endif

	return Local_u8Data;
}
//***************************************************************************************************************
void MUART2_SetCallback (void (*Copy_ptr)(void))
{
	#if (UART2_ENABLE == 1)
		UART2_Callback = Copy_ptr;
	#endif
}
//***************************************************************************************************************
/*	UART_3 API'S	*/
void MUART3_Init (void)
{
	InitUART (UART_3);
}
//***************************************************************************************************************
void MUART3_TransmitChar (u8  Copy_u8Data)
{
	while(!((UART3->SR)&(0x80)));
	UART3->DR = Copy_u8Data;
}
//***************************************************************************************************************
void MUART3_TransmitString(u8 *Copy_pu8Str)
{
	while((*Copy_pu8Str) != '\0')
	{
		MUART3_TransmitChar(*(Copy_pu8Str++));
	}
}
//***************************************************************************************************************
u8 MUART3_ReceiveChar (void)
{
	#if (UART3_ENABLE == 1)
		#if (UART3_RECEIVE_INTERRUPT_ENABLE == 0)
			if((UART3->SR)&(0x20))
		#endif
		{
			Global_u8UART3Buffer[Global_u8UART3Buffer_Index++]  = UART3->DR;
			return 1;
		}
	#endif

	return 0;
}
//***************************************************************************************************************
u8 MUART3_ReadData (void)
{
	static volatile u8 Local_u8Data = 0;

		#if (UART3_ENABLE == 1)
			Local_u8Data = Global_u8UART3Buffer[0];

			if(Local_u8Data)
			{
				for(u8 i = 0; i<Global_u8UART3Buffer_Index; i++)
				{
					Global_u8UART3Buffer[i] = Global_u8UART3Buffer[i+1];
				}

				Global_u8UART3Buffer_Index--;
			}
		#endif

	return Local_u8Data;
}
//***************************************************************************************************************
void MUART3_SetCallback (void (*Copy_ptr)(void))
{
	#if (UART3_ENABLE == 1)
		UART3_Callback = Copy_ptr;
	#endif
}
/*
*****************************************************************************************************************
*                               	       PRIVATE FUNCTION DEFINITIONS
*****************************************************************************************************************
*/
void InitUART (u8 Copy_u8UARTx)
{
	switch(Copy_u8UARTx)
	{
		case UART_1:
			/* Initialize GPIO Pins Alternate Function	*/
			MGPIO_voidSetPinMode  (GPIOA,PIN9, OUTPUT_AF_PP_2MHZ);
			MGPIO_voidSetPinMode  (GPIOA,PIN10, INPUT_PULLUP);

			/*	Set BaudRate	*/
			UART1->BRR = UART1_FREQUENCY/UART1_BAUDRATE;

			/* 8 DATA BITS, n STOP BITS, PARITY DISABLED	*/
			UART1->CR1  = (0x0);
			UART1->CR2  = (0x0);
			UART1->CR3  = (0x0);
			UART1->GTPR = (0x0);


			#if (UART1_DMA_TRANSMITTER_ENABLE == 1)
				UART1->CR3 |= (0x80);
			#endif

			#if (UART1_DMA_RECEIVER_ENABLE == 1)
				UART1->CR3 |= (0x40);
			#endif


			#if (UART1_TRANSMITTER_ENABLE == 1)
				UART1->CR1 |= (0x8);
			#endif

			#if (UART1_RECEIVER_ENABLE == 1)
				UART1->CR1 |= (0x4);
			#endif

			#if (UART1_RECEIVE_INTERRUPT_ENABLE == 1)
				UART1->CR1 |= (0x20);
			#endif


			/*	Enable UART	*/
				UART1->CR1 |= (0x2000);
			break;

		case UART_2:
			break;

		case UART_3:
			break;
	}
}
/*
*****************************************************************************************************************
*                               	            	ISR'S
*****************************************************************************************************************
*/
void USART1_IRQHandler(void)
{
	#if (UART1_ENABLE == 1)
		//LOOK FOR THE INTERRUPT SOURCE
		if((UART1->SR)&(0x20))
		{
			//Clear the Interrupt Flag
			UART1->SR &= ~(0x20);

			if (UART1_Callback != 0)			//Check if a Function is Assigned to Callback
			{
				(*(UART1_Callback))();
			}
		}
	#endif
}   
//***************************************************************************************************************
void USART2_IRQHandler(void)
{
	#if (UART2_ENABLE == 1)
		//LOOK FOR THE INTERRUPT SOURCE
		if((UART2->SR)&(0x20))
		{
			//Clear the Interrupt Flag
			UART2->SR &= ~(0x20);

			if (UART2_Callback != 0)			//Check if a Function is Assigned to Callback
			{
				(*(UART2_Callback))();
			}
		}
	#endif
}   
//***************************************************************************************************************
void USART3_IRQHandler(void)
{
	#if (UART3_ENABLE == 1)
		//LOOK FOR THE INTERRUPT SOURCE
		if((UART3->SR)&(0x20))
		{
			//Clear the Interrupt Flag
			UART3->SR &= ~(0x20);

			if (UART3_Callback != 0)			//Check if a Function is Assigned to Callback
			{
				(*(UART3_Callback))();
			}
		}
	#endif
}   
//*************************************************************************************************************** 
