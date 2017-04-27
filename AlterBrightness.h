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
	AlterBrightness(const Brightness&);
	AlterBrightness(const int&, const int&, const int&);

	~AlterBrightness();

	std::vector<std::string> options{};

	void setIncrement(const int&);
	void setDecrement(const int&);
	void setCurrentBrightness();
	void setMaxBrightness();
	void setPercentageBrightness(const float&);
	void initializeOptions();
	
	void chooseChange(const std::string&);
	void increaseBrightness();
	void decreaseBrightness();
	void setBrightnessByPercentage();

	std::vector<std::string> getOptions();
	//std::ofstream getStreamToOverwriteBrightness();

	int getIncrement() const;
	int getDecrement() const;
	int getCurrentBrightness() const;
	int getMaxBrightness() const;

	float getPercentageBrightness() const;
	float floatToPercent(const float&) const;

private:	
	std::ofstream overwriteBrightness{};
	int increment{};
	int decrement{};
	int currentBrightness{};
	int maxBrightness{};
	float percentageBrightness{};
};

#endif
