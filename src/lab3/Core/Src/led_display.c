/*
 * led_display.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Le Hoang
 */
#include "main.h"
#include "global.h"
int horstate = 0;
int verstate = 0;

void setHorLed(int color){
	switch(color){
	case RED:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, GPIO_PIN_SET);
		horstate = RED;
		break;
	case YEL:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, GPIO_PIN_SET);
		horstate = YEL;
		break;
	case GRN:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, GPIO_PIN_RESET);
		horstate = GRN;
		break;
	default:
		HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, GPIO_PIN_SET);
		horstate = OFF;
		break;
	}
}

void setVerLed(int color){
	switch(color){
	case RED:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, GPIO_PIN_SET);
		verstate = RED;
		break;
	case YEL:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, GPIO_PIN_SET);
		verstate = YEL;
		break;
	case GRN:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, GPIO_PIN_RESET);
		verstate = GRN;
		break;
	default:
		HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, GPIO_PIN_SET);
		verstate = OFF;
		break;
	}
}

int segment_buffer[4] = {0};

GPIO_PinState PinMap[11][7] = {
	    {0, 0, 0, 0, 0, 0, 1}, //0
	    {1, 0, 0, 1, 1, 1, 1}, //1
	    {0, 0, 1, 0, 0, 1, 0}, //2
	    {0, 0, 0, 0, 1, 1, 0}, //3
	    {1, 0, 0, 1, 1, 0, 0}, //4
	    {0, 1, 0, 0, 1, 0, 0}, //5
	    {0, 1, 0, 0, 0, 0, 0}, //6
	    {0, 0, 0, 1, 1, 1, 1}, //7
	    {0, 0, 0, 0, 0, 0, 0}, //8
	    {0, 0, 0, 0, 1, 0, 0}, //9
		{1, 1, 1, 1, 1, 1, 1}  //ALL LED TURN OFF
};

GPIO_TypeDef* segHorPorts[7] = {a_h_GPIO_Port, b_h_GPIO_Port, c_h_GPIO_Port, d_h_GPIO_Port, e_h_GPIO_Port, f_h_GPIO_Port, g_h_GPIO_Port};
uint16_t segHorPins[7] = {a_h_Pin, b_h_Pin, c_h_Pin, d_h_Pin, e_h_Pin, f_h_Pin, g_h_Pin};

GPIO_TypeDef* segVerPorts[7] = {a_v_GPIO_Port, b_v_GPIO_Port, c_v_GPIO_Port, d_v_GPIO_Port, e_v_GPIO_Port, f_v_GPIO_Port, g_v_GPIO_Port};
uint16_t segVerPins[7] = {a_v_Pin, b_v_Pin, c_v_Pin, d_v_Pin, e_v_Pin, f_v_Pin, g_v_Pin};

void set7segHor(int num){
    if(num < 0 || num > 10) num = 10;
    for(int s = 0; s < 7; s++){
        HAL_GPIO_WritePin(segHorPorts[s], segHorPins[s], (PinMap[num][s] == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
}

void set7segVer(int num){
    if(num < 0 || num > 10) num = 10;
    for(int s = 0; s < 7; s++){
        HAL_GPIO_WritePin(segVerPorts[s], segVerPins[s], (PinMap[num][s] == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
}

void scan7seg(int state){
	state = state%2;
	switch(state){
	case 0:
		HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
		set7segHor(segment_buffer[0]);
		set7segVer(segment_buffer[2]);
		break;
	case 1:
		HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_RESET);
		set7segHor(segment_buffer[1]);
		set7segVer(segment_buffer[3]);
		break;
	default:
		break;
	}
}

void updateSeg(int a, int b, int c, int d){
	segment_buffer[0] = a;
	segment_buffer[1] = b;
	segment_buffer[2] = c;
	segment_buffer[3] = d;
}

void updateSeg2Digits(int a, int b){
	segment_buffer[0] = a/10;
	segment_buffer[1] = a%10;
	segment_buffer[2] = b/10;
	segment_buffer[3] = b%10;
}

