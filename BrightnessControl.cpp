#include <cstring>
#include "AlterBrightness.h"

int main(int argc, char* argv[])
{
	AlterBrightness ab;
	char* ci = "sdfsdfd";
	char* control[strlen(*(argv + 1))] = {*(argv + 1)};
	unsigned changeAmount = atoi(*(argv + 2));
	unsigned currentBrightness = atoi(*(argv + 3));
	unsigned maxBrightness = atoi(*(argv + 4));

	ab.setIncrement(changeAmount);
	ab.setDecrement(changeAmount);
	ab.setCurrentBrightness(currentBrightness);
	ab.setMaxBrightness(maxBrightness);

	std::string ctl(*(control));
	ab.chooseChange((control));

	return 0;
}	
