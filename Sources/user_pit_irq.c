/*
 * user_pit0_irq.c
 *
 *  Created on: 2016Äê5ÔÂ26ÈÕ
 *      Author: yangs
 */

#include "fsl_pit_driver.h"

void PIT0_IRQHandler(void)
{
	PIT_DRV_ClearIntFlag(0,0);
	//GPIO_DRV_TogglePinOutput(kGpioLED1);
}
