#include <iostream>
#include <fstream>
#include "Brightness.h"

unsigned Brightness::maxBrightness = 0;
unsigned Brightness::currentBrightness = 30;
Brightness::Brightness()
{
}	

void Brightness::grabBrightness()
{
	std::fstream input;
	input.open("/sys/class/backlight/intel_backlight/brightness", std::ios::in);

	input >> currentBrightness;

	input.close();
}	
void Brightness::grabMaxBrightness()
{
	std::fstream input;
	input.open("/sys/class/backlight/intel_backlight/max_brightness", std::ios::in);

	input >> maxBrightness;

	input.close();
}

unsigned Brightness::getCurrentBrightness()
{
	return currentBrightness;
}
unsigned Brightness::getMaxBrightness()
{
	return maxBrightness;
}	
