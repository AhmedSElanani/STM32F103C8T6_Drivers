/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 5 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

/*
*********************************************************************************************************
*                                        			MACROS
*********************************************************************************************************
*/
/* Macro Definition for (NULL) */
#define	NULL	((void*)(0))

/*
*********************************************************************************************************
*                                        		TYPE DEFINITIONS
*********************************************************************************************************
*/
/* Task States Type */
typedef enum Task_State 
{
	DORMANT_STATE	= 0,
	WAITING_STATE	= 1,
	READY_STATE     = 2,
	RUNNING_STATE   = 3,
	SUSPENDED_STATE = 4
} Task_State;

/* Dispatched Task Type */
typedef struct 
{
	u8     Task_Priority;
	u8     Task_Position;
	void (*Task_Ptr) (void);
} Dispatched_Task;

/* TCB Type */
typedef struct 
{
	u8   		  Task_ID;
	u32 		  Task_Period;
	u32 		  Task_PeriodReload;
	u32 		  Task_InitialDelay;
	Task_State    Task_State;
	void 		(*Task_Ptr) (void);
} TCB;

/*
*********************************************************************************************************
*                                        	PRIVATE GLOBAL VARIABLES
*********************************************************************************************************
*/
/* Create TCBs and their Pointer */
static volatile  TCB  OS_TCB [OS_PRIORITIES][OS_QUEUELENGTH];

/* Create Arrays for the Top of each Queue */
static volatile u8 Global_u32OS_QueueTop[OS_PRIORITIES] 	 = {0};

/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' PROTOTYPES
*********************************************************************************************************
*/
void Scheduler (void);
Dispatched_Task* Dispatcher (void);

#endif
//***************************************************************************************************************
