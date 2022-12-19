/************************************************************************/
/*******************************swc : LCD driver*************************/
/*******************************By  :Mina Asser *************************/
/******************************Date : 2022/9/9***************************/
/***************************** Version : 1.0*****************************/
/************************************************************************/



#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H







void LCD_VidsendData(u8 copy_u8Data);
void LCD_VidsendCmd(u8 copy_u8cmd);
void LCD_VidInit(void);
void LCD_VidDisplayClear(void);
void LCD_Vidgotoxy(u8 copy_u8x ,u8 copy_u8y );
void LCD_VidSendSpecialChar(u8 *pattern ,u8 pattern_num,u8 copy_u8xpos ,u8 copy_u8ypos);
void Lcd_DisplayString(u8 *str);
void Lcd_DisplayCharacter(u8 character);
void LCD_DisplayNumber(s32 num);
void LCD_Display_Float(f64 number);
#endif
