/*
 * EXTI.c
 *
 *  Created on: Dec 18, 2021
 *      Author: EL-talkhawy
 */
#include "EXTI.h"

static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;

void EXI_Enable(ExInterruptSource_type Interrupt)
{
	SET_BIT(EXTI_IMR , Interrupt) ;
}

void EXI_Disable(ExInterruptSource_type Interrupt)
{
	Clear_BIT(EXTI_IMR , Interrupt) ;
}
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Edge)
	{
	case RISING_EDGE :
		SET_BIT(EXTI_RTSR , Interrupt) ;
		CLEAR_BIT(EXTI_FTSR , Interrupt) ;
		break ;
	case FALLING_EDGE :
		CLEAR_BIT(EXTI_RTSR , Interrupt) ;
		SET_BIT(EXTI_FTSR , Interrupt) ;
		break ;
	case FALLING_RISING_EDGE :
		SET_BIT(EXTI_RTSR , Interrupt) ;
		SET_BIT(EXTI_FTSR , Interrupt) ;
		break ;
	}
}
void EXI_SW_Interrupt (ExInterruptSource_type Interrupt)
{
	SET_BIT(EXTI_SWIER , Interrupt) ;
}
void EXI_ClearPending (ExInterruptSource_type Interrupt)
{
	SET_BIT(EXTI_PR  , Interrupt) ;
}
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt)
	{
	case EX_INT0:
	    INT0_Fptr=LocalPtr;
	    break;
	case EX_INT1:
	    INT1_Fptr=LocalPtr;
	    break;
	case EX_INT2:
	    INT2_Fptr=LocalPtr;
	    break;
	}
}

ISR(EXTI0_IRQHandler)
{

	if (INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
}

ISR(EXTI1_IRQHandler)
{
	if (INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}

ISR(EXTI2_IRQHandler)
{
	if (INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
}
