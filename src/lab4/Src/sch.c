/*
 * sch.c
 *
 *  Created on: Oct 14, 2025
 *      Author: GIGABYTE
 */

#include "sch.h"
#include "main.h"

volatile sTask SCH_tasks_G[SCH_MAX_TASKS];
static uint32_t currentTasks = 0;
static uint32_t ERROR_CODE_G = 0;
static volatile uint32_t timestamp = 0;

void SCH_Init(void)
{
    SCH_Delete_All_Tasks();
    currentTasks = 0;
    timestamp = 0;
    HAL_GPIO_WritePin(Led_1_GPIO_Port, Led_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Led_2_GPIO_Port, Led_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Led_3_GPIO_Port, Led_3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Led_4_GPIO_Port, Led_4_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Led_5_GPIO_Port, Led_5_Pin, GPIO_PIN_RESET);
}

uint8_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
    uint8_t index = 0;

    if (pFunction == 0) {
    	ERROR_CODE_G = ERROR_SCH_NULL_POINTER;
        return ERROR_CODE_G;
    }

    if (currentTasks >= SCH_MAX_TASKS) { //check number of tasks
        ERROR_CODE_G = ERROR_SCH_TOO_MANY_TASKS;
        return ERROR_CODE_G;
    }

    while ((SCH_tasks_G[index].pTask != 0) && (index < SCH_MAX_TASKS)) {
        index++;
    } //check for available slot

    if (index == SCH_MAX_TASKS) {
        	ERROR_CODE_G = ERROR_SCH_TOO_MANY_TASKS;
        	return ERROR_CODE_G;
        }
    SCH_tasks_G[index].pTask = pFunction;
    SCH_tasks_G[index].Delay = DELAY;
    SCH_tasks_G[index].Period = PERIOD;
    SCH_tasks_G[index].RunMe = 0;
    SCH_tasks_G[index].TaskID = index;
    
    currentTasks++;
    
    return index; 
}

uint8_t SCH_Delete_Task(uint32_t TaskID)
{
    if (TaskID >= SCH_MAX_TASKS) {
        ERROR_CODE_G = ERROR_SCH_INVALID_INDEX;
        return ERROR_CODE_G;
    }
    if (SCH_tasks_G[TaskID].pTask == 0) {
        ERROR_CODE_G = ERROR_SCH_INVALID_INDEX;
        return ERROR_CODE_G;
    }

    SCH_tasks_G[TaskID].pTask = 0;
    SCH_tasks_G[TaskID].Delay = 0;
    SCH_tasks_G[TaskID].Period = 0;
    SCH_tasks_G[TaskID].RunMe = 0;

    currentTasks--;
    
    return 0; 
}

uint8_t SCH_Delete_All_Tasks(void)
{
    uint8_t returnCode = 0;

    if (currentTasks == 0) {
        ERROR_CODE_G = ERROR_SCH_INVALID_INDEX;
        returnCode = ERROR_SCH_INVALID_INDEX; //error when no task to delete
    } 
    //reset everything
    for (uint8_t i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_tasks_G[i].pTask = 0;
        SCH_tasks_G[i].Delay = 0;
        SCH_tasks_G[i].Period = 0;
        SCH_tasks_G[i].RunMe = 0;
        SCH_tasks_G[i].TaskID = i;
    }
    currentTasks = 0;
    
    return returnCode;
}

void SCH_Update(void)
{
    timestamp++;
    for (uint8_t Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if (SCH_tasks_G[Index].pTask != 0) {
            
            if (SCH_tasks_G[Index].Delay > 0) {
                SCH_tasks_G[Index].Delay--;
            } else {
            	SCH_tasks_G[Index].RunMe++;
                if (SCH_tasks_G[Index].Period > 0) {
                   SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            }
        }
    }
}

void SCH_Dispatch_Tasks(void)
{
    for (uint8_t Index = 0; Index < SCH_MAX_TASKS; Index++) {
        if ((SCH_tasks_G[Index].RunMe > 0) && (SCH_tasks_G[Index].pTask != 0)) {
        	SCH_tasks_G[Index].RunMe--;
            (*SCH_tasks_G[Index].pTask)();
            // delete one_shot
            if (SCH_tasks_G[Index].Period == 0) {
                SCH_Delete_Task(Index);
            }
        }
    }
    // scheduler into idle mode 
    SCH_Go_To_Sleep();
}

void SCH_Go_To_Sleep(void)
{
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}

uint32_t SCH_Get_Current_Tasks(void)
{
    return currentTasks;
}

uint32_t SCH_Get_Error_Code(void)
{
    return ERROR_CODE_G;
}

 uint32_t SCH_Get_Time(void) {
     return timestamp;
 }
