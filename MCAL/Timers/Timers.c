/*
 * Timers.c
 *
 *  Created on: Mar 23, 2022
 *      Author: EL-talkhawy
 */
#include "Timers.h"

/***********************  Pointer to functions to be assigned to ISR ******************************/

static void (*Timer1_UP_Fptr)  (void) = NULLPTR ;
static void (*Timer1_CC_Fptr)  (void) = NULLPTR ;

static void (*Timer3_UP_Fptr)  (void) = NULLPTR ;
static void (*Timer3_CC_Fptr)  (void) = NULLPTR ;

void TIM1_Init()
{
	/* enable timer */
	SET_BIT(TIM1_CR1 , CEN) ;

	/* Edeged Aligned Mode */

	CLEAR_BIT(TIM1_CR1 , CMS0) ;
	CLEAR_BIT(TIM1_CR1 , CMS1) ;

	/* up counting */
	CLEAR_BIT(TIM1_CR1 , DIR) ;

	/* salve mode is disabled so i work to internal clock */

	CLEAR_BIT(TIM1_SMCR , SMS0) ;
	CLEAR_BIT(TIM1_SMCR , SMS1) ;
	CLEAR_BIT(TIM1_SMCR , SMS2) ;


}
void TIM1_TopValue (u16 value)
{
	TIM1_ARR = value ;
}
void TIM1_UpdateEvent_Source (UpdateEvent_Source_type updatesource)
{
	if(updatesource == ALL_EVENTS )
	{
		CLEAR_BIT(TIM1_CR1 , URS) ;
	}
	else
	{
		SET_BIT(TIM1_CR1 , URS) ;

	}
}

void TIM1_InputCaptureEnable (ICU_Edge_type edge)
{
	if(edge==RISING)
	{
		CLEAR_BIT(TIM1_CCER ,CC1P) ;
		CLEAR_BIT(TIM1_CCER ,CC1NP) ;
	}
	else if(edge==FALLING)
	{
		SET_BIT(TIM1_CCER ,CC1P) ;
		CLEAR_BIT(TIM1_CCER ,CC1NP) ;
	}
	else if(edge==BOTH)
	{
	     SET_BIT(TIM1_CCER ,CC1P) ;
		 SET_BIT(TIM1_CCER ,CC1NP) ;
	}

	/* CC1 channel is configured as input , IC1 is mapped on TI1 & TIMx_CCR1 register becomes read-only */
	SET_BIT(TIM1_CCMR1 , CC1S0) ;
	CLEAR_BIT(TIM1_CCMR1 , CC1S1) ;

	/* no filter & prescaler */

	/* capture compare enable */

	SET_BIT(TIM1_CCER , CC1E) ;

}
void TIM1_InputCaptureDisable (void)
 {
	CLEAR_BIT(TIM1_CCER , CC1E) ;
}

u16 TIM1_ICU_ReadRegister (void)
{
	return TIM1_CCR1 ;
}

void TIM1_ICU_InterruptEnable(void)
{
	SET_BIT(TIM1_DIER,CC1IE);
}
void TIM1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIM1_DIER,CC1IE);
}
void TIM1_Pwm_Freqeucy (u16 value)
{
	TIM1_ARR = value ;
}
void TIM1_Pwm_DutyCycle (u16 value)
{
	TIM1_CCR1 = value ;

}
void TIM1_PWM_Init (PWM_Mode_type mode)
{
	/* frequency determined by the value of the TIMx_ARR register
	 * a duty cycle determined by the value of the TIMx_CCRx register. */

	/* Preload register on TIMx_CCR1 enabled that has a duty cycle  */
	SET_BIT(TIM1_CCMR1 , OC1PE) ;
	SET_BIT(TIM1_CR1 , ARPE) ;

	/*before starting the counter, the user must initialize all the registers by setting the UG.*/

	/* polarity of output pin as active high */
	CLEAR_BIT(TIM1_CCER ,CC1P) ;
	SET_BIT(TIM1_EGR , CMOG) ;

	/* Enable OCx as output */
	SET_BIT(TIM1_CCER ,CC1E) ;
	SET_BIT(TIM1_CCER ,CC1NE) ;
	SET_BIT(TIM1_BDTR , MOE)  ;
	SET_BIT(TIM1_BDTR , OSSR)  ;

	switch (mode)
	{
	case NON_INVERTING :
		CLEAR_BIT(TIM1_CCMR1 , OC1M0) ;
	    SET_BIT(TIM1_CCMR1 , OC1M1) ;
		SET_BIT(TIM1_CCMR1 , OC1M2) ;
	case INVERTING :
		SET_BIT(TIM1_CCMR1 , OC1M0) ;
	    SET_BIT(TIM1_CCMR1 , OC1M1) ;
	    SET_BIT(TIM1_CCMR1 , OC1M2) ;
	}
}

/* you must call it before updating the register of pwm becuase these are preload register */
void TIM1_SW_UpdateEvent (void)
{
	/* Only counter overflow/underflow generates an update interrupt or DMA request */
	SET_BIT(TIM1_CR1 ,URS) ;

	SET_BIT(TIM1_EGR , UG) ;
}
void TIM1_CC_InterruptFlag_Clear (void)
{
	CLEAR_BIT(TIM1_SR , CC1IF) ;
}
void TIM1_UpdateInterruptFlag_Clear (void)
{
	CLEAR_BIT(TIM1_SR , UIF) ;
}
void TIM1_UpdateInterruptEnable (void)
{
	SET_BIT(TIM1_DIER , UIE) ;
}
void TIM1_UpdateInterruptDisable (void)
{
	CLEAR_BIT(TIM1_DIER , UIE) ;
}



void TIM1_EncoderMode ()
{
	/* the counter is counting on TI2 edges */
	SET_BIT(TIM1_SMCR , SMS0) ;
	SET_BIT(TIM1_SMCR , SMS1) ;
	SET_BIT(TIM1_SMCR , SMS2) ;

	/* working on rising edge  */
	CLEAR_BIT(TIM1_CCER , CC2P) ;
	CLEAR_BIT(TIM1_CCER , CC2NP) ;
}

void TIM1_UP_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_UP_Fptr=LocalFptr;
}

void TIM1_CC_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_CC_Fptr=LocalFptr;
}

ISR(TIM1_UP_IRQHandler)
{
	if(Timer1_UP_Fptr != NULLPTR)
	{
		Timer1_UP_Fptr() ;
	}

}

ISR(TIM1_CC_IRQHandler)
{
	if(Timer1_CC_Fptr != NULLPTR)
	{
		Timer1_CC_Fptr() ;
	}

}

/******************************************************************************************/


/* General purpose timer */

void TIM3_Init()
{
	/* enable timer */
	SET_BIT(TIM3_CR1 , CEN) ;

	/* Edeged Aligned Mode */
	CLEAR_BIT(TIM3_CR1 , CMS0) ;
	CLEAR_BIT(TIM3_CR1 , CMS1) ;

	/* up counting */
	CLEAR_BIT(TIM3_CR1 , DIR) ;

	/* salve mode is disabled so i work to internal clock */

	CLEAR_BIT(TIM3_SMCR , SMS0) ;
	CLEAR_BIT(TIM3_SMCR , SMS1) ;
	CLEAR_BIT(TIM3_SMCR , SMS2) ;
}
void TIM3_TopValue (u16 value)
{
	TIM3_ARR = value ;
}

void TIM3_SW_UpdateEvent (void)
{
	/* Only counter overflow /underflow generates an update interrupt or DMA request */
	SET_BIT(TIM3_CR1 , URS) ;
	SET_BIT(TIM3_EGR , UG) ;
}

 /* before starting the counter, the user must initialize all the registers by setting the UG .*/
void TIM3_UpdateInterruptFlag_Clear (void)
{
	CLEAR_BIT(TIM3_SR , UIF) ;
}

void TIM3_UpdateInterruptDisable (void)
{
	CLEAR_BIT(TIM3_DIER , UIE) ;
}

void TIM3_UpdateInterruptEnable (void)
{
	SET_BIT(TIM3_DIER , UIE) ;
}

void TIM3_UP_SetCallBack(void(*LocalFptr)(void))
{
	Timer3_UP_Fptr=LocalFptr;
}

void TIM3_CC_SetCallBack(void(*LocalFptr)(void))
{
	Timer3_CC_Fptr=LocalFptr;
}

ISR(TIM3_IRQHandler)
{
	if(Timer3_UP_Fptr != NULLPTR)
	{
		Timer3_UP_Fptr() ;
	}

}



void TIM3_PWM_Init (PWM_Mode_type mode)
{
	/* frequency determined by the value of the TIMx_ARR register
	 * a duty cycle determined by the value of the TIMx_CCRx register. */

	/* Preload register on TIMx_CCR1 enabled that has a duty cycle  */

	SET_BIT(TIM3_CCMR1 , OC1PE) ;
	SET_BIT(TIM3_CR1 , ARPE) ;

	/*before starting the counter, the user must initialize all the registers by setting the UG.*/

	/* polarity of output pin as active high */
	CLEAR_BIT(TIM1_CCER ,CC1P) ;

	/* Enable OCx as output */
	SET_BIT(TIM3_CCER ,CC1E) ;


	switch (mode)
	{
	case NON_INVERTING :
		CLEAR_BIT(TIM1_CCMR1 ,OC1M0) ;
	    SET_BIT(TIM1_CCMR1 , OC1M1) ;
		SET_BIT(TIM1_CCMR1 , OC1M2) ;
	case INVERTING :
		SET_BIT(TIM1_CCMR1 , OC1M0) ;
	    SET_BIT(TIM1_CCMR1 , OC1M1) ;
	    SET_BIT(TIM1_CCMR1 , OC1M2) ;
	}
}

/**********************************************************************************************/

/************************** Timer8  ********************************/

void TIM8_Init()
{
	/* enable timer */
	SET_BIT(TIM8_CR1 , CEN) ;

	/* Edeged Aligned Mode */

	CLEAR_BIT(TIM8_CR1 , CMS0) ;
	CLEAR_BIT(TIM8_CR1 , CMS1) ;

	/* up counting */
	CLEAR_BIT(TIM8_CR1 , DIR) ;

	/* salve mode is disabled so i work to internal clock */

	CLEAR_BIT(TIM8_SMCR , SMS0) ;
	CLEAR_BIT(TIM8_SMCR , SMS1) ;
	CLEAR_BIT(TIM8_SMCR , SMS2) ;


}
void TIM8_TopValue (u16 value)
{
	TIM8_ARR = value ;
}
void TIM8_PwmFreqeucy (u16 value)
{
	TIM8_ARR = value ;
}
void TIM8_Pwm_DutyCycle (u16 value)
{
	TIM8_CCR1 = value ;

}

void TIM8_UpdateEvent_Source (UpdateEvent_Source_type updatesource)
{
	if(updatesource == ALL_EVENTS )
	{
		CLEAR_BIT(TIM8_CR1 , URS) ;
	}
	else
	{
		SET_BIT(TIM8_CR1 , URS) ;

	}
}
/* you must call it before updating the register of pwm becuase these are preload register */
void TIM8_SW_UpdateEvent (void)
{
	/* Only counter overflow/underflow generates an update interrupt or DMA request */
	SET_BIT(TIM8_CR1 ,URS) ;
	SET_BIT(TIM8_EGR , UG) ;
}
void TIM8_PWM_Init (PWM_Mode_type mode)
{
	/* frequency determined by the value of the TIMx_ARR register
	 * a duty cycle determined by the value of the TIMx_CCRx register. */

	/* Preload register on TIMx_CCR1 enabled that has a duty cycle  */
	SET_BIT(TIM8_CCMR1 , OC1PE) ;
	SET_BIT(TIM8_CR1 , ARPE) ;

	/*before starting the counter, the user must initialize all the registers by setting the UG.*/

	/* polarity of output pin as active high */
	CLEAR_BIT(TIM8_CCER ,CC1P) ;

	/* Enable OCx as output */
	SET_BIT(TIM8_CCER ,CC1E) ;
	SET_BIT(TIM8_CCER ,CC1NE) ;
	SET_BIT(TIM8_BDTR , MOE)  ;
	SET_BIT(TIM8_BDTR , OSSR)  ;

	switch (mode)
	{
	case NON_INVERTING :
		CLEAR_BIT(TIM8_CCMR1 ,OC1M0) ;
	    SET_BIT(TIM8_CCMR1 , OC1M1) ;
		SET_BIT(TIM8_CCMR1 , OC1M2) ;
	case INVERTING :
		SET_BIT(TIM8_CCMR1 , OC1M0) ;
	    SET_BIT(TIM8_CCMR1 , OC1M1) ;
	    SET_BIT(TIM8_CCMR1 , OC1M2) ;
	}
}
