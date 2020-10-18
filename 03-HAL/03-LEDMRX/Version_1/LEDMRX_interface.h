/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 31 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplayFrame    (const u8* const Value_u8Data);
void HLEDMRX_voidDisplayAnimation(const u8* const Value_u8Data, const u16 Copy_u16Length, const u32 Copy_u32Delay);
void HLEDMRX_voidTurnOffDisplay	 (void);

#endif
//***************************************************************************************************************
