/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 29 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "Timer2_5_interface.h"

#include "TFT_interface.h"

#include "DigitalClock_interface.h"
#include "DigitalClock_config.h"
#include "DigitalClock_private.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void StartDigitalClock(void)
{
	InitDigitalClock();																/*Initialize the Application*/
	DisplayTitle();																	/*Title*/
	DisplayTime(&Global_Time_TypeTime);												/*Time*/
	DisplayDate(Global_u8Date, Global_u8Month, Global_u16Year,Global_u8Day);		/*Date and Day*/

	//ENABLE TIMER_3
	MTimer3_voidSetIntervalPeriodic (1000, UpdateSeconds);
}
/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' DEFINITIONS
*********************************************************************************************************
*/
static void InitDigitalClock(void)
{
	//INITALIZE TIME
	Global_Time_TypeTime.Seconds = DIGITALCLOCK_STARTTIME_SECONDS;
	Global_Time_TypeTime.Minutes = DIGITALCLOCK_STARTTIME_MINUTES;
	Global_Time_TypeTime.Hours   = DIGITALCLOCK_STARTTIME_HOURS;
	Global_Time_TypeTime.AM_PM   = (AM_PM_TYPE)(DIGITALCLOCK_STARTTIME_AM_PM);

	//INITALIZE DATE
	Global_u8Date				 = DIGITALCLOCK_STARTDATE;

	//INITALIZE DAY
	Global_u8Day		 		 = DIGITALCLOCK_STARTDAY - 1;

	//INITALIZE MONTH
	Global_u8Month 				 = DIGITALCLOCK_STARTMONTH - 2;
	UpdateMonths();

	//INITALIZE YEAR
	Global_u16Year				 = DIGITALCLOCK_STARTYEAR;

	/*INITALIZE TFT DISPLAY*/
	HTFT_voidInit ();

	//INITALIZE TIMER3
	MTimer3_voidInit ();

	/*	ENABLE INTERRUPTS FOR TIMER_3	*/
	MNVIC_voidEnableInterrupt (NVIC_IRQ_TIM3);
}
//***************************************************************************************************************
static void DisplayTitle(void)
{
	/*Background*/
	HTFT_voidFillColour (DIGITALCLOCK_BGCOLOR);

	/*Title*/
	HTFT_voidDrawString ((u8*)"Digital", X_TIILE_START_1, Y_TIILE_START_1 , DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	HTFT_voidDrawString ((u8*)"Clock"  , X_TIILE_START_2, Y_TIILE_START_2 , DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
}
//***************************************************************************************************************
static void DisplayTime (TIME_TYPE *Copy_PTime_TypeTime)
{
	/*DISPLAY SECONDS*/
	if((Copy_PTime_TypeTime->Seconds)/10)
	{
		HTFT_voidDrawNumber	((Copy_PTime_TypeTime->Seconds)/10, X_SECONDS_START_1, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber	((Copy_PTime_TypeTime->Seconds)%10, X_SECONDS_START_2, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}
	else
	{
		HTFT_voidDrawNumber	( 	0							 , X_SECONDS_START_1, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber	(Copy_PTime_TypeTime->Seconds	 , X_SECONDS_START_2, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}

	/*DISPLAY ':' */
	HTFT_voidDrawCharacter 	(   ':'                           , X_DOTS_START_1   , Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);

	/*DISPLAY MINUTES*/
	if((Copy_PTime_TypeTime->Minutes)/10)
	{
		HTFT_voidDrawNumber ((Copy_PTime_TypeTime->Minutes)/10, X_MINUTES_START_1, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber	((Copy_PTime_TypeTime->Minutes)%10, X_MINUTES_START_2, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}
	else
	{
		HTFT_voidDrawNumber	(    0                            , X_MINUTES_START_1, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber (Copy_PTime_TypeTime->Minutes     , X_MINUTES_START_2, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}

	/*DISPLAY ':' */
	HTFT_voidDrawCharacter  (   ':'                           , X_DOTS_START_2   , Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);

	/*DISPLAY HOURS*/
	if((Copy_PTime_TypeTime->Hours)/10)
	{
		HTFT_voidDrawNumber ((Copy_PTime_TypeTime->Hours)/10  , X_HOURS_START_1  , Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber ((Copy_PTime_TypeTime->Hours)%10  , X_HOURS_START_2	 , Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}
	else
	{
		HTFT_voidDrawNumber  (    0                            , X_HOURS_START_1  , Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber (Copy_PTime_TypeTime->Hours       , X_HOURS_START_2  , Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}

	/*DISPLAY AM_PM*/
	if(Copy_PTime_TypeTime->AM_PM)
	{
		HTFT_voidDrawString ((u8*)"PM"  					  , X_AM_PM_START	, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}
	else
	{
		HTFT_voidDrawString ((u8*)"AM" 						  , X_AM_PM_START	, Y_TIME_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}
}
//***************************************************************************************************************
static void DisplayDate	(u8	Copy_u8Date, u8 Copy_u8Month, u16 Copy_u16Year, u8 Copy_u8Day)
{
	/*DISPLAY DATE*/
	if(Copy_u8Date/10)
	{
		HTFT_voidDrawNumber	(Copy_u8Date/10  , X_DATE_START_1, Y_DATE_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber (Copy_u8Date%10  , X_DATE_START_2, Y_DATE_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}
	else
	{
		HTFT_voidDrawNumber (    0           , X_DATE_START_1 , Y_DATE_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
		HTFT_voidDrawNumber (Copy_u8Date     , X_DATE_START_2 , Y_DATE_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}

	/*DISPLAY YEAR*/
	for(u8 i=0 ;i<4; i++,Copy_u16Year /= 10)
	{
		HTFT_voidDrawNumber	(Copy_u16Year%10, X_YEAR_START - 12*i, Y_DATE_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
	}

	/*DISPLAY MONTH*/
	HTFT_voidDrawString (Global_u8Months[Copy_u8Month], X_MONTH_START, Y_DATE_START, DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);

	/*DISPLAY DAY*/
	HTFT_voidDrawString (Global_u8Days[Copy_u8Day]    , X_DAY_START	 , Y_DAY_START , DIGITALCLOCK_TEXTCOLOR, DIGITALCLOCK_BGCOLOR, 2);
}
//***************************************************************************************************************
static void UpdateSeconds(void)
{
	(Global_Time_TypeTime.Seconds)++ ;

	if( (Global_Time_TypeTime.Seconds) == 60)
	{
		(Global_Time_TypeTime.Seconds) = 0;
		UpdateMinutes();
	}

	DisplayTime(&Global_Time_TypeTime);
}
//***************************************************************************************************************
static void UpdateMinutes(void)
{
	(Global_Time_TypeTime.Minutes)++ ;

	if( (Global_Time_TypeTime.Minutes) == 60)
	{
		(Global_Time_TypeTime.Minutes) = 0;
		UpdateHours();
	}
}
//***************************************************************************************************************
static void UpdateHours(void)
{
	(Global_Time_TypeTime.Hours)++ ;

	if( (Global_Time_TypeTime.Hours) == 12)
	{
		(Global_Time_TypeTime.AM_PM) ^= (AM_PM_TYPE)(0x1);

		if( !(Global_Time_TypeTime.AM_PM) )
		{
			UpdateDays ();
		}
	}

	else if( (Global_Time_TypeTime.Hours) == 13)
	{
		(Global_Time_TypeTime.Hours)  = 1;
	}
}
//***************************************************************************************************************
static void UpdateDays(void)
{
	Global_u8Day++ ;
	Global_u8Date++ ;

	if( Global_u8Day == 7)
	{
		Global_u8Day = 0;
	}

	if( Global_u8Date > Global_u8MaximumMonthDays)
	{
		Global_u8Date = 1;
		UpdateMonths();
	}

	DisplayDate(Global_u8Date, Global_u8Month, Global_u16Year,Global_u8Day);		/*Date and Day*/
}
//***************************************************************************************************************
static void UpdateMonths(void)
{
	Global_u8Month++ ;

	if(Global_u8Month >= 12)
	{
		Global_u8Month = 0;
		UpdateYears();
	}

	switch(Global_u8Month)
	{
		case 0:  						Global_u8MaximumMonthDays = 31;  break;
		case 1: if(Global_u16Year%4)   {Global_u8MaximumMonthDays = 28;}
				else 				   {Global_u8MaximumMonthDays = 29;} break;
		case 2:  						Global_u8MaximumMonthDays = 31;  break;
		case 3:							Global_u8MaximumMonthDays = 30;  break;
		case 4:  						Global_u8MaximumMonthDays = 31;  break;
		case 5:  						Global_u8MaximumMonthDays = 30;  break;
		case 6:  						Global_u8MaximumMonthDays = 31;  break;
		case 7:  						Global_u8MaximumMonthDays = 31;  break;
		case 8:  						Global_u8MaximumMonthDays = 30;  break;
		case 9:  						Global_u8MaximumMonthDays = 31;  break;
		case 10: 						Global_u8MaximumMonthDays = 30;  break;
		case 11: 						Global_u8MaximumMonthDays = 31;  break;
	}
}
//***************************************************************************************************************
static void UpdateYears(void)
{
	Global_u16Year++ ;
}
//***************************************************************************************************************
