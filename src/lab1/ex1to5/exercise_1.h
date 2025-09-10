/*
 * exercise_1.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_EXERCISE_1_H_
#define SRC_EXERCISE_1_H_
#include "main.h"

void LED_toggle(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port,LED_RED_Pin);
	HAL_GPIO_TogglePin(YELLOW_LED_GPIO_Port,YELLOW_LED_Pin);
}

void initStage(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
}

void ex1(){
	static unsigned int init = 0;
	static unsigned int count = 0;

	if(init == 0){
		initStage();
		init++;
	}
	if(count >= 3){
		count = 0;
		LED_toggle();
	}
	else ++count;
}



#endif /* SRC_EXERCISE_1_H_ */
