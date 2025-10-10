/*
 * input_reading.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Le Hoang
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define N0_OF_BUTTONS 3 // 3 buttons

#define DURATION_FOR_AUTO_INCREASING 100 //1s

#define PRESSED GPIO_PIN_RESET
#define RELEASED GPIO_PIN_SET

void init_button_reading(void);

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
