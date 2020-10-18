/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 29 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef DIGITALCLOCK_CONFIG_H
#define DIGITALCLOCK_CONFIG_H

/*
*********************************************************************************************************
*                                        CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
/*	CONFIGURE DISPLAY COLORS	*/
#define DIGITALCLOCK_TEXTCOLOR						(TFT_COLOR_GREEN)
#define DIGITALCLOCK_BGCOLOR						(TFT_COLOR_BLACK)


/*	CONFIGURE START TIME	*/
#define DIGITALCLOCK_STARTTIME_SECONDS				(40)
#define DIGITALCLOCK_STARTTIME_MINUTES				(46)
#define DIGITALCLOCK_STARTTIME_HOURS				(4)
#define DIGITALCLOCK_STARTTIME_AM_PM				(1)   // (0) FOR (AM), (1) FOR (PM)

/*	CONFIGURE START DAY	*/
#define DIGITALCLOCK_STARTDATE						(30)  // FROM (1) to (31)
#define DIGITALCLOCK_STARTDAY						(5)	  // FROM (1) to (7)

/*	CONFIGURE START MONTH	*/
#define DIGITALCLOCK_STARTMONTH						(9)  // FROM (1) to (12)

/*	CONFIGURE START YEAR	*/
#define DIGITALCLOCK_STARTYEAR						(2020UL)

#endif
//***************************************************************************************************************
