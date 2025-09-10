/*
 * clock.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_EXERCISE_6_H_
#define SRC_EXERCISE_6_H_
#include "main.h"


uint16_t hourPins[12] = {
    h12_Pin, h1_Pin, h2_Pin, h3_Pin, h4_Pin, h5_Pin,
    h6_Pin, h7_Pin, h8_Pin, h9_Pin, h10_Pin, h11_Pin
};

void testLEDs(void) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            HAL_GPIO_WritePin(GPIOA, hourPins[j], GPIO_PIN_RESET);
        }
        HAL_GPIO_WritePin(GPIOA, hourPins[i], GPIO_PIN_SET);

        HAL_Delay(5000);
    }
}



#endif /* SRC_EXERCISE_6_H_ */
