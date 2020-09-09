//
// GENG 421 - Gus Brigantino
//
// Colors module
//

#include "geng421.h"
#include "rgb.h"
#include "colors.h"

#define RED_UP 0
#define RED_DN 1
#define GRN_UP 2
#define GRN_DN 3
#define BLUE_UP 4
#define BLUE_DN 5
#define RG_UP 6
#define RG_DN 7
#define GB_UP 8
#define GB_DN 9
#define BR_UP 10
#define BR_DN 11
#define RGB_UP 12
#define RGB_DN 13

#define DELAY_100MS 100

#define PWM_MIN 0
#define PWM_MAX 10

void ColorsClock(void)
{
	static int ColorsState = RED_UP;
	static int Delay = DELAY_100MS;
	static int PwmSetting = PWM_MIN;

	switch(ColorsState)
	{
	case RED_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = RED_DN;
			}
			else
			{
				PwmSetting++;
				RgbRedPwmSet(PwmSetting);
			}
		}
		break;
	case RED_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = GRN_UP;
				RgbRedPwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbRedPwmSet(PwmSetting);
			}
		}
		break;
	case GRN_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = GRN_DN;
			}
			else
			{
				PwmSetting++;
				RgbGreenPwmSet(PwmSetting);
			}
		}
		break;
	case GRN_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = BLUE_UP;
				RgbGreenPwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbGreenPwmSet(PwmSetting);
			}
		}
		break;
	case BLUE_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = BLUE_DN;
			}
			else
			{
				PwmSetting++;
				RgbBluePwmSet(PwmSetting);
			}
		}
		break;
	case BLUE_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = RG_UP;
				RgbBluePwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbBluePwmSet(PwmSetting);
			}
		}
		break;
	case RG_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = RG_DN;
			}
			else
			{
				PwmSetting++;
				RgbRedPwmSet(PwmSetting);
				RgbGreenPwmSet(PwmSetting);
			}
		}
		break;
	case RG_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = GB_UP;
				RgbRedPwmSet(0);
				RgbGreenPwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbRedPwmSet(PwmSetting);
				RgbGreenPwmSet(PwmSetting);
			}
		}
		break;
	case GB_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = GB_DN;
			}
			else
			{
				PwmSetting++;
				RgbBluePwmSet(PwmSetting);
				RgbGreenPwmSet(PwmSetting);
			}
		}
		break;
	case GB_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = BR_UP;
				RgbBluePwmSet(0);
				RgbGreenPwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbBluePwmSet(PwmSetting);
				RgbGreenPwmSet(PwmSetting);
			}
		}
		break;
	case BR_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = BR_DN;
			}
			else
			{
				PwmSetting++;
				RgbRedPwmSet(PwmSetting);
				RgbBluePwmSet(PwmSetting);
			}
		}
		break;
	case BR_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = RGB_UP;
				RgbRedPwmSet(0);
				RgbBluePwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbRedPwmSet(PwmSetting);
				RgbBluePwmSet(PwmSetting);
			}
		}
		break;
	case RGB_UP:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MAX)
			{
				ColorsState = RGB_DN;
			}
			else
			{
				PwmSetting++;
				RgbRedPwmSet(PwmSetting);
				RgbGreenPwmSet(PwmSetting);
				RgbBluePwmSet(PwmSetting);
			}
		}
		break;
	case RGB_DN:
		if(--Delay == 0)
		{
			Delay = DELAY_100MS;
			if(PwmSetting == PWM_MIN)
			{
				ColorsState = RED_UP;
				RgbRedPwmSet(0);
				RgbBluePwmSet(0);
				RgbGreenPwmSet(0);
				PwmSetting = PWM_MIN;
			}
			else
			{
				PwmSetting--;
				RgbRedPwmSet(PwmSetting);
				RgbGreenPwmSet(PwmSetting);
				RgbBluePwmSet(PwmSetting);
			}
		}
		break;
	}
}
