/*
 * Hardware_init.c
 *
 *  Created on: 2016Äê5ÔÂ17ÈÕ
 *      Author: yangs
 */


#include "pin_mux.h"
#include "board.h"
#include "gpio_pins.h"
#include "fsl_gpio_driver.h"
#include "fsl_pit_driver.h"
#include "fsl_i2c_master_driver.h"
#include "fsl_ftm_driver.h"
#include "fsl_adc16_driver.h"
#include "fsl_uart_driver.h"

#include <stdint.h>
//#include "mma8451.h"
//#include "fxas21002.h"

void PIT_Init(void);
void I2C_Init(void);
void FTM_QD_Init(void);
void FTM_PWM_Init(void);
void UART_Init(void);


void Hardware_Init(void)
{
	BOARD_ClockInit();
	/*                            */
	CLOCK_SYS_EnablePortClock(PORTA_IDX);
	CLOCK_SYS_EnablePortClock(PORTB_IDX);
	CLOCK_SYS_EnablePortClock(PORTC_IDX);
	CLOCK_SYS_EnablePortClock(PORTD_IDX);

	//configure_gpio_pins();
	configure_i2c_pins(I2C1_IDX);

	configure_uart_pins(UART0_IDX);
	configure_uart_pins(UART3_IDX);

	configure_adc_pins(ADC0_IDX);
	configure_adc_pins(ADC1_IDX);

	configure_ftm_pins(FTM0_IDX);
	configure_ftm_pins(FTM1_IDX);
	configure_ftm_pins(FTM2_IDX);

	GPIO_DRV_Init(inputPins,outputPins);

	//MMA8451_Init();
	//FXAS21002_Init();

}
/*
 * initial pit
 */
void PIT_Init(void)
{
	pit_user_config_t pit_config = {
			.isInterruptEnabled = true,
			.periodUs = 1000000u
	};
#ifdef DEBUG
	PIT_DRV_Init(PIT_IDX,1u);
#else
	PIT_DRV_Init(PIT_IDX,0u);
#endif
	PIT_DRV_InitChannel(PIT_IDX,0,&pit_config);
	PIT_DRV_StartTimer(0,0);
}
void I2C_Init(void)
{
//	i2c_master_state_t i2c_init = {
//
//	};
}

