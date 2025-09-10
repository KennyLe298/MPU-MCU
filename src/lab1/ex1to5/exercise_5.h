/*
 * exercise_5.h
 *
 *  Created on: Sep 10, 2025
 *      Author: GIGABYTE
 */

#ifndef INC_EXERCISE_5_H_
#define INC_EXERCISE_5_H_
#include "main.h"
#include "exercise_3.h"
#include "exercise_4.h"

void display7SEG2(int num){
	if(num >= 0 && num <= 9){
		for(int i = 7; i < 14; i++){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, segmentmap[num - 1][i]);
		}
	}
}

void ex5(){
	ex3();
	switch(ver_s){
	case 1:
		display7SEG(3 - ver_c);
		break;
	case 2:
		display7SEG(2 - ver_c);
		break;
	case 3:
		display7SEG(5 - ver_c);
		break;
	}
	switch(hor_s){
	case 1:
		display7SEG2(5 - hor_c);
		break;
	case 2:
		display7SEG2(3 - hor_c);
		break;
	case 3:
		display7SEG2(2 - hor_c);
		break;
	}
}



#endif /* INC_EXERCISE_5_H_ */
