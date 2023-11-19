/*
 * CAN.c
 *
 *  Created on: Jul 10, 2022
 *      Author: EL-talkhawy
 */

#include "CAN.h"

static void (*CAN_FIFO0_Fptr)  (void) = NULLPTR ;
static void (*CAN_FIFO1_Fptr)  (void) = NULLPTR ;

int i , x  ;

void BXCAN_Init (void)
{
	/* Initialization mode   */

	SET_BIT(CAN_MCR ,INRQ) ;
	CLEAR_BIT(CAN_MCR ,SLEEP ) ;

	while(READ_BIT(CAN_MSR ,INAK) == 0) ;

	/* bit rate */

	CAN_BTR = 0x00110007 ;

	/* Priority driven by the identifier of the message */

	CLEAR_BIT(CAN_MCR , TXFP ) ;

	/* The CAN hardware will automatically retransmit the message */

	CLEAR_BIT(CAN_MCR , NART ) ;

	/* The Sleep mode is left on software request */

	CLEAR_BIT(CAN_MCR , AWUM ) ;

	/* Time Triggered Communication mode disabled. */

	CLEAR_BIT(CAN_MCR , TTCM ) ;


	/* reciever */

	/* overrun locked */
	SET_BIT(CAN_MCR , RFLM ) ;

	/* Initialization filter mode */

	SET_BIT(CAN_FMR , FINIT) ;

	/* deactivate all filter register */

	CAN_FA1R = 0x00000000 ;

	/* all the filters to CAN1 can be used. */

	CAN_FMR = 28 << 7 ;

	/* Single 32-bit scale for all filters */

	CAN_FS1R = 0xffffffff ;

	/* Identifier List mode. */

	CAN_FM1R = 0xffffffff ;

	/* filter FIFO assignment  */

	CAN_FFA1R = 0x0000ffff ;

	/* Active filter mode */

	CLEAR_BIT(CAN_FMR , FINIT) ;

	/* activate all filter register */

	CAN_FA1R = 0xffffffff ;

	/* Normal mode */

	CLEAR_BIT(CAN_MCR ,INRQ) ;
	while(READ_BIT(CAN_MSR ,INAK) == 1) ;


}

void BXCAN_Reset (void)
{
	SET_BIT(CAN_MCR ,RESET) ;

}
void BXCAN_TestMode(CAN_TestMode_t mode)
{
	/* Initialization mode   */

	SET_BIT(CAN_MCR ,INRQ) ;
	CLEAR_BIT(CAN_MCR ,SLEEP ) ;

	switch (mode)
	{
	case SILENT :
		SET_BIT(CAN_BTR , SILM) ;
		CLEAR_BIT(CAN_BTR , LPKM) ;
		break ;
	case LOOPBACK :
		CLEAR_BIT(CAN_BTR , SILM) ;
		SET_BIT(CAN_BTR , LPKM) ;
		break ;
	case LOOPBACK_SILENT :
 		SET_BIT(CAN_BTR , SILM) ;
		SET_BIT(CAN_BTR , LPKM) ;
		break ;

	}
	/* Normal mode */

	CLEAR_BIT(CAN_MCR ,INRQ) ;

}


void BXCAN_RecieveMassageIdentifier (u16 identifier , u8 filterbank , u8 registernum )
{
	i = filterbank ;
	x = registernum ;
    CAN_FiRx = identifier ;
    CLEARBIT(CAN_FiRx , 29) ;
    CLEARBIT(CAN_FiRx , 30) ;
    CLEARBIT(CAN_FiRx , 31) ;

}
void BXCAN_Transmit (u8* data, u8 mailbox_num , CAN_Frame_type frame_type , u16 identifier , u8 datalength  )
{
	int i =  0 ;

	switch (mailbox_num)
	{
	case 0 :
		while (READ_BIT(CAN_TSR , TME0)==0) ;
		/* standard identifier */
		CLEAR_BIT(CAN_TI0R , IDE)   ;

		CAN_TI0R = identifier << 20 ;
		CAN_TDT0R = datalength ;
		for (i = 0 ; i < datalength ; ++i)
		{
			CAN_DATA0 = data[i] << (i * 8) ;
		}

		switch (frame_type)
		{
		case DATA :
			CLEAR_BIT(CAN_TI0R , RTR) ;
			break ;
		case REMOTE :
			SET_BIT(CAN_TI0R , RTR) ;
			break ;
		}
		SET_BIT(CAN_TI0R , TXRQ) ;
		break ;
	case 1 :
		while (READ_BIT(CAN_TSR , TME1)==0) ;
		/* standard identifier */
		CLEAR_BIT(CAN_TI1R , IDE)   ;

		CAN_TI1R = identifier << 20 ;
		CAN_TDT1R = datalength ;
		for (i = 0 ; i < datalength ; ++i)
		{
			CAN_DATA1 = data[i] << (i * 8) ;
		}

		switch (frame_type)
		{
		case DATA :
			CLEAR_BIT(CAN_TI1R , RTR) ;
			break ;
		case REMOTE :
			SET_BIT(CAN_TI1R , RTR) ;
			break ;
		}
		SET_BIT(CAN_TI1R , TXRQ) ;
		break ;
	case 2 :
		while (READ_BIT(CAN_TSR , TME2)==0) ;
		/* standard identifier */
		CLEAR_BIT(CAN_TI2R , IDE)   ;

		CAN_TI2R = identifier << 20 ;
		CAN_TDT2R = datalength ;
		for (i = 0 ; i < datalength ; ++i)
		{
			CAN_DATA2 = data[i] << (i * 8) ;
		}

		switch (frame_type)
		{
		case DATA :
			CLEAR_BIT(CAN_TI2R , RTR) ;
			break ;
		case REMOTE :
			SET_BIT(CAN_TI2R , RTR) ;
			break ;
		}
		SET_BIT(CAN_TI2R , TXRQ) ;
		break ;

	}
}

void BXCAN_FIFO0_Recieve (u8* str)
{
	u8 datalen = CAN_RDT0R & (u32) 0x0000000f ;
	u8 i ;
	for (i=0 ; i < datalen ; ++i)
	{
		str[i] = CAN_RECDATA0 >> (i *8 ) ;
	}
	SET_BIT(CAN_RF0R , RFOM0) ;

}
void BXCAN_FIFO0_InterruptEnable (void)
{
	SET_BIT(CAN_IER ,FMPIE0) ;
}
void BXCAN_FIFO0_InterruptdDisable (void)
{
    CLEAR_BIT(CAN_IER ,FMPIE0) ;
}
void BXCAN_FIFO1_InterruptEnable (void)
{
    SET_BIT(CAN_IER ,FMPIE1) ;

}
void BXCAN_FIFO1_InterruptdDisable (void)
{
    CLEAR_BIT(CAN_IER ,FMPIE1) ;
}
void CAN_FIFO0_SetCallBack(void(*LocalFptr)(void))
{
	CAN_FIFO0_Fptr=LocalFptr;
}
void CAN_FIFO1_SetCallBack(void(*LocalFptr)(void))
{
	CAN_FIFO1_Fptr=LocalFptr;
}
ISR(CAN1_RX1_IRQHandler)
{
	if(CAN_FIFO0_Fptr != NULLPTR)
	{
		CAN_FIF0_Fptr() ;
	}

}
