/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 OCT 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef UARTBOOTLOADER_PRIVATE_H
#define UARTBOOTLOADER_PRIVATE_H

/*
*********************************************************************************************************
*                                        			MACROS
*********************************************************************************************************
*/
//CONSTANTS
#define UARTBOOTLOADER_RECORDLENGTH							(261UL)
#define UARTBOOTLOADER_MAXIMUM_DATABLOCK_SIZE				(255UL)
#define UARTBOOTLOADER_HIGHERADDRESS_SIZE					(16UL)
#define UARTBOOTLOADER_LOWERADDRESS_DIGITS					(4UL)
#define UARTBOOTLOADER_HIGHERADDRESS_DIGITS					(4UL)
#define UARTBOOTLOADER_DATA_SIZE							(8UL)
#define UARTBOOTLOADER_DIGIT_SIZE							(4UL)

//POSITIONS
#define UARTBOOTLOADER_CHARACTERCOUNT_POSITION				(1UL)
#define UARTBOOTLOADER_RECORDTYPE_POSITION					(8UL)
#define UARTBOOTLOADER_STARTOFDATA_POSITION					(9UL)
#define UARTBOOTLOADER_STARTOFADDRESS_POSITION				(3UL)


/*
*********************************************************************************************************
*                                        		TYPE DEFINITIONS
*********************************************************************************************************
*/
typedef void (*Function_t)(void);

/*
*********************************************************************************************************
*                                        		GLOBAL VARIABLES
*********************************************************************************************************
*/
static volatile u8  		Global_u8Bootloader_Record[UARTBOOTLOADER_RECORDLENGTH];
static volatile u8  		Global_u8CharacterCount;
static volatile u16	 		Global_u16DataBlock[UARTBOOTLOADER_MAXIMUM_DATABLOCK_SIZE/2];
static volatile u32 		Global_u32FlashingAddress;
static volatile Function_t 	addr_to_call;


/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' PROTOTYPES
*********************************************************************************************************
*/
void InitSystem 	   (void);
u8   ParseTheRecord    (void);
u8   ConvertASCIItoHEX (u8 Copy_u8ASCII);
void TimeOut_Handler   (void);

#endif
//***************************************************************************************************************
