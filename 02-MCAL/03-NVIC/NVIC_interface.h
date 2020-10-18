/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 19 Aug 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/*
*********************************************************************************************************
*                               		INTERNAL INTERRUPTS' HANDLERS
*********************************************************************************************************
*/
/*
	Reset_Handler             
	NMI_Handler                
	HardFault_Handler         
	MemManage_Handler         
	BusFault_Handler           
	UsageFault_Handler         
	SVC_Handler                
	DebugMon_Handler          
	PendSV_Handler           
	SysTick_Handler    
*/

/*
*********************************************************************************************************
*                               		EXTERNAL INTERRUPTS' HANDLERS
*********************************************************************************************************
*/
/*      
    External Interrupts
    WWDG_IRQHandler            
    PVD_IRQHandler            
    TAMPER_IRQHandler        
    RTC_IRQHandler         
    FLASH_IRQHandler        
    RCC_IRQHandler            
    EXTI0_IRQHandler           
    EXTI1_IRQHandler           
    EXTI2_IRQHandler         
    EXTI3_IRQHandler           
    EXTI4_IRQHandler           
    DMA1_Channel1_IRQHandler   
    DMA1_Channel2_IRQHandler   
    DMA1_Channel3_IRQHandler  
    DMA1_Channel4_IRQHandler   
    DMA1_Channel5_IRQHandler   
    DMA1_Channel6_IRQHandler   
    DMA1_Channel7_IRQHandler   
    ADC1_2_IRQHandler          
    USB_HP_CAN1_TX_IRQHandler  
    USB_LP_CAN1_RX0_IRQHandler 
    CAN1_RX1_IRQHandler        
    CAN1_SCE_IRQHandler        
    EXTI9_5_IRQHandler         
    TIM1_BRK_IRQHandler        
    TIM1_UP_IRQHandler         
    TIM1_TRG_COM_IRQHandler    
    TIM1_CC_IRQHandler         
    TIM2_IRQHandler            
    TIM3_IRQHandler            
    TIM4_IRQHandler          
    I2C1_EV_IRQHandler       
    I2C1_ER_IRQHandler         
    I2C2_EV_IRQHandler        
	I2C2_ER_IRQHandler       
    SPI1_IRQHandler            
    SPI2_IRQHandler            
	USART1_IRQHandler         
    USART2_IRQHandler          
    USART3_IRQHandler          
    EXTI15_10_IRQHandler       
    RTCAlarm_IRQHandler        
    USBWakeUp_IRQHandler       
*/					

/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/* INTERRUPTS' IRQ NUMBERS */	
#define		NVIC_IRQ_WWDG							((u8)(0))
#define		NVIC_IRQ_PVD							((u8)(1))
#define		NVIC_IRQ_TAMPER							((u8)(2))
#define		NVIC_IRQ_RTC							((u8)(3))
#define		NVIC_IRQ_FLASH							((u8)(4))
#define		NVIC_IRQ_RCC							((u8)(5))
#define		NVIC_IRQ_EXTI0							((u8)(6))
#define		NVIC_IRQ_EXTI1							((u8)(7))
#define		NVIC_IRQ_EXTI2							((u8)(8))
#define		NVIC_IRQ_EXTI3							((u8)(9))
#define		NVIC_IRQ_EXTI4							((u8)(10))
#define		NVIC_IRQ_DMA1_CHANNEL1					((u8)(11))
#define		NVIC_IRQ_DMA1_CHANNEL2					((u8)(12))
#define		NVIC_IRQ_DMA1_CHANNEL3					((u8)(13))
#define		NVIC_IRQ_DMA1_CHANNEL4					((u8)(14))
#define		NVIC_IRQ_DMA1_CHANNEL5					((u8)(15))
#define		NVIC_IRQ_DMA1_CHANNEL6					((u8)(16))
#define		NVIC_IRQ_DMA1_CHANNEL7					((u8)(17))
#define		NVIC_IRQ_ADC1_2							((u8)(18))
#define		NVIC_IRQ_USB_HP_CAN_TX					((u8)(19))
#define		NVIC_IRQ_USB_LP_CAN_RX0					((u8)(20))
#define		NVIC_IRQ_CAN_RX1						((u8)(21))
#define		NVIC_IRQ_CAN_SCE						((u8)(22))
#define		NVIC_IRQ_EXTI9_5						((u8)(23))
#define		NVIC_IRQ_TIM1_BRK						((u8)(24))
#define		NVIC_IRQ_TIM1_UP						((u8)(25))
#define		NVIC_IRQ_TIM1_TRG_COM					((u8)(26))
#define		NVIC_IRQ_TIM1_CC						((u8)(27))
#define		NVIC_IRQ_TIM2							((u8)(28))
#define		NVIC_IRQ_TIM3							((u8)(29))
#define		NVIC_IRQ_TIM4							((u8)(30))
#define		NVIC_IRQ_I2C1_EV						((u8)(31))
#define		NVIC_IRQ_I2C1_ER						((u8)(32))
#define		NVIC_IRQ_I2C2_EV						((u8)(33))
#define		NVIC_IRQ_I2C2_ER						((u8)(34))
#define		NVIC_IRQ_SPI1							((u8)(35))
#define		NVIC_IRQ_SPI2							((u8)(36))
#define		NVIC_IRQ_USART1							((u8)(37))
#define		NVIC_IRQ_USART2							((u8)(38))
#define		NVIC_IRQ_USART3							((u8)(39))
#define		NVIC_IRQ_EXTI15_10						((u8)(40))
#define		NVIC_IRQ_RTCALARM						((u8)(41))
#define		NVIC_IRQ_USBWAKEUP						((u8)(42))
#define		NVIC_IRQ_TIM8_BRK						((u8)(43))
#define		NVIC_IRQ_TIM8_UP						((u8)(44))
#define		NVIC_IRQ_TIM8_TRG_COM					((u8)(45))
#define		NVIC_IRQ_TIM8_CC						((u8)(46))
#define		NVIC_IRQ_ADC3							((u8)(47))
#define		NVIC_IRQ_FSMC							((u8)(48))
#define		NVIC_IRQ_SDIO							((u8)(49))
#define		NVIC_IRQ_TIM5							((u8)(50))
#define		NVIC_IRQ_SPI3							((u8)(51))
#define		NVIC_IRQ_UART4							((u8)(52))
#define		NVIC_IRQ_UART5							((u8)(53))
#define		NVIC_IRQ_TIM6							((u8)(54))
#define		NVIC_IRQ_TIM7							((u8)(55))
#define		NVIC_IRQ_DMA2_CHANNEL1					((u8)(56))
#define		NVIC_IRQ_DMA2_CHANNEL2					((u8)(57))
#define		NVIC_IRQ_DMA2_CHANNEL3					((u8)(58))
#define		NVIC_IRQ_DMA2_CHANNEL4_5				((u8)(59))

/* INTERRUPTS' PRIORITY GROUP NUMBERS */	
#define		NVIC_PRI_GP_0							((u8)(0))
#define		NVIC_PRI_GP_1							((u8)(1))
#define		NVIC_PRI_GP_2							((u8)(2))
#define		NVIC_PRI_GP_3							((u8)(3))
#define		NVIC_PRI_GP_4							((u8)(4))
#define		NVIC_PRI_GP_5							((u8)(5))
#define		NVIC_PRI_GP_6							((u8)(6))
#define		NVIC_PRI_GP_7							((u8)(7))
#define		NVIC_PRI_GP_8							((u8)(8))
#define		NVIC_PRI_GP_9							((u8)(9))
#define		NVIC_PRI_GP_10							((u8)(10))
#define		NVIC_PRI_GP_11							((u8)(11))
#define		NVIC_PRI_GP_12							((u8)(12))
#define		NVIC_PRI_GP_13							((u8)(13))
#define		NVIC_PRI_GP_14							((u8)(14))
#define		NVIC_PRI_GP_15							((u8)(15))
#define		NVIC_PRI_GP_16							((u8)(16))

/* INTERRUPTS' SUB-PRIORITY NUMBERS */	
#define		NVIC_PRI_SP_0							((u8)(0))
#define		NVIC_PRI_SP_1							((u8)(1))
#define		NVIC_PRI_SP_2							((u8)(2))
#define		NVIC_PRI_SP_3							((u8)(3))
#define		NVIC_PRI_SP_4							((u8)(4))
#define		NVIC_PRI_SP_5							((u8)(5))
#define		NVIC_PRI_SP_6							((u8)(6))
#define		NVIC_PRI_SP_7							((u8)(7))
#define		NVIC_PRI_SP_8							((u8)(8))
#define		NVIC_PRI_SP_9							((u8)(9))
#define		NVIC_PRI_SP_10							((u8)(10))
#define		NVIC_PRI_SP_11							((u8)(11))
#define		NVIC_PRI_SP_12							((u8)(12))
#define		NVIC_PRI_SP_13							((u8)(13))
#define		NVIC_PRI_SP_14							((u8)(14))
#define		NVIC_PRI_SP_15							((u8)(15))
#define		NVIC_PRI_SP_16							((u8)(16))

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MNVIC_voidEnableInterrupt      (u8 Copy_u8InterruptNumber);
void MNVIC_voidDisableInterrupt     (u8 Copy_u8InterruptNumber);
void MNVIC_voidSetPendingFlag  	    (u8 Copy_u8InterruptNumber);
void MNVIC_voidClearPendingFlag	    (u8 Copy_u8InterruptNumber);
u8 	 MNVIC_u8GetActiveFlag          (u8 Copy_u8InterruptNumber);
void MNVIC_voidSetInterruptPriority (u8 Copy_u8InterruptNumber, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif
//***************************************************************************************************************
