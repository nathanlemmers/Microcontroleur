
#include "stm32f10x.h"
#include "MyGPIO.h"
#include "MyTimer.h"

MyGPIO_Struct_TypeDef Led_Int ;
	
void callback (void)
{
	MyGPIO_Toggle(Led_Int.GPIO, Led_Int.GPIO_Pin) ;
}

void testPWM ()
{
	MyTimer_Struct_TypeDef TimerSet = {TIM2, 5999, 5999} ;
	
	MyTimer_Base_Init(&TimerSet);
	
	MyTimer_PWM(TimerSet.Timer, 1);
	MyTimer_PWM_Cycle(TimerSet.Timer, 1, 0.2);
	MyTimer_PWM_ToGPIO(TimerSet.Timer, 1) ;
	MyTimer_Base_Start(TimerSet.Timer);
}
	
int main (void)
{
	MyTimer_Struct_TypeDef TimerSet = {TIM1, 5999, 5999} ;
	MyTimer_Base_Init(&TimerSet);
	MyTimer_Base_Start(TimerSet.Timer);
	MyTimer_ActiveIT(TimerSet.Timer, 7, &callback);
	
	// Configuration led2
	Led_Int.GPIO = GPIOA ;
	Led_Int.GPIO_Conf = Out_Ppull ;
	Led_Int.GPIO_Pin = 5 ;
	MyGPIO_Init (&Led_Int) ;
	
	testPWM();
	
	while (1) {

	}
}
