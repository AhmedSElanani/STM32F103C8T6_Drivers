/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 22 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
#define EXTI_LINE0_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE1_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE2_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE3_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE4_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE5_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE6_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE7_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE8_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE9_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE10_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE11_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE12_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE13_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE14_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define EXTI_LINE15_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE


/* Note: Select Value only if you Enabled EXTI_LINE0 */ 
#if (EXTI_LINE0_ENABLE == 1)
	#define EXTI_LINE0_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE0_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE0 Configuration	*/

/* Note: Select Value only if you Enabled EXTI_LINE1 */ 
#if (EXTI_LINE1_ENABLE == 1)
	#define EXTI_LINE1_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE1_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE1 Configuration	*/

/* Note: Select Value only if you Enabled EXTI_LINE2 */ 
#if (EXTI_LINE2_ENABLE == 1)
	#define EXTI_LINE2_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE2_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE2 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE3 */ 
#if (EXTI_LINE3_ENABLE == 1)
	#define EXTI_LINE3_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE3_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE3 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE4 */ 
#if (EXTI_LINE4_ENABLE == 1)
	#define EXTI_LINE4_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE4_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE4 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE5 */ 
#if (EXTI_LINE5_ENABLE == 1)
	#define EXTI_LINE5_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE5_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE5 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE6 */ 
#if (EXTI_LINE6_ENABLE == 1)
	#define EXTI_LINE6_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE6_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE6 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE7 */ 
#if (EXTI_LINE7_ENABLE == 1)
	#define EXTI_LINE7_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE7_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE7 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE8 */ 
#if (EXTI_LINE8_ENABLE == 1)
	#define EXTI_LINE8_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE8_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE8 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE9 */ 
#if (EXTI_LINE9_ENABLE == 1)
	#define EXTI_LINE9_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE9_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE9 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE10 */ 
#if (EXTI_LINE10_ENABLE == 1)
	#define EXTI_LINE10_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE10_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE10 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE11 */ 
#if (EXTI_LINE11_ENABLE == 1)
	#define EXTI_LINE11_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE11_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE11 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE12 */ 
#if (EXTI_LINE12_ENABLE == 1)
	#define EXTI_LINE12_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE12_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE12 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE13 */ 
#if (EXTI_LINE13_ENABLE == 1)
	#define EXTI_LINE13_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE13_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE13 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE14 */ 
#if (EXTI_LINE14_ENABLE == 1)
	#define EXTI_LINE14_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE14_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE14 Configuration	*/


/* Note: Select Value only if you Enabled EXTI_LINE15 */ 
#if (EXTI_LINE15_ENABLE == 1)
	#define EXTI_LINE15_RISINGEDGE_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
	#define EXTI_LINE15_FALLINGEDGE_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of EXTI_LINE15 Configuration	*/


#endif
//***************************************************************************************************************
