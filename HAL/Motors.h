/*
 * Motors.h
 *
 * Created: 2/3/2021 2:13:52 PM
 *  Author: EL-talkhawy
 */ 



#ifndef MOTORS_H_
#define MOTORS_H_

#include "MCAL/DIO_Interface.h"


#define  N1 PINA1
#define  N2 PINA2


#define  N3 PINA4
#define  N4 PINA5



typedef enum 
{
	MOTOR1 , 
	MOTOR2 , 
	MOTOR3 , 
	MOTOR4 
	
}MOTOR_type;

	
	


/*************************************** DC MOTOR ************************************/

void MOTOR_CW (MOTOR_type motor) ;

void MOTOR_CCW (MOTOR_type motor) ;

void MOTOR_STOP (MOTOR_type motor) ;

/**************************************************************************************/






#endif /* MOTORS_H_ */
