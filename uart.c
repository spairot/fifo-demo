/*
 * uart.c
 *
 * Created: 14/03/2017 11:14:03
 *  Author: Jonathan
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include "ring_buffer.h"
#include "uart.h"

ring_buffer_t rb_tx;

void Uart_init()
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	UCSR0B = 1<<RXEN0 | 1<<TXEN0;
	UCSR0C = 1<<UCSZ00 | 1<< UCSZ01;
	
	RB_init(&rb_tx);
}

void Uart_Transmit_IT( unsigned char *data, unsigned char nbytes )
{
	RB_write(&rb_tx, data, nbytes);
	Uart_EnableTransmitIT();
}


ISR(USART_UDRE_vect)
{
	if (RB_length(&rb_tx) > 0)
	{		
		UDR0 = RB_readByte(&rb_tx);
	} 
	else
	{
		Uart_DisableTransmitIT();
	}
}

