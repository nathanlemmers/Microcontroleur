
#include "stm32f10x.h"

int main (void)
{
	
	short buttonState; // CHANGER EN UINT 16

	RCC->APB2ENR |= (0x1 << 2) | (0x1 << 3) | (0x1 << 4);
	
	// On configure la led2 en output push-pull
	GPIOA->CRL |= (0x1 << (5*4));
	GPIOA->CRL &= ~(0xC << (5*4));
	
	// On configure le bouton externe sur PB0, en mode pull down
	GPIOB->CRL |= (0x8);
	GPIOB->CRL &= ~(0x7);
	// On configure la LED externe sur PB5, en mode push/pull
	GPIOB->CRL |= (0x1 << (5*4));
	GPIOB->CRL &= ~(0xC << (5*4));
	while (1) {
		// On copie l'état du bouton user dans la led2
		buttonState = (~GPIOC->IDR & (1<<13)) >> 8;
		GPIOA->ODR |= buttonState;
		GPIOA->ODR &= ~( buttonState );
	}
}
