/*
 * input_reading.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Le Hoang
 */

#include "input_reading.h"
#include "main.h"

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS]; //buffer that the final result is stored after debouncing

static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS]; //two buffer for debouncing
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static uint8_t flagForButtonPress1s[N0_OF_BUTTONS]; //flag for a button to be pressed for more than 1 sec
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS]; //counter for auto increase value after button pressed more than 1 sec

GPIO_TypeDef* buttonPorts[N0_OF_BUTTONS] = {button_1_GPIO_Port};
uint16_t buttonPins[N0_OF_BUTTONS] = {button_1_Pin};

void init_button_reading(void){
    for(int i = 0; i < N0_OF_BUTTONS; i++){
        debounceButtonBuffer1[i] = RELEASED;
        debounceButtonBuffer2[i] = RELEASED;
        buttonBuffer[i] = RELEASED;
    }
}

void button_reading(void){
	for(int i = 0; i < N0_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPorts[i], buttonPins[i]);

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){

			buttonBuffer[i] = debounceButtonBuffer1[i]; //accept if stable

			if(buttonBuffer[i] == PRESSED){ //start counting when button is pressed

				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				}
				else{
					flagForButtonPress1s[i] = 1; //flag when 1 sec passed since button pressed
					counterForButtonPress1s[i] = 0;
				}
			}
			else{ // released
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0; //reset for repetition
			}
		}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == PRESSED);
}

unsigned char is_button_pressed_1s (unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff ;
	return (flagForButtonPress1s[index] == 1) ;
}


