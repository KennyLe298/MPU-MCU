/*
 * command_parser.c
 *
 *  Created on: Oct 29, 2025
 *      Author: GIGABYTE
 */

#include "command_parser.h"
#include <string.h>

//Variables
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buf_write_idx = 0;
uint8_t buf_read_idx = 0;
uint8_t buf_flag = 0;

uint8_t command_flag = 0;
CommandType command_data = CMD_NONE;

typedef enum{
    IDLE = 0,
    WAIT_CMD,
    WAIT_END
} ParserState;

static ParserState parser_state = IDLE;
static uint8_t command_buffer[MAX_BUFFER_SIZE]; 
static uint8_t cmd_idx = 0;

void command_parser_init(void)
{
    parser_state = IDLE;
    cmd_idx = 0;
    command_flag = 0;
    command_data = CMD_NONE;
    buf_write_idx = 0;
    buf_read_idx = 0;
    buf_flag = 0;
    memset(buffer, 0, MAX_BUFFER_SIZE);
    memset(command_buffer, 0, MAX_BUFFER_SIZE);
}

void command_parser_fsm(void){
    if(buf_read_idx == buf_write_idx){
        return;
    }

    uint8_t cur_char = buffer[buf_read_idx];
    buf_read_idx++;
    if(buf_read_idx >= MAX_BUFFER_SIZE){
        buf_read_idx = 0;
    }

    switch(parser_state){
        case IDLE:
        if(cur_char == '!'){
            parser_state = WAIT_CMD;
            cmd_idx = 0;
            memset(command_buffer, 0, MAX_BUFFER_SIZE);
        }
        break;

        case WAIT_CMD:
        if(cur_char == '#'){
            command_buffer[cmd_idx] = '\0';
            if(strcmp((char*)command_buffer, "RST") == 0){
                command_data = CMD_RST;
                command_flag = 1;

            }
            else if(strcmp((char*)command_buffer, "OK") == 0){
                command_data = CMD_OK;
                command_flag = 1;

            }
            else{
                command_data = CMD_NONE;
                command_flag = 0;
            }

            parser_state = IDLE;
            cmd_idx = 0;
        }
        else if(cur_char != '!'){
            if(cmd_idx < MAX_BUFFER_SIZE - 1){
                command_buffer[cmd_idx++] = cur_char;
            }
            else {
                parser_state = IDLE;
                cmd_idx = 0;
            }
        }
        break;
        default:
        parser_state = IDLE;
        break;
    }
}
