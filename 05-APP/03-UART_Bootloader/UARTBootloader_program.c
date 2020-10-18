/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 OCT 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "UART_interface.h"
#include "SysTick_interface.h"
#include "FPEC_interface.h"

#include "UARTBootloader_interface.h"
#include "UARTBootloader_config.h"
#include "UARTBootloader_private.h"




/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void AUBL_voidStartUARTBootloader (void)
{
	//Initialize the System
	InitSystem();

	static volatile u8 Local_u8Record_Index, Local_u8PageErased_Flag, Local_u8EndOfFileReached;

	Local_u8Record_Index 	= 0;
	Local_u8PageErased_Flag = 0;
	
	//Start the Bootloader logic
	while(1)
	{
		if( MUART1_ReceiveChar() )
		{
			/*	Stop the TimeOut Timer	*/
			MSysTick_voidStopInterval();

			//Read the Received Char
			Global_u8Bootloader_Record[Local_u8Record_Index] = MUART1_ReadData();

			//Check that we Reached the End of Record
			if( Global_u8Bootloader_Record[Local_u8Record_Index] == '\n')
			{
				//Erase the Flash at the First Record Only
				if(!Local_u8PageErased_Flag)
				{
					//Unlock the FPEC Block
					FPEC_voidUnlockFPEC();

					//Erase the FPEC Block
					FPEC_voidEraseAppArea();

					//Set the Flag
					Local_u8PageErased_Flag = 1;
				}

				//Parse the Received Record and get the position in the file
				Local_u8EndOfFileReached = ParseTheRecord();

				//Check whether the Bootloader reached the end of file or not
				if(Local_u8EndOfFileReached)
				{
					//Initialize Vector table and the Start Address of the Application
					TimeOut_Handler();
				}
				else
				{
					//Reset the Record Index
					Local_u8Record_Index = 0;

					//Signal the Interface tool that the Bootloader is ready to Receive the Next record
					MUART1_TransmitString ((u8*)("ok"));
				}
			}
			else
			{
				Local_u8Record_Index++ ;
			}
		}
	}
}
/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' DEFINITIONS
*********************************************************************************************************
*/
void InitSystem (void)
{
	//Initialize UART
	MUART1_Init ();

	//Initialize Systick
	MSysTick_voidInit();

	//Set the TimeOut Function
	MSysTick_voidSetIntervalSingle(UARTBOOTLOADER_MAXIMUMTIMEOUT, TimeOut_Handler);
}
//***************************************************************************************************************
u8 ParseTheRecord (void)
{
	static volatile u8  Local_u8EndOfFile = 0;
	static volatile u16 Local_u16TempHigherAddress, Local_u16TempLowerAddress;				   


	//Check the Record Type
	switch(Global_u8Bootloader_Record[UARTBOOTLOADER_RECORDTYPE_POSITION])
	{
		case '0':
			//Erase the Old Lower Address
			Global_u32FlashingAddress &= ((u32)(0xFFFF0000));
		
			//Set the New Lower Address
			Local_u16TempLowerAddress = 0;
		
			for(u8 i=0; i<UARTBOOTLOADER_LOWERADDRESS_DIGITS; i++)
			{
				Local_u16TempLowerAddress  |= 
					(ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_STARTOFADDRESS_POSITION+i])) << 
					((UARTBOOTLOADER_DIGIT_SIZE-i-1)*(UARTBOOTLOADER_DIGIT_SIZE));				
			}
	
			Global_u32FlashingAddress |= (Local_u16TempLowerAddress);	
		
			
			//Set the Character Count
			Global_u8CharacterCount = 
					  ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_CHARACTERCOUNT_POSITION+1]) |
					((ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_CHARACTERCOUNT_POSITION]))<<UARTBOOTLOADER_DIGIT_SIZE);
			
		
			//Write the Data
			for(u8 i = 0, j=0; i<(2*Global_u8CharacterCount); j++, i +=4)
			{
				Global_u16DataBlock[j] =
				 (ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_STARTOFDATA_POSITION+i+1])) 								  |
				((ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_STARTOFDATA_POSITION+i]))  <<(1*UARTBOOTLOADER_DIGIT_SIZE)) |
				((ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_STARTOFDATA_POSITION+i+3]))<<(2*UARTBOOTLOADER_DIGIT_SIZE)) |
				((ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_STARTOFDATA_POSITION+i+2]))<<(3*UARTBOOTLOADER_DIGIT_SIZE));
			}	

			//Flash the Received Data Block
			FPEC_voidFlashWrite (Global_u32FlashingAddress, Global_u16DataBlock, Global_u8CharacterCount/2);
			break;
		
		case '1':
			//Signal the End of File
			Local_u8EndOfFile = 1;
			break;
		
		case '4':
			//Erase the Old Higher Address
			Global_u32FlashingAddress &= ((u32)(0x0000FFFF));
		
			//Set the New Higher Address
			Local_u16TempHigherAddress = 0;
		
			for(u8 i=0; i<UARTBOOTLOADER_HIGHERADDRESS_DIGITS; i++)
			{
				Local_u16TempHigherAddress  |= 
					(ConvertASCIItoHEX(Global_u8Bootloader_Record[UARTBOOTLOADER_STARTOFDATA_POSITION+i])) << 
					((UARTBOOTLOADER_DIGIT_SIZE-i-1)*(UARTBOOTLOADER_DIGIT_SIZE));				
			}
	
			Global_u32FlashingAddress |= ((u32)(Local_u16TempHigherAddress << UARTBOOTLOADER_HIGHERADDRESS_SIZE));
			break;
			
		case '5':
			//Ignore the Full Address
			break;
	}
	
	return(Local_u8EndOfFile);
}
//***************************************************************************************************************
u8 ConvertASCIItoHEX (u8 Copy_u8ASCII)
{
	 volatile u8 Local_u8HEX;

	if( (Copy_u8ASCII >= '0')&&(Copy_u8ASCII <= '9') )
	{
		Local_u8HEX = Copy_u8ASCII - '0';
	}
	else if( (Copy_u8ASCII >= 'A')&&(Copy_u8ASCII <= 'F') )
	{
		Local_u8HEX = Copy_u8ASCII - 'A' + 0xA;		
	}
	else if( (Copy_u8ASCII >= 'a')&&(Copy_u8ASCII <= 'f') )
	{
		Local_u8HEX = Copy_u8ASCII - 'a' + 0xA;				
	}

	 return(Local_u8HEX);
}
//***************************************************************************************************************
void TimeOut_Handler (void)
{	
	//Set the Start of the Flash Driver
	MSCB_voidSet_VectorTableBaseOffset();
	
	//Call the Start Address of the Application area
	addr_to_call = *(Function_t*)(UARTBOOTLOADER_ApplicationStartAddress);
	addr_to_call();
}
//***************************************************************************************************************
