#include <iostream>
#include <fstream>
#include <ios>
#include "AlterBrightness.h"

AlterBrightness::AlterBrightness()
{
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
void AlterBrightness::setCurrentBrightness(unsigned& current)
{
	currentBrightness = current;
}	
void AlterBrightness::setMaxBrightness(unsigned& max)
{
	maxBrightness = max;
}	

void AlterBrightness::chooseChange(char* changeChoice[])
{
	std::ofstream s;
	s.open("/sys/class/backlight/intel_backlight/brightness", std::ios::out);
	//std::cout << changeChoice << std::endl;
	//if (1)
	//	std::cout << changeChoice.compare("inc") << std::endl;
	//else
	//	std::cout << "0 is not true" << std::endl;
	//if (changeChoice.compare(AlterBrightness::getIncrease()) == 0)
	if (strcmp(*changeChoice, AlterBrightness::getIncrease()) == 0)
	{
		AlterBrightness::increaseBrightness();			
		std::cout << "Increase" << std::endl;
		std::cout << AlterBrightness::getCurrentBrightness() << std::endl;
		s << AlterBrightness::getCurrentBrightness();
	}
	else
	{
		AlterBrightness::decreaseBrightness();
		std::cout << AlterBrightness::getCurrentBrightness() << std::endl;
		s << AlterBrightness::getCurrentBrightness();
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

char* AlterBrightness::getIncrease() 
{
	return increase;
}
char* AlterBrightness::getDecrease() 
{
	return decrease;
}	
