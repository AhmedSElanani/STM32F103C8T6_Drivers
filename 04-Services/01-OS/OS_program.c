/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 5 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void SOS_voidCreateTask (u8 Copy_u8TaskPriority, u16 Copy_u16TaskID, u32 Copy_u32TaskPeriod, u32 Copy_u32TaskInitialDelay, void (*Copy_ptr) (void) )
{
	if( Copy_u8TaskPriority >= (OS_PRIORITIES) )
	{
		return;
	}
	else if(Global_u32OS_QueueTop[Copy_u8TaskPriority] <  OS_QUEUELENGTH)
	{
		/*	Set Task Parameters	*/
		( OS_TCB[Copy_u8TaskPriority][ Global_u32OS_QueueTop[Copy_u8TaskPriority] ] ).Task_ID		    = Copy_u16TaskID;
		( OS_TCB[Copy_u8TaskPriority][ Global_u32OS_QueueTop[Copy_u8TaskPriority] ] ).Task_Period	    = Copy_u32TaskPeriod;
		( OS_TCB[Copy_u8TaskPriority][ Global_u32OS_QueueTop[Copy_u8TaskPriority] ] ).Task_PeriodReload = Copy_u32TaskPeriod;
		( OS_TCB[Copy_u8TaskPriority][ Global_u32OS_QueueTop[Copy_u8TaskPriority] ] ).Task_InitialDelay = Copy_u32TaskInitialDelay;
		( OS_TCB[Copy_u8TaskPriority][ Global_u32OS_QueueTop[Copy_u8TaskPriority] ] ).Task_State	   	= DORMANT_STATE;
		( OS_TCB[Copy_u8TaskPriority][ Global_u32OS_QueueTop[Copy_u8TaskPriority] ] ).Task_Ptr		    = Copy_ptr;
		
		/*	Update Top of Queue	*/
		(Global_u32OS_QueueTop[Copy_u8TaskPriority])++;
	}
}
//***************************************************************************************************************
void SOS_voidStartScheduler (void)
{
	MSysTick_voidInit();									/* initialize systick */
	MSysTick_voidSetIntervalPeriodic(OS_TICKS,Scheduler);	/* Call scheduler periodically */
}
//***************************************************************************************************************
void SOS_voidSuspendTask (void (*Copy_ptr) (void))
{
	for(u8 i=0; i<OS_PRIORITIES; i++)
	{
		for(u8 j=0; j<Global_u32OS_QueueTop[i]; j++)
		{
			if((OS_TCB[i][j]).Task_Ptr == Copy_ptr)
			{
				(OS_TCB[i][j]).Task_State = SUSPENDED_STATE;
				return;
			}
		}
	}	
}
//***************************************************************************************************************
void SOS_voidResumeTask (void (*Copy_ptr) (void))
{
	for(u8 i=0; i<OS_PRIORITIES; i++)
	{
		for(u8 j=0; j<Global_u32OS_QueueTop[i]; j++)
		{
			if((OS_TCB[i][j]).Task_Ptr == Copy_ptr)
			{
				(OS_TCB[i][j]).Task_State = READY_STATE;
				return;
			}
		}
	}	
}
//***************************************************************************************************************
void SOS_voidKillTask (void (*Copy_ptr) (void))
{
	for(u8 i=0; i<OS_PRIORITIES ;i++)
	{
		for(u8 j=0; j<Global_u32OS_QueueTop[i]; j++)
		{
			if( (OS_TCB[i][j]).Task_Ptr == Copy_ptr )
			{
				for(u8 k=j; k<Global_u32OS_QueueTop[i]-1; k++)
				{
					OS_TCB[i][k] = OS_TCB[i][k+1];
				}
				/*	Update Top of Queue	*/
				(Global_u32OS_QueueTop[i])--;
				return;
			}
		}
	}	
}
//***************************************************************************************************************
void Scheduler (void)
{
	static volatile  Dispatched_Task *Running_Task;
		
	/*	Handle Dormant and Waiting Tasks	*/
	for(u8 i=0; i<OS_PRIORITIES; i++)		
	{
		for(u8 j=0; j<Global_u32OS_QueueTop[i] ; j++)
		{
			if( (OS_TCB[i][j]).Task_State  ==  DORMANT_STATE )
			{
				if(!((OS_TCB[i][j]).Task_InitialDelay))
				{
					(OS_TCB[i][j]).Task_State =  WAITING_STATE;
				}
				else
				{
					((OS_TCB[i][j]).Task_InitialDelay)-- ;
				}
			}
			
			if( (OS_TCB[i][j]).Task_State ==  WAITING_STATE )
			{
				if( !( ((OS_TCB[i][j]).Task_Period) % ((OS_TCB[i][j] ).Task_PeriodReload) ) )
				{
					 (OS_TCB[i][j]).Task_State   =  READY_STATE;
					 (OS_TCB[i][j]).Task_Period  = (OS_TCB[i][j]).Task_PeriodReload;
				}
				
				((OS_TCB[i][j]).Task_Period)--;
			}
		}	
	}	
	
	/*	Call the Dispatcher	*/
	while( (Running_Task = Dispatcher()) != NULL )
	{
		/*	Set the dispatched task state to Running State	*/
		(OS_TCB[(Running_Task->Task_Priority)][(Running_Task->Task_Position)]).Task_State = RUNNING_STATE;

		/*	Execute the task	*/
		(Running_Task->Task_Ptr)();

		/* Return to Waiting state	*/
		(OS_TCB[(Running_Task->Task_Priority)][(Running_Task->Task_Position)]).Task_State = WAITING_STATE;
	}
}
//***************************************************************************************************************
Dispatched_Task* Dispatcher (void)
{
	static volatile Dispatched_Task Current_DispatchedTask;
	static volatile u8 i =0;
	
	/*	Handle Ready Tasks	*/
	for( ; i<OS_PRIORITIES; i++)
	{
		for(u8 j=0 ; j<Global_u32OS_QueueTop[i] ; j++)
		{
			if( (OS_TCB[i][j]).Task_State ==  READY_STATE )
			{
				 Current_DispatchedTask.Task_Priority =   i;
				 Current_DispatchedTask.Task_Position =   j;
				 Current_DispatchedTask.Task_Ptr	  =  (OS_TCB[i][j]).Task_Ptr;
				
				return (&Current_DispatchedTask);
			}   	 
		}
	}
	
	/* If no Task Ready, Reset Index, and Return Null */
	i = 0;

	return (NULL);
}
//***************************************************************************************************************
