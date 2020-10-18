/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 19 Aug 2020										  */
/* Version	: V02												  */
/******************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*
*********************************************************************************************************
*                                           	MACROS
*********************************************************************************************************
*/
/* GPIOS */
#define		GPIOA					((u8)(0))
#define		GPIOB					((u8)(1))
#define		GPIOC					((u8)(2))

/* GPIO PINS */
#define		PIN0					((u8)(0))
#define		PIN1					((u8)(1))
#define		PIN2					((u8)(2))
#define		PIN3					((u8)(3))
#define		PIN4					((u8)(4))
#define		PIN5					((u8)(5))
#define		PIN6					((u8)(6))
#define		PIN7					((u8)(7))
#define		PIN8					((u8)(8))
#define		PIN9					((u8)(9))
#define		PIN10					((u8)(10))
#define		PIN11					((u8)(11))
#define		PIN12					((u8)(12))
#define		PIN13					((u8)(13))
#define		PIN14					((u8)(14))
#define		PIN15					((u8)(15))

/* GPIO INPUT MODES */	
#define		INPUT_ANALOG			((u8)(0x0))
#define		INPUT_FLOATING			((u8)(0x4))
#define		INPUT_PULLDOWN			((u8)(0x10))
#define		INPUT_PULLUP			((u8)(0x11))

/* GPIO OUTPUT MODES */	
#define		OUTPUT_GP_PP_2MHZ		((u8)(0x2))
#define		OUTPUT_GP_PP_10MHZ		((u8)(0x1))
#define		OUTPUT_GP_PP_50MHZ		((u8)(0x3))

#define		OUTPUT_GP_OD_2MHZ		((u8)(0x6))
#define		OUTPUT_GP_OD_10MHZ		((u8)(0x5))
#define		OUTPUT_GP_OD_50MHZ		((u8)(0x7))

#define		OUTPUT_AF_PP_2MHZ		((u8)(0xA))
#define		OUTPUT_AF_PP_10MHZ		((u8)(0x9))
#define		OUTPUT_AF_PP_50MHZ		((u8)(0xB))

#define		OUTPUT_AF_OD_2MHZ		((u8)(0xE))
#define		OUTPUT_AF_OD_10MHZ		((u8)(0xD))
#define		OUTPUT_AF_OD_50MHZ		((u8)(0xF))

/* GPIO OUTPUT VALUES */	
#define		GPIO_PIN_LOW			((u8)(0x0))
#define		GPIO_PIN_HIGH			((u8)(0x1))

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void MGPIO_voidSetPinMode  (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8   MGPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin);
void MGPIO_voidTogglePin (u8 Copy_u8Port, u8 Copy_u8Pin);
void MGPIO_voidLockPin (u8 Copy_u8Port, u8 Copy_u8Pin);

#endif
//***************************************************************************************************************
