/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 16 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/*
*********************************************************************************************************
*                                          CONFIGURABLE PARAMETERS
*********************************************************************************************************
*/
#define SPI1_ENABLE 		(1)		// (0) FOR DISABLE, (1) FOR ENABLE
#define SPI2_ENABLE 		(0)		// (0) FOR DISABLE, (1) FOR ENABLE


/* Note: Select Value only if you Enabled SPI_1 */ 
#if (SPI1_ENABLE == 1)
	#define	SPI1_SLAVE		 GPIOA,PIN0					// NOTE: Write in pair GPIOx,PINy
	#define SPI1_CPHA		(SPI1_CPHA_WR)				// OPTIONS: (SPI1_CPHA_WR 		 / SPI1_CPHA_RW)
	#define SPI1_CPOL		(SPI1_CPOL_IDLEHIGH)		// OPTIONS: (SPI1_CPOL_IDLELOW 	 / SPI1_CPOL_IDLEHIGH)
	#define SPI1_MODE		(SPI1_MODE_MASTER)			// OPTIONS: (SPI1_MODE_MASTER 	 / SPI1_MODE_SLAVE)
	
	/* 	OPTIONS: (	SPI1_CLOCKPRE_2  / SPI1_CLOCKPRE_4  / SPI1_CLOCKPRE_8   / SPI1_CLOCKPRE_16 /
					SPI1_CLOCKPRE_32 / SPI1_CLOCKPRE_64 / SPI1_CLOCKPRE_128 / SPI1_CLOCKPRE_256   ) 	*/
	#define SPI1_CLOCKPRE	(SPI1_CLOCKPRE_2)
	
	#define SPI1_DATAORDER	(SPI1_DATAORDER_MSBFIRST)	// OPTIONS: (SPI1_DATAORDER_LSBFIRST / SPI1_DATAORDER_MSBFIRST)	
	#define SPI1_DATASIZE	(SPI1_DATASIZE_8BITS)		// OPTIONS: (SPI1_DATASIZE_8BITS 	 / SPI1_DATASIZE_16BITS)
#endif	/* End of SPI_1 Configuration	*/


/* Note: Select Value only if you Enabled SPI_2 */ 
#if (SPI2_ENABLE == 1)
	#define	SPI2_SLAVE		 GPIOA,PIN0					// NOTE: Write in pair GPIOx,PINy
	#define SPI2_CPHA		(SPI2_CPHA_WR)				// OPTIONS: (SPI2_CPHA_WR 		 / SPI2_CPHA_RW)
	#define SPI2_CPOL		(SPI2_CPOL_IDLEHIGH)		// OPTIONS: (SPI2_CPOL_IDLELOW 	 / SPI2_CPOL_IDLEHIGH)
	#define SPI2_MODE		(SPI2_MODE_MASTER)			// OPTIONS: (SPI2_MODE_MASTER 	 / SPI2_MODE_SLAVE)
	
	/* 	OPTIONS: (	SPI2_CLOCKPRE_2  / SPI2_CLOCKPRE_4  / SPI2_CLOCKPRE_8   / SPI2_CLOCKPRE_16 /
					SPI2_CLOCKPRE_32 / SPI2_CLOCKPRE_64 / SPI2_CLOCKPRE_128 / SPI2_CLOCKPRE_256   ) 	*/
	#define SPI2_CLOCKPRE	(SPI2_CLOCKPRE_2)				
	
	#define SPI2_DATAORDER	(SPI2_DATAORDER_MSBFIRST)	// OPTIONS: (SPI2_DATAORDER_LSBFIRST / SPI2_DATAORDER_MSBFIRST)	
	#define SPI2_DATASIZE	(SPI2_DATASIZE_8BITS)		// OPTIONS: (SPI2_DATASIZE_8BITS     / SPI2_DATASIZE_16BITS)
#endif	/* End of SPI_2 Configuration	*/

#endif
//***************************************************************************************************************
