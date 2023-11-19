/*
 * EXTI.h
 *
 *  Created on: Dec 18, 2021
 *      Author: EL-talkhawy
 */

#ifndef MCAL_EXTI_H_
#define MCAL_EXTI_H_

#include "StdTypes.h"
#include "Utils.h"
#include "MEM_MAP.h"
#include "NVIC_INTERFACE.h"

typedef enum
{
	RISING_EDGE  ,
	FALLING_EDGE ,
	FALLING_RISING_EDGE

}TriggerEdge_type;

typedef enum
{
	EX_INT0=0 ,
	EX_INT1   ,
	EX_INT2   ,
	EX_INT3   ,
	EX_INT4   ,
	EX_INT5   ,
	EX_INT6   ,
	EX_INT7   ,
	EX_INT8   ,
	EX_INT9   ,
	EX_INT10  ,
	EX_INT11  ,
	EX_INT12  ,
	EX_INT13  ,
	EX_INT14  ,
	EX_INT15  ,
	EX_INT16  ,
	EX_INT17  ,
	EX_INT18

}ExInterruptSource_type;

typedef enum
{
	EX_EVENT0=0  ,
	EX_EVENT1    ,
	EX_EVENT2    ,
	EX_EVENT3    ,
	EX_EVENT4    ,
	EX_EVENT5    ,
	EX_EVENT6    ,
	EX_EVENT7    ,
	EX_EVENT8    ,
	EX_EVENT9    ,
	EX_EVENT10   ,
	EX_EVENT11   ,
	EX_EVENT12   ,
	EX_EVENT13   ,
	EX_EVENT14   ,
	EX_EVENT15   ,
	EX_EVENT16   ,
	EX_EVENT17   ,
	EX_EVENT18


}ExEventSource_type;


void EXI_Enable(ExInterruptSource_type Interrupt)  ;
void EXI_Disable(ExInterruptSource_type Interrupt) ;
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge) ;
void EXI_SW_Interrupt (ExInterruptSource_type Interrupt) ;
void EXI_ClearPending (ExInterruptSource_type Interrupt) ;
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void)) ;






#endif /* MCAL_EXTI_H_ */
