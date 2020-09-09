//
// GENG 421 - Gus Brigantino
//
// RR module
//

#include "geng421.h"
#include "game.h"
#include "rgb.h"
#include "nav.h"
#include "lcd.h"
#include "eprintf.h"
#include <stdlib.h>

#define ST_READY 0
#define ST_WAIT 1
#define ST_WATCH 2
#define ST_CORRECT 3
#define ST_INCORRECT 4

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define DELAY_END 3000
#define NO_DELAY 1

#define DEBOUNCE_TIME 50

void RocketReactions(void)
{
	static int GameState = ST_READY;
	static int Delay = 1, DelayWait = 0;

	static int DirectionState = 0;
	static int DirectionPrintState = 0;

	static Bool isSelectPressedCur = FALSE;
	static Bool isSelectPressedPrev = FALSE;
	static Bool isUpPressedCur = FALSE;
	static Bool isUpPressedPrev = FALSE;
	static Bool isDownPressedCur = FALSE;
	static Bool isDownPressedPrev = FALSE;
	static Bool isLeftPressedCur = FALSE;
	static Bool isLeftPressedPrev = FALSE;
	static Bool isRightPressedCur = FALSE;
	static Bool isRightPressedPrev = FALSE;

	static int timeCounter = 0;

	switch(GameState)
	{
	case ST_READY:
		if(--Delay == 0)
		{
			RGB_RED_DIS();
			RGB_GRN_DIS();
			RGB_BLUE_ENA();

			LcdPrintf(0, 0, "GENG421 Final Project");
			LcdPrintf(1, 0, "Rocket Reactions Game");
			LcdPrintf(2, 0, "                     ");
			LcdPrintf(3, 0, "Press SELECT to Start");
		}
		isSelectPressedCur = NavSelectIsPressed();
		if(isSelectPressedCur != isSelectPressedPrev)
		{
			GameState = ST_WAIT;
			Delay = NO_DELAY;
		}
		else
			isSelectPressedPrev = isSelectPressedCur;
		break;
	case ST_WAIT:
		if(--Delay == 0)
		{
			RGB_RED_ENA();
			RGB_GRN_ENA();
			RGB_BLUE_DIS();

			LcdPrintf(3, 0, "     Get Ready!!     ");
		}
		do
		{
			Delay = rand() & 0xFFF;
		}
		while(Delay > 4000);

		DelayWait = Delay;
		timeCounter = 0;
		GameState = ST_WATCH;
		break;
	case ST_WATCH:
		if(--Delay == 0)
		{
			RGB_RED_DIS();
			RGB_GRN_DIS();
			RGB_BLUE_DIS();

			DirectionState = rand() & 0x3;
			DirectionPrintState = DirectionState;


			switch(DirectionPrintState)
			{
			case UP:
				LcdPrintf(3, 0, "          U          ");
				break;
			case DOWN:
				LcdPrintf(3, 0, "          D          ");
				break;
			case LEFT:
				LcdPrintf(3, 0, "          L          ");
				break;
			case RIGHT:
				LcdPrintf(3, 0, "          R          ");
				break;
			}
		}
		timeCounter++;
		switch(DirectionState)
		{
		case UP:
			isUpPressedCur = NavUpIsPressed();
			if(isUpPressedCur != isUpPressedPrev)
				GameState = ST_CORRECT;
			else
				isUpPressedPrev = isUpPressedCur;

			isDownPressedCur = NavDownIsPressed();
			if(isDownPressedCur != isDownPressedPrev)
				GameState = ST_INCORRECT;
			else
				isDownPressedPrev = isDownPressedCur;

			isLeftPressedCur = NavLeftIsPressed();
			if(isLeftPressedCur != isLeftPressedPrev)
				GameState = ST_INCORRECT;
			else
				isLeftPressedPrev = isLeftPressedCur;

			isRightPressedCur = NavRightIsPressed();
			if(isRightPressedCur != isRightPressedPrev)
				GameState = ST_INCORRECT;
			else
				isRightPressedPrev = isRightPressedCur;
			break;
		case DOWN:
			isUpPressedCur = NavUpIsPressed();
			if(isUpPressedCur != isUpPressedPrev)
				GameState = ST_INCORRECT;
			else
				isUpPressedPrev = isUpPressedCur;

			isDownPressedCur = NavDownIsPressed();
			if(isDownPressedCur != isDownPressedPrev)
				GameState = ST_CORRECT;
			else
				isDownPressedPrev = isDownPressedCur;

			isLeftPressedCur = NavLeftIsPressed();
			if(isLeftPressedCur != isLeftPressedPrev)
				GameState = ST_INCORRECT;
			else
				isLeftPressedPrev = isLeftPressedCur;

			isRightPressedCur = NavRightIsPressed();
			if(isRightPressedCur != isRightPressedPrev)
				GameState = ST_INCORRECT;
			else
				isRightPressedPrev = isRightPressedCur;
			break;
		case LEFT:
			isUpPressedCur = NavUpIsPressed();
			if(isUpPressedCur != isUpPressedPrev)
				GameState = ST_INCORRECT;
			else
				isUpPressedPrev = isUpPressedCur;

			isDownPressedCur = NavDownIsPressed();
			if(isDownPressedCur != isDownPressedPrev)
				GameState = ST_INCORRECT;
			else
				isDownPressedPrev = isDownPressedCur;

			isLeftPressedCur = NavLeftIsPressed();
			if(isLeftPressedCur != isLeftPressedPrev)
				GameState = ST_CORRECT;
			else
				isLeftPressedPrev = isLeftPressedCur;

			isRightPressedCur = NavRightIsPressed();
			if(isRightPressedCur != isRightPressedPrev)
				GameState = ST_INCORRECT;
			else
				isRightPressedPrev = isRightPressedCur;
			break;
		case RIGHT:
			isUpPressedCur = NavUpIsPressed();
			if(isUpPressedCur != isUpPressedPrev)
				GameState = ST_INCORRECT;
			else
				isUpPressedPrev = isUpPressedCur;

			isDownPressedCur = NavDownIsPressed();
			if(isDownPressedCur != isDownPressedPrev)
				GameState = ST_INCORRECT;
			else
				isDownPressedPrev = isDownPressedCur;

			isLeftPressedCur = NavLeftIsPressed();
			if(isLeftPressedCur != isLeftPressedPrev)
				GameState = ST_INCORRECT;
			else
				isLeftPressedPrev = isLeftPressedCur;

			isRightPressedCur = NavRightIsPressed();
			if(isRightPressedCur != isRightPressedPrev)
				GameState = ST_CORRECT;
			else
				isRightPressedPrev = isRightPressedCur;
			break;
		}
		break;
	case ST_CORRECT:
		RGB_RED_DIS();
		RGB_GRN_ENA();
		RGB_BLUE_DIS();
		LcdPrintf(2, 0, "      Congrats!      ");
		LcdPrintf(3, 0, "Time: %d msecs", timeCounter - (DEBOUNCE_TIME + DelayWait));
		Delay = DELAY_END;
		GameState = ST_READY;
		break;
	case ST_INCORRECT:
		RGB_RED_ENA();
		RGB_GRN_DIS();
		RGB_BLUE_DIS();
		LcdPrintf(2, 0, "     too bad! :(     ");;
		LcdPrintf(3, 0, "Time: %d msecs", timeCounter - (DEBOUNCE_TIME + DelayWait));
		Delay = DELAY_END;
		GameState = ST_READY;
		break;
	}
}
