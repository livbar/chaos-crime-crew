#include "Input_Validation.hpp"

// input validation makes sure user can only enter specific range
// will reprompt until entry is within range
int input_range_validate(const int user_num)
{
	int input;

	do
	{
		std::cout << "Please enter your choice: \n";
		std::cout << ">>";
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cout << "Invalid entry....try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	} while(std::cin.fail() || input < 1 || input > user_num);

	return input;

}




