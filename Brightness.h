#ifndef BRIGHTNESS_H 
#define BRIGHTNESS_H
#include <fstream>

class Brightness
{
public:
	Brightness();
	~Brightness();

	void grabBrightness();
	void grabMaxBrightness();

	static unsigned getCurrentBrightness();
	static unsigned getMaxBrightness();

private:
	std::ifstream* readBrightnessValues;
	static unsigned currentBrightness;
	static unsigned maxBrightness;
};	
#endif
