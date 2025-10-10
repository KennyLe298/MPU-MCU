/*
 * traffic.c
 *
 *  Created on: Oct 2, 2025
 *      Author: GIGABYTE
 */

#include "main.h"
#include "timer.h"
#include "led_display.h"
#include "input_processing.h"

static int state = -1;
static int counter = 0;

void traffic_fsm(void) {
    switch(state) {
    case -1: // Initialization State
        state = 0;
        counter = green_duration;
        setTimer2(1000);
        break;
    
    case 0: // green hor, red ver
        setHorLed(GRN);
        setVerLed(RED);
        if(flag2) {
            flag2 = 0;
            counter--;
            if(counter <= 0) {
                counter = amber_duration;
                setTimer2(1000);
                state = 1;
            } 
            else setTimer2(1000);
            

        }
        updateSeg2Digits(counter, counter + amber_duration);
        break;

    case 1: // yel hor, red ver
        setHorLed(YEL);
        setVerLed(RED);
        if(flag2) {
            flag2 = 0;
            counter--;
            if(counter <= 0) {
                counter = green_duration;
                setTimer2(1000);
                state = 2;
            } else setTimer2(1000);
        }
        updateSeg2Digits(counter, counter);
        break;

    case 2: // red hor , green ver
        setHorLed(RED);
        setVerLed(GRN);
        if(flag2) {
            flag2 = 0; 
            counter--;
            if(counter <= 0) {
                counter = amber_duration;
                setTimer2(1000);
                state = 3;
            } else setTimer2(1000);
            
        }
        updateSeg2Digits(counter +  amber_duration, counter);
        break;

    case 3: // red hor, yel ver
        setHorLed(RED);
        setVerLed(YEL);
        if(flag2) {
            flag2 = 0;
            counter--;
            if(counter <= 0) {
                counter = green_duration;
                setTimer2(1000);
                state = 0;
            } else setTimer2(1000);

        }
        updateSeg2Digits(counter, counter);
        break;
    }
}


void traffic_reset(void) {
    state = -1;
}

void traffic_set_counter(int value) {
    counter = value;
}
