/*
 * exercise_9.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_EXERCISE_9_H_
#define SRC_EXERCISE_9_H_
#include "main.h"
#include "exercise_6.h"
#include "exercise_7.h"
#include "exercise_8.h"
#include "exercise_9.h"

void clearNumberOnClock(int num) {
    if (num < 0 || num > 11) return;

    HAL_GPIO_WritePin(GPIOA, hourPins[num], GPIO_PIN_RESET);
}


#endif /* SRC_EXERCISE_9_H_ */
