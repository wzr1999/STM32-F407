#include "../Inc/key.h"
#include "../Inc/Exit.h"


void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
{
  uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;
  if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
  { 
    tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
    tmppre = (0x4 - tmppriority);
    tmpsub = tmpsub >> tmppriority;
    tmppriority = (uint32_t)NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority << tmppre;
    tmppriority |=  NVIC_InitStruct->NVIC_IRQChannelSubPriority & tmpsub;
    tmppriority = tmppriority << 0x04;        
    NVIC->IP[NVIC_InitStruct->NVIC_IRQChannel] = tmppriority;
    NVIC->ISER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
  }
  else
  {
    NVIC->ICER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
  }
}

// static void NVIC_Config()
// {
// 	NVIC_InitTypeDef	NVIC_Initstruct;
 
//     //选择中断源——KEY1按键
// 	NVIC_Initstruct.NVIC_IRQChannel=KEY1_IRQn;
//     //抢占优先级配置为1
// 	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=1;
//     //子优先级为1
// 	NVIC_Initstruct.NVIC_IRQChannelSubPriority=1;
//     //使能中断通道
// 	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	
// 	NVIC_Init(&NVIC_Initstruct);
 
// }

//Key Interrupt Init PC2
void KEY_Init(void){
 
   GPIO_InitTypeDef GPIO_InitStruct;// Define Init Config Struct
   //EXTI_InitTypeDef EXTI_InitStruct;

   /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

    //初始化中断控制器   
	//NVIC_Config();
  HAL_GPIO_WritePin(SWITCH_GPIO_Port,GPIO_PIN_2,GPIO_PIN_SET);
  /*Configure GPIO pin : SWITCH_Pin */
  GPIO_InitStruct.Pin = SWITCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(SWITCH_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);


}