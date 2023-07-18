#include "rcc.h"
rcc RCC_object;

RCC_GpioPortName_t usedPort = RCC_GPIO_PORT_A;
int main()
{
	RCC_object.RCC_gpioPortInit(usedPort);
	while(1);
}