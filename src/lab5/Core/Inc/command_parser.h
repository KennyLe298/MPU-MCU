/*
 * command_parser.h
 *
 *  Created on: Oct 29, 2025
 *      Author: GIGABYTE
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_
#include "main.h"

#define MAX_BUFFER_SIZE 30

typedef enum{
    CMD_NONE = 0,
    CMD_RST,
    CMD_OK
} CommandType;

//Variables
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buf_write_idx;
extern uint8_t buf_read_idx;
extern uint8_t buf_flag;
extern uint8_t command_flag;
extern CommandType command_data;

void command_parser_init(void);
void command_parser_fsm(void);



#endif /* INC_COMMAND_PARSER_H_ */
