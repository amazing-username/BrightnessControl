#include <iostream>
#include <iomanip>
#include <fstream>
#include "AlterBrightness.h"
#include "Brightness.h"

int main(int argc, char* argv[])
{

	//char* control[strlen(*(argv + 1))] = {*(argv + 1)};
	//unsigned currentBrightness;
	//unsigned maxBrightness;
	
	Brightness* br = new Brightness;
	//std::cout << "argc is: " << argc << std::endl;
	if (argc == 3)
	{
		std::string control = *(argv + 1);
		unsigned changeAmount = atoi(*(argv + 2));
		float brightnessPercentage = atoi(*(argv + 2));
		
		(*br).grabBrightness();
		(*br).grabMaxBrightness();

		
		AlterBrightness* ab = new AlterBrightness(br);
		delete br;
		(*ab).setIncrement(changeAmount);
		(*ab).setDecrement(changeAmount);
		(*ab).setPercentageBrightness(brightnessPercentage);

		(*ab).chooseChange((control));
			
		delete ab;
	}
	else
	{
		std::cout << "Inlude one of the following arguements: " << std::endl;
		std::cout << std::setw(10) << "inc"; 
		std::cout << std::setw(10) << "dec";
		std::cout << std::setw(10) << "per" << std::endl << std::endl;


		std::cout << "If inc or dec add a value to adjust the brightness by value" << std::endl;
		std::cout << "If per add a value between 0 and 100 to adjust the brightness by percentage" << std::endl;
		std::cout << "Adjusting the percentage by brightness is recommended" << std::endl << std::endl;
		std::cout << "Example: Hot.out per 30" << std::endl << std::endl;
	
	}
	/**
	switch(argc)
	{
		case 3: 
			//std::cout << "two" << std::endl;
		
		
			
			AlterBrightness* ab = new AlterBrightness;
			delete br;
			(*ab).setIncrement(changeAmount);
			(*ab).setDecrement(changeAmount);
			(*ab).setPercentageBrightness(brightnessPercentage);

			(*ab).chooseChange((control));
			
			delete ab;
			break;
		default:
			

			break;
	}
	*/


	//PointerRemoval pR;

	return 0;
}	
