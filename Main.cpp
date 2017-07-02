#include <iostream>
#include <iomanip>
#include <fstream>
#include "AlterBrightness.h"
#include "Brightness.h"
#include"RetrieveArguments.h"

int main(int argc, char* argv[])
{

	RetrieveArguments args{argc, argv};
	Brightness br{};
	if (argc == 3)
	{
		auto control{args.argumentElements()[1]};
		auto changeAmount = args.argumentElements()[2];
		auto brightnessPercentage = args.argumentElements()[2];
		
		br.grabBrightness();
		br.grabMaxBrightness();

		
		AlterBrightness ab{};
		ab.setIncrement(atoi(changeAmount.c_str()));
		ab.setDecrement(atoi(changeAmount.c_str()));
		ab.setPercentageBrightness(atoi(brightnessPercentage.c_str()));

		ab.chooseChange((control));
	}
	else if (argc == 2) 
	{
		std::string control{*(argv +1)};
		if (control.compare("cur") == 0)
		{
			br.grabBrightness();	
			br.grabMaxBrightness();
			AlterBrightness ab{};
			ab.chooseChange(control);
		}
	}
	else
	{
		std::cout << "Inlude one of the following arguements: " << std::endl;
		std::cout << std::setw(10) << "inc"; 
		std::cout << std::setw(10) << "dec";
		std::cout << std::setw(10) << "per"; 
		std::cout << std::setw(10) << "cur" << std::endl << std::endl;


		std::cout << "If inc or dec add a value to adjust the brightness by value" << std::endl;
		std::cout << "If per add a value between 0 and 100 to adjust the brightness by percentage" << std::endl;
		std::cout << "If cur then the current percentage is printed" << std::endl;
		std::cout << "Adjusting the percentage by brightness is recommended" << std::endl << std::endl;
		std::cout << "Example: Hot.out per 30" << std::endl << std::endl;
	}

	return 0;
}	
