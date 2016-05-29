/*
 * app_interface.h
 *
 *  Created on: 2016Äê5ÔÂ26ÈÕ
 *      Author: yangs
 */

#ifndef SOURCES_APP_INTERFACE_H_
#define SOURCES_APP_INTERFACE_H_

#include "board.h"

static inline void Board_Init(void){
	Hardware_Init();
}

static inline void Motor_Out_L(int16_t duty);

static inline void Motor_Out_R(int16_t duty);

static inline uint16_t ReadSpeed_L(void);

static inline uint16_t ReadSpeed_R(void);

static inline uint16_t ReadGyro(uint8_t axis);

static inline uint16_t ReadAcc(uint8_t axis);

static inline void ReadSensor(uint8_t Instance,uint16_t *Sensor_data);


#endif /* SOURCES_APP_INTERFACE_H_ */
