/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 11 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SysTick_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void HDAC_voidInit (void)
{
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN0, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN1, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN2, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN3, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN4, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN5, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN6, OUTPUT_GP_PP_2MHZ);
	MGPIO_voidSetPinMode  (DAC_OUTPUT_PIN7, OUTPUT_GP_PP_2MHZ);

	MSysTick_voidInit();
}
//***************************************************************************************************************
u8 HDAC_voidPlay_Audiofile (const u8* const Value_u8Sample, const u16 Copy_u16FileLength, const u16 Copy_u16SampleRate)
{	
	/*	Check the DAC is currently not busy	*/
	if( (Current_AudioFile)||(Current_AudioFileLength) )
	{
		return 0;
	}

	/*	This code gets executed if DAC is not Busy	*/
	Current_AudioFile 		= Value_u8Sample;
	Current_AudioFileLength = Copy_u16FileLength;
	MSysTick_voidSetIntervalPeriodic(1000000UL/Copy_u16SampleRate, WriteSample);
	
	return 1;
}
//***************************************************************************************************************
void WriteSample (void)
{
	static volatile u16  SamplesIndex = 0;

	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN0,GET_BIT(Current_AudioFile[SamplesIndex],0));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN1,GET_BIT(Current_AudioFile[SamplesIndex],1));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN2,GET_BIT(Current_AudioFile[SamplesIndex],2));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN3,GET_BIT(Current_AudioFile[SamplesIndex],3));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN4,GET_BIT(Current_AudioFile[SamplesIndex],4));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN5,GET_BIT(Current_AudioFile[SamplesIndex],5));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN6,GET_BIT(Current_AudioFile[SamplesIndex],6));
	MGPIO_voidSetPinValue(DAC_OUTPUT_PIN7,GET_BIT(Current_AudioFile[SamplesIndex],7));

	SamplesIndex++ ;

	if(SamplesIndex == Current_AudioFileLength)
	{
		MSysTick_voidStopInterval();

		/*	Reset Variables	*/
		SamplesIndex 			= 0;
		Current_AudioFile 		= 0;
		Current_AudioFileLength = 0;
	}
}
//***************************************************************************************************************
