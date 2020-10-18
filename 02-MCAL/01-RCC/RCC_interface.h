/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 8 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/* Clock Types */
#define RCC_HSE_CRYSTAL						(0)
#define RCC_HSE_RC							(1)
#define RCC_HSI								(2)
#define RCC_PLL								(3)

/* PLL Input Options */
#define RCC_PLL_IN_HSI_DIV_2				(0)
#define RCC_PLL_IN_HSE_CRYSTAL_DIV_2		(1)
#define RCC_PLL_IN_HSE_CRYSTAL				(2)
#define RCC_PLL_IN_HSE_RC_DIV_2				(3)
#define RCC_PLL_IN_HSE_RC					(4)

/* System Buses */
#define	RCC_AHB								((u8)(0))
#define	RCC_APB1							((u8)(1))
#define	RCC_APB2							((u8)(2))

/* AHB Bus Peripherals' IDs */
#define	RCC_AHB_DMA1EN						((u8)(0))
#define	RCC_AHB_DMA2EN						((u8)(1))
#define	RCC_AHB_SRAMEN						((u8)(2))
#define	RCC_AHB_FLITFEN						((u8)(4))
#define	RCC_AHB_CRCEN						((u8)(6))
#define	RCC_AHB_FSMCEN						((u8)(8))
#define	RCC_AHB_SDIOEN						((u8)(10))

/* APB1 Bus Peripherals' IDs */
#define	RCC_APB1_TIM2EN						((u8)(0))
#define	RCC_APB1_TIM3EN						((u8)(1))
#define	RCC_APB1_TIM4EN						((u8)(2))
#define	RCC_APB1_TIM5EN						((u8)(3))
#define	RCC_APB1_TIM6EN						((u8)(4))
#define	RCC_APB1_TIM7EN						((u8)(5))
#define	RCC_APB1_TIM12EN					((u8)(6))
#define	RCC_APB1_TIM13EN					((u8)(7))
#define	RCC_APB1_TIM14EN					((u8)(8))
#define	RCC_APB1_WWDGEN						((u8)(11))
#define	RCC_APB1_SPI2EN						((u8)(14))
#define	RCC_APB1_SPI3EN						((u8)(15))
#define	RCC_APB1_USART2EN					((u8)(17))
#define	RCC_APB1_USART3EN					((u8)(18))
#define	RCC_APB1_USART4EN					((u8)(19))
#define	RCC_APB1_USART5EN					((u8)(20))
#define	RCC_APB1_I2C1EN						((u8)(21))
#define	RCC_APB1_I2C2EN						((u8)(22))
#define	RCC_APB1_USBEN						((u8)(23))
#define	RCC_APB1_CANEN						((u8)(25))
#define	RCC_APB1_BKPEN						((u8)(27))
#define	RCC_APB1_PWREN						((u8)(28))
#define	RCC_APB1_DACEN						((u8)(29))

/* APB2 Bus Peripherals' IDs */
#define	RCC_APB2_AFIOEN						((u8)(0))
#define	RCC_APB2_IOPAEN						((u8)(2))
#define	RCC_APB2_IOPBEN						((u8)(3))
#define	RCC_APB2_IOPCEN						((u8)(4))
#define	RCC_APB2_IOPDEN						((u8)(5))
#define	RCC_APB2_IOPEEN						((u8)(6))
#define	RCC_APB2_IOPFEN						((u8)(7))
#define	RCC_APB2_IOPGEN						((u8)(8))
#define	RCC_APB2_ADC1EN						((u8)(9))
#define	RCC_APB2_ADC2EN						((u8)(10))
#define	RCC_APB2_TIM1EN						((u8)(11))
#define	RCC_APB2_SPI1EN						((u8)(12))
#define	RCC_APB2_TIM8EN						((u8)(13))
#define	RCC_APB2_USART1EN					((u8)(14))
#define	RCC_APB2_ADC3EN						((u8)(15))
#define	RCC_APB2_TIM9EN						((u8)(19))
#define	RCC_APB2_TIM10EN					((u8)(20))
#define	RCC_APB2_TIM11EN					((u8)(21))

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MRCC_voidInitSysClock (void);
void MRCC_voidEnableClock  (u8 Copy_u8BusID, u8 Copy_u8PerID);
void MRCC_voidDisableClock (u8 Copy_u8BusID, u8 Copy_u8PerID);

#endif
//***************************************************************************************************************
