/*
 * exercise_2.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Chu Le Hoang
 */

#ifndef INC_EXERCISE_2_H_
#define INC_EXERCISE_2_H_
#include "main.h"

void initStage(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
}

void StageYellow(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_GPIO_TogglePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin);
}

void StageGreen(){
	HAL_GPIO_TogglePin(YELLOW_LED_GPIO_Port, YELLOW_LED_Pin);
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}

void StageRed(){
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void ex2(){
	static unsigned init = 0;
	static unsigned count = 0;
	static unsigned stage = 0;

	if(init == 0) {
		initStage();
		stage = 1;
		init++;
	}

	switch(stage){
	case 1:
	{
		if(count == 5){
			stage = 2;
			StageYellow();
			count = 0;
		}
		break;
	}
	case 2:
	{
		if(count == 3){
			stage = 3;
			StageGreen();
			count = 0;
		}
		break;
	}
	case 3:
	{
		if(count == 2){
			stage = 1;
			StageRed();
			count  = 0;
		}
		break;
	}
	}
	++count;
}
#endif /* INC_EXERCISE_2_H_ */
