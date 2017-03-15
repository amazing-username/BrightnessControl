#include <iostream>
#include <fstream>
#include "AlterBrightness.h"
#include "Brightness.h"

int main(int argc, char* argv[])
{
	char* control[strlen(*(argv + 1))] = {*(argv + 1)};
	unsigned changeAmount = atoi(*(argv + 2));
	float brightnessPercentage = atoi(*(argv + 2));
	unsigned currentBrightness;
	unsigned maxBrightness;



	Brightness br;
	br.grabBrightness();
	br.grabMaxBrightness();
	AlterBrightness ab;


	ab.setIncrement(changeAmount);
	ab.setDecrement(changeAmount);
	ab.setPercentageBrightness(brightnessPercentage);

	ab.chooseChange((control));

	return 0;
}	
