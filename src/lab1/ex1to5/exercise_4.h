/*
 * exercise_4.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Chu Le Hoang
 */

#ifndef INC_EXERCISE_4_H_
#define INC_EXERCISE_4_H_
#include "main.h"

int segmentmap[10][7] = {
    {0,0,0,0,0,0,1}, // 0
    {1,0,0,1,1,1,1}, // 1
    {0,0,1,0,0,1,0}, // 2
    {0,0,0,0,1,1,0}, // 3
    {1,0,0,1,1,0,0}, // 4
    {0,1,0,0,1,0,0}, // 5
    {0,1,0,0,0,0,0}, // 6
    {0,0,0,1,1,1,1}, // 7
    {0,0,0,0,0,0,0}, // 8
    {0,0,0,0,1,0,0}  // 9
};

void display7SEG(int num){
	if (num < 0 || num > 9){
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, GPIO_PIN_SET);  //turn of all segment if wrong input
	        return;
	    }
	for (int i = 0; i < 7; i++){
	        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, segmentmap[num][i]);
	    }
}


#endif /* INC_EXERCISE_4_H_ */
