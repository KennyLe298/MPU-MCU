/*
 * timer.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Le Hoang
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_



#define TIMER_CYCLE 10

extern int flag1, flag2, flag3, flag4, flag5;
extern int timer1, timer2, timer3, timer4, timer5;

void setTimer1(int);
void setTimer2(int);
void setTimer3(int);
void setTimer4(int);
void setTimer5(int);
void resetTimer(int);

void timerRun();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim);

#endif /* INC_TIMER_H_ */
