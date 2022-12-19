/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : UART DRIVER    *************************************************************************************************************/
/************************************************* BY      : Mina Asser *************************************************************************************************************/
/************************************************* Date    : 26Oct2022       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Int.h"
#include "UART_Priv.h"
void USART_Init(void){
/*	u8 Local_u8UCRC = 0; // write values on UCSRC
	SET_BIT(Local_u8UCRC,URSEL);
	// Asynchronous
	CLR_BIT(Local_u8UCRC,UMSEL);
    // select parity to disable
	CLR_BIT(Local_u8UCRC,UPM0);
	CLR_BIT(Local_u8UCRC,UPM1);
    // 1 stop bit
	CLR_BIT(Local_u8UCRC,USBS);
    // 8 bit character size
    SET_BIT(Local_u8UCRC, UCSZ0);
	SET_BIT(Local_u8UCRC, UCSZ1);
	UCSRC = Local_u8UCRC;
	// Setting baud rate
	CLR_BIT(UCSRA, U2X);
	UBRRL = 51;
	// Enable tx and rx
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB ,TXEN); */

	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC, UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	UBRRL = 51 ;
	SET_BIT(UCSRB , RXEN);
	SET_BIT(UCSRB , TXEN);

}
void USART_VoidSend(u8 Copy_U8data){
while(GET_BIT(UCSRA,UDRE)!=1);
UDR = Copy_U8data;



}
u8 USART_U8Recieve(void){
while(GET_BIT(UCSRA,RXC)!=1);
return UDR;


}

void UART_SENDSTRING(u8 *word)

{int p =0 ;

while(word[p]!= 0)
{

USART_VoidSend(word[p]);
	p++;
}

}

void UART_RecieveString(u8*str)
{
u8 i = 0 ;
str[i]= USART_U8Recieve() ;

while(str[i] != '\n'){

	i++ ;
	str[i] = USART_U8Recieve();
	if(str[i] == ' ' || str[i] == '\r'){
	i--;
	continue;
	}


}
str[i] = '\0' ;

}

Recieve_Status UART_RecieveChar(u8 * ptr)
{
	Recieve_Status state = NOTOK ;
	if(GET_BIT(UCSRA,7))
	{
		*ptr= UDR ;
		state= OK ;
	}
	return state ;
}

