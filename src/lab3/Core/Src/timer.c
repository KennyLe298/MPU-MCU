/*
 * timer.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Le Hoang
 */


#include "main.h"
#include "input_reading.h"
#include "timer.h"

int timer1 = 0, timer2 = 0, timer3 = 0, timer4 = 0, timer5 = 0;

int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

void setTimer1(int timer){
    timer1 = timer / TIMER_CYCLE;
    flag1 = 0;
}

void setTimer2(int timer){
    timer2 = timer / TIMER_CYCLE;
    flag2 = 0;
}

void setTimer3(int timer){
    timer3 = timer / TIMER_CYCLE;
    flag3 = 0;
}

void setTimer4(int timer){
    timer4 = timer / TIMER_CYCLE;
    flag4 = 0;
}
void setTimer5(int timer){
    timer5 = timer / TIMER_CYCLE;
    flag5 = 0;
}

void timerRun(){
    timer1--;
    timer2--;
    timer3--;
    timer4--;
    timer5--;
    if (timer1 == 0){
        flag1 = 1;
    }
    if (timer2 == 0){
        flag2 = 1;
    }
    if (timer3 == 0){
        flag3 = 1;
    }
    if (timer4 == 0){
        flag4 = 1;
    }
    if (timer5 == 0){
        flag5 = 1;
    }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*htim){
	if(htim->Instance == TIM2){
		button_reading();
		timerRun();
	}
}


void resetTimer(int timer){
	switch(timer){
	case 1:
		timer1 = 0; flag1 = 0;
		break;
	case 2:
		timer2 = 0; flag2 = 0;
		break;
	case 3:
		timer3 = 0; flag3 = 0;
		break;
	case 4:
		timer4 = 0; flag4 = 0;
        break;
    case 5:
        timer5 = 0; flag5 = 0;
		break;
	default:
		timer1 = 0;
		timer2 = 0;
		timer3 = 0;
		timer4 = 0;
        timer5 = 0;
		flag1 = 0;
		flag2 = 0;
		flag3 = 0;
		flag4 = 0;
        flag5 = 0;
		break;
	}
}


