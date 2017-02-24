#include <iostream>
#include <cstring>
#include <fstream>
#include <ios>
#include "AlterBrightness.h"
#include "Brightness.h"

int main(int argc, char* argv[])
{
	char* control[strlen(*(argv + 1))] = {*(argv + 1)};
	unsigned changeAmount = atoi(*(argv + 2));
	unsigned currentBrightness;
	unsigned maxBrightness;

	/**
	std::fstream input;
	input.open("/sys/class/backlight/intel_backlight/brightness", std::ios::in);
	input >> currentBrightness;
	std::cout << currentBrightness << std::endl;
	input.close();

	input.open("/sys/class/backlight/intel_backlight/max_brightness", std::ios::in);
	input >> maxBrightness;
	std::cout << maxBrightness << std::endl;
	input.close();
	*/

	AlterBrightness ab;
	Brightness br;
	br.grabBrightness();
	br.grabMaxBrightness();

	currentBrightness = br.getCurrentBrightness();
	maxBrightness = br.getMaxBrightness();

	ab.setIncrement(changeAmount);
	ab.setDecrement(changeAmount);
	ab.setCurrentBrightness(currentBrightness);
	ab.setMaxBrightness(maxBrightness);

	//std::string ctl(*(control));
	ab.chooseChange((control));

	return 0;
}	
