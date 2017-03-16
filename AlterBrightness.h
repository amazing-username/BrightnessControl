#ifndef ALTERBRIGHTNESS_H
#define ALTERBRIGHTNESS_H
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include "Brightness.h"

class AlterBrightness
{
public:	
	AlterBrightness();
	AlterBrightness(Brightness*);
	AlterBrightness(const unsigned&, const unsigned&, const unsigned&);

	~AlterBrightness();

	std::vector<std::string>* options;
	//void setStreamToOverwriteBrightness();

	void setIncrement(const unsigned&);
	void setDecrement(const unsigned&);
	void setCurrentBrightness();
	void setMaxBrightness();
	void setPercentageBrightness(const float&);
	void initializeOptions();
	
	void chooseChange(const std::string&);
	void increaseBrightness();
	void decreaseBrightness();
	void setBrightnessByPercentage();

	std::vector<std::string>* getOptions();
	std::ofstream* getStreamToOverwriteBrightness();

	unsigned getIncrement() const;
	unsigned getDecrement() const;
	unsigned getCurrentBrightness() const;
	unsigned getMaxBrightness() const;

	float getPercentageBrightness() const;
	float floatToPercent(const float&) const;

	/**
	char* getIncrease();
	char* getDecrease();
	char* getPercent();
	*/
	
private:	
	std::ofstream* overwriteBrightness;
	unsigned increment;
	unsigned decrement;
	unsigned currentBrightness;
	unsigned maxBrightness;
	float percentageBrightness;
	/**
	char* increase;
	char* decrease;
	char* percent;
	*/
};

#endif
