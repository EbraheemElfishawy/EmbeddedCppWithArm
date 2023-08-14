#ifndef _DIMMER_LED_H
#define _DIMMER_LED_H
#include "led.h"

enum ledBrightnessLevel_Type
{
    LEVEL_0,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVELS_CNT
};

class dimmerLed : public led
{
    private:


    public:
    dimmerLed(ledBrightnessLevel_Type _initialLevel, LedColor_Type _color, LedState_Type _state): led(_color,_state)
    {
        
    }
    void setBrightnessLevel(ledBrightnessLevel_Type _brightnessLevel);
	ledBrightnessLevel_Type getBrightnessLevel(void);
};

#endif