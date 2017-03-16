#include <iostream>
//#include <cstring>
#include <ios>
#include "AlterBrightness.h"

AlterBrightness::AlterBrightness()
{
	currentBrightness = Brightness::getCurrentBrightness();
	maxBrightness = Brightness::getMaxBrightness();
	AlterBrightness::options = new std::vector<std::string>;
	initializeOptions();
	overwriteBrightness = new std::ofstream;	
	(*overwriteBrightness).open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);
}	
AlterBrightness::AlterBrightness(Brightness* br)
{
	currentBrightness = (*br).getCurrentBrightness();
	maxBrightness = (*br).getMaxBrightness();
	options = new std::vector<std::string>;
	initializeOptions();
	overwriteBrightness = new std::ofstream;	
	(*overwriteBrightness).open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);
}
AlterBrightness::AlterBrightness(const unsigned& change, const unsigned& current, const unsigned& max)
{
	increment = change;
	decrement = change;
	currentBrightness = current;
	maxBrightness = max;
}	
AlterBrightness::~AlterBrightness()
{
	delete options;
	delete overwriteBrightness;
}

void AlterBrightness::setIncrement(const unsigned& change)
{
	increment = change;
}	
void AlterBrightness::setDecrement(const unsigned& change)
{
	decrement = change;
}	
/**
void AlterBrightness::setCurrentBrightness()
{
	currentBrightness = current;
}	
void AlterBrightness::setMaxBrightness()
{
	maxBrightness = max;
}	
*/
void AlterBrightness::setPercentageBrightness(const float& percent)
{
	percentageBrightness = percent;
}
void AlterBrightness::initializeOptions()
{
	(*options).push_back("inc");
	(*options).push_back("dec");
	(*options).push_back("per");
}

void AlterBrightness::chooseChange(const std::string& changeChoice)
{
	//std::ofstream s;
	//s.open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);
	//std::cout << (*options).at(0) << std::endl;

	//if (strcmp(*changeChoice, getIncrease()) == 0)
	//if (strcmp(*changeChoice, (*options).at(0)) == 0)
	if ((*options).at(0).compare(changeChoice) == 0)
	{
		increaseBrightness();			

		std::cout << getCurrentBrightness() << std::endl;
		(*overwriteBrightness) << getCurrentBrightness();
	}
	//else if (strcmp(*changeChoice, getDecrease()) == 0)
	else if ((*options).at(1).compare(changeChoice) == 0)
	{
		decreaseBrightness();

		std::cout << getCurrentBrightness() << std::endl;
		(*overwriteBrightness) << getCurrentBrightness();
	}	
	//else if (strcmp(*changeChoice, getPercent()) == 0)
	else if ((*options).at(2).compare(changeChoice) == 0)
	{

		//std::cout << "Percentage" << std::endl;
		setBrightnessByPercentage();

		std::cout << percentageBrightness << "%" << std::endl;
		(*overwriteBrightness) << currentBrightness;
	}
	else
	{
		std::cout << "Neither increase or decrease" << std::endl;
	}
	//s.close();
}	
void AlterBrightness::increaseBrightness()
{
	if (getCurrentBrightness() + getIncrement() < getMaxBrightness())
	{
		currentBrightness = getCurrentBrightness() + getIncrement();
	}
	else
		currentBrightness = getMaxBrightness();
}	
void AlterBrightness::decreaseBrightness()
{
	if (getCurrentBrightness() - getDecrement() > 0)
	{
	currentBrightness = getCurrentBrightness() - getDecrement();
	}
	else
		currentBrightness = 1;
}	
void AlterBrightness::setBrightnessByPercentage()
{
	if (getPercentageBrightness() < 0 || getPercentageBrightness() > 100)
	{
		std::cout << "Has to be between 0 and 100" <<std::endl;
	}
	else
	{
		currentBrightness = (maxBrightness * (floatToPercent(percentageBrightness)));
		std::cout << currentBrightness << std::endl;
	}
}


std::vector<std::string>* AlterBrightness::getOptions()
{
	return options;
}
std::ofstream* AlterBrightness::getStreamToOverwriteBrightness()
{
	return overwriteBrightness; 
}

unsigned AlterBrightness::getIncrement() const 
{
	return increment;
}		
unsigned AlterBrightness::getDecrement() const 
{
	return decrement;
}		
unsigned AlterBrightness::getCurrentBrightness() const 
{
	return currentBrightness;
}		
unsigned AlterBrightness::getMaxBrightness() const 
{
	return maxBrightness;
}		


float AlterBrightness::getPercentageBrightness() const
{
	return percentageBrightness;
}
float AlterBrightness::floatToPercent(const float& percent) const
{
	return percent / 100;
}

/**
char* AlterBrightness::getIncrease() 
{
	return increase;
}
char* AlterBrightness::getDecrease() 
{
	return decrease;
}	
char* AlterBrightness::getPercent()
{
	return percent;
}
*/
