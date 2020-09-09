//
// GENG 421 - Gus Brigantino
//
// RGB LED module header file
//

#ifndef RGB_H_
#define RGB_H_

#include "gpio.h"


#define RGB_RED_ENA()	(GPIO_PB4_CLR())
#define RGB_RED_DIS()	(GPIO_PB4_SET())
#define RGB_RED_TOG()	(GPIO_PB4_TOG())

#define RGB_GRN_ENA()	(GPIO_PC7_CLR())
#define RGB_GRN_DIS()	(GPIO_PC7_SET())
#define RGB_GRN_TOG()	(GPIO_PC7_TOG())

#define RGB_BLUE_ENA()	(GPIO_PA9_CLR())
#define RGB_BLUE_DIS()	(GPIO_PA9_SET())
#define RGB_BLUE_TOG()	(GPIO_PA9_TOG())


void	RgbClock(void);
void	RgbRedPwmSet(int PwmSetting);
int		RgbRedPwmGet(void);
void 	RgbGreenPwmSet(int PwmSetting);
int 	RgbGreenPwmGet(void);

#endif	// RGB_H_
