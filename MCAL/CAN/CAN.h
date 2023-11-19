/*
 * CAN.h
 *
 *  Created on: Jul 10, 2022
 *      Author: EL-talkhawy
 */

#ifndef MCAL_CAN_H_
#define MCAL_CAN_H_

#include "DIO_Interface.h"
#include "StdTypes.h"
#include "Utils.h"
#include "MEM_MAP.h"

typedef enum
{
	SLEEP_MODE = 0 ,
	INITIALIZATION ,
	NORMAL

}CAN_Mode_t ;
typedef enum
{
	SILENT = 0 ,
	LOOPBACK ,
	LOOPBACK_SILENT

}CAN_TestMode_t ;

typedef enum
{
	STANDARD = 0 ,
	EXTENDED

}CAN_Identifier_type ;

typedef enum
{
	DATA = 0 ,
	REMOTE

}CAN_Frame_type ;



void BXCAN_Init (void)  ;
void BXCAN_Reset (void) ;
void BXCAN_TestMode(CAN_TestMode_t mode) ;
void BXCAN_Transmit (u8* data, u8 mailbox_num , CAN_Frame_type frame_type , u16 identifier , u8 datalength) ;
void BXCAN_FIFO0_Recieve (u8* str) ;
void BXCAN_FIFO0_InterruptEnable (void) ;
void BXCAN_FIFO0_InterruptdDisable (void) ;
void BXCAN_FIFO1_InterruptEnable (void) ;
void BXCAN_FIFO1_InterruptdDisable (void) ;
void CAN_FIFO0_SetCallBack(void(*LocalFptr)(void)) ;
void CAN_FIFO1_SetCallBack(void(*LocalFptr)(void)) ;




#endif /* MCAL_CAN_H_ */
