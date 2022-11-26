/**
  ******************************************************************************
  * @file    main.c
  * @author  Mouadh Dahech
  * @brief   Bit Mask 
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
//#include "stm32f4xx.h"
#include "GPIO.h"
#include "led.h"

int counter = 0;

    
void InputOutputConfig()
//void InputOutputConfig(GPIOx, Pin, Mode,Type, Speed)

{
  GPIO_Clock_Enable(GPIOD);
  GPIO_Config(GPIOD,PIN12,OUTPUT,OUTPUT_PUSH_PULL, LOW_SPEED);
  GPIO_Config(GPIOD,PIN15,OUTPUT,OUTPUT_PUSH_PULL, LOW_SPEED);
  
  
}
//void ButtonToggle(*GPIOx,  Pin, PinValue)
void ButtonToggle()
{
  
  while(1)
  {
  GPIO_Write_Pin(GPIOD, PIN12, SET);
  if (GPIO_Read_Pin(GPIOA ,  PIN1)==1){
    GPIO_Write_Pin(GPIOD, PIN15, SET);
    (GPIO_Read_Pin(GPIOA ,  PIN1)==0);
      counter++;
  }
  else if (counter !=0 && GPIO_Read_Pin(GPIOA ,  PIN1)==1)
  {
     GPIO_Write_Pin(GPIOD, PIN15, RESET);
    
    
  }
}
}


/* Private define ------------------------------------------------------------*/
/*----------------Private Functions Prototype---------------------------------*/
//static void delay(unsigned int delay);

/* Private variables ---------------------------------------------------------*/

int main()
{
  InputOutputConfig(GPIOD, PIN12,OUTPUT,OUTPUT_PUSH_PULL, LOW_SPEED);
  ButtonToggle(*GPIOA,  PIN1, SET);
   
   
 
  
  
  
  
/*typedef Struct
{
  volatile (uint32_t) MODDER;
  volatile (uint32_t) ODR;
}GPIO_TypeDef;*/

 // GPIO_Config(GPIOD,PIN12,OUTPUT,OUTPUT_PUSH_PULL, LOW_SPEED);
  
  //GPIO_Write_Port(GPIOD, 10);
  
  
  
 // GPIO_Write_Pin(GPIOD, PIN12, SET);
  
 // GPIO_Write_Pin(GPIOD, PIN12, RESET);

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
