/*
 * user_i2c_irq.c
 *
 *  Created on: 2016��5��26��
 *      Author: yangs
 */
#include "fsl_i2c_master_driver.h"
#include "fsl_i2c_shared_function.h"


void I2C1_IRQHandler(void){
	I2C_DRV_MasterIRQHandler(1);
}

