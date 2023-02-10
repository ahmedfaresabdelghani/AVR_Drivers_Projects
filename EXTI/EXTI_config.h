/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : EXTI           ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options:
 * 			1-Low_LEVEL
 * 			2-ON_CHANGE
 * 			3-FALLING_EDGE
 * 			4-RISING_EDGE
 */
#define INT0_SENSE             FALLING_EDGE

/*Options:
 * 			1-ENABLED
 * 			2-DISABLED
 */
#define INT0_INITIAL_STATE		ENABLED

#endif
