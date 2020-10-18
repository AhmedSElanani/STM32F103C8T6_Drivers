/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 15 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
#define DMA_CH1_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define DMA_CH2_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define DMA_CH3_ENABLE		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define DMA_CH4_ENABLE		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define DMA_CH5_ENABLE		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define DMA_CH6_ENABLE		(0)		// (0) FOR DISABLE, (1) FOR ENABLE
#define DMA_CH7_ENABLE		(0)		// (0) FOR DISABLE, (1) FOR ENABLE


/* Note: Select Value only if you Enabled CHANNEL_1 */ 
#if (DMA_CH1_ENABLE == 1)
	#define DMA_CH1_MEM2MEM_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH1_MSIZE		 						(DMA_CH_MSIZE_8BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH1_PSIZE		 						(DMA_CH_PSIZE_8BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH1_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH1_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH1_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH1_DATA_TRANSFER_DIR 					(0)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY
	#define DMA_CH1_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of Channel_1 Configuration	*/

/* Note: Select Value only if you Enabled CHANNEL_2 */ 
#if (DMA_CH2_ENABLE == 1)
	#define DMA_CH2_MEM2MEM_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH2_MSIZE		 						(DMA_CH_MSIZE_8BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH2_PSIZE		 						(DMA_CH_PSIZE_8BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH2_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH2_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH2_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH2_DATA_TRANSFER_DIR 					(0)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY
	#define DMA_CH2_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of Channel_2 Configuration	*/

/* Note: Select Value only if you Enabled CHANNEL_3 */ 
#if (DMA_CH3_ENABLE == 1)
	#define DMA_CH3_MEM2MEM_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH3_MSIZE		 						(DMA_CH_MSIZE_32BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH3_PSIZE		 						(DMA_CH_PSIZE_32BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH3_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH3_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH3_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH3_DATA_TRANSFER_DIR 					(1)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY
	#define DMA_CH3_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE			 
#endif	/* End of Channel_3 Configuration	*/

/* Note: Select Value only if you Enabled CHANNEL_4 */ 
#if (DMA_CH4_ENABLE == 1)
	#define DMA_CH4_MEM2MEM_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH4_MSIZE		 						(DMA_CH_MSIZE_8BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH4_PSIZE		 						(DMA_CH_PSIZE_8BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH4_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH4_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH4_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH4_DATA_TRANSFER_DIR 					(0)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY	 
	#define DMA_CH4_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of Channel_4 Configuration	*/

/* Note: Select Value only if you Enabled CHANNEL_5 */ 
#if (DMA_CH5_ENABLE == 1)
	#define DMA_CH5_MEM2MEM_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH5_MSIZE		 						(DMA_CH_MSIZE_8BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH5_PSIZE		 						(DMA_CH_PSIZE_8BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH5_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH5_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH5_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH5_DATA_TRANSFER_DIR 					(0)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY	 
	#define DMA_CH5_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of Channel_5 Configuration	*/

/* Note: Select Value only if you Enabled CHANNEL_6 */ 
#if (DMA_CH6_ENABLE == 1)
	#define DMA_CH6_MEM2MEM_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH6_MSIZE		 						(DMA_CH_MSIZE_8BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH6_PSIZE		 						(DMA_CH_PSIZE_8BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH6_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH6_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH6_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH6_DATA_TRANSFER_DIR 					(0)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY	 
	#define DMA_CH6_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of Channel_6 Configuration	*/

/* Note: Select Value only if you Enabled CHANNEL_7 */ 
#if (DMA_CH7_ENABLE == 1)
	#define DMA_CH7_MEM2MEM_ENABLE 						(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH7_MSIZE		 						(DMA_CH_MSIZE_32BITS)	// OPTIONS: (DMA_CH_MSIZE_8BITS / DMA_CH_MSIZE_16BITS / DMA_CH_MSIZE_32BITS)
	#define DMA_CH7_PSIZE		 						(DMA_CH_PSIZE_32BITS)	// OPTIONS: (DMA_CH_PSIZE_8BITS / DMA_CH_PSIZE_16BITS / DMA_CH_PSIZE_32BITS)
	#define DMA_CH7_MINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH7_PINC_ENABLE 						(1)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH7_CIRCMODE_ENABLE 					(0)						// (0) FOR DISABLE, (1) FOR ENABLE
	#define DMA_CH7_DATA_TRANSFER_DIR 					(0)						// (0) FOR READ FROM PERIPHERAL, (1) FOR READ FROM MEMORY	 
	#define DMA_CH7_TRANSFER_COMPLETE_INTERRUPT_ENABLE 	(1)						// (0) FOR DISABLE, (1) FOR ENABLE
#endif	/* End of Channel_7 Configuration	*/


#endif
//***************************************************************************************************************
