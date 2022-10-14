
#include "stm32f10x.h"
#include "MyGPIO.h"
#include "MyTimer.h"

MyGPIO_Struct_TypeDef Led_Int ;
	
void callback (void)
{
	MyGPIO_Toggle(Led_Int.GPIO, Led_Int.GPIO_Pin) ;
}
	
int main (void)
{
	MyTimer_Struct_TypeDef Timer = {TIM1, 5999, 5999} ;
	MyTimer_Base_Init(&Timer);
	MyTimer_Base_Start(Timer.Timer);
	MyTimer_ActiveIT(Timer.Timer, 7, &callback);
	
	// Configuration led2
	Led_Int.GPIO = GPIOA ;
	Led_Int.GPIO_Conf = Out_Ppull ;
	Led_Int.GPIO_Pin = 5 ;
	MyGPIO_Init (&Led_Int) ;
	while (1) {

	}
}
