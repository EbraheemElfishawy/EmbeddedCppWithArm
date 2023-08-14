#ifndef __LED_H
#define __LED_H
#include <stdint.h>
#include "led_cfg.h"


#define LED_BUILTIN_MODE_BIT	(1<<(LED_BUILTIN_PIN*2U)) /*10: As every pin takes 2 bits in MODER register*/
#define LED_RED_MODE_BIT		(1<<(LED_RED_PIN*2U)) /*0 : As every pin takes 2 bits in MODER register*/
#define LED_GREEN_MODE_BIT		(1<<(LED_GREEN_PIN*2U))	/*2 : As every pin takes 2 bits in MODER register*/
#define LED_BLUE_MODE_BIT		(1<<(LED_BLUE_PIN*2U))	/*8 : As every pin takes 2 bits in MODER register*/

enum LedColor_Type 
{
	RED_LED = 0,
	GREEN_LED,
	BLUE_LED,
	BUILTIN_LED
};
enum LedState_Type
{
	OFF = 0,
	ON
};

/*LED's attribute*/
 class led
{
	private:
		LedColor_Type color; 		/* Color of LED*/
		LedState_Type state;		/* State of LED*/
	public:
		led(LedColor_Type _color, LedState_Type _state);
		void setState(LedState_Type _state);
		LedState_Type getState(void);	
};

#endif
