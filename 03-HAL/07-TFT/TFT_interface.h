/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 26 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H



/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/* COLOR DEFINITIONS	*/
#define   TFT_COLOR_BLACK 	 	(0x0000)
#define   TFT_COLOR_BROWN   	(0x1060)
#define   TFT_COLOR_LIGHTBROWN  (0xFA41)
#define   TFT_COLOR_BLUE    	(0x001F)
#define   TFT_COLOR_RED     	(0xF800)
#define   TFT_COLOR_ORANGE  	(0xF860)
#define   TFT_COLOR_GREEN   	(0x07E0)
#define   TFT_COLOR_DARKGREEN   (0x2200)
#define   TFT_COLOR_CYAN    	(0x07FF)
#define   TFT_COLOR_MAGENTA 	(0xF81F)
#define   TFT_COLOR_YELLOW  	(0xFFE0)
#define   TFT_COLOR_WHITE   	(0xFFFF)

/*	TFT DIMENSIONS	*/
#define TFT_WIDTH  			(128)
#define TFT_HEIGHT 			(160)

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void HTFT_voidInit 		    (void);
void HTFT_voidDisplayImage  (const u16* Copy_pu16Image);
void HTFT_voidFillColour    (u16 Copy_u16Colour);
void HTFT_voidDrawPixel     (u8 Copy_u8X , u8 Copy_u8Y , u16 Copy_u16Colour);
void HTFT_voidDrawVLine	    (u8 Copy_u8X , u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Colour);
void HTFT_voidDrawHLine	    (u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y , u16 Copy_u16Colour);
void HTFT_voidDrawRectangle (u8 Copy_u8X1, u8 Copy_u8X2, u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Colour);
void HTFT_voidDrawCharacter (u8 Copy_u8Character, u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16TextColour, u16 Copy_u16BG, u8 Copy_u8Size);
void HTFT_voidDrawNumber 	(u8 Copy_u8Number, u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16TextColour, u16 Copy_u16BGColour, u8 Copy_u8Size);
void HTFT_voidDrawString    (u8* Copy_pu8String, u8 Copy_u8X, u8 Copy_u8Y, u16 Copy_u16TextColour, u16 Copy_u16BGColour, u8 Copy_u8Size);

#endif
//***************************************************************************************************************
