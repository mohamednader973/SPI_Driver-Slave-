/*
 * SPI.c
 *
 * Created: 10/4/2020 1:11:53 AM
 *  Author: monad
 */ 
#include "SPI.h"
#define Uint8   unsigned char
typedef struct{
	Uint8 SPR0    :1;
	Uint8 SPR1    :1;
	Uint8 CPHA    :1;
	Uint8 CPOL    :1;
	Uint8 MASTR   :1;
	Uint8 DORD    :1;
	Uint8 SPE_BIT :1;
	Uint8 SPIE    :1;
}SPI_ControlType;
typedef struct{
	Uint8 SPI2X :1;
	Uint8 R1    :1;
	Uint8 R2    :1;
	Uint8 R3    :1;
	Uint8 R4    :1;
	Uint8 R5    :1;
	Uint8 WCOL  :1;
	Uint8 SPIF_BIT  :1;
}SPI_StatusType;
typedef struct{
	SPI_ControlType	SPI_SPCR;
	SPI_StatusType  SPI_SPSR;
	Uint8 SPI_SPDR;
}SPICfg;
#define SPICOM ((volatile SPICfg*)0x2D)



#include <avr/io.h>

void SPI_Init (unsigned char status)
{
	switch(status)
	{
		case 'M':
		DDRB |=(1<<SS)|(1<<MOSI)|(1<<SCK);
		DDRB &=~(1<<MISO);
		SPICOM->SPI_SPCR.MASTR = 1;
		SPICOM->SPI_SPCR.SPE_BIT  = 1;
		PORTB |=(1<<SS); 
		break;
		case 'S':
		DDRB &=~(1<<SS)|(1<<MOSI)|(1<<SCK);
		DDRB |=(1<<MISO);
		SPICOM->SPI_SPCR.SPE_BIT = 1;
		break;
	}
}
unsigned char SPI_TxRx (unsigned char data)
{
	SPICOM->SPI_SPDR=data;
	while(SPICOM->SPI_SPSR.SPIF_BIT ==0);
	return SPICOM->SPI_SPDR;
}
