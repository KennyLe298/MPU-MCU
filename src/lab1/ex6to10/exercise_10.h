/*
 * exercise_10.h
 *
 *  Created on: Sep 10, 2025
 *      Author: Chu Le Hoang
 */

#ifndef SRC_EXERCISE_10_H_
#define SRC_EXERCISE_10_H_

#include "main.h"

#include "exercise_6.h"
#include "exercise_7.h"
#include "exercise_8.h"
#include "exercise_9.h"

//global time variables
int sec = 0;
int min = 0;
int hrs = 0;

// clock simulation
void Clock(void) {
    ++sec;
    if (sec > 59) {
        sec = 0;
        ++min;
    }
    if (min > 59) {
        min = 0;
        ++hrs;
    }
    if (hrs > 23) {
        hrs = 0;
    }
    clearAllClock();

    int s_idx = sec / 5;    // map 0–59 sec → 0–11
    int m_idx = min / 5;    // map 0–59 min → 0–11
    int h_idx = hrs % 12;   // map 0–23 hr → 0–11 (0 = h12)

    setNumberOnClock(s_idx);
    setNumberOnClock(m_idx);
    setNumberOnClock(h_idx);
}
#endif /* SRC_EXERCISE_10_H_ */
