#include "led.h"
#define SINGLE_LED  1
#define MULTI_LEDS  0


#if SINGLE_LED

GPIO_PinConfigs builtInLedPinConfigs;
/* Using bunch of function calls as elements of array to initialize the Array of objects with parameterized constructors*/
gpio builtInLedPinInst(GPIO_PORT_A);

led::led(LedColor_Type _color, LedState_Type _state) :color(_color), state(_state)
{
    builtInLedPinConfigs.pinNumber = GPIO_PIN_5;
    builtInLedPinConfigs.pinMode   = GPIO_PinMode_OUTPUT;
    builtInLedPinConfigs.pinState  = (GPIO_PinState_t)_state;
    builtInLedPinInst.GPIO_PinInit(&builtInLedPinConfigs);
    builtInLedPinInst.GPIO_PinStateSet(&builtInLedPinConfigs,(GPIO_PinState_t)_state);
}
void led::setState(LedState_Type _state)
{
    builtInLedPinInst.GPIO_PinStateSet(&builtInLedPinConfigs,(GPIO_PinState_t)_state);
}
LedState_Type led::getState(void)const
{
    return (LedState_Type)builtInLedPinInst.GPIO_PinStateGet(&builtInLedPinConfigs);
}

#elif MULTI_LEDS

GPIO_PinConfigs LED_AllLedPinConfigs[LEDS_COUNT];
/* Using bunch of function calls as elements of array to initialize the Array of objects with parameterized constructors*/
gpio LED_AllLedPinInst[LEDS_COUNT]={gpio(GPIO_PORT_A),gpio(GPIO_PORT_B),gpio(GPIO_PORT_C),gpio(GPIO_PORT_A)};

led::led(LedColor_Type _color, LedState_Type _state) :color(_color), state(_state)
{
    switch(_color)
    {
        case BUILTIN_LED:
            LED_AllLedPinConfigs[_color].pinNumber = GPIO_PIN_5;
            break;
        case RED_LED:
           LED_AllLedPinConfigs[_color].pinNumber = GPIO_PIN_6;
           break; 
    }
    
    LED_AllLedPinConfigs[_color].pinMode   = GPIO_PinMode_OUTPUT;
    LED_AllLedPinConfigs[_color].pinState  = (GPIO_PinState_t)_state;
    LED_AllLedPinInst[_color].GPIO_PinInit(&LED_AllLedPinConfigs[_color]);
    LED_AllLedPinInst[_color].GPIO_PinStateSet(&LED_AllLedPinConfigs[_color],(GPIO_PinState_t)_state);

}
void led::setState(LedState_Type _state)
{
    LED_AllLedPinInst[color].GPIO_PinStateSet(&LED_AllLedPinConfigs[color],(GPIO_PinState_t)_state);
}
LedState_Type led::getState(void)const
{
    return (LedState_Type)LED_AllLedPinInst[color].GPIO_PinStateGet(&LED_AllLedPinConfigs[color]);
}
#endif
