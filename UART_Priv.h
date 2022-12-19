/***************************************************************************************************************************************************************************************/
/************************************************* SWE     : UART DRIVER    *************************************************************************************************************/
/************************************************* BY      : Mina Asser *************************************************************************************************************/
/************************************************* Date    : 26Oct2022       *************************************************************************************************************/
/************************************************* Version : v1.0          *************************************************************************************************************/
/***************************************************************************************************************************************************************************************/
#ifndef UART_PRIV_H
#define UART_PRIV_H

#define MCFREQ     8000000


#define UDR            *((volatile u8*)0x2C) // USART data register input - output
#define UCSRA          *((volatile u8*)0x2B) // USART control and status register A
#define UCSRB          *((volatile u8*)0x2A) // USART control and status register B
#define UCSRC          *((volatile u8*)0X20) // USART control and status register C
#define UBRRL          *((volatile u8*)0X29) //
//#define UBRRH          *((volatile u8*)0X40) //

/*USART Control and status registerA UCSRA*/

#define 			             RXC						7
#define						     TXC		  				6
#define						     UDRE		  				5
#define						     FE		  				    4
#define						     DDR		  				3
#define						     PE		  				    2
#define						     U2X		  				1
#define						     MPCM		  				0

/* USART Control and status registerB UCSRB */
#define                         RXCIE                        7
#define                         TXCIE                        6
#define                         UDRIE                        5
#define                         RXEN                         4
#define                         TXEN                         3
#define                         UCSZ2                        2
#define                         RXB8                         1
#define                         TXB8                         0



/* USART Control and status registerC UCSRC */
#define                         RXCIE                        7
#define                         TXCIE                        6
#define                         UDRIE                        5
#define                         RXEN                         4
#define                         TXEN                         3
#define                         UCSZ2                        2
#define                         RXB8                         1
#define                         TXB8                         0

/* USART Control and status registerC UCSRC */
#define                         URSEL                        7
#define                         UMSEL                        6
#define                         UPM1                         5
#define                         UPM0                         4
#define                         USBS                         3
#define                         UCSZ1                        2
#define                         UCSZ0                        1
#define                         UCPOL                        0



/* USART BAUD RATE REGISTER 1 */
#define                         URSEL                        7
#define                         UMSEL                        6
#define                         UPM1                         5
#define                         UPM0                         4
#define                         USBS                         3
#define                         UCSZ1                        2
#define                         UCSZ0                        1
#define                         UCPOL                        0
#endif
