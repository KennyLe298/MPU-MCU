/*
 * uart.h
 *
 *  Created on: Oct 29, 2025
 *      Author: GIGABYTE
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
#include "command_parser.h"

void uart_init(ADC_HandleTypeDef *hadc, UART_HandleTypeDef *huart);
void uart_fsm(void);



#endif /* INC_UART_H_ */
