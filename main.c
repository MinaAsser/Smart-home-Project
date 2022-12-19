/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: ACTIVIE
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "smarthome_interface.h"
#include "UART_Int.h"
#include "LCD_interface.h"
#include "ADC_int.h"
#include <util/delay.h>
u8 opfl1 = 0 ;

int main(){
	u16 x;
	u8  *ptr1 = &opfl1;
	u8  opfl2 = 0 , *ptr = &opfl2;
	u8 Local_status, Pass_status, Option;
	u8 Local_u8Var[10] = {"0"};
	u8 Pass_arr[10];
	  u8 Entry_msg[50]={" Enter user name (you have 3 trials) \n"};
	 u8 Try_again[20]={"Try again:  \n"};
	  u8 Enter_Pass[50]={"Enter password: \n "};
	 u8 Welcome[50]={"Welcome \n"};
	 u8 Wrong_Pass[50]={"Wrong pass \n"};
	 u8 Options[280]={" To turn Light off send '0' \n To turn Light on send '1' \n For temperature display send '2' \n To turn off alarm send '3' \n To Close the door send '4' \n To open the door send '5' \n To exit program send '6'\n"};
	DIO_VidSetPinDirection(Port_D , Pin0, Input);
	DIO_VidSetPinDirection(Port_D , Pin1, Output);
	DIO_VidSetPortDirection(Port_B,Output);
	DIO_VidSetPortDirection(Port_C,Output);
	USART_Init();
	ADC_VidInit();
	Smart_homeInit();
	LCD_VidInit();

	while(opfl1 == 0){
		UART_SENDSTRING(Entry_msg); // Please Enter you password
		for(u8 i = 0;i<=2;i++)
		{
			UART_RecieveString(Local_u8Var);
			Local_status = Checkusername(Local_u8Var);

if (Local_status <=10 && i<2 && Local_status != 0){

// user name is correct then passed
 break;
}
else if (Local_status == 0 && i <2 ){

	// user name is incorrect then try again
 UART_SENDSTRING(Try_again);

}

else {
DIO_VidSetPinValue(Smart_Home_PORT,Alarm_Pin,PinHigh);//	break;
}

}// 3 trials loop ending


if(Local_status <= 10 && Local_status!=0)
{
	for(u8 j = 0;j<=2;j++)
	{

UART_SENDSTRING(Enter_Pass);
UART_RecieveString(Pass_arr);
Pass_status =check_password(Pass_arr,Local_status);
if(Pass_status <=10 && Pass_status !=0 && j<2)
{
	UART_SENDSTRING(Welcome);
	// Door on aft7 el solenoid
	DIO_VidSetPinValue(Smart_Home_PORT,Pin6,PinHigh);
	UART_SENDSTRING(Options);
	_delay_ms(3000);
// close door

while( opfl2 != 1){

	Option = USART_U8Recieve();

switch (Option){
case '0' : Smart_Ledoff(); break;
case '1' : Smart_LedOn();  break;
case '2' : 	 x = ADC_VidRead_ADC_ChannelSync(ADC_0);
             DIO_VidSetPortValue(Port_B, x);

           f32 analog_valueC = (( x * 5 * 100 ) / 1024.0 );
           _delay_ms(100);
           Lcd_DisplayString("the temperature is :");
           LCD_Vidgotoxy(1,0);
           LCD_DisplayNumber(analog_valueC);
           _delay_ms(5000);
           LCD_VidDisplayClear();
           _delay_ms(1);
break;
case '3' :DIO_VidSetPinValue(Port_C,Pin5,PinLow); break;
case '4' : DIO_VidSetPinValue(Smart_Home_PORT,Pin6,PinLow);break;
case '5' : DIO_VidSetPinValue(Smart_Home_PORT,Pin6,PinHigh);break;

case '6' : *ptr = 1; break;

default : break;
}// switch case ending

}//  while opflag end


} // if 2 ending
else if (Pass_status ==0 && j<2){
	if(*ptr ==1){
		break;
	}

	UART_SENDSTRING(Wrong_Pass);
}
else {
DIO_VidSetPinValue(Smart_Home_PORT,Alarm_Pin,PinHigh);//	break;
}
	} //password for loop end
} // user check if end
if(*ptr ==1){
	*ptr1 = 1;
	break;
}

		}// while 1 end


} // int main ending bracket

