
#include "stm32f10x.h"
#include "MyGPIO.h"
#include "MyTimer.h"


int main (void)
{
	MyTimer_Struct_TypeDef Timer2 = {TIM2, 5999, 5999} ;
	MyTimer_Base_Init(&Timer2);
	MyTimer_Base_Start(TIM2);
	
	
	
	while (1) {

	}
}
