
#include "stm32f10x.h"
#include "MyGPIO.h"
#include "MyTimer.h"

int cont = 0;
MyGPIO_Struct_TypeDef Led_Int ;
	
void TIM1_UP_IRQHandler (void)
{
	TIM1->SR &= ~(TIM_SR_UIF) ;
	cont++ ;
}

void TIM2_IRQHandler (void)
{
	TIM2->SR &= ~(TIM_SR_UIF) ;
	cont++ ;
	MyGPIO_Toggle(Led_Int.GPIO, Led_Int.GPIO_Pin) ;
}

void TIM3_IRQHandler (void)
{
	TIM3->SR &= ~(TIM_SR_UIF) ;
	cont++ ;
}

void TIM4_IRQHandler (void)
{
	TIM4->SR &= ~(TIM_SR_UIF) ;
	cont++ ;
}

int main (void)
{
	MyTimer_Struct_TypeDef Timer = {TIM2, 5999, 5999} ;
	MyTimer_Base_Init(&Timer);
	MyTimer_Base_Start(Timer.Timer);
	MyTimer_ActiveIT(Timer.Timer, 7);
	
	// Configuration led2
	Led_Int.GPIO = GPIOA ;
	Led_Int.GPIO_Conf = Out_Ppull ;
	Led_Int.GPIO_Pin = 5 ;
	MyGPIO_Init (&Led_Int) ;
	while (1) {

	}
}
