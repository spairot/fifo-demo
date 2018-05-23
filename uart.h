/*
 * uart.h
 *
 * Created: 14/03/2017 11:11:46
 *  Author: Jonathan
 */ 


#ifndef UART_H_
#define UART_H_

#define		Uart_EnableTransmitIT()		UCSR0B |= (1<<UDRIE0)
#define		Uart_DisableTransmitIT()	UCSR0B &= ~(1<<UDRIE0)


void		Uart_init();
void		Uart_Transmit_IT(unsigned char *data, unsigned char nbytes);


#endif /* UART_H_ */