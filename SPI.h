/*
 * SPI.h
 *
 * Created: 10/4/2020 1:12:09 AM
 *  Author: monad
 */ 


#ifndef SPI_H_
#define SPI_H_

#define SS       4
#define MOSI     5
#define MISO     6
#define SCK      7


void SPI_Init (unsigned char status);
unsigned char SPI_TxRx (unsigned char data);


#endif /* SPI_H_ */