/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : UART DRIVER    *************************************************************************************************************/
/************************************************* BY      : Mina Asser *************************************************************************************************************/
/************************************************* Date    : 26Oct2022       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/
#ifndef UART_INT_H
#define UART_INT_H

#define UART_RX     PIN0
#define UART_TX     PIN1

void USART_Init(void);
void USART_VoidSend(u8 data);
u8 USART_U8Recieve(void);

void UART_SENDSTRING(u8 *word);


void UART_RecieveString(u8*str);

typedef enum
{
	OK=0,
	NOTOK
}Recieve_Status;

Recieve_Status UART_RecieveChar(u8 * ptr);






#endif
