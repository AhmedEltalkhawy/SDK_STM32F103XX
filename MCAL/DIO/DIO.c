/*
 * DIO.c
 *
 *  Created on: Jun 5, 2022
 *      Author: EL-talkhawy
 */
#include "DIO_Interface.h"

static void DIO_InitPin (DIO_Pin_Mode_Type pinmode , DIO_Output_Pin_Type outpin , DIO_Pin_type pin , DIO_Input_PIN_Type input_pin)
{
	u8 pnum = pin % 16 ;
	DIO_Port_type port = pin / 16 ;
	u8 tpnum ;
	if(pnum <= 7)
	{
		tpnum = pnum * 4 ;
	}
	else
	{
		tpnum = pnum - 8 ;
		tpnum = tpnum * 4 ;
	}

	switch (port)
	{
	case PA :
		switch(pinmode)
		{
		case GENERAL_PURPOSE_OUTPUT :
			if (pnum <= 7)
			{
				SET_BIT(GPIOA_CRL , tpnum) ;
				SET_BIT(GPIOA_CRL , tpnum + 1) ;
			}
			else
			{
				SET_BIT(GPIOA_CRH , tpnum) ;
				SET_BIT(GPIOA_CRH , tpnum + 1) ;
			}
			switch (outpin)
			{
			case GENERALPURPOSE_PUSHPULL :
				if (pnum <= 7)
				{
				     CLEAR_BIT(GPIOA_CRL , tpnum + 2) ;
					 CLEAR_BIT(GPIOA_CRL , tpnum + 3) ;
				}
				else
				{
					CLEAR_BIT(GPIOA_CRH , tpnum + 2) ;
					CLEAR_BIT(GPIOA_CRH , tpnum + 3) ;
				}
				break ;
			case GENERALPURPOSE_OPENDRAIN :
				if (pnum <= 7)
				{
					 SET_BIT(GPIOA_CRL , tpnum + 2) ;
					 CLEAR_BIT(GPIOA_CRL , tpnum + 3) ;
				}
				else
				{
					SET_BIT(GPIOA_CRH , tpnum + 2) ;
					CLEAR_BIT(GPIOA_CRH , tpnum + 3) ;
				}
				break ;

	         }
			break ;
			case ALTERANTE_FUNCTION_OUTPUT :
				if (pnum <= 7)
				{
					SET_BIT(GPIOA_CRL , tpnum) ;
					SET_BIT(GPIOA_CRL , tpnum + 1) ;
				}
				else
				{
					SET_BIT(GPIOA_CRH , tpnum) ;
					SET_BIT(GPIOA_CRH , tpnum + 1) ;
				}
				switch (outpin)
				{
				case ALTERANTE_PUSHPULL :
					if (pnum <= 7)
					{
						 CLEAR_BIT(GPIOA_CRL , tpnum + 2) ;
						 SET_BIT(GPIOA_CRL , tpnum + 3) ;
					}
					else
					{
						CLEAR_BIT(GPIOA_CRH , tpnum + 2) ;
						SET_BIT(GPIOA_CRH , tpnum + 3) ;
					}
					break ;
				case ALTERANTE_OPENDRAIN :
					if (pnum <= 7)
					{
						 SET_BIT(GPIOA_CRL , tpnum + 2) ;
						 SET_BIT(GPIOA_CRL , tpnum + 3) ;
					}
					else
					{
						SET_BIT(GPIOA_CRH , tpnum + 2) ;
						SET_BIT(GPIOA_CRH , tpnum + 3) ;
					}
					break ;

				 }
				break ;
				case INPUT :
					if (pnum <= 7)
					{
						CLEAR_BIT(GPIOA_CRL , tpnum) ;
						CLEAR_BIT(GPIOA_CRL , tpnum + 1) ;
					}
					else
					{
						CLEAR_BIT(GPIOA_CRH , tpnum) ;
						CLEAR_BIT(GPIOA_CRH , tpnum + 1) ;
					}
					switch(input_pin)
					{
					case ANALOG :
						if (pnum <= 7)
						{
							 CLEAR_BIT(GPIOA_CRL , tpnum + 2) ;
							 CLEAR_BIT(GPIOA_CRL , tpnum + 3) ;
						}
						else
						{
							CLEAR_BIT(GPIOA_CRH , tpnum + 2) ;
							CLEAR_BIT(GPIOA_CRH , tpnum + 3) ;
						}
						break ;
					case INPUT_FLOATING:
						if (pnum <= 7)
						{
							 SET_BIT(GPIOA_CRL , tpnum + 2) ;
							 CLEAR_BIT(GPIOA_CRL , tpnum + 3) ;
						}
						else
						{
							SET_BIT(GPIOA_CRH , tpnum + 2) ;
							CLEAR_BIT(GPIOA_CRH , tpnum + 3) ;
						}
						break ;
					case INPUT_PULLDOWN:
						CLEAR_BIT(GPIOA_ODR,pnum);
						if (pnum >= 7)
						{
							 CLEAR_BIT(GPIOA_CRL , tpnum + 2) ;
							 SET_BIT(GPIOA_CRL , tpnum + 3) ;

						}
						else
						{
							CLEAR_BIT(GPIOA_CRH , tpnum + 2) ;
							SET_BIT(GPIOA_CRH , tpnum + 3) ;
						}
						break ;
					case INPUT_PULLUP:
						SET_BIT(GPIOA_ODR,pnum);
						if (pnum <= 7)
						{
							 CLEAR_BIT(GPIOA_CRL , tpnum + 2) ;
							 SET_BIT(GPIOA_CRL , tpnum + 3) ;

						}
						else
						{
							CLEAR_BIT(GPIOA_CRH , tpnum + 2) ;
							SET_BIT(GPIOA_CRH , tpnum + 3) ;
						}
						break ;
					}
					break;
		}
		break;
		//case PB :


	}
}

void DIO_WritePIN (DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
	u8 pnum = pin % 16 ;
	DIO_Port_type port = pin / 16 ;
	if(volt == HIGH_)
	{
		switch (port)
		{
		case PA :
			SET_BIT(GPIOA_ODR , pnum) ;
			break ;
		case PB :
			SET_BIT(GPIOB_ODR , pnum) ;
			break ;
		case PC :
			SET_BIT(GPIOC_ODR , pnum) ;
			break ;
		case PD :
			SET_BIT(GPIOD_ODR , pnum) ;
			break ;

		}
	}
	else
	{
		switch(port)
		{
		case PA :
			CLEAR_BIT(GPIOA_ODR , pnum) ;
			break ;
		case PB :
			CLEAR_BIT(GPIOB_ODR , pnum) ;
			break ;
		case PC :
			CLEAR_BIT(GPIOC_ODR , pnum) ;
			break ;
		case PD :
			CLEAR_BIT(GPIOD_ODR , pnum) ;
			break ;

		}
	}

}
DIO_PinVoltage_type DIO_ReadPIN (DIO_Pin_type pin)
{
	u8 pnum = pin %16 ;
	DIO_Port_type port = pin /16 ;

	DIO_PinVoltage_type volt = LOW_ ;
	switch(port)
	{
	   case PA :
		volt = READ_BIT(GPIOA_IDR , pnum) ;
		break ;
		case PB :
		volt = READ_BIT(GPIOB_IDR , pnum) ;
		break ;
		case PC :
		volt = READ_BIT(GPIOC_IDR , pnum) ;
		break ;
		case PD :
		volt = READ_BIT(GPIOD_IDR , pnum) ;
		break ;

	}
	return volt ;
}

void DIO_WritePort (DIO_Port_type port , u16 value)
{
	switch(port)
	{
		case PA :
		GPIOA_ODR= value ;
		break ;
		case PB :
		GPIOB_ODR= value ;
		break ;
		case PC :
		GPIOC_ODR = value ;
		break ;
		case PD :
		GPIOD_ODR = value ;
		break ;
	}
}

void DIO_TogglePIN (DIO_Pin_type pin)
{
	u8 pnum = pin %16 ;
	DIO_Port_type port = pin /16 ;
	switch(port)
	{
		case PA :
		TOGGLE_BIT(GPIOA_ODR , pnum) ;
		break ;
		case PB :
		TOGGLE_BIT(GPIOB_ODR  , pnum) ;
		break ;
		case PC :
	   TOGGLE_BIT(GPIOC_ODR  , pnum) ;
		break ;
		case PD :
		TOGGLE_BIT(GPIOD_ODR  , pnum) ;
		break ;

	}


}


void DIO_Init ()
{
	u8 i ;
	for (i= PINA0 ; i < TOTAL_PINS ; ++i)
	{
		DIO_InitPin(PinsModeArray[i] ,PinsOutputArray[i] , i , PinsInputArray[i]) ;
    }
}
