#ifndef ALTERBRIGHTNESS_H
#define ALTERBRIGHTNESS_H
#include <cstring>
#include <string>

class AlterBrightness
{
public:	
	AlterBrightness();
	
	AlterBrightness(unsigned&, unsigned&, unsigned&);

	void setIncrement(unsigned&);
	void setDecrement(unsigned&);
	void setCurrentBrightness(unsigned&);
	void setMaxBrightness(unsigned&);
	
	void chooseChange(char*[]);
	void increaseBrightness();
	void decreaseBrightness();

	unsigned getIncrement() const;
	unsigned getDecrement() const;
	unsigned getCurrentBrightness() const;
	unsigned getMaxBrightness() const;

	char* getIncrease();
	char* getDecrease();
	
private:	
	unsigned increment;
	unsigned decrement;
	unsigned currentBrightness;
	unsigned maxBrightness;
	char* increase = "inc";
	char* decrease = "dec";
};

#endif
