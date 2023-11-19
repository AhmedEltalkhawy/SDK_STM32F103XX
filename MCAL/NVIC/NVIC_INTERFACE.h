
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
/*********************************************************/
#include "MEM_MAP.h"

#define ISR(vector)         void vector (void)
#define CPSIE()  __asm__ __volatile__ ("CPSIE i" ::)
#define CPSID()  __asm__ __volatile__ ("CPSID i" ::)



typedef enum
{
	EXTI0 = 6 ,
	EXTI1 = 7 ,
	EXTI2 = 8 ,
	CAN1_RX0 = 20 ,
	CAN1_RX1 = 21 ,
	TIM1_UP = 25 ,   /* TIM1 Update  */
	TIM1_CC = 27 ,   /* TIM1 Capture Compare interrupt */
	TIM3_ = 29

}IRQN_Type ;

void NVIC_InterruptSetEnable (IRQN_Type  irqn) ;
void NVIC_InterruptClearEnable (IRQN_Type  irqn) ;
void NVIC_InterruptSetPending (IRQN_Type  irqn) ;
void NVIC_InterruptClearPending (IRQN_Type  irqn) ;
void NVIC_OpenGlobalInterrupt (void) ;
void NVIC_CloseGlobalInterrupt (void) ;

/*********************************************************/
#define NO_SUB_PRIORITY 0

/////////////////////////
#define PEND_SV        -6
#define SYSTICK        -5
////////////////////////////
#define SV_CALL        -4
/////////////////////////
#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1
/////////////////////////

//GROUP 3
//Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;

//u8 Priority   = ( Copy_u8SubPriority | (Copy_u8GroupPriority << 4) )  ;
// 0x100 Hex  ---> 256 Decimal
#define GROUP3     0x05FA0300//0 bit for sub & 4 bit For group   << 0
#define GROUP4     0x05FA0400//1 bit for sub & 3 bit For group   << 1
#define GROUP5     0x05FA0500//2 bit for sub & 2 bit For group   << 2
#define GROUP6     0x05FA0600//3 bit for sub & 1 bit For group   << 3
#define GROUP7     0x05FA0700//4 bit for sub & 0 bit For group   << 4

////////////////////////

//#define For Interrupt ID =  POsition In Vector Table
#define WWDG   0
#define EXT0   6
#define EXT1   7
#define DMA_ID 11
/////////////////////////



u8   MNVIC_u8GetActive          ( u8 Copy_u8INTID );

void MNVIC_VidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group );



#endif /* NVIC_INTERFACE_H_ */
