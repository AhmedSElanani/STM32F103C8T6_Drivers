/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SEVENSEGMENT_PRIVATE_H
#define SEVENSEGMENT_PRIVATE_H


/* Seven Segment Values */

static volatile const u8 G_SevenSegment[10][7] =
				 	 {	{GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW },
						{GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_LOW , GPIO_PIN_LOW , GPIO_PIN_LOW },
						{GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_HIGH},
						{GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_LOW , GPIO_PIN_HIGH},
						{GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH},
						{GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH},
						{GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH},
						{GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_LOW , GPIO_PIN_LOW , GPIO_PIN_LOW },
						{GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH},
						{GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_HIGH, GPIO_PIN_LOW , GPIO_PIN_HIGH, GPIO_PIN_HIGH}	};

#endif
//***************************************************************************************************************
