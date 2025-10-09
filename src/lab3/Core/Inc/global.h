/*
 * global.h
 *
 *  Created on: Oct 8, 2025
 *      Author: GIGABYTE
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "led_display.h"
#include "input_reading.h"
#include "input_processing.h"

// 1 : normal, 2 : modify red, 3 : modify amber, 4 : modify green
extern int current_mode;

// default duration
extern int red_duration;
extern int amber_duration;
extern int green_duration;

#define RED		1
#define YEL		2
#define GRN		3

#define OFF		0


extern int scan_state;


#endif /* INC_GLOBAL_H_ */
