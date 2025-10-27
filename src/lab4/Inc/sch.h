/*
 * sch.h
 *
 *  Created on: Oct 14, 2025
 *      Author: GIGABYTE
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_

#include "stm32f1xx_hal.h"

#define SCH_MAX_TASKS 10

#define ERROR_SCH_INVALID_INDEX								101
#define ERROR_SCH_TOO_MANY_TASKS 							102
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 					103
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 	104
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 			105
#define ERROR_SCH_LOST_SLAVE 								106
#define ERROR_SCH_CAN_BUS_ERROR 							107
#define ERROR_I2C_WRITE_BYTE_AT24C64 						108
#define ERROR_SCH_NULL_POINTER								109

typedef struct
{
    void (*pTask)(void); // pointer to the task function
    uint32_t Delay;      // delay in ticks before task run
    uint32_t Period;     // interval between runs
    uint8_t RunMe;      
    uint32_t TaskID;    // task id
} sTask;

void SCH_Init(void);
uint8_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t TaskID);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Go_To_Sleep(void);

uint8_t SCH_Delete_All_Tasks(void);
void SystemClock_Config(void); 

uint32_t SCH_Get_Current_Tasks(void);
uint32_t SCH_Get_Error_Code(void);

uint32_t SCH_Get_Time(void);

#endif /* INC_SCH_H_ */
