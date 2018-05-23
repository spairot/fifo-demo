/*
 * Test_RingBuffer.c
 *
 * Created: 14/03/2017 10:07:28
 * Author : Jonathan
 */ 

#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>
#include "uart.h"

unsigned char test1[] = "Hola Mundo 123457890\r\n";
unsigned char test2[] = "123457890 TEST 2\r\n";

int main(void)
{
    /* Replace with your application code */
	Uart_init();
	
	Uart_Transmit_IT(test1,strlen(test1));
	Uart_Transmit_IT(test2,strlen(test2));
	sei();		
    while (1) 
    {
    }
}

