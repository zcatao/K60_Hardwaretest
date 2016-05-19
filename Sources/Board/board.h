/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined(__BOARD_H__)
#define __BOARD_H__

#include <stdint.h>
#include "pin_mux.h"
#include "gpio_pins.h"
/* The board name */
#define BOARD_NAME                      "Sontao_board"

#define CLOCK_VLPR 1U
#define CLOCK_RUN  2U
#define CLOCK_NUMBER_OF_CONFIGURATIONS 3U

#ifndef CLOCK_INIT_CONFIG
#define CLOCK_INIT_CONFIG CLOCK_RUN
#endif

#if (CLOCK_INIT_CONFIG == CLOCK_RUN)
#define CORE_CLOCK_FREQ 96000000U
#else
#define CORE_CLOCK_FREQ 4000000U
#endif

/* OSC0 configuration. */
#define OSC0_XTAL_FREQ 50000000U
#define OSC0_SC2P_ENABLE_CONFIG  false
#define OSC0_SC4P_ENABLE_CONFIG  false
#define OSC0_SC8P_ENABLE_CONFIG  false
#define OSC0_SC16P_ENABLE_CONFIG false
#define MCG_HGO0   kOscGainLow
#define MCG_RANGE0 kOscRangeVeryHigh
#define MCG_EREFS0 kOscSrcExt

/* EXTAL0 PTA18 */
#define EXTAL0_PORT   PORTA
#define EXTAL0_PIN    18
#define EXTAL0_PINMUX kPortPinDisabled

/* XTAL0 PTA19 */
#define XTAL0_PORT   PORTA
#define XTAL0_PIN    19
#define XTAL0_PINMUX kPortPinDisabled

/* RTC external clock configuration. */
#define RTC_XTAL_FREQ   32768U
#define RTC_SC2P_ENABLE_CONFIG       false
#define RTC_SC4P_ENABLE_CONFIG       false
#define RTC_SC8P_ENABLE_CONFIG       false
#define RTC_SC16P_ENABLE_CONFIG      false
#define RTC_OSC_ENABLE_CONFIG        false

//#define BOARD_RTC_CLK_FREQUENCY     32768U;
/* The UART to use for debug messages. */
#ifndef BOARD_DEBUG_UART_INSTANCE
    #define BOARD_DEBUG_UART_INSTANCE   2
    #define BOARD_DEBUG_UART_BASEADDR   UART2
#endif
#ifndef BOARD_DEBUG_UART_BAUD
    #define BOARD_DEBUG_UART_BAUD       115200
#endif

/* This define to use for power manager demo */
#define BOARD_LOW_POWER_UART_BAUD       9600

#define BOARD_USE_UART
#define PM_DBG_UART_IRQ_HANDLER         UART2_RX_TX_IRQHandler
#define PM_DBG_UART_IRQn                UART2_RX_TX_IRQn

/* Define feature for the low_power_demo */
#define FSL_FEATURE_HAS_VLLS2 (1)

/* board gpio mapping */
#define kGpioKeyUp 						kGpioPTC0
#define kGpiokeyDown					kGPioPTB20
#define kGpioKeyLeft					kGpioPTC1
#define kGpioKeyRight					kGpioPTB22
#define kGpioKeyCentre					kGpioPTB21
#define kGpioKeyCom						kGpioPTB23

#define kGpioSW0						kGpioPTE0
#define kGpioSW1						kGpioPTE1
#define kGpioSW2					    kGpioPTE2
#define kGpioSW3						kGpioPTE3
/* */
/* The i2c instance used for i2c connection by default */
#define BOARD_I2C_INSTANCE              1
#define BOARD_I2C_GPIO_SCL              GPIO_MAKE_PIN(GPIOC_IDX, 10)
#define BOARD_I2C_GPIO_SDA              GPIO_MAKE_PIN(GPIOC_IDX, 11)




/* ADC TWRPI ID input channel */
#define BOARD_ADC_TWRPIID0_CHAN          1
#define BOARD_ADC_TWRPIID1_CHAN          16
#define BOARD_ADC_TWRPI                  1

#define TX_DEBUG_CONSOLE_DIS PORT_HAL_SetMuxMode(PORTE, 8, kPortPinDisabled)
#define RX_DEBUG_CONSOLE_DIS PORT_HAL_SetMuxMode(PORTE, 9, kPortPinDisabled)

#define SW_INT_DIS PORT_HAL_SetPinIntMode(PORTA, 19, kPortIntDisabled)
#define SW_DIS PORT_HAL_SetMuxMode(PORTA, 19, kPortPinDisabled)


/* The rtc instance used for rtc_func */
#define BOARD_RTC_FUNC_INSTANCE         0

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

void Hardware_Init(void);

void dbg_uart_init(void);
/*This function to used for power manager demo*/
void disable_unused_pins(void);
void enable_unused_pins(void);
/* Function to initialize clock base on board configuration. */
void BOARD_ClockInit(void);

/* Function to initialize OSC0 base on board configuration. */
void BOARD_InitOsc0(void);

/* Function to initialize RTC external clock base on board configuration. */
void BOARD_InitRtcOsc(void);



#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* __BOARD_H__ */
