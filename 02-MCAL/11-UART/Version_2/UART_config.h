/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Oct 2020										  */
/* Version	: V02												  */
/******************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
#define UART1_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define UART2_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define UART3_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE


/* Note: Select Value only if you Enabled UART_1 */ 
#if (UART1_ENABLE == 1)
	#define	UART1_FREQUENCY							(8000000UL)		//CHOOSE UART1 CLOCK FREQUENCY
	#define	UART1_BAUDRATE							(9600UL)		//CHOOSE SUITABLE BAUDRATE
	#define	UART1_TRANSMITTER_ENABLE				(1)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART1_RECEIVER_ENABLE					(1)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART1_RECEIVE_INTERRUPT_ENABLE			(0)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART1_DMA_TRANSMITTER_ENABLE			(0)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART1_DMA_RECEIVER_ENABLE				(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART1_BUFFERSIZE						(50)			//CHOOSE UART1 BUFFER SIZE
#endif	/* End of UART_1 Configuration	*/

/* Note: Select Value only if you Enabled UART_2 */ 
#if (UART2_ENABLE == 1)
	#define	UART2_FREQUENCY							(8000000UL)		//CHOOSE UART2 CLOCK FREQUENCY
	#define	UART2_BAUDRATE							(9600UL)		//CHOOSE SUITABLE BAUDRATE
	#define	UART2_TRANSMITTER_ENABLE				(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART2_RECEIVER_ENABLE					(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART2_RECEIVE_INTERRUPT_ENABLE			(1)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART2_DMA_TRANSMITTER_ENABLE			(0)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART2_DMA_RECEIVER_ENABLE				(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART2_BUFFERSIZE						(50)			//CHOOSE UART2 BUFFER SIZE, FROM (0) TO (255)
#endif	/* End of UART_2 Configuration	*/

/* Note: Select Value only if you Enabled UART_3 */ 
#if (UART3_ENABLE == 1)
	#define	UART3_FREQUENCY							(8000000UL)		//CHOOSE UART3 CLOCK FREQUENCY
	#define	UART3_BAUDRATE							(9600UL)		//CHOOSE SUITABLE BAUDRATE
	#define	UART3_TRANSMITTER_ENABLE				(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART3_RECEIVER_ENABLE					(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART3_RECEIVE_INTERRUPT_ENABLE			(1)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART3_DMA_TRANSMITTER_ENABLE			(0)				// (0) FOR DISABLE, (1) FOR ENABLE
	#define	UART3_DMA_RECEIVER_ENABLE				(0)				// (0) FOR DISABLE, (1) FOR ENABLE	
	#define	UART3_BUFFERSIZE						(50)			//CHOOSE UART3 BUFFER SIZE	
#endif	/* End of UART_3 Configuration	*/


#endif
//*******************************************************************************************************
