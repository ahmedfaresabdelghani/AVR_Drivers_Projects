/************************************************************************************/
/************************************************************************************/
/**********************      AUTHOR: AHMED FARES         ****************************/
/**********************      LAYER: HAL                  ****************************/
/**********************      SWC:CLCD                    ****************************/
/**********************      VERSION: 1.00               ****************************/
/************************************************************************************/
/************************************************************************************/
/*preprocessor file guard*/

  #ifndef _CLCD_INTERFACE_H_
  #define _CLCD_INTERFACE_H_















void CLCD_voidSendCommand(u8 CLCD_u8Command);
void CLCD_voidSendData(u8 CLCD_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSend_String(const char*Copy_pcString);
void CLCD_voidGo_To_X_Y(u8 Copy_u8Xpos,u8 Copy_u8Ypos);
void CLCD_voidDraw_Sympol(u8 *Copy_Pu8Pattren,u8 Copy_u8Block_Num,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidClear_Display(void);



  #endif
