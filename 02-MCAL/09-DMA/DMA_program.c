/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


/*
*****************************************************************************************************************
*                               	            FUNCTION DEFINITIONS
*****************************************************************************************************************
*/
void MDMA_voidInit (void)
{
	#if (DMA_CH1_ENABLE == 1)
		#if   (DMA_CH1_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[0]).CCR = (0x00004000);				
		#elif (DMA_CH1_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[0]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH1_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[0]).CCR) |= (0x00000400);				
		#elif (DMA_CH1_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[0]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH1_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[0]).CCR) |= (0x00000100);				
		#elif (DMA_CH1_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[0]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH1_MINC_ENABLE == 1)
			((DMA1->Channel[0]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH1_PINC_ENABLE == 1)
			((DMA1->Channel[0]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH1_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[0]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH1_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[0]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH1_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[0]).CCR) |= (0x00000002);				
		#endif
	#endif	


	#if (DMA_CH2_ENABLE == 1)
		#if   (DMA_CH2_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[1]).CCR = (0x00004000);				
		#elif (DMA_CH2_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[1]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH2_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[1]).CCR) |= (0x00000400);				
		#elif (DMA_CH2_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[1]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH2_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[1]).CCR) |= (0x00000100);				
		#elif (DMA_CH1_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[1]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH2_MINC_ENABLE == 1)
			((DMA1->Channel[1]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH2_PINC_ENABLE == 1)
			((DMA1->Channel[1]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH2_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[1]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH2_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[1]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH2_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[1]).CCR) |= (0x00000002);				
		#endif
	#endif	

	
	#if (DMA_CH3_ENABLE == 1)
		#if   (DMA_CH3_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[2]).CCR = (0x00004000);				
		#elif (DMA_CH3_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[2]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH3_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[2]).CCR) |= (0x00000400);				
		#elif (DMA_CH3_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[2]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH3_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[2]).CCR) |= (0x00000100);				
		#elif (DMA_CH3_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[2]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH3_MINC_ENABLE == 1)
			((DMA1->Channel[2]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH3_PINC_ENABLE == 1)
			((DMA1->Channel[2]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH3_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[2]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH3_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[2]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH3_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[2]).CCR) |= (0x00000002);				
		#endif
	#endif	

	
	#if (DMA_CH4_ENABLE == 1)
		#if   (DMA_CH4_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[3]).CCR = (0x00004000);				
		#elif (DMA_CH4_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[3]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH4_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[3]).CCR) |= (0x00000400);				
		#elif (DMA_CH4_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[3]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH4_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[3]).CCR) |= (0x00000100);				
		#elif (DMA_CH4_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[3]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH4_MINC_ENABLE == 1)
			((DMA1->Channel[3]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH4_PINC_ENABLE == 1)
			((DMA1->Channel[3]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH4_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[3]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH4_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[3]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH4_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[3]).CCR) |= (0x00000002);				
		#endif
	#endif	

	
	#if (DMA_CH5_ENABLE == 1)
		#if   (DMA_CH5_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[4]).CCR = (0x00004000);				
		#elif (DMA_CH5_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[4]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH5_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[4]).CCR) |= (0x00000400);				
		#elif (DMA_CH5_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[4]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH5_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[4]).CCR) |= (0x00000100);				
		#elif (DMA_CH5_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[4]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH5_MINC_ENABLE == 1)
			((DMA1->Channel[4]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH5_PINC_ENABLE == 1)
			((DMA1->Channel[4]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH5_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[4]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH5_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[4]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH5_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[4]).CCR) |= (0x00000002);				
		#endif
	#endif	

	
	#if (DMA_CH6_ENABLE == 1)
		#if   (DMA_CH6_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[5]).CCR = (0x00004000);				
		#elif (DMA_CH6_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[5]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH6_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[5]).CCR) |= (0x00000400);				
		#elif (DMA_CH6_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[5]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH6_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[5]).CCR) |= (0x00000100);				
		#elif (DMA_CH6_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[5]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH6_MINC_ENABLE == 1)
			((DMA1->Channel[5]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH6_PINC_ENABLE == 1)
			((DMA1->Channel[5]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH6_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[5]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH6_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[5]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH6_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[5]).CCR) |= (0x00000002);				
		#endif
	#endif	

	
	#if (DMA_CH7_ENABLE == 1)
		#if   (DMA_CH7_MEM2MEM_ENABLE == 1)
			(DMA1->Channel[6]).CCR = (0x00004000);				
		#elif (DMA_CH7_MEM2MEM_ENABLE == 0)
			(DMA1->Channel[6]).CCR = (0x00000000);		
		#endif
		
		
		#if   (DMA_CH7_MSIZE == DMA_CH_MSIZE_16BITS)
			((DMA1->Channel[6]).CCR) |= (0x00000400);				
		#elif (DMA_CH7_MSIZE == DMA_CH_MSIZE_32BITS)
			((DMA1->Channel[6]).CCR) |= (0x00000800);				
		#endif


		#if   (DMA_CH7_PSIZE == DMA_CH_PSIZE_16BITS)
			((DMA1->Channel[6]).CCR) |= (0x00000100);				
		#elif (DMA_CH7_PSIZE == DMA_CH_PSIZE_32BITS)
			((DMA1->Channel[6]).CCR) |= (0x00000200);				
		#endif

		
		#if   (DMA_CH7_MINC_ENABLE == 1)
			((DMA1->Channel[6]).CCR) |= (0x00000080);				
		#endif

		
		#if   (DMA_CH7_PINC_ENABLE == 1)
			((DMA1->Channel[6]).CCR) |= (0x00000040);				
		#endif


		#if   (DMA_CH7_CIRCMODE_ENABLE == 1)
			((DMA1->Channel[6]).CCR) |= (0x00000020);				
		#endif
		
		
		#if   (DMA_CH7_DATA_TRANSFER_DIR == 1)
			((DMA1->Channel[6]).CCR) |= (0x00000010);				
		#endif

		
		#if   (DMA_CH7_TRANSFER_COMPLETE_INTERRUPT_ENABLE == 1)
			((DMA1->Channel[6]).CCR) |= (0x00000002);				
		#endif
	#endif	
}
//***************************************************************************************************************
void MDMA_voidSetPeripheralAddress (u8 Copy_u8Channel, u32* Copy_pu32PeripheralAddress)
{
	((DMA1->Channel[Copy_u8Channel]).CPAR) = ((u32)(Copy_pu32PeripheralAddress));
}
//***************************************************************************************************************
void MDMA_voidSetMemoryAddress (u8 Copy_u8Channel, u32* Copy_pu32MemoryAddress)
{
	((DMA1->Channel[Copy_u8Channel]).CMAR) = ((u32)(Copy_pu32MemoryAddress));
}
//***************************************************************************************************************
void MDMA_voidSetNumberOfData (u8 Copy_u8Channel, u16 Copy_u16NumberOfData)
{
	((DMA1->Channel[Copy_u8Channel]).CNDTR) = (Copy_u16NumberOfData);
}
//***************************************************************************************************************
void MDMA_voidSetCallback (u8 Copy_u8Channel, void (*Copy_ptr)(void))
{
	DMA_Callback[Copy_u8Channel] = Copy_ptr;
}
//***************************************************************************************************************
void MDMA_voidEnableChannel (u8 Copy_u8Channel)
{
	((DMA1->Channel[Copy_u8Channel]).CCR) |= (1);				
}
//***************************************************************************************************************
void MDMA_voidDisableChannel (u8 Copy_u8Channel)
{
	((DMA1->Channel[Copy_u8Channel]).CCR) &= ~(1);				
}
/*
*****************************************************************************************************************
*                                       		    ISR'S
*****************************************************************************************************************
*/
void DMA1_Channel1_IRQHandler(void)
{
	DMA1->IFCR = (DMA1_CGIF1);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[0]) != 0)
	{
		(DMA_Callback[0])();
	}
}
//***************************************************************************************************************
void DMA1_Channel2_IRQHandler(void)
{	
	DMA1->IFCR = (DMA1_CGIF2);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[1]) != 0)
	{
		(DMA_Callback[1])();
	}
}
//***************************************************************************************************************
void DMA1_Channel3_IRQHandler(void)
{
	DMA1->IFCR = (DMA1_CGIF3);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[2]) != 0)
	{
		(DMA_Callback[2])();
	}
}
//***************************************************************************************************************
void DMA1_Channel4_IRQHandler(void)
{
	DMA1->IFCR = (DMA1_CGIF4);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[3]) != 0)
	{
		(DMA_Callback[3])();
	}	
}
//***************************************************************************************************************
void DMA1_Channel5_IRQHandler(void)
{
	DMA1->IFCR = (DMA1_CGIF5);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[4]) != 0)
	{
		(DMA_Callback[4])();
	}
}
//***************************************************************************************************************
void DMA1_Channel6_IRQHandler(void)
{
	DMA1->IFCR = (DMA1_CGIF6);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[5]) != 0)
	{
		(DMA_Callback[5])();
	}
}
//***************************************************************************************************************
void DMA1_Channel7_IRQHandler(void)
{
	DMA1->IFCR = (DMA1_CGIF7);		//Clear Global Interrupt Flag
	
	if( (DMA_Callback[6]) != 0)
	{
		(DMA_Callback[6])();
	}
}
//***************************************************************************************************************
