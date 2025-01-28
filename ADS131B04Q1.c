/*
 * ADS131B04Q1.c
 *
 *  Created on: Jan 25, 2025
 *      Author: William Gomez
 */
#include "ADS131B04Q1.h"

//Define external variables
SPI_HandleTypeDef* ADS131_hspi;
GPIO_TypeDef* ADS131pinLetter;
uint16_t ADS131_PIN_Number;
/**/
int ADS131B04Q1_Init(SPI_HandleTypeDef* hspi, GPIO_TypeDef* GPIOpinLetter, uint16_t GPIO_PIN_Number){
	ADS131_hspi = hspi;
	ADS131pinLetter = GPIOpinLetter;
	ADS131_PIN_Number = GPIO_PIN_Number;
	int status = 0;

	//begin by ensuring CS line is high impedance
	HAL_GPIO_WritePin(ADS131pinLetter, ADS131_PIN_Number, GPIO_PIN_SET);

	//check if ADC is connected
	status = ADS131B04Q1_CheckConnection();
	if(status == HAL_ERROR){
		return status; //if ADC is not connected, return 1
	}

	//drive CS line low
	HAL_GPIO_WritePin(ADS131pinLetter, ADS131_PIN_Number, GPIO_PIN_RESET);


	return 0;
}

int ADS131B04Q1_CheckConnection(){
	int status = 0;
	uint8_t RxData[2] = {0,0};

	//Read nnn nnnn plus 1 registers beginning at address a aaaa a: 101a aaaa annn nnnn
	//reading register 00h, only reading first register so nnn nnnn should be 000 0000
	//command should be 0b10100000, 0b00000000
	uint8_t TxCommand[2] = {0b10100000, 0b00000000};
	//drive CS line low
	HAL_GPIO_WritePin(ADS131pinLetter, ADS131_PIN_Number, GPIO_PIN_RESET);

	//send no command, which the ADS131B04 will read as "NULL" to which it will respond with a status byte
	status = HAL_SPI_Transmit(ADS131_hspi, TxCommand, 2, HAL_MAX_DELAY);
	if(status == HAL_ERROR){
			return status;
	}
	status = HAL_SPI_Receive (ADS131_hspi, RxData, 2, HAL_MAX_DELAY);
	//todo: make sure MSB goes into RxData[0]
	if(RxData[0] == 0b01000100){
		return 0;
	}
	return 1;
}


int ADS131B04Q1_ReadChannels(int32_t *channelReading1, int32_t *channelReading2, int32_t *channelReading3, int32_t *channelReading4){


	return 0;
}

