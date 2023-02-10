/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : EXTI           ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define Low_LEVEL   		1
#define ON_CHANGE   		2
#define FALLING_EDGE		3
#define RISING_EDGE 		4

#define INT0				1
#define INT1                2

#define ENABLED  			1
#define DISABLED			2

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
//void EXTI_voidInt2Init(void);

/*Description: A function to set the required sense control of INT0 using post built Configuration
 * inputs : Copy_u8sense , Copy_u8INTPin
 * Options for sense:
 * 			1-Low_LEVEL
 * 			2-ON_CHANGE
 * 			3-FALLING_EDGE
 * 			4-RISING_EDGE
 * Options for Int :
 * 			1-INT0
 * 			2-INT1
 * Outputs:Error status with type u8
 *    */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense,u8 Copy_u8Int);
u8 EXTI_u8IntEnableControl(u8 Copy_u8Int,u8 Copy_u8IntControl);
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func) (void));


#endif
