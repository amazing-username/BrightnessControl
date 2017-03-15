#include <iostream>
#include <fstream>
#include <ios>
#include "AlterBrightness.h"
#include "Brightness.h"

AlterBrightness::AlterBrightness()
{
	currentBrightness = Brightness::getCurrentBrightness();
	maxBrightness = Brightness::getMaxBrightness();
}	
AlterBrightness::AlterBrightness(unsigned& change, unsigned& current, unsigned& max)
{
	increment = change;
	decrement = change;
	currentBrightness = current;
	maxBrightness = max;
}	

void AlterBrightness::setIncrement(unsigned& change)
{
	increment = change;
}	
void AlterBrightness::setDecrement(unsigned& change)
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
void AlterBrightness::setPercentageBrightness(float& percent)
{
	percentageBrightness = percent;
}

void AlterBrightness::chooseChange(char* changeChoice[])
{
	std::ofstream s;
	s.open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);

	if (strcmp(*changeChoice, AlterBrightness::getIncrease()) == 0)
	{
		AlterBrightness::increaseBrightness();			

		std::cout << AlterBrightness::getCurrentBrightness() << std::endl;
		s << AlterBrightness::getCurrentBrightness();
	}
	else if (strcmp(*changeChoice, AlterBrightness::getDecrease()) == 0)
	{
		AlterBrightness::decreaseBrightness();

		std::cout << AlterBrightness::getCurrentBrightness() << std::endl;
		s << AlterBrightness::getCurrentBrightness();
	}	
	else if (strcmp(*changeChoice, AlterBrightness::getPercent()) == 0)
	{

		std::cout << "Percentage" << std::endl;
		setBrightnessByPercentage();

		std::cout << percentageBrightness / 100 << std::endl;
		s << currentBrightness;
	}
	else
	{
		std::cout << "Neither increase or decrease" << std::endl;
	}
	s.close();
}	
void AlterBrightness::increaseBrightness()
{
	if (AlterBrightness::getCurrentBrightness() + AlterBrightness::getIncrement() < AlterBrightness::getMaxBrightness())
	{
		currentBrightness = AlterBrightness::getCurrentBrightness() + AlterBrightness::getIncrement();
	}
	else
		currentBrightness = AlterBrightness::getMaxBrightness();
}	
void AlterBrightness::decreaseBrightness()
{
	if (AlterBrightness::getCurrentBrightness() - AlterBrightness::getDecrement() > 0)
	{
	currentBrightness = AlterBrightness::getCurrentBrightness() - AlterBrightness::getDecrement();
	}
	else
		currentBrightness = 1;
}	
void AlterBrightness::setBrightnessByPercentage()
{
	if (AlterBrightness::getPercentageBrightness() < 0 || AlterBrightness::getPercentageBrightness() > 100)
	{
		std::cout << "Has to be between 0 and 100" <<std::endl;
	}
	else
	{
		currentBrightness = (maxBrightness * (percentageBrightness/ 100));
		std::cout << currentBrightness << std::endl;
	}
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
