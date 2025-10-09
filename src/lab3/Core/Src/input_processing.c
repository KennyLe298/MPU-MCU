/*
 * input_processing.c
 *
 *  Created on: Sep 30, 2025
 *      Author: GIGABYTE
 */

#include "main.h"
#include "input_reading.h"
#include "led_display.h"
#include "timer.h"
#include "global.h"
#include "traffic.h"

// for modify (1-99)
int temp_value = 1;

int blink_state = 0;

void fsm_for_input_processing(void){
    static uint8_t last_mode_button = 1;
    static uint8_t last_inc_button = 0;
    static uint8_t last_set_button = 0;

    if(is_button_pressed(0) && !last_mode_button){
        current_mode++;
        if(current_mode > 4) current_mode = 1;

        if(current_mode == 1) {
            traffic_reset();
        }
        else {
            HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin|yel_h_Pin|grn_h_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin|yel_v_Pin|grn_v_Pin, GPIO_PIN_SET);
        }

        if(current_mode == 2) temp_value = red_duration;
        else if(current_mode == 3) temp_value = amber_duration;
        else if(current_mode == 4) temp_value = green_duration;
        //2Hz blink
        setTimer1(250); // flag1
        last_inc_button = 1;
        last_set_button = 1;
    }
    last_mode_button = is_button_pressed(0);

    if(current_mode == 1){

    	if(flag2 == 0 && timer2 == 0){
    	    setTimer2(1000);
    	}
    	traffic_fsm();
    }
		else if(current_mode == 2 || current_mode == 3 || current_mode == 4){
			updateSeg2Digits(current_mode, temp_value);

        if(flag1){
            flag1 = 0;
            blink_state = !blink_state;
            setTimer1(250);
            if(current_mode == 2){
                if(blink_state){
                    HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_RESET);
                } else {
                    HAL_GPIO_WritePin(red_h_GPIO_Port, red_h_Pin, GPIO_PIN_SET);
                    HAL_GPIO_WritePin(red_v_GPIO_Port, red_v_Pin, GPIO_PIN_SET);
                }
            }
            else if(current_mode == 3){
                if(blink_state){
                    HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_RESET);
                } else {
                    HAL_GPIO_WritePin(yel_h_GPIO_Port, yel_h_Pin, GPIO_PIN_SET);
                    HAL_GPIO_WritePin(yel_v_GPIO_Port, yel_v_Pin, GPIO_PIN_SET);
                }
            }
            else if(current_mode == 4){
                if(blink_state){
                    HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, GPIO_PIN_RESET);
                } else {
                    HAL_GPIO_WritePin(grn_h_GPIO_Port, grn_h_Pin, GPIO_PIN_SET);
                    HAL_GPIO_WritePin(grn_v_GPIO_Port, grn_v_Pin, GPIO_PIN_SET);
                }
            }
        }
        if(is_button_pressed(1) && !last_inc_button){
            temp_value++;
            if(temp_value > 99) temp_value = 1;
        }
        if(is_button_pressed_1s(1)){
            temp_value++;
            if(temp_value > 99) temp_value = 1;
        }
        last_inc_button = is_button_pressed(1);

        if(is_button_pressed(2) && !last_set_button){
            if(current_mode == 2){
                if(temp_value >= 2){
                    red_duration = temp_value;
                    if(red_duration > amber_duration){
                        green_duration = red_duration - amber_duration;
                    }
                    else{
                        amber_duration = 1; //auto set amber to be 1 when red is small
                        green_duration = red_duration - 1;
                    }
                }
            }
            else if(current_mode == 3){
                if(temp_value > 0 && temp_value < red_duration){
                    amber_duration = temp_value;
                    green_duration = red_duration - amber_duration;
                }
            }
            else if(current_mode == 4){
                if(temp_value > 0 && temp_value < red_duration){
                    green_duration = temp_value;
                    amber_duration = red_duration - green_duration;
                }
            }
        }
        last_set_button = is_button_pressed(2);
    }
}

