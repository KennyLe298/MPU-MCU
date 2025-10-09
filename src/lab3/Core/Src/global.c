/*
 * global.c
 *
 *  Created on: Oct 8, 2025
 *      Author: GIGABYTE
 */

#include "global.h"

// 1 : normal, 2 : modify red, 3 : modify amber, 4 : modify green
int current_mode = 1;

// default duration
int red_duration = 5;
int amber_duration = 2;
int green_duration = 3;

int scan_state = 0;
