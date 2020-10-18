/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 OCT 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef UARTBOOTLOADER_CONFIG_H
#define UARTBOOTLOADER_CONFIG_H

/*
*********************************************************************************************************
*                                        CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
#define UARTBOOTLOADER_ApplicationStartAddress		(0x08001004)		//THE ADDRESS OF THE RESET VECTOR 
#define UARTBOOTLOADER_MAXIMUMTIMEOUT				(5000000UL)			//TIMEOUT AFTER 5 SECONDS

#endif
//***************************************************************************************************************
