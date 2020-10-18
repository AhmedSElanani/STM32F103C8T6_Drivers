/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 26 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
// NOTE: Write in pair GPIOx,PINy
#define	TFT_A0_PIN			  GPIOA,PIN2					
#define	TFT_RESET_PIN		  GPIOA,PIN3

/*	TFT COLOR MODE	*/
#define	TFT_COLMOD	 		 (TFT_COLMOD_RGB565)	// OPTIONS: (TFT_COLMOD_RGB444 / TFT_COLMOD_RGB565 / TFT_COLMOD_RGB666)

/*	TFT DIMENSIONS	*/
#define	TFT_WIDTH_START		 (0)
#define	TFT_WIDTH_END		 (127)

#define	TFT_HEIGHT_START 	 (0)
#define	TFT_HEIGHT_END	 	 (159)

#endif
//***************************************************************************************************************
