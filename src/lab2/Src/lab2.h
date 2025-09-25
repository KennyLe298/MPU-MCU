/*
 * lab2.h
 *
 *  Created on: Sep 15, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_LAB2_H_
#define SRC_LAB2_H_
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

void LED_toggle(){
	HAL_GPIO_TogglePin(EN0_GPIO_Port,EN0_Pin);
	HAL_GPIO_TogglePin(EN1_GPIO_Port,EN1_Pin);
}
//Exercise 1
//void init(){
//	display7SEG(-1);
//	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//}
//
//int counter1 = 50;
//void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim){
//	counter1--;
//	if (counter1 == 0){
//		if (HAL_GPIO_ReadPin(EN0_GPIO_Port, EN0_Pin) == 0){
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//			display7SEG(2);
////			update7SEG(index_led++);
//		}
//		else {
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//			display7SEG(1);
////			update7SEG(index_led++);
//		}
//		counter1 = 50;
//	}
//}

//  Exercise 2
//int const clockNum = 4;
//int clockArr[4] = {0, 0, 0, 0};
//int clockFlag[4] = {0, 0, 0, 0};
//int const cycle = 10;
//void clockRuns(){
//	for (int i = 0; i < clockNum; i++){
//		if (clockArr[i] > 0) clockArr[i]--;
//		else {
//			clockFlag[i] = 1;
//		}
//	}
//}
//	Exercise 2
//int clock_1 = 100;
//int clock7Seg = 50;
//int stage = 0; //initial stage
////void setClock (int time, int clockNo){
////	int newTime = time/cycle;
////	if (clockNo < clockNum){
////		int clockArr[clockNo] = newTime;
////		int clockFlag[clockNo] = 0;
////	}
////}
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
//	clock_1--;
//	if (clock_1 <= 0) {
//		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
//		clock_1 = 100;
//	}
//	clock7Seg--;
//	if (clock7Seg <= 0){
//		switch (stage){
//			case 0:
//			{
//				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//				display7SEG(1);
//				stage = 1;
//				break;
//			}
//			case 1:
//			{
//				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//				display7SEG(2);
//				stage = 2;
//				break;
//			}
//			case 2:
//			{
//				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//				display7SEG(3);
//				stage = 3;
//				break;
//			}
//			case 3:
//			{
//				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//				display7SEG(0);
//				stage = 0;
//				break;
//			}
//		}
//		clock7Seg = 50;
//	}
//}

//Exercise 3
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {0,9,0,8};
void selectEn(int index){
	switch (index){
		case 0:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		}
		case 1:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		}
		case 2:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		}
		case 3:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			break;
		}
		default:
		{
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			break;
		}
	}
}
void update7SEG(int index){
	if(index_led >= MAX_LED){
		index_led = 0;
	}
	index = index%4;
	switch(index){
	case 0:
	{
		selectEn(index);
		display7SEG(led_buffer[index]);
		break;
	}
	case 1:
	{
		selectEn(index);
		display7SEG(led_buffer[index]);
		break;
	}
	case 2:
	{
		selectEn(index);
		display7SEG(led_buffer[index]);
		break;
	}
	case 3:
	{
		selectEn(index);
		display7SEG(led_buffer[index]);
		break;
	}
	default:
	{
		selectEn(-1);
		break;
	}
	}
}
// Exercise 4
//int clock_1 = 25;
//int clockBlink = 100;
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
//	clock_1--;
//	clockBlink--;
//	if(clock_1 <= 0){
//		update7SEG(index_led);
//		index_led++;
//		clock_1 =25;
//	}
//	if(clockBlink <= 0){
//		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
//		clockBlink = 100;
//	}
//}
int timer0_counter = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10;

void setTimer0(int duration){
    timer0_counter = duration / TIMER_CYCLE;
    timer0_flag = 0;
}

int timer1_counter = 0;
int timer1_flag = 0;

void setTimer1(int duration){
    timer1_counter = duration / TIMER_CYCLE;
    timer1_flag = 0;
}


int timer2_counter = 0;
int timer2_flag = 0;
int timer3_counter = 0;
int timer3_flag = 0;

void setTimer2(int duration){ timer2_counter = duration / TIMER_CYCLE; timer2_flag = 0; }
void setTimer3(int duration){ timer3_counter = duration / TIMER_CYCLE; timer3_flag = 0; }




void timer_run(){
    if(timer0_counter > 0){
        timer0_counter--;
        if(timer0_counter == 0) timer0_flag = 1;
    }
//    //for ex8
    if(timer1_counter > 0){
        timer1_counter--;
        if(timer1_counter == 0) timer1_flag = 1;
    }
//    //for ex9
    if(timer2_counter > 0){
        timer2_counter--;
        if(timer2_counter == 0) timer2_flag = 1;
    }
    //for ex10
    if(timer3_counter > 0){
        timer3_counter--;
        if(timer3_counter == 0) timer3_flag = 1;
    }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    timer_run();
}

int hour = 15, minute = 8, second = 50;
// Exercise 5
void updateClockBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}
//ex9
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;

//Letter A
//Row 0: 00011000
//Row 1: 00100100
//Row 2: 01000010
//Row 3: 01000010
//Row 4: 01111110
//Row 5: 01000010
//Row 6: 01000010
//Row 7: 01000010
uint8_t matrix_buffer[8] = {
	  0b00011000,
    0b00100100,
    0b01000010,
    0b01000010,
    0b01111110,
    0b01000010,
    0b01000010,
    0b01000010
};

//C
//uint8_t matrix_buffer[8] = {
//    0b00111000,
//    0b01000100,
//    0b10000000,
//    0b10000000,
//    0b10000000,
//    0b10000000,
//    0b01000100,
//    0b00111000
//};

void selectRow(int index){
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, (index == 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, (index == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, (index == 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, (index == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, (index == 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, (index == 5) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, (index == 6) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, (index == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void writeCols(uint8_t data){

    HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, (data & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, (data & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, (data & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, (data & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}


void led_matrix_init(){
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, GPIO_PIN_RESET);
}

void updateLEDMatrix(int index){
    index = index % MAX_LED_MATRIX;
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);
    writeCols(matrix_buffer[index]);
    selectRow(index);
}
//ex10
void shiftCharacterLeft(void){
    for(int i = 0; i < MAX_LED_MATRIX; i++){
        uint8_t leftmost_bit = (matrix_buffer[i] & 0b10000000) >> 7;
        matrix_buffer[i] = matrix_buffer[i] << 1;
        matrix_buffer[i] = matrix_buffer[i] | leftmost_bit;
    }
}
void shiftCharacterRight(void){
    for(int i = 0; i < MAX_LED_MATRIX; i++){
        uint8_t rightmost_bit = (matrix_buffer[i] & 0b00000001) << 7;
        matrix_buffer[i] = matrix_buffer[i] >> 1;
        matrix_buffer[i] = matrix_buffer[i] | rightmost_bit;
    }
}
void shiftCharacterDown(void){
    uint8_t last_row = matrix_buffer[MAX_LED_MATRIX - 1];
    for(int i = MAX_LED_MATRIX - 2; i >= 0; i--){
        matrix_buffer[i+1] = matrix_buffer[i];
    }
    matrix_buffer[0] = last_row;
}




#endif /* SRC_LAB2_H_ */
