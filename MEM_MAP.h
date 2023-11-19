/*
 * MEM_MAP.h
 *
 *  Created on: Dec 8, 2021
 *      Author: EL-talkhawy
 */

#ifndef MEM_MAP_H_
#define MEM_MAP_H_
#include "StdTypes.h"
/* DIO_Registers */

#define GPIOA_BASE_ADDRESS     0x40010800
#define GPIOB_BASE_ADDRESS     0x40010C00
#define GPIOC_BASE_ADDRESS     0x40011000
#define GPIOD_BASE_ADDRESS     0x40011400


#define GPIOA_CRL       (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH       (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR       (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR       (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR      (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR       (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR      (*(volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))

#define GPIOB_CRL       (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH       (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR       (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR       (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSRR      (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BSRR      (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR       (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCKR      (*(volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))

#define GPIOC_CRL       (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH       (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR       (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR       (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSRR      (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BSRR      (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR       (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCKR      (*(volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))

#define GPIOD_CRL       (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x00))
#define GPIOD_CRH       (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x04))
#define GPIOD_IDR       (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x08))
#define GPIOD_ODR       (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x0C))
#define GPIOD_BSRR      (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x10))
#define GPIOD_BSRR      (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x10))
#define GPIOD_BRR       (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x14))
#define GPIOD_LCKR      (*(volatile u32*)(GPIOD_BASE_ADDRESS + 0x18))


/************************************************************************/
/*	AFIO registers	*/

#define AFIO_BASE_ADDRESS     0x40010000

#define AFIO_EXTICR1    (*(volatile u32*)(AFIO_BASE_ADDRESS + 0x00))
#define AFIO_MAPR    (*(volatile u32*)(AFIO_BASE_ADDRESS + 0x04))



/*	Ext Int Event registers	*/

#define EXTI_BASE_ADDRESS     0x40010400

#define EXTI_IMR    (*(volatile u32*)(EXTI_BASE_ADDRESS + 0x00)) /* Interrupt mask register */
#define EXTI_EMR    (*(volatile u32*)(EXTI_BASE_ADDRESS + 0x04)) /* Event mask register */
#define EXTI_RTSR   (*(volatile u32*)(EXTI_BASE_ADDRESS + 0x08)) /* Rising trigger selection  */
#define EXTI_FTSR   (*(volatile u32*)(EXTI_BASE_ADDRESS + 0x0C)) /* Falling trigger selection */
#define EXTI_SWIER  (*(volatile u32*)(EXTI_BASE_ADDRESS + 0x10)) /* Software interrupt event */
#define EXTI_PR     (*(volatile u32*)(EXTI_BASE_ADDRESS + 0x14)) /* Pending register */

/*************************************************************************/

/*  Advanced Control Timer */

#define  TIM1_BASE_ADDRESS  0x40012C00

#define TIM1_CR1    (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x00))  /* TIM1 control register*/
#define TIM1_CR2    (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x04))  /* TIM1 control register*/
#define TIM1_SMCR   (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x08))  /* slave mode control */
#define TIM1_SR     (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x10))  /* TIM1 status register */
#define TIM1_DIER   (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x0C))  /* DMA/interrupt */
#define TIM1_EGR    (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x14))  /* TIM1 event generation */
#define TIM1_CCMR1  (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x18))  /* capture/compare mode  1 */
#define TIM1_CCER   (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x20))  /* capture/compare enable  */
#define TIM1_CNT    (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x24))  /* TIM1 counter has counter value  */
#define TIM1_PSC    (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x28))  /* TIM1 prescaler   */
#define TIM1_ARR    (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x2C))  /* TIM1 prescaler   */
#define TIM1_CCR1   (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x34))  /* TIM1 capture/compare 1 has the value of capture*/
#define TIM1_CCR2   (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x38))  /* TIM1 capture/compare register 2 */
#define TIM1_BDTR   (*(volatile u16*) (TIM1_BASE_ADDRESS + 0x44))  /* TIM1 break and dead-time register*/

/***********************************************************************************************/

#define  TIM8_BASE_ADDRESS  0x40013400

#define TIM8_CR1    (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x00))  /* TIM1 control register*/
#define TIM8_CR2    (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x04))  /* TIM1 control register*/
#define TIM8_SMCR   (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x08))  /* slave mode control */
#define TIM8_SR     (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x10))  /* TIM1 status register */
#define TIM8_DIER   (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x0C))  /* DMA/interrupt */
#define TIM8_EGR    (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x14))  /* TIM1 event generation */
#define TIM8_CCMR1  (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x18))  /* capture/compare mode  1 */
#define TIM8_CCER   (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x20))  /* capture/compare enable  */
#define TIM8_CNT    (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x24))  /* TIM1 counter has counter value  */
#define TIM8_PSC    (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x28))  /* TIM1 prescaler   */
#define TIM8_ARR    (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x2C))  /* TIM1 prescaler   */
#define TIM8_CCR1   (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x34))  /* TIM1 capture/compare 1 has the value of capture*/
#define TIM8_CCR2   (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x38))  /* TIM1 capture/compare register 2 */
#define TIM8_BDTR   (*(volatile u16*) (TIM8_BASE_ADDRESS + 0x44))  /* TIM1 break and dead-time register*/



/* TIM1_CR1 */

#define  ARPE    7  /* Auto-reload register preload enable */
#define  CMS1    6
#define  CMS0    5
#define  DIR     4  /* 0 up 1 down */
#define  URS     2
#define  UDIS    1
#define  CEN     0

/* TIM1_CCMR1 */

#define CC1S0    0
#define CC1S1    1
#define OC1PE    3
#define OC1M0    4
#define OC1M1    5
#define OC1M2    6


/* TIM1_CCER */

#define CC1E     0
#define CC1P     1
#define CC1NE    2
#define CC1NP    3
#define CC2P     5
#define CC2NP    7

/* TIM1_DIER */
#define UIE      0
#define CC1IE    1

/* TIM1_EGR */

#define UG  0
#define CMOG 5

/* TIM1_BDTR */

#define MOE     15
#define OSSR    11

/* TIM1_SMCR */

#define SMS0      0
#define SMS1      1
#define SMS2      2

/* TIM1_SR */
#define  UIF   0   /* It is cleared by software. */
#define  CC1IF 1  /* It is cleared by software or by reading the TIMx_CCR1 register */

/* General purpose timer*/

#define  TIM3_BASE_ADDRESS  0x40000400

#define TIM3_CR1    (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x00))  /* TIM1 control register*/
#define TIM3_SMCR   (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x08))  /* slave mode control */
#define TIM3_SR     (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x10))  /* TIM1 status register */
#define TIM3_DIER   (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x0C))  /* DMA/interrupt */
#define TIM3_EGR    (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x14))  /* TIM1 event generation */
#define TIM3_CCMR1  (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x18))  /* capture/compare mode  1 */
#define TIM3_CCER   (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x20))  /* capture/compare enable  */
#define TIM3_CNT    (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x24))  /* TIM1 counter has counter value  */
#define TIM3_PSC    (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x28))  /* TIM1 prescaler   */
#define TIM3_ARR    (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x2C))  /* TIM1 prescaler   */
#define TIM3_CCR1   (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x34))  /* TIM1 capture/compare 1 has the value of capture*/
#define TIM3_CCR2   (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x38))  /* TIM1 capture/compare register 2 */
#define TIM3_BDTR   (*(volatile u16*) (TIM3_BASE_ADDRESS + 0x44))  /* TIM1 break and dead-time register*/




/* NVIC REGISTER */

extern int iser , icer , ispr , icpr ;


#define NVIC_ISER  (*(volatile u32*) (0x100 + 0x04 * iser))  /* TIM1 control register*/
#define NVIC_ICER  (*(volatile u32*) (0x180 + 0x04 * icer))  /* TIM1 control register*/
#define NVIC_ISPR  (*(volatile u32*) (0x200 + 0x04 * ispr))  /* Interrupt set-pending register*/
#define NVIC_ICPR  (*(volatile u32*) (0x280 + 0x04 * icpr))  /* Interrupt clear-pending register*/
#define NVIC_STIR  (*(volatile u32*) (0x280))   /* Software trigger interrupt register*/

/**********************************************************************************************/

/* CAN REGISTER */


#define  BXCAN1_BASE_ADDRESS  0x40006400
#define  BXCAN2_BASE_ADDRESS  0x40006800


#define CAN_MCR  (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X00)) /* CAN master control register */
#define CAN_MSR  (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X04)) /* CAN master status register */
#define CAN_TSR  (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X08)) /* CAN transmit status register */
#define CAN_RF0R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X0C)) /* CAN receive FIFO 0 register */
#define CAN_RF1R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X10)) /* CAN receive FIFO 1 register */
#define CAN_BTR  (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X1C)) /* CAN master status register */
#define CAN_IER  (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X14)) /*CAN interrupt enable register */
#define CAN_ESR  (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X18)) /*CAN interrupt enable register */

#define CAN_TI0R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X180)) /* TX mailbox identifier register */
#define CAN_TI1R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X190)) /* TX mailbox identifier register */
#define CAN_TI2R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X1A0)) /* TX mailbox identifier register */

#define CAN_TDT0R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X184)) /* data length control */
#define CAN_TDT1R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X194)) /* data length control */
#define CAN_TDT2R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X1A4)) /* data length control */

#define CAN_TDL0R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X188)) /* mailbox data low register */
#define CAN_TDL1R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X198)) /* mailbox data low register */
#define CAN_TDL2R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X1A8)) /* mailbox data low register */

#define CAN_TDH0R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X18C)) /* mailbox data high register */
#define CAN_TDH1R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X19C)) /* mailbox data high register */
#define CAN_TDH2R (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X1AC)) /* mailbox data high register */

#define CAN_DATA0 (*(volatile u64*) (BXCAN1_BASE_ADDRESS + 0X188)) /* mailbox data low register */
 #define CAN_DATA1 (*(volatile u64*) (BXCAN1_BASE_ADDRESS + 0X198)) /* mailbox data low register */
#define CAN_DATA2 (*(volatile u64*) (BXCAN1_BASE_ADDRESS + 0X1A8)) /* mailbox data low register */

#define CAN_RDT0R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0x1B4)) /* FIFO mailbox data length control */
#define CAN_RDT1R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0x1C4)) /* FIFO mailbox data length control */
#define CAN_RDL0R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0x1B8)) /* FIFO mailbox data low register */
#define CAN_RDL1R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0x1C8)) /*FIFO mailbox data low register */
#define CAN_RDH0R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0x1BC)) /* FIFO mailbox data high register */
#define CAN_RDH1R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0x1CC)) /*FIFO mailbox data high register */

#define CAN_FFA1R   (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X214)) /* CAN filter master register */
#define CAN_FMR     (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X200)) /* CAN filter master register */
#define CAN_FM1R    (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X204)) /* CAN filter mode register */
#define CAN_FA1R    (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X21C)) /* CAN filter activation register */
#define CAN_FS1R    (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X20C)) /* CAN filter scale register */


#define CAN_identifier    (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X240)) /* CAN filter scale register */

extern int i , x ;

#define CAN_FiRx     (*(volatile u32*) (BXCAN1_BASE_ADDRESS + 0X240 + (i * x * 4) - 4)) /* CAN filter FIFO assignment register */

#define CAN_RECDATA0   (*(volatile u64*) (BXCAN1_BASE_ADDRESS + 0x1B8)) /* FIFO mailbox data low register */
#define CAN_RECDATA1   (*(volatile u64*) (BXCAN1_BASE_ADDRESS + 0x1C8)) /*FIFO mailbox data low register */


/*CAN_MCR BITS */

#define INRQ    0
#define SLEEP   1
#define TXFP    2
#define RFLM    3
#define NART    4
#define AWUM    5
#define ABOM    6
#define TTCM    7
#define RESET   15

/*CAN_MSR BITS */

#define INAK    0
#define SLAK    1

/* CAN_TSR BITS */

#define RQCP0   0
#define TXOK0   1
#define ALST0   2
#define TERR0   3
#define ABRQ0   7

#define RQCP1   8
#define TXOK1   9
#define ALST1   10
#define TERR1   11
#define ABRQ1   15

#define RQCP2   16
#define TXOK2   17
#define ALST2   18
#define TERR2   19
#define ABRQ2   23



#define TME0   26
#define TME1   27
#define TME2   28

/* CAN_BTR BITS */

#define SILM    31
#define LPKM    30

/*CAN_IER BITS */


#define FMPIE0   1
#define FMPIE1   4


/* CAN_TIxR BITS */

#define TXRQ    0
#define RTR     1
#define IDE     2

/* from bit 21 to 31 represent the identifier */


/* CAN_TDTxR   BITS */

/* from bit 0 to 3 represent data length */

/* CAN_FMR BITS */

#define FINIT    0

/* CAN_RF0R BITS */

#define RFOM0  5

/* CAN_RF1R BITS */

#define RFOM1  5














#endif /* MEM_MAP_H_ */
