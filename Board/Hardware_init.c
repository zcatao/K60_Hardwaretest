/*
 * Hardware_init.c
 *
 *  Created on: 2016Äê5ÔÂ17ÈÕ
 *      Author: yangs
 */

#include "pin_mux.h"
#include "board.h"
#include "gpio_pins.h"
#include "fsl_clock_manager.h"
#include "fsl_gpio_driver.h"
#include "fsl_pit_driver.h"
#include "fsl_i2c_master_driver.h"
#include "fsl_ftm_driver.h"
#include "fsl_adc16_driver.h"
#include "fsl_uart_driver.h"

#include <stdint.h>
//#include "mma8451.h"
//#include "fxas21002.h"

uint8_t txbuff[20];
uint8_t txSize = 20;
uint8_t Cmdbuff[10];
uint8_t CmdSize = 0;



static void PIT_Init(void);
static void I2C_Init(void);
static void FTM_QD_Init(void);
static void FTM_PWM_Init(void);
static void UART_Init(void);
static void ADC_Init(void);

void Hardware_Init(void)
{


	/*                            */
	CLOCK_SYS_EnablePortClock(PORTA_IDX);
	CLOCK_SYS_EnablePortClock(PORTB_IDX);
	CLOCK_SYS_EnablePortClock(PORTC_IDX);
	CLOCK_SYS_EnablePortClock(PORTD_IDX);

	BOARD_ClockInit();

	dbg_uart_init();

	//configure_gpio_pins();

	configure_i2c_pins(I2C1_IDX);

	configure_uart_pins(UART0_IDX);
	configure_uart_pins(UART3_IDX);

	//configure_adc_pins(ADC0_IDX);
	//configure_adc_pins(ADC1_IDX);

	//configure_ftm_pins(FTM0_IDX);
	//configure_ftm_pins(FTM1_IDX);
	//configure_ftm_pins(FTM2_IDX);

	OSA_Init();

	GPIO_DRV_Init(inputPins,outputPins);

	I2C_Init();

	//MMA8451_Init();
	//FXAS21002_Init();

}
/*
 * initial pit
 */
static void PIT_Init(void)
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

	PIT_DRV_StartTimer(0,0);				/*start PIT time */
}
const i2c_device_t dev_fxas21002 = {
		.address = FXAS21002_address,
		.baudRate_kbps = FXAS21002_baudRate
};
const i2c_device_t dev_MMA8451 = {
		.address = MMA8451_address,
		.baudRate_kbps = MMA8451_baudRate
};
static void I2C_Init(void)
{
	i2c_master_state_t I2C_master;
	I2C_DRV_MasterInit(I2C1_IDX,&I2C_master);
	Cmdbuff[0] = 'a';
	txbuff[0] = '0';
	I2C_DRV_MasterSendData(I2C1_IDX,&dev_fxas21002,Cmdbuff,1,txbuff,1);
}


