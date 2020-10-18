/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 29 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "SCB_interface.h"
#include "Timer2_5_interface.h"

#include "IR_NEC_interface.h"
#include "TFT_interface.h"

#include "SnakeGame_interface.h"
#include "SnakeGame_config.h"
#include "SnakeGame_private.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void StartSnakeGame(void)
{
	InitSystem();			 /*Initialize the Application*/
	DisplayWelcomeMessage(); /*Welcome Message*/

	while(1)
	{
		DrawTheField();		 /*Draw the Game Field*/
		StartNewGame();	 	 /*Wait until the User Presses ok, then start the Game,It never exits unless the User hit something */
		EndTheGame();		 /*Display Game Over*/
	}
}
/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' DEFINITIONS
*********************************************************************************************************
*/
static void InitSystem(void)
{
	/*INITALIZE TFT DISPLAY*/
	HTFT_voidInit ();

	/*INITALIZE IR-NEC REMOTE CONTROLLER*/
	HIR_NEC_voidInit();

	//INITALIZE TIMER3
	MTimer3_voidInit ();

	/*SET INTERRUPT PRIORITY GROUPING*/
	MSCB_voidSet_SWInterruptPriorityGrouping (SCB_SW_PRI_GP4_SP4);

	/*SET INTERRUPT PRIORITY FOR EACH PERIPHERAL*/
	MNVIC_voidSetInterruptPriority (NVIC_IRQ_EXTI15_10, NVIC_PRI_GP_0, NVIC_PRI_SP_0);
	MNVIC_voidSetInterruptPriority (NVIC_IRQ_TIM3     , NVIC_PRI_GP_1, NVIC_PRI_SP_0);

	/*	ENABLE INTERRUPTS FOR TIMER_3	*/
	MNVIC_voidEnableInterrupt (NVIC_IRQ_TIM3);
}
//***************************************************************************************************************
static void DisplayWelcomeMessage (void)
{
	/*Background*/
	HTFT_voidFillColour (TFT_COLOR_ORANGE);

	/*Welcome Message*/
	HTFT_voidDrawString ((u8*)"Snake", X_WELCOME_MESSAGE_1	, Y_WELCOME_MESSAGE_1 ,
									   TFT_COLOR_GREEN	 	, TFT_COLOR_ORANGE    , FONTSIZE_WELCOME_MESSAGE);

	HTFT_voidDrawString ((u8*)"Game"  , X_WELCOME_MESSAGE_2	, Y_WELCOME_MESSAGE_2 ,
										TFT_COLOR_GREEN		, TFT_COLOR_ORANGE    , FONTSIZE_WELCOME_MESSAGE);

	/*Welcome Message*/
	MTimer3_voidSetBusyWait (DELAY_WELCOME_MESSAGE);
}
//***************************************************************************************************************
static void DrawTheField	(void)
{
	/*Background*/
	HTFT_voidFillColour (TFT_COLOR_BLACK);

	/*Points and Levels Titles*/
	HTFT_voidDrawString ((u8*)"Points:", X_POINTSTITLE_START , Y_POINTSTITLE_START  ,
										 TFT_COLOR_WHITE	 , TFT_COLOR_BLACK 		, FONTSIZE_POINTS);


	HTFT_voidDrawString ((u8*)"Level:", X_LEVELSTITLE_START	, Y_LEVELSTITLE_START  ,
										TFT_COLOR_WHITE		, TFT_COLOR_BLACK 	   , FONTSIZE_LEVELS);


	/*Field Background*/
	HTFT_voidDrawRectangle (FIELD_X1, FIELD_X2, FIELD_Y1, FIELD_Y2, TFT_COLOR_LIGHTBROWN);

	/*Field Borders*/
	DrawTheBorders();
}
//***************************************************************************************************************
static void DrawTheBorders (void)
{
	HTFT_voidDrawRectangle (DISPLAY_X1  , DISPLAY_X2, BORDER_Y , FIELD_Y1  , TFT_COLOR_BROWN);
	HTFT_voidDrawRectangle (FIELD_X2	, DISPLAY_X2, BORDER_Y , DISPLAY_Y2, TFT_COLOR_BROWN);
	HTFT_voidDrawRectangle (DISPLAY_X1  , DISPLAY_X2, FIELD_Y2 , DISPLAY_Y2, TFT_COLOR_BROWN);
	HTFT_voidDrawRectangle (DISPLAY_X1  , FIELD_X1  , BORDER_Y , DISPLAY_Y2, TFT_COLOR_BROWN);
}
//***************************************************************************************************************
static void DrawTheGrid (void)
{
	/*Draw Vertical Lines*/
	HTFT_voidDrawVLine	(GRID_X1, BORDER_Y, FIELD_Y2,TFT_COLOR_BROWN);
	HTFT_voidDrawVLine	(GRID_X2, BORDER_Y, FIELD_Y2,TFT_COLOR_BROWN);
	HTFT_voidDrawVLine	(GRID_X3, BORDER_Y, FIELD_Y2,TFT_COLOR_BROWN);

	/*Draw Horizontal Lines*/
	HTFT_voidDrawHLine	(FIELD_X1, FIELD_X2, GRID_Y1, TFT_COLOR_BROWN);
	HTFT_voidDrawHLine	(FIELD_X1, FIELD_X2, GRID_Y2, TFT_COLOR_BROWN);
}
//***************************************************************************************************************
static void DisplayPromptMessage (void)
{
	HTFT_voidDrawRectangle (X_MESSAGE_BOX_START, X_MESSAGE_BOX_END, Y_MESSAGE_BOX_START, Y_MESSAGE_BOX_END, TFT_COLOR_ORANGE);


	HTFT_voidDrawString ((u8*)"Press OK", X_MESSAGE_START_1 , Y_MESSAGE_START_1  ,
										  TFT_COLOR_GREEN	, TFT_COLOR_ORANGE   , FONTSIZE_MESSAGEBOX);


	HTFT_voidDrawString ((u8*)"When", X_MESSAGE_START_2	, Y_MESSAGE_START_2  ,
									  TFT_COLOR_GREEN	, TFT_COLOR_ORANGE 	 , FONTSIZE_MESSAGEBOX);


	HTFT_voidDrawString ((u8*)"Ready!", X_MESSAGE_START_3	, Y_MESSAGE_START_3  ,
										TFT_COLOR_GREEN		, TFT_COLOR_ORANGE 	 , FONTSIZE_MESSAGEBOX);
}
//***************************************************************************************************************
static void StartNewGame (void)
{
	/*Set the Snake in Initial Position*/
	Snake[0].Direction  = RIGHT;
	Snake[0].X_Position = X_SNAKE_STARTPOSITION;
	Snake[0].Y_Position = Y_SNAKE_STARTPOSITION;

	Snake[1].X_Position = X_SNAKE_STARTPOSITION - SNAKE_SIZE;
	Snake[1].Y_Position = Y_SNAKE_STARTPOSITION;

	Snake[2].X_Position = X_SNAKE_STARTPOSITION - (2*SNAKE_SIZE);
	Snake[2].Y_Position = Y_SNAKE_STARTPOSITION;

	/*Set Snake Length, Points, Level, and Status*/
	Global_u8SnakeLength  =  3;
	Global_u8Points 	  = -1;
	Global_u8Level 	   	  =  0;
	Global_u8Status 	  =  1;


	/*Prompt the User to Press the Button OK when Ready*/
	DisplayPromptMessage();

	/*Re-send the Message after 65 seconds*/
	MTimer3_voidSetIntervalPeriodic (DELAY_TIMEOUT, DisplayPromptMessage);

	/*Wait until the Button OK is pressed*/
	while(HIR_NEC_u8ReadReceivedFrame() != IR_NEC_BUTTON_OK_PRESSED);

	/*Erase the Message Box*/
	HTFT_voidDrawRectangle (X_MESSAGE_BOX_START, X_MESSAGE_BOX_END, Y_MESSAGE_BOX_START, Y_MESSAGE_BOX_END, TFT_COLOR_LIGHTBROWN);

	UpdatePointsAndLevel();

	/*Draw the Grid, the Snake, and the Fruit*/
	DrawTheGrid  ();
	DrawTheSnake ();
	PlaceTheFruit();

	/*Remain here as long as the Snake is alive*/
	while(Global_u8Status);
}
//***************************************************************************************************************
static void UpdatePointsAndLevel (void)
{
	/*Update the Points*/
	Global_u8Points++ ;

	/*Display the Points*/
	if(Global_u8Points/10)
	{
		HTFT_voidDrawNumber	(Global_u8Points/10, X_POINTS_START_1, Y_POINTS_START, TFT_COLOR_WHITE, TFT_COLOR_BLACK, FONTSIZE_POINTS);
		HTFT_voidDrawNumber	(Global_u8Points%10, X_POINTS_START_2, Y_POINTS_START, TFT_COLOR_WHITE, TFT_COLOR_BLACK, FONTSIZE_POINTS);
	}
	else
	{
		HTFT_voidDrawNumber	( 	0	 		   , X_POINTS_START_1, Y_POINTS_START, TFT_COLOR_WHITE, TFT_COLOR_BLACK, FONTSIZE_POINTS);
		HTFT_voidDrawNumber	(Global_u8Points   , X_POINTS_START_2, Y_POINTS_START, TFT_COLOR_WHITE, TFT_COLOR_BLACK, FONTSIZE_POINTS);
	}

	if(!(Global_u8Points%LEVELUP_POINTS))
	{
		/*Update the Level*/
		Global_u8Level++;

		/*Update the Game Speed*/
		UpdateTheGameSpeed (Global_u8Level);

		HTFT_voidDrawNumber	(Global_u8Level, X_LEVELS_START, Y_LEVELS_START, TFT_COLOR_WHITE, TFT_COLOR_BLACK, FONTSIZE_LEVELS);
	}
}
//***************************************************************************************************************
static void UpdateTheGameSpeed (u8 Copy_u8GameLevel)
{
	MTimer3_voidSetIntervalPeriodic ( ((DELAY_SPEED_LEVEL0)-(DELAY_SPEED_LEVELUP*Copy_u8GameLevel)) , MoveTheSnake);
}
//***************************************************************************************************************
static void DrawTheFruit (void)
{
	HTFT_voidDrawRectangle (Global_u8XPOS_Fruit, Global_u8XPOS_Fruit+FRUIT_SIZE,
							Global_u8YPOS_Fruit, Global_u8YPOS_Fruit+FRUIT_SIZE, TFT_COLOR_RED);
}
//***************************************************************************************************************
static void PlaceTheFruit (void)
{
	/*Erase the old Fruit*/
	HTFT_voidDrawRectangle (Global_u8XPOS_Fruit, Global_u8XPOS_Fruit+FRUIT_SIZE,
							Global_u8YPOS_Fruit, Global_u8YPOS_Fruit+FRUIT_SIZE, TFT_COLOR_LIGHTBROWN);

	/*Use the Values in Timer_3 Registers to get initial Random Number*/
	Global_u8XPOS_Fruit = (RandomNumberGenerator( MTimer3_u16GetRemainingTime() ) % (X_FRUIT_UPPERRANGE-X_FRUIT_LOWERRANGE))
								+ (X_FRUIT_LOWERRANGE);

	Global_u8YPOS_Fruit = (RandomNumberGenerator( MTimer3_u16GetRemainingTime() ) % (Y_FRUIT_UPPERRANGE-Y_FRUIT_LOWERRANGE))
								+ (Y_FRUIT_LOWERRANGE);

	/*Draw the Fruit in the Randomly chosen Spot*/
	DrawTheFruit();
}
//***************************************************************************************************************
static u32 RandomNumberGenerator (u16 Copy_u16RandomValue)
{
	static volatile u32 b, z1, z2, z3, z4;

	/*Start with the given initial Random Number*/
	z1 ^= Copy_u16RandomValue;
	z2 ^= Copy_u16RandomValue;
	z3 ^= Copy_u16RandomValue;
	z4 ^= Copy_u16RandomValue;

	/*Generate the Random Number*/
	b  = ((z1 << 6) ^ z1) >> 13;
	z1 = ((z1 & 4294967294U) << 18) ^ b;
	b  = ((z2 << 2) ^ z2) >> 27;
	z2 = ((z2 & 4294967288U) << 2) ^ b;
	b  = ((z3 << 13) ^ z3) >> 21;
	z3 = ((z3 & 4294967280U) << 7) ^ b;
	b  = ((z4 << 3) ^ z4) >> 12;
	z4 = ((z4 & 4294967168U) << 13) ^ b;

	return (z1 ^ z2 ^ z3 ^ z4);
}
//***************************************************************************************************************
static void EraseOldSnake (void)
{
	//Erase the Last Part of the Snake
	HTFT_voidDrawRectangle  (Snake[Global_u8SnakeLength-1].X_Position , (Snake[Global_u8SnakeLength-1].X_Position)+6,
							(Snake[Global_u8SnakeLength-1].Y_Position), (Snake[Global_u8SnakeLength-1].Y_Position)+6, TFT_COLOR_LIGHTBROWN);

}
//***************************************************************************************************************
static void DrawTheSnake (void)
{
	/*Draw the Head*/
	HTFT_voidDrawRectangle  (Snake[0].X_Position , (Snake[0].X_Position)+SNAKE_SIZE,
							(Snake[0].Y_Position), (Snake[0].Y_Position)+SNAKE_SIZE, TFT_COLOR_DARKGREEN);

	/*Draw the Eyes*/
	switch(Snake[0].Direction)
	{
		case RIGHT:
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_4, Snake[0].Y_Position +EYE_POSITION_2, TFT_COLOR_WHITE);
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_4, Snake[0].Y_Position +EYE_POSITION_3, TFT_COLOR_WHITE);
			break;

		case LEFT:
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_1, Snake[0].Y_Position +EYE_POSITION_2, TFT_COLOR_WHITE);
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_1, Snake[0].Y_Position +EYE_POSITION_3, TFT_COLOR_WHITE);
			break;

		case UP:
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_2, Snake[0].Y_Position +EYE_POSITION_1, TFT_COLOR_WHITE);
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_3, Snake[0].Y_Position +EYE_POSITION_1, TFT_COLOR_WHITE);
			break;

		case DOWN:
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_2, Snake[0].Y_Position +EYE_POSITION_4, TFT_COLOR_WHITE);
			HTFT_voidDrawPixel     (Snake[0].X_Position +EYE_POSITION_3, Snake[0].Y_Position +EYE_POSITION_4, TFT_COLOR_WHITE);
			break;
	}


	/*Draw the Body*/
	for(u8 i=1; i<Global_u8SnakeLength-1; i++)
	{
		HTFT_voidDrawRectangle  (Snake[i].X_Position , (Snake[i].X_Position)+SNAKE_SIZE,
								(Snake[i].Y_Position), (Snake[i].Y_Position)+SNAKE_SIZE, TFT_COLOR_GREEN);
	}
}
//***************************************************************************************************************
static void MoveTheSnake (void)
{
	static volatile u8 Local_u8Button;

	/*Check if the User hit any Arrow or hit Pause*/
	Local_u8Button = CheckButtons();

	if(Local_u8Button)
	{
		if(Local_u8Button == IR_NEC_BUTTON_OK_PRESSED)
		{
			PauseTheGame();		//This Function will not exit until the User Press Continue
		}
		else
		{
			MoveTheHead(Local_u8Button);
		}
	}


	/*Set the Direction for Each Body Part*/
	for(u8 i=Global_u8SnakeLength-1; i>0; i--)
	{
		Snake[i].X_Position  = Snake[i-1].X_Position;
		Snake[i].Y_Position  = Snake[i-1].Y_Position;
		Snake[i].Direction   = Snake[i-1].Direction;
	}

	/*Update the Head Position*/
	switch(Snake[0].Direction)
	{
		case RIGHT:
			Snake[0].X_Position += SNAKE_SIZE;
			break;

		case LEFT:
			Snake[0].X_Position -= SNAKE_SIZE;
			break;

		case UP:
			Snake[0].Y_Position -= SNAKE_SIZE;
			break;

		case DOWN:
			Snake[0].Y_Position += SNAKE_SIZE;
			break;
	}

	/*Check if the Snake Hit the Border or Itself*/
	if( CheckForHit() )
	{
		/*Indicate a Snake Hit*/
		Global_u8Status = 0;

		/*Show the Snake hit*/
		DrawTheSnake();
		return;
	}

	/*Check if the Snake ate the Fruit*/
	if( CheckTheFruit() )
	{
		UpdateTheBody();
		UpdatePointsAndLevel();
		DrawTheBorders();
		PlaceTheFruit();
	}

	/*Redraw the Grid, the Snake, and the Fruit*/
	EraseOldSnake();
	DrawTheGrid  ();
	DrawTheFruit ();
	DrawTheSnake ();
}
//***************************************************************************************************************
static u8 CheckButtons (void)
{
	return (HIR_NEC_u8ReadReceivedFrame());
}
//***************************************************************************************************************
static void PauseTheGame (void)
{
	/*Stop the Timer, So as not to call Move Snake Temporarily*/
	MTimer3_voidStopTimer ();

	//Ask User to press OK to continue
	HTFT_voidDrawRectangle (X_PAUSEGAME_BOX_START, X_PAUSEGAME_BOX_END,
							Y_PAUSEGAME_BOX_START, Y_PAUSEGAME_BOX_END, TFT_COLOR_ORANGE);


	HTFT_voidDrawString ((u8*)"Game Paused ..", X_PAUSEGAME_START, Y_PAUSEGAME_START_1,
											    TFT_COLOR_GREEN  , TFT_COLOR_ORANGE   , FONTSIZE_PAUSEGAME);


	HTFT_voidDrawString ((u8*)"  Press OK    ", X_PAUSEGAME_START, Y_PAUSEGAME_START_2,
										  	  	TFT_COLOR_GREEN	 , TFT_COLOR_ORANGE   , FONTSIZE_PAUSEGAME);


	HTFT_voidDrawString ((u8*)" to Continue: ", X_PAUSEGAME_START, Y_PAUSEGAME_START_3,
												TFT_COLOR_GREEN	 , TFT_COLOR_ORANGE   , FONTSIZE_PAUSEGAME);


	/*Wait until the Button OK is pressed*/
	while(HIR_NEC_u8ReadReceivedFrame() != IR_NEC_BUTTON_OK_PRESSED);

	/*Remove the Message Box*/
	HTFT_voidDrawRectangle (X_PAUSEGAME_BOX_START, X_PAUSEGAME_BOX_END,
							Y_PAUSEGAME_BOX_START, Y_PAUSEGAME_BOX_END, TFT_COLOR_LIGHTBROWN);


	/*Redraw the Grid, the Snake, and the Fruit*/
	DrawTheGrid ();
	DrawTheFruit();
	DrawTheSnake();

	/*Start Calling Move Snake again*/
	UpdateTheGameSpeed (Global_u8Level);
}
//***************************************************************************************************************
static void MoveTheHead (u8 Copy_u8PressedButton)
{
	switch(Snake[0].Direction)
	{
		case RIGHT:
		case LEFT:
			if(Copy_u8PressedButton == IR_NEC_BUTTON_UP_PRESSED)
			{
				Snake[0].Direction = UP;
			}
			else if(Copy_u8PressedButton == IR_NEC_BUTTON_DOWN_PRESSED)
			{
				Snake[0].Direction = DOWN;
			}
			break;

		case UP:
		case DOWN:
			if(Copy_u8PressedButton == IR_NEC_BUTTON_RIGHT_PRESSED)
			{
				Snake[0].Direction = RIGHT;
			}
			else if(Copy_u8PressedButton == IR_NEC_BUTTON_LEFT_PRESSED)
			{
				Snake[0].Direction = LEFT;
			}
			break;
	}
}
//***************************************************************************************************************
static u8 CheckTheFruit (void)
{
	/*Declare a Flag to find out if the Snake ate the Fruit*/
	volatile u8 Local_u8AteTheFruit_Flag = 0;

	if( (u8)((Snake[0].X_Position)-(Global_u8XPOS_Fruit)) <= (FRUIT_SIZE) )
	{
		if( (u8)((Snake[0].Y_Position)-(Global_u8YPOS_Fruit)) <= (FRUIT_SIZE) )
		{
			Local_u8AteTheFruit_Flag = 1;
		}
		else if( (u8)((Global_u8YPOS_Fruit)-(Snake[0].Y_Position)) <= (SNAKE_SIZE) )
		{
			Local_u8AteTheFruit_Flag = 1;
		}
	}
	else if( (u8)((Global_u8XPOS_Fruit)-(Snake[0].X_Position)) <= (SNAKE_SIZE) )
	{
		if( (u8)((Snake[0].Y_Position)-(Global_u8YPOS_Fruit)) <= (FRUIT_SIZE) )
		{
			Local_u8AteTheFruit_Flag = 1;
		}
		else if( (u8)((Global_u8YPOS_Fruit)-(Snake[0].Y_Position)) <= (SNAKE_SIZE) )
		{
			Local_u8AteTheFruit_Flag = 1;
		}
	}

	return (Local_u8AteTheFruit_Flag);
}
//***************************************************************************************************************
static u8 CheckForHit (void)
{
	/*Declare a Flag to find out if the Snake hit a Border*/
	volatile u8 Local_u8Hit_Flag = 0;

	if( CheckHitItself() )
	{
		Local_u8Hit_Flag = 1;
	}
	else if( CheckHitBorder() )
	{
		Local_u8Hit_Flag = 1;
	}

	return (Local_u8Hit_Flag);
}
//***************************************************************************************************************
static u8 CheckHitItself (void)
{
	/*Declare a Flag to find out if the Snake hit itself*/
	volatile u8 Local_u8Hit_Flag = 0;

	for(u8 i=4; i<Global_u8SnakeLength-1; i++)
	{
		if( (u8)((Snake[0].X_Position)-(Snake[i].X_Position)) < (SNAKE_SIZE) )
		{
			if( (u8)((Snake[0].Y_Position)-(Snake[i].Y_Position)) < (SNAKE_SIZE) )
			{
				Local_u8Hit_Flag = 1;
				break;
			}
			else if( (u8)((Snake[i].Y_Position)-(Snake[0].Y_Position)) < (SNAKE_SIZE) )
			{
				Local_u8Hit_Flag = 1;
				break;
			}
		}
		else if( (u8)((Snake[i].X_Position)-(Snake[0].X_Position)) < (SNAKE_SIZE) )
		{
			if( (u8)((Snake[0].Y_Position)-(Snake[i].Y_Position)) < (SNAKE_SIZE) )
			{
				Local_u8Hit_Flag = 1;
				break;
			}
			else if( (u8)((Snake[i].Y_Position)-(Snake[0].Y_Position)) < (SNAKE_SIZE) )
			{
				Local_u8Hit_Flag = 1;
				break;
			}
		}
	}

	return (Local_u8Hit_Flag);
}
//***************************************************************************************************************
static u8 CheckHitBorder (void)
{
	/*Declare a Flag to find out if the Snake hit a Border*/
	volatile u8 Local_u8Hit_Flag = 0;

	if( (Snake[0].X_Position) <= (FIELD_X1) )
	{
		Local_u8Hit_Flag = 1;
	}
	else if( (Snake[0].X_Position)+(SNAKE_SIZE) >= (FIELD_X2) )
	{
		Local_u8Hit_Flag = 1;
	}
	else if( (Snake[0].Y_Position) <= (FIELD_Y1) )
	{
			Local_u8Hit_Flag = 1;
	}else if( (Snake[0].Y_Position)+(SNAKE_SIZE)  >= (FIELD_Y2) )
	{
		Local_u8Hit_Flag = 1;
	}

	return (Local_u8Hit_Flag);
}
//***************************************************************************************************************
static void UpdateTheBody (void)
{
	/*Copy the last Body part*/
	Snake[Global_u8SnakeLength] = Snake[Global_u8SnakeLength-1];

	/*Update the Tail Position*/
	switch(Snake[Global_u8SnakeLength-1].Direction)
	{
		case RIGHT:
			Snake[Global_u8SnakeLength].X_Position = (Snake[Global_u8SnakeLength-1].X_Position) - SNAKE_SIZE;
			break;

		case LEFT:
			Snake[Global_u8SnakeLength].X_Position = (Snake[Global_u8SnakeLength-1].X_Position) + SNAKE_SIZE;
			break;

		case UP:
			Snake[Global_u8SnakeLength].Y_Position = (Snake[Global_u8SnakeLength-1].Y_Position) + SNAKE_SIZE;
			break;

		case DOWN:
			Snake[Global_u8SnakeLength].Y_Position = (Snake[Global_u8SnakeLength-1].Y_Position) - SNAKE_SIZE;
			break;
	}

	/*Update the Snake Length*/
	Global_u8SnakeLength++;
}
//***************************************************************************************************************
static void EndTheGame (void)
{
	/*Stop the Timer, So as not to call Move Snake again*/
	MTimer3_voidStopTimer ();

	/*Wait for 1Sec to show the Snake hit, before Moving On*/
	MTimer3_voidSetBusyWait (DELAY_END_GAME);

	//Display Game Over
	DisplayGameOver();
}
//***************************************************************************************************************
static void DisplayGameOver (void)
{
	/*Background*/
	HTFT_voidFillColour (TFT_COLOR_BLACK);

	/*Welcome Message*/
	HTFT_voidDrawString ((u8*)"GAME"  , X_GAME_OVER_1	 , Y_WELCOME_MESSAGE_1 ,
									    TFT_COLOR_RED	 , TFT_COLOR_BLACK     , FONTSIZE_GAME_OVER);

	HTFT_voidDrawString ((u8*)"OVER!" , X_GAME_OVER_2	, Y_WELCOME_MESSAGE_2 ,
										TFT_COLOR_RED	, TFT_COLOR_BLACK     , FONTSIZE_GAME_OVER);

	/*Welcome Message*/
	MTimer3_voidSetBusyWait (DELAY_GAME_OVER);
}
//***************************************************************************************************************
