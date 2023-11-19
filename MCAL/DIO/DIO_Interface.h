/*
 * DIO_Interface.h
 *
 *  Created on: Jun 5, 2022
 *      Author: EL-talkhawy
 */

#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

#include "MEM_MAP.h"
#include "StdTypes.h"
#include "Utils.h"

typedef enum
{
	GENERAL_PURPOSE_OUTPUT  ,
	ALTERANTE_FUNCTION_OUTPUT ,
	INPUT

}DIO_Pin_Mode_Type ;

typedef enum
{
	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN

}DIO_Output_Pin_Type ;

typedef enum
{
	ANALOG ,
	INPUT_FLOATING ,
	INPUT_PULLDOWN ,
	INPUT_PULLUP

}DIO_Input_PIN_Type ;
typedef enum
{
	LOW_ ,
	HIGH_

}DIO_PinVoltage_type;

typedef enum
{
	PA ,
	PB ,
	PC ,
	PD


}DIO_Port_type;

typedef enum
{
	PINA0  ,
	PINA1  ,
	PINA2  ,
	PINA3  ,
	PINA4  ,
	PINA5  ,
	PINA6  ,
	PINA7  ,
	PINA8  ,
	PINA9  ,
	PINA10 ,
	PINA11 ,
	PINA12 ,
	PINA13 ,
	PINA14 ,
	PINA15 ,

	PINB0  ,
	PINB1  ,
	PINB2  ,
	PINB3  ,
	PINB4  ,
	PINB5  ,
	PINB6  ,
	PINB7  ,
	PINB8  ,
	PINB9  ,
	PINB10 ,
	PINB11 ,
	PINB12 ,
	PINB13 ,
	PINB14 ,
	PINB15 ,

    PINC0  ,
    PINC1  ,
    PINC2  ,
    PINC3  ,
    PINC4  ,
    PINC5  ,
    PINC6  ,
    PINC7  ,
	PINC8  ,
	PINC9  ,
	PINC10 ,
	PINC11 ,
	PINC12 ,
	PINC13 ,
	PINC14 ,
	PINC15 ,

    PIND0  ,
	PIND1  ,
    PIND2  ,
    PIND3  ,
    PIND4  ,
    PIND5  ,
    PIND6  ,
    PIND7  ,
	PIND8  ,
	PIND9  ,
	PIND10 ,
	PIND11 ,
	PIND12 ,
	PIND13 ,
	PIND14 ,
	PIND15 ,


   TOTAL_PINS

}DIO_Pin_type;

extern const DIO_Pin_Mode_Type PinsModeArray     [TOTAL_PINS] ;
extern const DIO_Output_Pin_Type PinsOutputArray   [TOTAL_PINS] ;
extern const DIO_Input_PIN_Type PinsInputArray   [TOTAL_PINS] ;

void DIO_WritePIN (DIO_Pin_type pin ,DIO_PinVoltage_type volt) ;
void DIO_Init () ;


#endif /* MCAL_DIO_INTERFACE_H_ */
