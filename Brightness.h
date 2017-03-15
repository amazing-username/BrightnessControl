#ifndef BRIGHTNESS_H 
#define BRIGHTNESS_H

class Brightness
{
public:
	Brightness();

	void grabBrightness();
	void grabMaxBrightness();

	static unsigned getCurrentBrightness();
	static unsigned getMaxBrightness();

private:
	static unsigned currentBrightness;
	static unsigned maxBrightness;
};	
#endif
