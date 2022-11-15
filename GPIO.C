#include "GPIO.h"


void GPIO_Clock_Enable(uint32_t *GPIOx)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD );
  uint16_t *RCCAHB1 = (uint16_t*)(0x40023830);
  
  *RCCAHB1 = 0x00000000;
  if(GPIOx ==GPIOA) 
    
  {
    *RCCAHB1 |= (1<<0);
  }
  else if (GPIOx == GPIOB)
  {
    *RCCAHB1 |= (1<<1);
  }
  else if (GPIOx == GPIOC)
  {
    *RCCAHB1 |= (1<<2);
  }
  else if (GPIOx == GPIOD)
  {
    *RCCAHB1 |= (1<<3);
  }
    

}
void GPIO_Config(uint32_t *GPIOx,uint8_t pin, uint8_t Mode , uint8_t Type)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD );
  if (pin >= PIN0 && pin <= PIN15)
  {
    assert(Mode ==INPUT || Mode == OUTPUT || Mode ==ALTERNATE || Mode == ANALOG_INPUT);
    assert(Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN );
  
  }

    *GPIOx_MODE_R |= (1<< Mode);
   // GPIOx_OD_R --> 
    *GPIOx_PUPDR  |= (1<< Type);

 
        
    
}