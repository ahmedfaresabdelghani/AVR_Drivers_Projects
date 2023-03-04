/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********     Layer : MCAL         ************/
/***********     SWC : TIMER          ************/
/***********     Version : 1.00       ************/
/*************************************************/
/*************************************************/


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_RISING_EDGE 		1
#define ICU_FALLING_EDGE 		2
void TIMER0_voidInit(void);

void TIMER1_voidInit(void);

void TIMER1_voidSetICR(u16 Copy_u16TopValue);

void TIMER1_voidSetChannelACompareMatch(u16 Copy_u16TopValue);

void TIMER1_voidSetChannelBCompareMatch(u16 Copy_u16TopValue);

u16 TIMER1_voidReadTimerValue(void);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

u8 TIMER0_u8SetCallBack(void(* Copy_pvCallBackFunc)(void));

void TIMER0_voidSetCompMatchValue(u8 Copy_u8value);

void ICU_voidInit(void);

u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge);

void ICU_voidDisableInterrupt(void);

void ICU_voidEnableInterrupt(void);

u16 ICU_u16ReadInputCapture(void);

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
