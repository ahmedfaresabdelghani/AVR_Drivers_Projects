/*************************************************/
/*************************************************/
/***********   Author : Ahmed Fares   ************/
/***********   Layer : HAL            ************/
/***********   HWC : CLCD             ************/
/***********   Version : 1.00         ************/
/***********   DATE : 1/28/2023       ************/
/*************************************************/
/*************************************************/

/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

/*constant char  because i won't change any thing in this string for any reason*/
void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);


void CLCD_PrintNumber(u32 Copy_u32Number);
void CLCD_voidsendnumber(u32 copy_u32number);


#endif
