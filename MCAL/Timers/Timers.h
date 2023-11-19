/*
 * TIimers.h
 *
 *  Created on: Mar 23, 2022
 *      Author: EL-talkhawy
 */

#ifndef MCAL_TIMERS_H_
#define MCAL_TIMERS_H_

#include "StdTypes.h"
#include "Utils.h"
#include "MEM_MAP.h"
#include "NVIC_INTERFACE.h"

typedef enum
{
	ONLY_OVERUNDERFLOW ,
	ALL_EVENTS
}UpdateEvent_Source_type ;

typedef enum
{
	RISING,
	FALLING,
	BOTH
}ICU_Edge_type;

typedef enum
{
	NON_INVERTING, /* pwm mode 1 in up counter */
	INVERTING

}PWM_Mode_type;

void TIM1_Init(void) ;
void TIM1_UpdateEvent_Source (UpdateEvent_Source_type updatesource) ;
void TIM1_TopValue (u16 value) ;
void TIM1_UpdateInterruptFlag_Clear (void) ;
void TIM1_InputCaptureEnable (ICU_Edge_type edge) ;
void TIM1_InputCaptureDisable (void) ;
u16  TIM1_ICU_ReadRegister (void) ;
void TIM1_ICU_InterruptEnable(void) ;
void TIM1_ICU_InterruptDisable(void) ;
void TIM1_Pwm_Freqeucy (u16 value) ;
void TIM1_Pwm_DutyCycle (u16 value) ;
void TIM1_PWM_Init (PWM_Mode_type mode) ;
void TIM1_SW_UpdateEvent (void) ;
void TIM1_UpdateInterruptEnable (void) ;
void TIM1_UpdateInterruptDisable (void) ;
void TIM1_UP_SetCallBack (void(*LocalFptr)(void)) ;
void TIM1_CC_SetCallBack (void(*LocalFptr)(void))  ;
void TIM1_CC_InterruptFlag_Clear (void) ;


void TIM3_Init(void) ;
void TIM3_SW_UpdateEvent (void) ;
void TIM3_UpdateInterruptEnable (void) ;
void TIM3_TopValue (u16 value) ;
void TIM3_UpdateInterruptFlag_Clear (void) ;
void TIM3_UpdateInterruptDisable (void) ;
void TIM3_UP_SetCallBack(void(*LocalFptr)(void)) ;
void TIM3_CC_SetCallBack(void(*LocalFptr)(void)) ;




void TIM3_PWM_Init (PWM_Mode_type mode) ;


void TIM8_Init() ;
void TIM8_TopValue (u16 value) ;
void TIM8_Pwm_Freqeucy (u16 value) ;
void TIM8_Pwm_DutyCycle (u16 value) ;



void TIM8_UpdateEvent_Source (UpdateEvent_Source_type updatesource) ;
void TIM8_SW_UpdateEvent (void) ;
void TIM8_PWM_Init (PWM_Mode_type mode) ;








#endif /* MCAL_TIMERS_H_ */
