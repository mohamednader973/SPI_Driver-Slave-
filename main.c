/*
 * Reciever.c
 *
 * Created: 10/4/2020 8:18:56 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include "SPI.h"
#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	DDRC |=(1<<7);
	SPI_Init('S');
    /* Replace with your application code */
    while (1) 
    {
		if (SPI_TxRx(0x55)==0x01)
		{
			PORTC ^=(1<<7);
		}
    }
}

