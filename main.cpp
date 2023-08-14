#include"led.h"
#include "dimmerLed.h"

int main()
{
	dimmerLed Led1(LEVEL_0,BUILTIN_LED,ON);
	//led BuiltInLED(BUILTIN_LED,ON);
	Led1.setState(ON);

	while(1);
}