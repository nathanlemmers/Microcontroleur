#include "MyTimer.h"

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer )
{
	if (Timer->Timer == TIM1) {
		
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;
		
		TIM1->PSC = 5999 ;
		TIM1->ARR = 5999 ;
		TIM1->CR1 &= ~TIM_CR1_DIR ;
		
	} else if (Timer->Timer == TIM2) {
		
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;
		
		TIM2->PSC = 5999 ;
		TIM2->ARR = 5999 ;
		TIM2->CR1 &= ~TIM_CR1_DIR ;
		
	} else if (Timer->Timer == TIM3) {
		
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN ;
		
		TIM3->PSC = 5999 ;
		TIM3->ARR = 5999 ;
		TIM3->CR1 &= ~TIM_CR1_DIR ;
		
	} else if (Timer->Timer == TIM4) {
		
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN ;
		
		TIM4->PSC = 5999 ;
		TIM4->ARR = 5999 ;
		TIM4->CR1 &= ~TIM_CR1_DIR ;
		
	}
}


void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio)
{
	Timer->DIER |= TIM_DIER_UIE ;
	NVIC->ISER |= NVIC_ISER_SETENA_28 ; 
}
