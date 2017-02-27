#ifndef BRIGHTNESS_H 
#define BRIGHTNESS_H

class Brightness
{
public:
	Brightness();

	void grabBrightness();
	void grabMaxBrightness();

	unsigned getCurrentBrightness() const;
	unsigned getMaxBrightness() const;

private:
	unsigned currentBrightness;
	unsigned maxBrightness;
};	
#endif
