/*
 * GPTM.h
 *
 *  Created on: Jun 7, 2025
 *      Author: Mohamed Ashraf
 */

#ifndef MCAL_INC_GPTM_H_
#define MCAL_INC_GPTM_H_


#include<stdint.h>
#include"tm4c123gh6pm.h"
/**
 * @brief Initializes Wide Timer 0A as a 32-bit one-shot down counter.
 *        The timer uses a prescaler to create a tick time of 0.1 ms.
 *        Clock source is assumed to be 16 MHz.
 */
void GPTM_WTimer0Init(void);
/**
 * @brief Reads the number of ticks that have elapsed since the timer started.
 * @return Elapsed ticks (each tick is 0.1 ms)
 * @note Assumes one-shot mode starting from 0xFFFFFFFF.
 */
uint32_t GPTM_WTimer0Read(void);
/**
 * @brief Blocking delay using original 0.1ms-resolution timer.
 * @param milliseconds Delay duration in milliseconds.
 */
void delay_ms(uint32_t milliseconds);

#endif /* MCAL_INC_GPTM_H_ */
