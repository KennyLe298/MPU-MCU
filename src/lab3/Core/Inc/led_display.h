/*
 * input_display.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Le Hoang
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

extern int horstate;
extern int verstate;

void setHorLed(int);
void setVerLed(int);

extern int segment_buffer[4];

void set7segHor(int);
void set7segVer(int);
void scan7seg(int);

void updateSeg(int, int, int, int);
void updateSeg2Digits(int, int);


#endif /* INC_LED_DISPLAY_H_ */
