/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 30 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#ifndef SNAKEGAME_PRIVATE_H
#define SNAKEGAME_PRIVATE_H

/*
*********************************************************************************************************
*                                        			MACROS
*********************************************************************************************************
*/
/* X-COORDINATE OFFSETS	*/
#define X_WELCOME_MESSAGE_1			(5U)
#define X_WELCOME_MESSAGE_2			(20U)

#define X_POINTSTITLE_START			(1U)
#define X_POINTS_START_1			(43U)
#define X_POINTS_START_2			(49U)

#define X_LEVELSTITLE_START			(78U)
#define X_LEVELS_START				(115U)

#define X_MESSAGE_BOX_START			(12U)
#define X_MESSAGE_BOX_END			(115U)

#define X_MESSAGE_START_1			(18U)
#define X_MESSAGE_START_2			(30U)
#define X_MESSAGE_START_3			(28U)

#define X_PAUSEGAME_BOX_START		(16U)
#define X_PAUSEGAME_BOX_END			(114U)

#define X_PAUSEGAME_START			(20U)

#define X_GAME_OVER_1				(8U)
#define X_GAME_OVER_2				(8U)

#define X_SNAKE_STARTPOSITION		(55U)

#define X_FRUIT_LOWERRANGE			(6U)
#define X_FRUIT_UPPERRANGE			(120U)

/* Y-COORDINATE OFFSETS	*/
#define Y_WELCOME_MESSAGE_1			(30U)
#define Y_WELCOME_MESSAGE_2			(70U)

#define Y_POINTSTITLE_START			(1U)
#define Y_POINTS_START				(1U)

#define Y_LEVELSTITLE_START			(1U)
#define Y_LEVELS_START		    	(1U)

#define Y_MESSAGE_BOX_START			(40U)
#define Y_MESSAGE_BOX_END			(105U)

#define Y_MESSAGE_START_1			(43U)
#define Y_MESSAGE_START_2			(63U)
#define Y_MESSAGE_START_3			(87U)

#define Y_PAUSEGAME_BOX_START		(46U)
#define Y_PAUSEGAME_BOX_END			(90U)

#define Y_PAUSEGAME_START_1			(50U)
#define Y_PAUSEGAME_START_2			(65U)
#define Y_PAUSEGAME_START_3			(80U)

#define Y_GAME_OVER_1				(40U)
#define Y_GAME_OVER_2				(80U)

#define Y_SNAKE_STARTPOSITION		(55U)

#define Y_FRUIT_LOWERRANGE			(16U)
#define Y_FRUIT_UPPERRANGE			(152U)

/* EYES POSITIONS	*/
#define EYE_POSITION_1				(1U)
#define EYE_POSITION_2				(2U)
#define EYE_POSITION_3				(4U)
#define EYE_POSITION_4				(5U)


/* DISPLAY EDGES	*/
#define DISPLAY_X1					(0U)
#define DISPLAY_X2					(127U)
#define DISPLAY_Y1					(0U)
#define DISPLAY_Y2					(159U)

/* BORDERS	*/
#define BORDER_Y					(11U)

/* FIELD EDGES	*/
#define FIELD_X1					(2U)
#define FIELD_X2					(125U)
#define FIELD_Y1					(13U)
#define FIELD_Y2					(157U)

/* GRID	*/
#define GRID_X1						(32U)
#define GRID_X2						(63U)
#define GRID_X3						(94U)
#define GRID_Y1						(61U)
#define GRID_Y2						(109U)

/* FONT SIZES	*/
#define FONTSIZE_WELCOME_MESSAGE	(4U)
#define FONTSIZE_POINTS				(1U)
#define FONTSIZE_LEVELS				(1U)
#define FONTSIZE_MESSAGEBOX			(2U)
#define FONTSIZE_GAME_OVER			(4U)
#define FONTSIZE_PAUSEGAME			(1U)

/* FRUIT SIZE	*/
#define FRUIT_SIZE					(3U)

/* MAXIMUM SNAKE LENGTH	*/
#define SNAKE_SIZE					(6U)
#define SNAKE_MAXIMUM_LENGTH		(99U)

/* LEVEL UP POINTS	*/
#define LEVELUP_POINTS				(10U)

/* ANIMATION DELAYS	*/
#define DELAY_WELCOME_MESSAGE		(2000UL)
#define DELAY_TIMEOUT				(65000UL)
#define DELAY_SPEED_LEVEL0			(1000UL)
#define DELAY_SPEED_LEVELUP			(150UL)
#define DELAY_END_GAME				(1200UL)
#define DELAY_GAME_OVER				(3000UL)

/*
*********************************************************************************************************
*                                        		TYPE DEFINITIONS
*********************************************************************************************************
*/
/* DIRECTIONS */
typedef enum DIRECTIONSTYPE
{
	RIGHT	= 0,
	LEFT	= 1,
	UP		= 2,
	DOWN	= 3
} DIRECTIONSTYPE;


/* Snake Type */
typedef struct
{
	u8     		   	X_Position;
	u8     		   	Y_Position;
	//SNAKE_BODYPART 	BodyPart;
	DIRECTIONSTYPE	Direction;
} SNAKE_TYPE;

/*
*********************************************************************************************************
*                                        		GLOBAL VARIABLES
*********************************************************************************************************
*/
volatile SNAKE_TYPE		 Snake[SNAKE_MAXIMUM_LENGTH];
volatile u8 			 Global_u8XPOS_Fruit = 120;
volatile u8 			 Global_u8YPOS_Fruit = 150;
volatile u8  			 Global_u8SnakeLength;
volatile u8  			 Global_u8Points;
volatile u8  			 Global_u8Level;
volatile u8  			 Global_u8Status;

/*
*********************************************************************************************************
*                                        PRIVATE FUNCTIONS' PROTOTYPES
*********************************************************************************************************
*/
static void InitSystem			  (void);
static void DisplayWelcomeMessage (void);
static void DrawTheField		  (void);
static void DrawTheBorders 		  (void);
static void DrawTheGrid 		  (void);
static void DisplayPromptMessage  (void);
static void StartNewGame 	   	  (void);
static void UpdatePointsAndLevel  (void);
static void UpdateTheGameSpeed 	  (u8 Copy_u8GameLevel);
static void DrawTheFruit 		  (void);
static void PlaceTheFruit 		  (void);
static u32  RandomNumberGenerator (u16 Copy_u16RandomValue);
static void EraseOldSnake 		  (void);
static void DrawTheSnake 		  (void);
static void MoveTheSnake		  (void);
static u8   CheckButtons		  (void);
static void PauseTheGame 		  (void);
static void MoveTheHead 		  (u8 Copy_u8PressedButton);
static u8   CheckTheFruit		  (void);
static u8   CheckForHit			  (void);
static u8   CheckHitItself 		  (void);
static u8   CheckHitBorder 		  (void);
static void UpdateTheBody 		  (void);
static void EndTheGame	   	      (void);
static void DisplayGameOver		  (void);

#endif
//***************************************************************************************************************
