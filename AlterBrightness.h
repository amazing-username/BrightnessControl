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
	void setCurrentBrightness();
	void setMaxBrightness();
	void setPercentageBrightness(float&);
	
	void chooseChange(char*[]);
	void increaseBrightness();
	void decreaseBrightness();
	void setBrightnessByPercentage();


	unsigned getIncrement() const;
	unsigned getDecrement() const;
	unsigned getCurrentBrightness() const;
	unsigned getMaxBrightness() const;

	float getPercentageBrightness() const;

	char* getIncrease();
	char* getDecrease();
	char* getPercent();
	
private:	
	unsigned increment;
	unsigned decrement;
	unsigned currentBrightness;
	unsigned maxBrightness;
	float percentageBrightness;
	char* increase = "inc";
	char* decrease = "dec";
	char* percent = "per";
};

#endif
