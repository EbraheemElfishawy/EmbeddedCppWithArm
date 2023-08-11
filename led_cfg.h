#ifndef __LED_CFG_H
#define __LED_CFG_H

#include "gpio.h"

#define LEDS_COUNT	4
#define RED_LED_INDEX		0
#define GREEN_LED_INDEX		1
#define BLUE_LED_INDEX		2
#define BUILIN_LED_INDEX	3

#define LED_PORT				GPIOA 		/*All leds are connected to GPIOA*/
#define LED_PORT_CLOCK			(1U<<0)		/*To enable clock for GPIOA as GPIOAEN bit = 0 in AHB1ENR*/

#define LED_BUILTIN_PIN			(5)		/*As the built-in led is connected to PA5*/
#define LED_RED_PIN				(0)		/*As red 		  led is connected to PA0*/
#define LED_GREEN_PIN			(1)		/*As green 		  led is connected to PA1*/
#define LED_BLUE_PIN			(4)		/*As blue 		  led is connected to PA4*/




#endif