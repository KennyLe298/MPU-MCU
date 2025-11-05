/*
 * uart.c
 *
 *  Created on: Oct 29, 2025
 *      Author: GIGABYTE
 */

#include "uart.h"
#include "stdio.h"

typedef enum{
    COMM_IDLE = 0,
    COMM_WAIT_RST,
    COMM_SEND_ADC,
    COMM_WAIT_OK
} CommState;

static CommState comm_state = COMM_IDLE;
static ADC_HandleTypeDef* adc_handle;
static UART_HandleTypeDef* uart_handle;
static uint32_t adc_value = 0;
static uint32_t timeout_counter = 0;
static uint32_t last_tick = 0;

#define TIMEOUT_MS 3000
#define RESPONSE_FORMAT "!ADC=%lu#\r\n"

void uart_init(ADC_HandleTypeDef *hadc, UART_HandleTypeDef *huart) {
    comm_state = COMM_IDLE;
    adc_handle = hadc;
    uart_handle = huart;
    adc_value = 0;
    timeout_counter = 0;
    last_tick = HAL_GetTick();
    HAL_ADC_Start(adc_handle);
}

static void send_adc_response(void){
    char response[50];
    int len = sprintf(response, RESPONSE_FORMAT, adc_value);
    HAL_UART_Transmit(uart_handle, (uint8_t*)response, len, 1000);
}

void uart_fsm(void){
    uint32_t cur_tick = HAL_GetTick();
    
    switch(comm_state){
        case COMM_IDLE:
        if(command_flag == 1 && command_data == CMD_RST){
            command_flag = 0;
            comm_state = COMM_SEND_ADC;
        }
        break;

        case COMM_SEND_ADC:
        adc_value = HAL_ADC_GetValue(adc_handle);
        send_adc_response();
        last_tick = HAL_GetTick();
        comm_state = COMM_WAIT_OK;
        break;

        case COMM_WAIT_OK:
        if(command_flag == 1 && command_data == CMD_OK){
            command_flag = 0;
            comm_state = COMM_IDLE;
        }
        else if((cur_tick - last_tick) >= TIMEOUT_MS){
            send_adc_response();
            last_tick = HAL_GetTick();
        }
        else if(command_flag == 1 && command_data == CMD_RST){
            command_flag = 0;
            comm_state = COMM_SEND_ADC;
        }
        break;
        default:
        comm_state = COMM_IDLE;
        break;
    }
}
