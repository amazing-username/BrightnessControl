#include <iostream>
#include <fstream>
#include "Brightness.h"

int Brightness::maxBrightness = 0;
int Brightness::currentBrightness = 0;
Brightness::Brightness()
{ } 

Brightness::~Brightness()
{ }

void Brightness::grabBrightness()
{
	readBrightnessValues.open("/sys/class/backlight/intel_backlight/brightness", std::ios::in);

	readBrightnessValues >> currentBrightness;
	
	readBrightnessValues.close();
}	
void Brightness::grabMaxBrightness()
{
	readBrightnessValues.open("/sys/class/backlight/intel_backlight/max_brightness", std::ios::in);

	readBrightnessValues >> maxBrightness;

	readBrightnessValues.close();
}

unsigned Brightness::getCurrentBrightness()
{
	return currentBrightness;
}
unsigned Brightness::getMaxBrightness()
{
	return maxBrightness;
}	
