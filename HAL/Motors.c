/*
 * Motors.c
 *
 * Created: 2/3/2021 2:14:23 PM
 *  Author: EL-talkhawy
 */ 
#include "Motors.h"

void MOTOR_CW (MOTOR_type motor) 
{
	switch(motor)
	{
		case MOTOR1 : 
		DIO_WritePIN(N1 , HIGH_) ;
		DIO_WritePIN(N2 , LOW_) ;
		break ; 
		case MOTOR2 :
		DIO_WritePIN(N3 , HIGH_) ;
		DIO_WritePIN(N4 , LOW_) ;
		break ;
	}
}

void MOTOR_CCW (MOTOR_type motor) 
{
	switch(motor)
	{
		case MOTOR1 :
		DIO_WritePIN(N1 , LOW_) ;
		DIO_WritePIN(N2 , HIGH_) ;
		break ;
		case MOTOR2 :
		DIO_WritePIN(N3 , LOW_) ;
		DIO_WritePIN(N4 , HIGH_) ;
		break ;
	}
	
}

void MOTOR_STOP (MOTOR_type motor) 
{
	switch(motor)
	{
		case MOTOR1 :
		DIO_WritePIN(N1 , LOW_) ;
		DIO_WritePIN(N2 , LOW_) ;
		break ;
		case MOTOR2 :
		DIO_WritePIN(N3 , LOW_) ;
		DIO_WritePIN(N4 , LOW_) ;
		break ;
	}
	
}



