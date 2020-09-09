//
// GENG 421 - Gus Brigantino
//
// RGB LED module
//

#include "geng421.h"
#include "rgb.h"


#define RED_ST_OFF		0
#define RED_ST_ON		1

#define RED_PWM_MIN		0
#define RED_PWM_MAX		10

#define GRN_ST_OFF		0
#define GRN_ST_ON		1

#define GRN_PWM_MIN		0
#define GRN_PWM_MAX		10

#define BLUE_ST_OFF		0
#define BLUE_ST_ON		1

#define BLUE_PWM_MIN	0
#define BLUE_PWM_MAX	10


static int	RedPwmSetting = 0;
static int 	GreenPwmSetting = 0;
static int	BluePwmSetting = 0;

void RgbClock(void)
{
	static int	RedState = RED_ST_OFF;
	static int	RedPwmCount = RED_PWM_MIN;

	static int GreenState = GRN_ST_OFF;
	static int GreenPwmCount = GRN_PWM_MIN;

	static int BlueState = BLUE_ST_OFF;
	static int BluePwmCount = BLUE_PWM_MIN;

	RedPwmCount++;
	switch(RedState)
	{
	case RED_ST_OFF:
		if (RedPwmCount == RED_PWM_MAX)
		{
			RedPwmCount = 0;
			if (RedPwmSetting != 0)
			{
				RGB_RED_ENA();
				RedState = RED_ST_ON;
				break;
			}
		}
		break;

	case RED_ST_ON:
		if (RedPwmCount >= RedPwmSetting)
		{
			if (RedPwmSetting == RED_PWM_MAX)
			{
				RedPwmCount = 0;
			}
			else
			{
				RGB_RED_DIS();
				RedState = RED_ST_OFF;
				break;
			}
		}
		break;
	}


	GreenPwmCount++;
	switch(GreenState)
	{
	case GRN_ST_OFF:
		if (GreenPwmCount == GRN_PWM_MAX)
		{
			GreenPwmCount = 0;
			if (GreenPwmSetting != 0)
			{
				RGB_GRN_ENA();
				GreenState = GRN_ST_ON;
				break;
			}
		}
		break;

	case GRN_ST_ON:
		if (GreenPwmCount >= GreenPwmSetting)
		{
			if (GreenPwmSetting == GRN_PWM_MAX)
			{
				GreenPwmCount = 0;
			}
			else
			{
				RGB_GRN_DIS();
				GreenState = GRN_ST_OFF;
				break;
			}
		}
		break;
	}


	BluePwmCount++;
	switch(BlueState)
	{
	case BLUE_ST_OFF:
		if (BluePwmCount == BLUE_PWM_MAX)
		{
			BluePwmCount = 0;
			if (BluePwmSetting != 0)
			{
				RGB_BLUE_ENA();
				BlueState = BLUE_ST_ON;
				break;
			}
		}
		break;

	case BLUE_ST_ON:
		if (BluePwmCount >= BluePwmSetting)
		{
			if (BluePwmSetting == BLUE_PWM_MAX)
			{
				BluePwmCount = 0;
			}
			else
			{
				RGB_BLUE_DIS();
				BlueState = BLUE_ST_OFF;
				break;
			}
		}
		break;
	}
}


void RgbRedPwmSet(int PwmSetting)
{
	if (PwmSetting < RED_PWM_MIN)
	{
		PwmSetting = RED_PWM_MIN;
	}
	if (PwmSetting > RED_PWM_MAX)
	{
		PwmSetting = RED_PWM_MAX;
	}
	RedPwmSetting = PwmSetting;
}

void RgbGreenPwmSet(int PwmSetting)
{
	if (PwmSetting < GRN_PWM_MIN)
	{
		PwmSetting = GRN_PWM_MIN;
	}
	if (PwmSetting > GRN_PWM_MAX)
	{
		PwmSetting = GRN_PWM_MAX;
	}
	GreenPwmSetting = PwmSetting;
}

void RgbBluePwmSet(int PwmSetting)
{
	if (PwmSetting < BLUE_PWM_MIN)
	{
		PwmSetting = BLUE_PWM_MIN;
	}
	if (PwmSetting > BLUE_PWM_MAX)
	{
		PwmSetting = BLUE_PWM_MAX;
	}
	BluePwmSetting = PwmSetting;
}


int RgbRedPwmGet(void)
{
	return RedPwmSetting;
}

int RgbGreenPwmGet(void)
{
	return GreenPwmSetting;
}

int RgbBluePwmGet(void)
{
	return BluePwmSetting;
}
