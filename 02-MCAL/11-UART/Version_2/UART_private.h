/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Oct 2020										  */
/* Version	: V02												  */
/******************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


/*
*********************************************************************************************************
*                                           TYPE DEFINITIONS
*********************************************************************************************************
*/
/*	STRUCTURE TO HOLD UART REGISTERS	*/
typedef struct 
{
	volatile u32 SR;
	volatile u32 DR;	
	volatile u32 BRR;
	volatile u32 CR1;	
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;		
} UART_TypeDef;


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/*	POINTERS TO THE TYPE UART_TypeDef	*/
#define UART1 	((volatile UART_TypeDef*)(0x40013800))
#define UART2 	((volatile UART_TypeDef*)(0x40004400))
#define UART3 	((volatile UART_TypeDef*)(0x40004800))


/*	UARTx	*/
#define UART_1 (0)
#define UART_2 (1)
#define UART_3 (2)


/*
*********************************************************************************************************
*                                       PRIVATE GLOBAL VARIABLES
*********************************************************************************************************
*/
#if (UART1_ENABLE == 1)
	static void (*volatile UART1_Callback)(void)			   =   0;
	static volatile u8 Global_u8UART1Buffer [UART1_BUFFERSIZE] = { 0 };
	static volatile u8 Global_u8UART1Buffer_Index 			   =   0;
#endif

#if (UART2_ENABLE == 1)
	static void (*volatile UART2_Callback)(void) 			   =   0;
	static volatile u8 Global_u8UART2Buffer [UART2_BUFFERSIZE] = { 0 };
	static volatile u8 Global_u8UART2Buffer_Index 			   =   0;
#endif

#if (UART3_ENABLE == 1)
	static void (*volatile UART3_Callback)(void) 			   =   0;
	static volatile u8 Global_u8UART3Buffer [UART3_BUFFERSIZE] = { 0 };
	static volatile u8 Global_u8UART3Buffer_Index 			   =   0;
#endif


/*
*********************************************************************************************************
*                                       PRIVATE FUNCTIONS PROTOTYPES
*********************************************************************************************************
*/
void InitUART (u8 Copy_u8UARTx);

#endif
//***************************************************************************************************************
