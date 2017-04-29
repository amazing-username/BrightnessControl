#include <iostream>
#include <ios>
#include "AlterBrightness.h"

AlterBrightness::AlterBrightness()
{
	currentBrightness = Brightness::getCurrentBrightness();
	maxBrightness = Brightness::getMaxBrightness();
	initializeOptions();
	overwriteBrightness.open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);
}	
AlterBrightness::AlterBrightness(const Brightness& br)
{
	currentBrightness = br.getCurrentBrightness();
	maxBrightness = br.getMaxBrightness();
	initializeOptions();
	overwriteBrightness.open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);
}
AlterBrightness::AlterBrightness(const int& change, const int& current, const int& max)
{
	increment = change;
	decrement = change;
	currentBrightness = current;
	maxBrightness = max;
}	
AlterBrightness::~AlterBrightness()
{ overwriteBrightness.close(); }

void AlterBrightness::setIncrement(const int& change)
{ increment = change; }	

void AlterBrightness::setDecrement(const int& change)
{ decrement = change; }	

void AlterBrightness::setPercentageBrightness(const float& percent)
{ percentageBrightness = percent; }

void AlterBrightness::initializeOptions()
{
	options.push_back("inc");
	options.push_back("dec");
	options.push_back("per");
	options.push_back("cur");
}

void AlterBrightness::chooseChange(const std::string& changeChoice)
{
	if (options.at(0).compare(changeChoice) == 0)
	{
		increaseBrightness();			

		std::cout << getCurrentBrightness() << std::endl;
		overwriteBrightness << getCurrentBrightness();
	}
	else if (options.at(1).compare(changeChoice) == 0)
	{
		decreaseBrightness();

		std::cout << getCurrentBrightness() << std::endl;
		overwriteBrightness << getCurrentBrightness();
	}	
	else if (options.at(2).compare(changeChoice) == 0)
	{
		setBrightnessByPercentage();

		std::cout << percentageBrightness << "%" << std::endl;
		overwriteBrightness << currentBrightness;
	}
	else if (options.at(3).compare(changeChoice) == 0)
	{	
		float percentage{static_cast<float>(getCurrentBrightness()) / static_cast<float>(getMaxBrightness())};
		percentage*=100;
		std::cout << "The current percentage is: " << percentage << "%" << std::endl;
	}	
	else
		std::cout << "Neither increase or decrease" << std::endl;
}	
void AlterBrightness::increaseBrightness()
{
	if (getCurrentBrightness() + getIncrement() < getMaxBrightness())
		currentBrightness = getCurrentBrightness() + getIncrement();
	else
		currentBrightness = getMaxBrightness();
}	
void AlterBrightness::decreaseBrightness()
{
	if (getCurrentBrightness() - getDecrement() > 0)
	currentBrightness = getCurrentBrightness() - getDecrement();
	else
		currentBrightness = 1;
}	
void AlterBrightness::setBrightnessByPercentage()
{
	if (getPercentageBrightness() < 0 || getPercentageBrightness() > 100)
		std::cout << "Has to be between 0 and 100" <<std::endl;
	else
	{
		currentBrightness = (maxBrightness * (floatToPercent(percentageBrightness)));
		std::cout << currentBrightness << std::endl;
	}
}


std::vector<std::string> AlterBrightness::getOptions()
{ return options; }
//std::ofstream AlterBrightness::getStreamToOverwriteBrightness()
//{ return overwriteBrightness; }

int AlterBrightness::getIncrement() const 
{ return increment; }		

int AlterBrightness::getDecrement() const 
{ return decrement; }		

int AlterBrightness::getCurrentBrightness() const 
{ return currentBrightness; }		

int AlterBrightness::getMaxBrightness() const 
{ return maxBrightness; }		


float AlterBrightness::getPercentageBrightness() const
{ return percentageBrightness; }

float AlterBrightness::floatToPercent(const float& percent) const
{ return percent / 100; }
