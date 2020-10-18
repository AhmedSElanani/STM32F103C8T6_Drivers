/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 16 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/*
*********************************************************************************************************
*                                           TYPE DEFINITIONS
*********************************************************************************************************
*/
/*	STRUCTURE TO HOLD SPI REGISTERS	*/
typedef struct 
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
} SPI_TypeDef;


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/*	POINTERS TO THE TYPE SPI	*/ 
#define SPI1 	((volatile SPI_TypeDef*)(0x40013000))
#define SPI2 	((volatile SPI_TypeDef*)(0x40003800))


/*	CONFIGURATION OPTIONS FOR SPI1	*/
#define SPI1_CPHA_RW 			 (0)
#define SPI1_CPHA_WR 	 		 (1)
	
#define SPI1_CPOL_IDLELOW 	     (0)
#define SPI1_CPOL_IDLEHIGH 		 (1)

#define SPI1_MODE_SLAVE 		 (0)
#define SPI1_MODE_MASTER 		 (1)

#define SPI1_CLOCKPRE_2 		 (0)
#define SPI1_CLOCKPRE_4 		 (8)
#define SPI1_CLOCKPRE_8 		 (16)
#define SPI1_CLOCKPRE_16 		 (24)
#define SPI1_CLOCKPRE_32 		 (32)
#define SPI1_CLOCKPRE_64 		 (40)
#define SPI1_CLOCKPRE_128 		 (48)
#define SPI1_CLOCKPRE_256 		 (56)

#define SPI1_DATAORDER_MSBFIRST  (0)
#define SPI1_DATAORDER_LSBFIRST  (1)

#define SPI1_DATASIZE_8BITS  	 (0)
#define SPI1_DATASIZE_16BITS 	 (1)


/*	CONFIGURATION OPTIONS FOR SPI1	*/
#define SPI2_CPHA_RW 			 (0)
#define SPI2_CPHA_WR 	 		 (1)
  
#define SPI2_CPOL_IDLELOW 	     (0)
#define SPI2_CPOL_IDLEHIGH 		 (1)
 
#define SPI2_MODE_SLAVE 		 (0)
#define SPI2_MODE_MASTER 		 (1)
  
#define SPI2_CLOCKPRE_2 		 (0)
#define SPI2_CLOCKPRE_4 		 (8)
#define SPI2_CLOCKPRE_8 		 (16)
#define SPI2_CLOCKPRE_16 		 (24)
#define SPI2_CLOCKPRE_32 		 (32)
#define SPI2_CLOCKPRE_64 		 (40)
#define SPI2_CLOCKPRE_128 		 (48)
#define SPI2_CLOCKPRE_256 		 (56)

#define SPI2_DATAORDER_MSBFIRST  (0)
#define SPI2_DATAORDER_LSBFIRST  (1)

#define SPI2_DATASIZE_8BITS  	 (0)
#define SPI2_DATASIZE_16BITS 	 (1)



/*
*********************************************************************************************************
*                                           GLOBAL VARIABLES
*********************************************************************************************************
*/
static  void (*volatile SPI1_Callback)(u8) = 0;
static  void (*volatile SPI2_Callback)(u8) = 0;

#endif
//***************************************************************************************************************
