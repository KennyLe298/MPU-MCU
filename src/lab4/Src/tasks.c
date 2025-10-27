/*
 * tasks.c
 *
 *  Created on: Oct 14, 2025
 *      Author: GIGABYTE
 */
#include "tasks.h"
#include "main.h"
void LED_Task_500ms(void){
    HAL_GPIO_TogglePin(Led_1_GPIO_Port, Led_1_Pin);
}

void LED_Task_1000ms(void){
    HAL_GPIO_TogglePin(Led_2_GPIO_Port, Led_2_Pin);
}

void LED_Task_1500ms(void){
    HAL_GPIO_TogglePin(Led_3_GPIO_Port, Led_3_Pin);
}

void LED_Task_2000ms(void){
    HAL_GPIO_TogglePin(Led_4_GPIO_Port, Led_4_Pin);
}

void LED_Task_2500ms(void){
    HAL_GPIO_TogglePin(Led_5_GPIO_Port, Led_5_Pin);
}

void OneShot_Task(void) {
    //turn all LEDs off
    HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led_2_GPIO_Port, Led_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led_3_GPIO_Port, Led_3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led_4_GPIO_Port, Led_4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led_5_GPIO_Port, Led_5_Pin, GPIO_PIN_SET);
    HAL_Delay(300); 
    
    //turn on in order
    HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_RESET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(Led_2_GPIO_Port, Led_2_Pin, GPIO_PIN_RESET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(Led_3_GPIO_Port, Led_3_Pin, GPIO_PIN_RESET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(Led_4_GPIO_Port, Led_4_Pin, GPIO_PIN_RESET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(Led_5_GPIO_Port, Led_5_Pin, GPIO_PIN_RESET);
    HAL_Delay(500);
    
}

void Print_Timestamp(void) {
	uint32_t time = SCH_Get_Time();
}
