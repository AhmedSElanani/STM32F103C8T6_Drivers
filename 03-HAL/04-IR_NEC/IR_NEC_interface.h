/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 31 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef IR_NEC_INTERFACE_H
#define IR_NEC_INTERFACE_H


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
//REMOTE BUTTONS
#define		IR_NEC_NO_BUTTON_PRESSED			((u8)(0x00))
#define		IR_NEC_BUTTON_0_PRESSED				((u8)(0x19))
#define		IR_NEC_BUTTON_1_PRESSED				((u8)(0x45))
#define		IR_NEC_BUTTON_2_PRESSED				((u8)(0x46))
#define		IR_NEC_BUTTON_3_PRESSED				((u8)(0x47))
#define		IR_NEC_BUTTON_4_PRESSED				((u8)(0x44))
#define		IR_NEC_BUTTON_5_PRESSED				((u8)(0x40))
#define		IR_NEC_BUTTON_6_PRESSED				((u8)(0x43))
#define		IR_NEC_BUTTON_7_PRESSED				((u8)(0x07))
#define		IR_NEC_BUTTON_8_PRESSED				((u8)(0x15))
#define		IR_NEC_BUTTON_9_PRESSED				((u8)(0x09))
#define		IR_NEC_BUTTON_STAR_PRESSED			((u8)(0x16))
#define		IR_NEC_BUTTON_WINDOW_PRESSED		((u8)(0x0D))
#define		IR_NEC_BUTTON_UP_PRESSED			((u8)(0x18))
#define		IR_NEC_BUTTON_DOWN_PRESSED			((u8)(0x52))
#define		IR_NEC_BUTTON_RIGHT_PRESSED			((u8)(0x5A))
#define		IR_NEC_BUTTON_LEFT_PRESSED			((u8)(0x08))
#define		IR_NEC_BUTTON_OK_PRESSED			((u8)(0x1C))

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void HIR_NEC_voidInit (void);
u8 HIR_NEC_u8ReadReceivedFrame (void);

#endif
//***************************************************************************************************************
