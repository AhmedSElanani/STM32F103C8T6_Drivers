/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 29 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef DIGiTALCLOCK_PRIVATE_H
#define DIGiTALCLOCK_PRIVATE_H

/*
*********************************************************************************************************
*                                        			MACROS
*********************************************************************************************************
*/
/* X-COORDINATE OFFSETS	*/
#define X_TIILE_START_1				(27)
#define X_TIILE_START_2				(35)

#define X_SECONDS_START_1			(75)
#define X_SECONDS_START_2			(87)

#define X_MINUTES_START_1			(39)
#define X_MINUTES_START_2			(51)

#define X_HOURS_START_1				(3)
#define X_HOURS_START_2				(15)

#define X_DOTS_START_1				(63)
#define X_DOTS_START_2				(27)

#define X_AM_PM_START				(102)

#define X_DATE_START_1				(10)
#define X_DATE_START_2				(22)

#define X_MONTH_START				(38)

#define X_YEAR_START				(114)

#define X_DAY_START					(16)

/* Y-COORDINATE OFFSETS	*/
#define Y_TIILE_START_1				(5)
#define Y_TIILE_START_2				(25)

#define Y_TIME_START				(55)

#define Y_DATE_START				(75)

#define Y_DAY_START					(105)

/*
*********************************************************************************************************
*                                        		TYPE DEFINITIONS
*********************************************************************************************************
*/
/* AM_PM */
typedef enum AM_PM
{
	AM	= 0,
	PM	= 1
} AM_PM_TYPE;

/* Time Type */
typedef struct
{
	u8     		Seconds;
	u8     		Minutes;
	u8     		Hours;
	AM_PM_TYPE	AM_PM;
} TIME_TYPE;

/*
*********************************************************************************************************
*                                        		LOOKUP TABLES
*********************************************************************************************************
*/
u8	Global_u8Months[][4] = {	"JAN",
								"FEB",
								"MAR",
								"APR",
								"MAY",
								"JUN",
								"JUL",
								"AUG",
								"SEP",
								"OCT",
								"NOV",
								"DEC"	};

u8	Global_u8Days  [][10] = {	"Saturday " ,
								" Sunday  " ,
								" Monday  " ,
								" Tuesday " ,
								"Wednesday" ,
								"Thursday " ,
								" Friday  "		};

/*
*********************************************************************************************************
*                                        		GLOBAL VARIABLES
*********************************************************************************************************
*/
TIME_TYPE   Global_Time_TypeTime;
u8		 	Global_u8Date;
u8		 	Global_u8Month;
u16		 	Global_u16Year;
u8		 	Global_u8Day;
u8		 	Global_u8MaximumMonthDays;


/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' PROTOTYPES
*********************************************************************************************************
*/
static void InitDigitalClock(void);
static void DisplayTitle	(void);
static void DisplayTime 	(TIME_TYPE *Copy_PTime_TypeTime);
static void DisplayDate	 	(u8	Copy_u8Date, u8 Copy_u8Month, u16 Copy_u16Year, u8 Copy_u8Day);
static void UpdateSeconds	(void);
static void UpdateMinutes	(void);
static void UpdateHours		(void);
static void UpdateDays		(void);
static void UpdateMonths	(void);
static void UpdateYears		(void);

#endif
//***************************************************************************************************************
