/*
 * DIO_lcfg.c
 *
 *  Created on: Dec 8, 2021
 *      Author: EL-talkhawy
 */
#include "DIO_Interface.h"


 const DIO_Pin_Mode_Type PinsModeArray [TOTAL_PINS] = {

	INPUT       ,    /*port A pin 0 */
	GENERAL_PURPOSE_OUTPUT       ,    /*port A pin 1 */
	GENERAL_PURPOSE_OUTPUT       ,                       /*port A pin 2 */
	GENERAL_PURPOSE_OUTPUT  	    ,   /*port A pin 3 */
	GENERAL_PURPOSE_OUTPUT       ,    /*port A pin 4  */
	GENERAL_PURPOSE_OUTPUT         ,    /*port A pin 5  */
	GENERAL_PURPOSE_OUTPUT         ,    /*port A pin 6  */
	INPUT       ,    /*port A pin 7  */
	ALTERANTE_FUNCTION_OUTPUT 	    ,    /*port A pin 8  */
	INPUT       ,    /*port A pin 9  */
	GENERAL_PURPOSE_OUTPUT       ,    /*port A pin 10 */
	GENERAL_PURPOSE_OUTPUT     ,    /*port A pin 11 */
	GENERAL_PURPOSE_OUTPUT 	    ,    /*port A pin 12 */
	INPUT       ,    /*port A pin 13 */
	INPUT       ,    /*port A pin 14 */
	GENERAL_PURPOSE_OUTPUT       ,    /*port A pin 15 */

	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 0  */
	INPUT                   ,    /*port B pin 2  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 3  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 4  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 5  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 6  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 7  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 8  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 9  */
	INPUT                   ,    /*port B pin 10 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 11 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 12 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port B pin 13 */
	INPUT                   ,    /*port B pin 14 */
	GENERAL_PURPOSE_OUTPUT  ,   /*port B pin 15 */

	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 0  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 1  */
	INPUT                   ,    /*port C pin 2  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 3  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 4  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 5  */
	INPUT                   ,    /*port C pin 6  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 7  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 8  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 9  */
	INPUT                   ,    /*port D pin 10 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 11 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 12 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 13 */
	INPUT                   ,    /*port C pin 14 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port C pin 15 */

	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 0  */
	INPUT                   ,    /*port D pin 2  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 3  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 4  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 5  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 6  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 7  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 8  */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 9  */
	INPUT                   ,    /*port D pin 10 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 11 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 12 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 13 */
	INPUT                   ,    /*port D pin 14 */
	GENERAL_PURPOSE_OUTPUT  ,    /*port D pin 15 */


} ;

 const DIO_Input_PIN_Type PinsInputArray [TOTAL_PINS] = {

	INPUT_FLOATING           ,  /* port A pin 0 */
    INPUT_FLOATING   ,  /* port A pin 1 */
	INPUT_PULLDOWN   ,  /* port A pin 2 */
	INPUT_PULLUP     ,  /* port A pin 3 */

	ANALOG           ,  /* port A pin 4 */
	INPUT_FLOATING   ,  /* port A pin 5 */
    INPUT_PULLDOWN   ,  /* port A pin 6 */
    INPUT_PULLUP     ,  /* port A pin 7 */

	ANALOG           ,  /* port A pin 8 */
	INPUT_FLOATING   ,  /* port A pin 9 */
    INPUT_PULLDOWN   ,  /* port A pin 10 */
    INPUT_PULLUP     ,  /* port A pin 11 */

	ANALOG           ,  /* port A pin 12 */
	INPUT_FLOATING   ,  /* port A pin 13 */
    INPUT_PULLDOWN   ,  /* port A pin 14 */
	INPUT_PULLUP     ,  /* port A pin 15 */

	ANALOG           ,  /* port B pin 0 */
	INPUT_FLOATING   ,  /* port B pin 1 */
	INPUT_PULLDOWN   ,  /* port B pin 2 */
	INPUT_PULLUP     ,  /* port B pin 3 */

	ANALOG           ,  /* port B pin 4 */
	INPUT_FLOATING   ,  /* port B pin 5 */
	INPUT_PULLDOWN   ,  /* port B pin 6 */
	INPUT_PULLUP     ,  /* port B pin 7 */

	ANALOG           ,  /* port B pin 8 */
	INPUT_FLOATING   ,  /* port B pin 9 */
	INPUT_PULLDOWN   ,  /* port B pin 10 */
	INPUT_PULLUP     ,  /* port B pin 11 */

	ANALOG           ,  /* port B pin 12 */
	INPUT_FLOATING   ,  /* port B pin 13 */
	INPUT_PULLDOWN   ,  /* port B pin 14 */
	INPUT_PULLUP     ,  /* port B pin 15 */

    ANALOG           ,  /* port C pin 0 */
	INPUT_FLOATING   ,  /* port C pin 1 */
	INPUT_PULLDOWN   ,  /* port C pin 2 */
	INPUT_PULLUP     ,  /* port C pin 3 */

	ANALOG           ,  /* port C pin 4 */
	INPUT_FLOATING   ,  /* port C pin 5 */
	INPUT_PULLDOWN   ,  /* port C pin 6 */
	INPUT_PULLUP     ,  /* port C pin 7 */

	ANALOG           ,  /* port C pin 8 */
	INPUT_FLOATING   ,  /* port C pin 9 */
	INPUT_PULLDOWN   ,  /* port C pin 10 */
	INPUT_PULLUP     ,  /* port C pin 11 */

	ANALOG           ,  /* port C pin 12 */
	INPUT_FLOATING   ,  /* port C pin 13 */
	INPUT_PULLDOWN   ,  /* port C pin 14 */
	INPUT_PULLUP     ,  /* port C pin 15 */

	 ANALOG           ,  /* port D pin 0 */
	INPUT_FLOATING   ,   /* port D pin 1 */
	INPUT_PULLDOWN   ,   /* port D pin 2 */
	INPUT_PULLUP     ,   /* port D pin 3 */
	ANALOG           ,   /* port D pin 4 */
	INPUT_FLOATING   ,   /* port D pin 5 */
	INPUT_PULLDOWN   ,   /* port D pin 6 */
	INPUT_PULLUP     ,   /* port D pin 7 */

	ANALOG           ,    /* port D pin 8 */
	INPUT_FLOATING   ,    /* port D pin 9 */
	INPUT_PULLDOWN   ,    /* port D pin 10 */
	INPUT_PULLUP     ,    /* port D pin 11 */

	ANALOG           ,    /* port D pin 12 */
	INPUT_FLOATING   ,    /* port D pin 13 */
	INPUT_PULLDOWN   ,    /* port D pin 14 */
	INPUT_PULLUP     ,    /* port D pin 15 */


 } ;
 const DIO_Output_Pin_Type PinsOutputArray [TOTAL_PINS] = {

	GENERALPURPOSE_PUSHPULL ,    /* port A pin 0 */
	GENERALPURPOSE_PUSHPULL ,    /* port A pin 1 */
	GENERALPURPOSE_PUSHPULL ,         /* port A pin 2 */
	GENERALPURPOSE_PUSHPULL ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_PUSHPULL ,

	ALTERANTE_PUSHPULL  ,
	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_PUSHPULL  ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	GENERALPURPOSE_PUSHPULL  ,        /* port A pin 15 */

	GENERALPURPOSE_PUSHPULL ,    /* port B pin 0 */
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,        /* port B pin 15 */

	GENERALPURPOSE_PUSHPULL ,    /* port C pin 0 */
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,        /* port C pin 15 */

	GENERALPURPOSE_PUSHPULL ,    /* port D pin 0 */
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN ,

	GENERALPURPOSE_PUSHPULL ,
	GENERALPURPOSE_OPENDRAIN ,
	ALTERANTE_PUSHPULL ,
	ALTERANTE_OPENDRAIN         /* port D pin 15 */

 };




