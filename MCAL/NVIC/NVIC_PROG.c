


#include"NVIC_INTERFACE.h"
#include"NVIC_REG.h"

void NVIC_OpenGlobalInterrupt (void)
{
	CPSIE() ;
}
void NVIC_CloseGlobalInterrupt (void)
{
	CPSID() ;
}
void NVIC_InterruptSetEnable ( IRQN_Type  irqn ){

	MNVIC->ISER[ irqn / 32 ] = 1 << (irqn % 32 ) ;

}

void NVIC_InterruptClearEnable ( IRQN_Type  irqn ){

	MNVIC->ICER[ irqn / 32 ] = 1 << ( irqn % 32 ) ;

}


void NVIC_InterruptSetPending (IRQN_Type  irqn ){

	MNVIC->ISPR[ irqn / 32 ] = 1 << ( irqn % 32 ) ;


}

void NVIC_InterruptClearPending ( IRQN_Type  irqn ){

	MNVIC->ICPR[ irqn / 32 ] = 1 << ( irqn % 32 ) ;

}


u8   MNVIC_u8GetActive( u8 Copy_u8INTID ){

	u8 LOC_u8Active = GET_BIT( (MNVIC->IAPR[ Copy_u8INTID/32 ]) , ( Copy_u8INTID % 32 ) );
	return LOC_u8Active ;

}


void MNVIC_VidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group ){

	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;
	//Core Peripheral
	if( Copy_u8INTID < 0  ){

		if( Copy_u8INTID == MEMORY_MANAGE || Copy_u8INTID == BUS_FAULT || Copy_u8INTID == USAGE_FAULT ){

			Copy_u8INTID += 3;
			SCB->SHPR1 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}
		else if ( Copy_u8INTID == SV_CALL ){

			Copy_u8INTID += 7;
			SCB->SHPR2 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}
		else if( Copy_u8INTID == PEND_SV || Copy_u8INTID == SYSTICK ){

			Copy_u8INTID += 8;

			SCB->SHPR3 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}

	}
    //External Peripheral
	else if( Copy_u8INTID >= 0 ){

		MNVIC->IPR[ Copy_u8INTID ] = Priority << 4 ;

	}

	SCB->AIRCR = Copy_u8Group ;

}

