#include "led.h"


#define GPIO_OTYPE_OFFSET    (0x04/4)
#define OSPEED_OFFSET        (0X08/4)
#define OFFSET_ODR           (0x14/4)
#define OFFSET_IDR           (0X10/4)
#define OFFSET_BSRR          (0x18/4)


void AssertValid(void)
{
  __asm("NOP");
}

void AssertFailed(void)
{
  while(1){}
}

#define EMB_ASSERT(Exp) ((Exp) ? AssertValid() : AssertFailed())


void GPIO_Clock_Enable(uint32_t *GPIOx)
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );

  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
  
  if(GPIOx == GPIOA)
  {
    *RCCAHB1 |= (1<<0);
  }
  else if(GPIOx == GPIOB)
  {
    *RCCAHB1 |= (1<<1);
  }
  else if(GPIOx == GPIOC)
  {
    *RCCAHB1 |= (1<<2);
  }
  else if(GPIOx == GPIOD)
  {
    *RCCAHB1 |= (1<<3);
  }
}  
void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode, uint8_t Type, uint8_t Speed)
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
  EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  EMB_ASSERT(Mode >= INPUT && Mode <= ANALOG_INPUT);
  EMB_ASSERT(Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN);
  EMB_ASSERT(Speed >= LOW_SPEED && Speed <= VERY_HIGH_SPEED);
    
  *GPIOx &= ~(0xFF << Pin*2);
  *GPIOx |= (Mode << Pin*2);
   if(Mode == OUTPUT)
  {
    *(GPIOx + GPIO_OTYPE_OFFSET) &= ~(1 << Pin);
    *(GPIOx + GPIO_OTYPE_OFFSET) |= (Type << Pin);
    
    *(GPIOx + OSPEED_OFFSET) &= ~(0x3 << Pin*2);
    *(GPIOx + OSPEED_OFFSET) |= (Speed << Pin*2);
  }
  else 
  {
    //misra
  } 
}

void GPIO_Write_Pin(uint32_t *GPIOx, uint8_t Pin, uint8_t PinValue)
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
  EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  EMB_ASSERT(PinValue == 0 || PinValue == 1);
  
  *(GPIOx + OFFSET_ODR) &= ~(1<<Pin);
  *(GPIOx + OFFSET_ODR) |=  (PinValue<<Pin);
}

uint8_t GPIO_Read_Pin(uint32_t *GPIOx, uint8_t Pin)
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
  EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  
  return ((*(GPIOx + OFFSET_IDR) >> Pin) & 1);
}