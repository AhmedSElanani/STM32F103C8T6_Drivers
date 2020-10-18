/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 26 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "Timer2_5_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void HTFT_voidInit (void)
{
	/*	INITIALIZE TFT PINS	*/
	MGPIO_voidSetPinMode (TFT_A0_PIN	, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode (TFT_RESET_PIN , OUTPUT_GP_PP_2MHZ);

	/*	SET RESET PIN INITIALLY LOW		*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN , GPIO_PIN_LOW);

	/*	INITIALIZE TIMER_2	*/
	MTimer2_voidInit ();
	
	/*	INITIALIZE SPI_1	*/
	MSPI1_voidInit ();

	/*	SEND RESET PULSE	*/
	MGPIO_voidSetPinValue(TFT_RESET_PIN , GPIO_PIN_HIGH);
	MTimer2_voidSetBusyWait(TFT_RESETPULSE_1);
	
	MGPIO_voidSetPinValue(TFT_RESET_PIN , GPIO_PIN_LOW);
	MTimer2_voidSetBusyWait(TFT_RESETPULSE_2);
	
	MGPIO_voidSetPinValue(TFT_RESET_PIN , GPIO_PIN_HIGH);
	MTimer2_voidSetBusyWait(TFT_RESETPULSE_3);
	
	MGPIO_voidSetPinValue(TFT_RESET_PIN , GPIO_PIN_LOW);
	MTimer2_voidSetBusyWait(TFT_RESETPULSE_4);
	
	MGPIO_voidSetPinValue(TFT_RESET_PIN , GPIO_PIN_HIGH);
	MTimer2_voidSetBusyWait(TFT_RESETPULSE_5);
	MTimer2_voidSetBusyWait(TFT_RESETPULSE_6);

	/*	SEND SLEEP OUT COMMAND	*/
	voidWriteCommand (TFT_COMMAND_SLPOUT);

	/*	DELAY FOR 150MSEC	*/
	MTimer2_voidSetBusyWait(TFT_INIT_DELAY_1);
	MTimer2_voidSetBusyWait(TFT_INIT_DELAY_2);
	MTimer2_voidSetBusyWait(TFT_INIT_DELAY_3);

	/*	SEND COLOR MODE COMMAND	*/
	voidWriteCommand (TFT_COMMAND_COLMOD);

	/*	SELECT COLOR MODE	*/
	voidWriteData (TFT_COLMOD);
	
	/*	SEND DISPLAY ON COMMAND	*/
	voidWriteCommand (TFT_COMMAND_DISPON);
}
//***************************************************************************************************************
void HTFT_voidDisplayImage (const u16* Copy_pu16Image)
{
	/*	SET COLUMN ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_CASET);
	voidWriteData 	 ((u8)((TFT_WIDTH_START)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_WIDTH_START)&(0x00FF)));
	voidWriteData	 ((u8)((TFT_WIDTH_END)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_WIDTH_END)&(0x00FF)));

	/*	SET ROW ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_RASET);
	voidWriteData	 ((u8)((TFT_HEIGHT_START)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_HEIGHT_START)&(0x00FF)));
	voidWriteData	 ((u8)((TFT_HEIGHT_END)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_HEIGHT_END)&(0x00FF)));

	/*	Draw the Image	*/
	voidWriteCommand (TFT_COMMAND_RAMWR);

	for(u16 i=0; i<(TFT_WIDTH_END+1)*(TFT_HEIGHT_END+1); i++ )
	{
		voidWriteData ((u8)(Copy_pu16Image[i] >> 8));
		voidWriteData ((u8)(Copy_pu16Image[i]));
	}
}
//***************************************************************************************************************
void HTFT_voidFillColour (u16 Copy_u16Colour)
{
	/*	SET COLUMN ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_CASET);
	voidWriteData 	 ((u8)((TFT_WIDTH_START)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_WIDTH_START)&(0x00FF)));
	voidWriteData	 ((u8)((TFT_WIDTH_END)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_WIDTH_END)&(0x00FF)));

	/*	SET ROW ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_RASET);
	voidWriteData	 ((u8)((TFT_HEIGHT_START)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_HEIGHT_START)&(0x00FF)));
	voidWriteData	 ((u8)((TFT_HEIGHT_END)&(0xFF00)));
	voidWriteData	 ((u8)((TFT_HEIGHT_END)&(0x00FF)));

	/*	Draw the Image	*/
	voidWriteCommand (TFT_COMMAND_RAMWR);

	for(u16 i=0; i<(TFT_WIDTH_END+1)*(TFT_HEIGHT_END+1); i++ )
	{
		voidWriteData ((u8)(Copy_u16Colour >> 8));
		voidWriteData ((u8)(Copy_u16Colour));
	}
}
//***************************************************************************************************************
void HTFT_voidDrawPixel (u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16Colour)
{
	/*	SET COLUMN ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_CASET);
	voidWriteData 	 ((u8)((Copy_u8X)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8X)&(0x00FF)));
	voidWriteData	 ((u8)((Copy_u8X)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8X)&(0x00FF)));

	/*	SET ROW ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_RASET);
	voidWriteData	 ((u8)((Copy_u8Y)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8Y)&(0x00FF)));
	voidWriteData	 ((u8)((Copy_u8Y)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8Y)&(0x00FF)));

	/*	Draw the Image	*/
	voidWriteCommand (TFT_COMMAND_RAMWR);

	voidWriteData ((u8)(Copy_u16Colour >> 8));
	voidWriteData ((u8)(Copy_u16Colour));
}
//***************************************************************************************************************
void HTFT_voidDrawVLine	(u8 Copy_u8X , u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Colour)
{
	/*	SET COLUMN ADDRESS	*/
		voidWriteCommand (TFT_COMMAND_CASET);
		voidWriteData 	 ((u8)((Copy_u8X)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8X)&(0x00FF)));
		voidWriteData	 ((u8)((Copy_u8X)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8X)&(0x00FF)));

		/*	SET ROW ADDRESS	*/
		voidWriteCommand (TFT_COMMAND_RASET);
		voidWriteData	 ((u8)((Copy_u8Y1)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8Y1)&(0x00FF)));
		voidWriteData	 ((u8)((Copy_u8Y2)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8Y2)&(0x00FF)));

		/*	Draw the Rectangle	*/
		voidWriteCommand (TFT_COMMAND_RAMWR);

		for(u16 i=0; i<=Copy_u8Y2-Copy_u8Y1; i++ )
		{
			voidWriteData ((u8)(Copy_u16Colour >> 8));
			voidWriteData ((u8)(Copy_u16Colour));
		}
}
//***************************************************************************************************************
void HTFT_voidDrawHLine	(u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y , u16 Copy_u16Colour)
{
	/*	SET COLUMN ADDRESS	*/
		voidWriteCommand (TFT_COMMAND_CASET);
		voidWriteData 	 ((u8)((Copy_u8X1)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8X1)&(0x00FF)));
		voidWriteData	 ((u8)((Copy_u8X2)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8X2)&(0x00FF)));

		/*	SET ROW ADDRESS	*/
		voidWriteCommand (TFT_COMMAND_RASET);
		voidWriteData	 ((u8)((Copy_u8Y)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8Y)&(0x00FF)));
		voidWriteData	 ((u8)((Copy_u8Y)&(0xFF00)));
		voidWriteData	 ((u8)((Copy_u8Y)&(0x00FF)));

		/*	Draw the Rectangle	*/
		voidWriteCommand (TFT_COMMAND_RAMWR);

		for(u16 i=0; i<=Copy_u8X2-Copy_u8X1; i++ )
		{
			voidWriteData ((u8)(Copy_u16Colour >> 8));
			voidWriteData ((u8)(Copy_u16Colour));
		}
}
//***************************************************************************************************************
void HTFT_voidDrawRectangle (u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Colour)
{
	/*	SET COLUMN ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_CASET);
	voidWriteData 	 ((u8)((Copy_u8X1)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8X1)&(0x00FF)));
	voidWriteData	 ((u8)((Copy_u8X2)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8X2)&(0x00FF)));

	/*	SET ROW ADDRESS	*/
	voidWriteCommand (TFT_COMMAND_RASET);
	voidWriteData	 ((u8)((Copy_u8Y1)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8Y1)&(0x00FF)));
	voidWriteData	 ((u8)((Copy_u8Y2)&(0xFF00)));
	voidWriteData	 ((u8)((Copy_u8Y2)&(0x00FF)));

	/*	Draw the Rectangle	*/
	voidWriteCommand (TFT_COMMAND_RAMWR);

	for(u16 i=0; i<(Copy_u8X2-Copy_u8X1+1)*(Copy_u8Y2-Copy_u8Y1+1); i++ )
	{
		voidWriteData ((u8)(Copy_u16Colour >> 8));
		voidWriteData ((u8)(Copy_u16Colour));
	}
}
//***************************************************************************************************************
void HTFT_voidDrawCharacter (u8 Copy_u8Character, u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16TextColour, u16 Copy_u16BGColour, u8 Copy_u8Size)
{
	setAddrWindow(Copy_u8X, Copy_u8X+6*Copy_u8Size-1, Copy_u8Y,  Copy_u8Y+8*Copy_u8Size-1);

	u8 Local_u8line = 0x01;        // print the top row first

	// print the rows, starting at the top
	 for(u8 row=0; row<8; row++)
	 {
		 for(u8 i=0; i<Copy_u8Size; i++)
		 {
			 // print the columns, starting on the left
			 for(u8 col=0; col<5; col++)
			 {
				 if(Font[(Copy_u8Character*5)+col]&Local_u8line)
				 {
					 // bit is set in Font, print pixel(s) in text color
					 for(u8 j=0; j<Copy_u8Size; j++)
					 {
						 voidPushColor(Copy_u16TextColour);
					 }
	        }
	        else
	        {
	        	// bit is cleared in Font, print pixel(s) in background color
	        	for(u8 j=0; j<Copy_u8Size; j++)
	        	{
	        		voidPushColor(Copy_u16BGColour);
	        	}
	        }
	      }

	      // print blank column(s) to the right of character
	      for(u8 j=0; j<Copy_u8Size; j++)
	      {
	    	  voidPushColor(Copy_u16BGColour);
	      }
	    }

	    	Local_u8line <<= 1;   // move up to the next row
	  }
}
//***************************************************************************************************************
void HTFT_voidDrawNumber (u8 Copy_u8Number, u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16TextColour, u16 Copy_u16BGColour, u8 Copy_u8Size)
{
	HTFT_voidDrawCharacter (Copy_u8Number +'0',Copy_u8X,Copy_u8Y,Copy_u16TextColour,Copy_u16BGColour,Copy_u8Size);
}
//***************************************************************************************************************
void HTFT_voidDrawString (u8* Copy_pu8String, u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16TextColour, u16 Copy_u16BGColour, u8 Copy_u8Size)
{
	while(*Copy_pu8String)
	{
		HTFT_voidDrawCharacter (*Copy_pu8String, Copy_u8X, Copy_u8Y, Copy_u16TextColour, Copy_u16BGColour, Copy_u8Size);
		Copy_pu8String++;
		Copy_u8X += 6*Copy_u8Size;
	}
}
/*
*********************************************************************************************************
*                                       PRIVATE FUNCTION DEFINITIONS
*********************************************************************************************************
*/
static void voidWriteCommand (u8 Copy_u8Command)
{
	static u8 Local_u8Dummy;
	
	/* Set A0 LOW	*/
	MGPIO_voidSetPinValue (TFT_A0_PIN,GPIO_PIN_LOW);

	/*	Send Command over SPI	*/
	MSPI1_voidSendReceiveSynchronous (Copy_u8Command, &Local_u8Dummy);
}
//***************************************************************************************************************
static void voidWriteData (u8 Copy_u8Data)
{
	static u8 Local_u8Dummy;

	/* Set A0 HIGH	*/
	MGPIO_voidSetPinValue (TFT_A0_PIN,GPIO_PIN_HIGH);

	/*	Send Data over SPI	*/
	MSPI1_voidSendReceiveSynchronous (Copy_u8Data, &Local_u8Dummy);
}
//***************************************************************************************************************
static void setAddrWindow(u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2)
{
	/*	SET COLUMN ADDRESS	*/
		voidWriteCommand (TFT_COMMAND_CASET);
		voidWriteData 	 ((u8)(Copy_u8X1&(0xFF00)));
		voidWriteData	 ((u8)(Copy_u8X1&(0x00FF)));
		voidWriteData	 ((u8)(Copy_u8X2&(0xFF00)));
		voidWriteData	 ((u8)(Copy_u8X2&(0x00FF)));

		/*	SET ROW ADDRESS	*/
		voidWriteCommand (TFT_COMMAND_RASET);
		voidWriteData	 ((u8)(Copy_u8Y1&(0xFF00)));
		voidWriteData	 ((u8)(Copy_u8Y1&(0x00FF)));
		voidWriteData	 ((u8)(Copy_u8Y2&(0xFF00)));
		voidWriteData	 ((u8)(Copy_u8Y2&(0x00FF)));

		/*	Draw the Rectangle	*/
		voidWriteCommand (TFT_COMMAND_RAMWR);
}
//***************************************************************************************************************
static void voidPushColor (u16 Copy_u16Color)
{
	voidWriteData((u8)(Copy_u16Color >> 8));
	voidWriteData((u8)Copy_u16Color);
}
//***************************************************************************************************************
