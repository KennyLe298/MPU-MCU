/*
 * exercise_7.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_EXERCISE_7_H_
#define SRC_EXERCISE_7_H_
#include "main.h"
#include "exercise_6.h"
#include "exercise_7.h"
#include "exercise_8.h"
#include "exercise_9.h"

void clearAllClock(void) {
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(GPIOA, hourPins[i], GPIO_PIN_RESET);
    }
}


#endif /* SRC_EXERCISE_7_H_ */
