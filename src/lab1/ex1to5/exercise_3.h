/*
 * exercise_3.h
 *
 *  Created on: Sep 9, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_EXERCISE_3_H_
#define SRC_EXERCISE_3_H_
#include "main.h"

int init = 0; //initialize variable
int ver_s = 0, hor_s = 0; // vertical and horizontal stage variable
int ver_c = 0, hor_c = 0; // vertical and horizontal counter/timer

void VerInitStage(){
	ver_s = 1;
	HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(gre_v_GPIO_Port, gre_v_Pin, GPIO_PIN_SET);
}

void ver_s2(){
	ver_s = 2;
	HAL_GPIO_TogglePin(yel_v_GPIO_Port, yel_v_Pin);
	HAL_GPIO_TogglePin(gre_v_GPIO_Port, gre_v_Pin);
}
void ver_s3(){
	ver_s = 3;
	HAL_GPIO_TogglePin(red_v_GPIO_Port, red_v_Pin);
	HAL_GPIO_TogglePin(yel_v_GPIO_Port, yel_v_Pin);
}
void ver_s1(){
	ver_s = 1;
	HAL_GPIO_TogglePin(gre_v_GPIO_Port, gre_v_Pin);
	HAL_GPIO_TogglePin(red_v_GPIO_Port, red_v_Pin);
}

void HorInitStage(){
	hor_s = 1;
	HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(gre_h_GPIO_Port, gre_h_Pin, GPIO_PIN_RESET);
}

void hor_s2(){
	hor_s = 2;
	HAL_GPIO_TogglePin(gre_h_GPIO_Port, gre_h_Pin);
	HAL_GPIO_TogglePin(red_h_GPIO_Port, red_h_Pin);
}

void hor_s3(){
	hor_s = 3;
	HAL_GPIO_TogglePin(yel_h_GPIO_Port, yel_h_Pin);
	HAL_GPIO_TogglePin(gre_h_GPIO_Port, gre_h_Pin);
}

void hor_s1(){
	hor_s = 1;
	HAL_GPIO_TogglePin(red_h_GPIO_Port, red_h_Pin);
	HAL_GPIO_TogglePin(yel_h_GPIO_Port, yel_h_Pin);
}

void ex3(){
	if(init == 0){
		++init;
		VerInitStage();
		HorInitStage();
	}
	switch(ver_s){
	case 1:
		if(ver_c >=3){
			ver_s2();
			ver_c = 0;
		}
		break;
	case 2:
		if(ver_c >= 2){
			ver_s3();
			ver_c = 0;
		}
		break;
	case 3:
		if(ver_c >= 5){
			ver_s1();
			ver_c = 0;
		}
		break;
	}
	switch(hor_s){
	case 1:
		if(hor_c >= 5){
			hor_s2();
			hor_c = 0;
		}
		break;
	case 2:
		if(hor_c >= 3){
			hor_s3();
			hor_c = 0;
		}
		break;
	case 3:
		if(hor_c >= 2){
			hor_s1();
			hor_c = 0;
		}
		break;
	}
	++ver_c;
	++hor_c;
}



#endif /* SRC_EXERCISE_3_H_ */
