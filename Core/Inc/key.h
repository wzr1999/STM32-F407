#ifndef ___key___H
#define ___key___H

#include "main.h"
#include "stm32f4xx_it.h"
 
#include "stm32f407xx.h"

#define GPIO_PortSourceGPIOC       ((uint8_t)0x02)
#define GPIO_PinSource2            ((uint8_t)0x02)
//KEY1
 
#define KEY1_GPIO_PIN			GPIO_PIN_2
#define KEY1_PORT				GPIOC
#define	KEY1_IRQn				EXTI0_IRQn 
#define	KEY1_PortSource			GPIO_PortSourceGPIOC
#define KEY1_PinSource			GPIO_PinSource2
#define KEY1_IRQHandler			EXTI0_IRQHandler
#define	KEY1_Line				LL_SYSCFG_EXTI_LINE0
 
typedef struct
{
  uint8_t NVIC_IRQChannel;                  
  uint8_t NVIC_IRQChannelPreemptionPriority;  
  uint8_t NVIC_IRQChannelSubPriority;         
  FunctionalState NVIC_IRQChannelCmd;        
} NVIC_InitTypeDef;

void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);

void KEY_Init(void);
 
#endif
 