/*
 * Scheduler.h
 *
 *  Created on: Jun 21, 2023
 *      Author: Fam Ayman
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "CortexMX_OS_Porting.h"
typedef enum
{
	NoError,
	Ready_Queue_Init_Problem,
	Task_Exceeded_StackSize,
}MYRTOS_ERRORID;
typedef struct {
	unsigned int Stack_Size;
	unsigned char priority;
	void (*p_TaskEntry)(void);// pointer to Task C Function
	unsigned char AutoStart ;
	unsigned int _S_PSP_Task; //Not Entered by the user
	unsigned int _E_PSP_Task; //Not Entered by the user
	unsigned int * CurrentPSP;//Not Entered by the user
	char TaskName[50];
	enum {
		Suspend,
		Waiting,
		Ready,
		Running
	}Task_State; //Not Entered by the user
	struct
	{
		enum {
			enable,
			disable

		}Blocking;
		unsigned int Ticks_Count;
	}TimingWaiting;

}Task_Ref;
MYRTOS_ERRORID MYRTOS_init();
MYRTOS_ERRORID MYRTOS_Create_Task(Task_Ref* Task);
void MYRTOS_ActivateTask(Task_Ref * Task);
void MYRTOS_TerminateTask(Task_Ref * Task);
void MYRTOS_Start_OS();
#endif /* INC_SCHEDULER_H_ */
