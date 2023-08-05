#include"gpio.h"

int main()
{
	GPIO_PinConfigs gpio_ObjBuiltInLedConfigs;
	gpio_ObjBuiltInLedConfigs.pinNumber=GPIO_PIN_5;
  	gpio_ObjBuiltInLedConfigs.pinMode=GPIO_PinMode_OUTPUT;
  	gpio_ObjBuiltInLedConfigs.pinState=GPIO_PIN_STATE_HIGH;

	gpio gpio_ObjBuiltInLed(GPIO_PORT_A);
	gpio_ObjBuiltInLed.GPIO_PinInit(&gpio_ObjBuiltInLedConfigs);
	gpio_ObjBuiltInLed.GPIO_PinStateSet(&gpio_ObjBuiltInLedConfigs,GPIO_PIN_STATE_HIGH);

	while(1);
}