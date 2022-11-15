/**
  ******************************************************************************
  * @file    main.c
  * @author  Mouadh Dahech
  * @brief   Bit Mask 
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "GPIO.h"


/* Private define ------------------------------------------------------------*/
/*----------------Private Functions Prototype---------------------------------*/
static void delay(unsigned int delay);

/* Private variables ---------------------------------------------------------*/

int main()
{
  GPIO_Clock_Enable(GPIOD);
  
  GPIO_Config(GPIOD,PIN12,OUTPUT,OUTPUT_PUSH_PULL);
 // GPIO_Clock_Enable(GPIOB);
 // GPIO_Clock_Enable(GPIOC);
  //GPIO_Clock_Enable(GPIOD);
  /*Activate GPIOD clock*/
  
  /*Config PD12 as output*/

  /*Config PD13 as output*/

  /*Config PD14 as output*/

  /*Config PD15 as output*/

  
  /*Config PD12, PD13, PD14 AND PD15 push-pull mode*/

  while(1)
  {
   
  }
}



/**************************************END OF FILE**************************************/
