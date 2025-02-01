int main(void){
  int status = 0;

	int32_t channelReading1 = 0;
	int32_t channelReading2 = 0;
	int32_t channelReading3 = 0;
	int32_t channelReading4 = 0;

	float voltsChannelReading1 = 0;
	float voltsChannelReading2 = 0;
	float voltsChannelReading3 = 0;
	float voltsChannelReading4 = 0;

	unsigned char tx_buff[100];

status = ADS131B04Q1_Init(&hspi1, GPIOA, GPIO_PIN_3);
  if(status == 1){
  	  return 1;
  }
  
  while (1) {
	  //returns signed 2s complement number as a fraction of range
	  status = ADS131B04Q1_ReadChannels(&channelReading1, &channelReading2, &channelReading3, &channelReading4);
	  if(status == 1){
	    	  return 1;
	  }

	  //convert signed values to voltage values
	  voltsChannelReading1 = (float)channelReading1/(1<<23);
	  voltsChannelReading2 = (float)channelReading2/(1<<23);
	  voltsChannelReading3 = (float)channelReading3/(1<<23);
	  voltsChannelReading4 = (float)channelReading4/(1<<23);

	  sprintf((char*)tx_buff, "CH1: %f V\n\r", voltsChannelReading1);
	  HAL_UART_Transmit(&hlpuart1, tx_buff, strlen((char*)tx_buff), 1000);

	  sprintf((char*)tx_buff, "CH2: %f V\n\r", voltsChannelReading2);
	  HAL_UART_Transmit(&hlpuart1, tx_buff, strlen((char*)tx_buff), 1000);

	  sprintf((char*)tx_buff, "CH3: %f V\n\r", voltsChannelReading3);
	  HAL_UART_Transmit(&hlpuart1, tx_buff, strlen((char*)tx_buff), 1000);

	  sprintf((char*)tx_buff, "CH4: %f V\n\r", voltsChannelReading4);
	  HAL_UART_Transmit(&hlpuart1, tx_buff, strlen((char*)tx_buff), 1000);
  }
 
}
