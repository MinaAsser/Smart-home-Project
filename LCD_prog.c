/************************************************************************/
/*******************************swc : LCD driver*************************/
/*******************************By  :Mina Asser *************************/
/******************************Date : 2022/9/9***************************/
/***************************** Version : 1.0*****************************/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include <util/delay.h>


/* At send data function :
 * 1- RS pin is high to select the Data register .
 * 2- RW pin is low to select read data .
 * 3- enable pin is set to high at first to hold the data for 3 ms .
 * 4- Then enable pin is set to low to let go for data to achieve to pins .
 *
 */
void LCD_VidsendData(u8 copy_u8Data){
	
	DIO_VidSetPinValue(CONTROL_PORT, RS_PIN, PinHigh);
	DIO_VidSetPinValue(CONTROL_PORT, RW_PIN, PinLow);
	DIO_VidSetPortValue(DATA_PORT,copy_u8Data);
	DIO_VidSetPinValue(CONTROL_PORT, E_PIN, PinHigh);
	_delay_ms(3);
	DIO_VidSetPinValue(CONTROL_PORT, E_PIN, PinLow);
	
}
/* At send command function :
 * 1- RS pin is low to select the instruction register .
 * 2- RW pin is low to select read instruction .
 * 3- enable pin is set to high at first to hold the data for 3 ms .
 * 4- Then enable pin is set to low to let go for data to achieve to pins.
 *
 */

void LCD_VidsendCmd(u8 copy_u8Cmd){
	
	DIO_VidSetPinValue(CONTROL_PORT, RS_PIN, PinLow);
	DIO_VidSetPinValue(CONTROL_PORT, RW_PIN, PinLow);
	DIO_VidSetPortValue(DATA_PORT,copy_u8Cmd);
	DIO_VidSetPinValue(CONTROL_PORT, E_PIN, PinHigh);
	_delay_ms(3);
	DIO_VidSetPinValue(CONTROL_PORT, E_PIN, PinLow);
	
}
void LCD_VidInit(void){

	_delay_ms(40);
	LCD_VidsendCmd(0b00111100);
	_delay_ms(1);
	LCD_VidsendCmd(0b00001100);


	LCD_VidsendCmd(1);


}
void LCD_VidDisplayClear(void){

	LCD_VidsendCmd(1);

}
void LCD_Vidgotoxy(u8 copy_u8x ,u8 copy_u8y ) {


	if (copy_u8x ==1) {
		copy_u8y += 0x40;


	}
	/* to Achive DDRAM */
	LCD_VidsendCmd(copy_u8y + 0b10000000 );


}
/* For Painting and special characters */
void LCD_VidSendSpecialChar(u8 *pattern ,u8 pattern_num,u8 copy_u8xpos ,u8 copy_u8ypos){

	u8 local_address = 8 * pattern_num ;
	LCD_VidsendCmd(0b01000000 + local_address);
	for(u8 i =0;i<8;i++){

		LCD_VidsendData(pattern[i]);
	}

	LCD_Vidgotoxy(copy_u8xpos,copy_u8ypos);
	LCD_VidsendData(pattern_num);



}

void LCD_DisplayNumber(s32 num)
{
    s32 reversed = 0;
    u8 counter = 0;
    if (num < 0)
    {
        LCD_VidsendData('-');
        num *= -1;
    }
    do
    {
        reversed = reversed * 10 + (num % 10);
        num = num / 10;
        counter++;
    } while (num != 0);
    do
    {
    	LCD_VidsendData(reversed % 10 + '0');
        reversed = reversed / 10;
        counter--;
    } while (counter != 0);
}


void Lcd_DisplayCharacter(u8 character)
{
	LCD_VidsendData(character);
}



void Lcd_DisplayString(u8 *str)
{
    while (*str != 0)
    {
    	LCD_VidsendData(*str);
        str++;
    }
}

void Lcd_SetCursorPosition(u8 row, u8 col)
{
    u8 address = col + (0x40 * row);
    SET_BIT(address, 7);
    LCD_VidsendCmd(address);
}
void LCD_Display_Float(f64 number)
{
   s32 Num_First	= number ;
   s32 Num_Second  = (number - Num_First )*100 ;
   u8 arr_num[10] = {0};
   u8 arr_num2[10] = {0};
   u8 i = 0 , k = 0;
    if (number == 0){
    LCD_VidsendData('0');
                    }
    else if(number > 0)
    {
       while( Num_First > 0)
       {
	       arr_num[i] = (Num_First % 10) + 48 ; // change from asci
	       Num_First /=10 ;
	       i++;
       }
      for (u8 j = (i-1) ; j>=0 ; j-- )
       {
    	  LCD_VidsendData(arr_num[j]);
       }
       if(Num_Second !=0 )
       {
    	LCD_VidsendData('.');
       }

       while(Num_Second > 0)
       {
    	arr_num2[k] = (Num_Second % 10) +48 ;
    	Num_Second /= 10;
    	k++;
       }

      for ( u8 j = (k-1); j>=0; j--)
      {
    	  LCD_VidsendData(arr_num2[j]);

      }

}

else
{
	Num_First *= -1 ;
	 while( Num_First > 0)
	       {
		       arr_num[i] = (Num_First % 10) + 48 ; // change from asci
		       Num_First /=10 ;
		       i++;
	       }
     LCD_VidsendData('-');
	 for (u8 j = (i-1) ; j>=0 ; j-- )
	       {
	       	LCD_VidsendData(arr_num[j]);
	       }
	  if(Num_Second !=0 )
	    {
	    	LCD_VidsendData('.');
	    }

	  while(Num_Second > 0)
	      {
	      	arr_num2[k] = (Num_Second % 10) +48 ;
	      	Num_Second /= 10;
	      	k++;
	      }


	   for ( u8 j = (k-1); j>=0; j--)
	    {
	    LCD_VidsendData(arr_num2[j]);

	    }






	}


}




