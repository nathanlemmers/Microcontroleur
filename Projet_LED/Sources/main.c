
#include "stm32f10x.h"
#include "MyGPIO.h"

int main (void)
{
	MyGPIO_Struct_TypeDef Led_Int ; 
	MyGPIO_Struct_TypeDef Bouton_Int ; 
	MyGPIO_Struct_TypeDef Led_Ext ; 
	MyGPIO_Struct_TypeDef Bouton_Ext ; 
	
	
	// Configuration led2
	Led_Int.GPIO = GPIOA ;
	Led_Int.GPIO_Conf = Out_Ppull ;
	Led_Int.GPIO_Pin = 5 ;
	
	//Configuration bouton interne
	Bouton_Int.GPIO = GPIOC ;
	Bouton_Int.GPIO_Conf = In_PullDown ;
	Bouton_Int.GPIO_Pin = 13 ;
	
	
	//Configuration led externe
	Led_Ext.GPIO = GPIOB ;
	Led_Ext.GPIO_Conf = Out_Ppull ;
	Led_Ext.GPIO_Pin = 5 ;
	
	//Configuration bouton externe
	Bouton_Ext.GPIO = GPIOB ;
	Bouton_Ext.GPIO_Conf = In_PullDown ;
	Bouton_Ext.GPIO_Pin = 0 ;
	
	
	MyGPIO_Init (&Led_Ext) ;
	MyGPIO_Init (&Bouton_Int) ;
	MyGPIO_Init (&Led_Int) ;
	MyGPIO_Init (&Bouton_Ext) ;
	
	while (1) {
		/*
		if (MyGPIO_Read(Bouton_Int.GPIO, Bouton_Int.GPIO_Pin)==0) {
			MyGPIO_Reset(Led_Int.GPIO, Led_Int.GPIO_Pin) ;
		}
		else {
			MyGPIO_Set(Led_Int.GPIO, Led_Int.GPIO_Pin) ;
		}
		*/
		if (MyGPIO_Read(Bouton_Ext.GPIO, Bouton_Ext.GPIO_Pin)==0) {
			MyGPIO_Set(Led_Ext.GPIO, Led_Ext.GPIO_Pin) ;
		}
		else {
			MyGPIO_Reset(Led_Ext.GPIO, Led_Ext.GPIO_Pin) ;
		}
	}
}
