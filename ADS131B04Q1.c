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

	HAL_GPIO_WritePin(ADS131pinLetter, ADS131_PIN_Number, GPIO_PIN_RESET);


	return 0;
}

int ADS131B04Q1_CheckConnection(GPIO_TypeDef* GPIOpinLetter, uint16_t GPIO_PIN_Number){

}


int ADS131B04Q1_ReadChannel(GPIO_TypeDef* GPIOpinLetter, uint16_t GPIO_PIN_Number, int32_t *channelReading){

}

