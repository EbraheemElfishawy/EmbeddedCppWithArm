#include "led.h"

GPIO_PinConfigs LED_AllLedPinConfigs[LEDS_COUNT];
/* Using bunch of function calls as elements of array to initialize the Array of objects with parameterized constructors*/
gpio LED_AllLedPinInst[LEDS_COUNT]={gpio(GPIO_PORT_A),gpio(GPIO_PORT_B),gpio(GPIO_PORT_C),gpio(GPIO_PORT_A)};

led::led(LedColor_Type _color, LedState_Type _state) :color(_color), state(_state)
{
    LED_AllLedPinConfigs[_color].pinNumber = GPIO_PIN_5;
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
