#include "Courtyard.hpp"

// constructor
Courtyard::Courtyard()
{
	area_number = 2;
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
	
}



// method that describes library setting/surroundings
void Courtyard::room_setting()
{
std:std::cout << std::endl;
	std::cout << "You find yourself outside in the courtyard.\n"
		<< "It's very dark but there are three clear ways to leave. To the north, you can head towards \n"
		<< "Hagia Sophia. To the west, out through the Imperial Gate. Finally, to the south, towards Council street. \n"
		<< "If you recall correctly, there's a metro station just one block down in that direction." << std::endl;
	std::cout << std::endl;

}


// returns pointer to next room chosen
Space * Courtyard::move_choices(Agent * agent)
{
	// offer agent choices of directions to move and/or actions to perform
	std::cout << std::endl;
	std::cout << "Which direction would like to go?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Up (towards Hagia Sophia)" << std::endl;
	std::cout << "2. Down (towards Council Street)" << std::endl;
	std::cout << "3. Left (towards Imperial Gate)" << std::endl;
	std::cout << "4. Right (back inside Library of Ahmet III)" << std::endl;

	int counter = 1;
	while (true)
	{
		// User makes a choice based on the options presented.
		// If it is the second time around, the options are presented again.
		if (counter > 1)
		{
			std::cout << std::endl;
			std::cout << "Which direction would like to go?" << std::endl;
			std::cout << std::endl;
			std::cout << "1. Up (towards Hagia Sophia)" << std::endl;
			std::cout << "2. Down (towards Council Street)" << std::endl;
			std::cout << "3. Left (towards Imperial Gate)" << std::endl;
			std::cout << "4. Right (back inside Library of Ahmet III)" << std::endl;
		}

		int user_choice = input_range_validate(4);

		switch (user_choice)
		{
		case 1:

			// TODO if agent heads this way with none or without all three items.. driver shoots him
			// TODO else, agent is victorious


			// agent walks towards Hagia Sophia
			std::cout << "You run as fast as you can towards Hagia Sophia. Just before you enter the building someone \n"
				      << "calls out your name. As you turn around you see a fancy car parked on the side of the street." << std::endl;
			std::cout << std::endl;
			std::cout << "The driver congratulates you on completing your missing as instructs you to get inside the car.\n"
				      << "You get in and a few hours later, you are on a yacht celebrating your initiation into C3." << std::endl;
			std::cout << std::endl;
			std::cout << "Well done, my friend!!" << std::endl;
			std::exit(0);
			break;
		case 2:
			// agent walks towards council street
			std::cout << "You run out of the courtyard and as you start crossing the street you get hit by a Turkish beer truck." << std::endl;
			std::cout << "A bystander rushes over to help you and notices something sticking out from your backpack" << std::endl;
			std::cout << "He grabs your backpack and takes off running... you are too wounded to go after him." << std::endl;
			std::cout << std::endl;
			std::cout << "The ambulance arrives, but it's too late. You've succumbed to your injuries." << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
			std::exit(0);
			break;
		case 3:
			// agent walks towards imperial gate
			std::cout << std::endl;
			std::cout << "As soon as you exit the courtyard through the Imperial Gate, you are apprehended by the police." << std::endl;
			std::cout << std::endl;
			std::cout << "....a few days later you find yourself inside a Turkish prison cell. You are never heard from again." << std::endl;
			std::cout << std::endl;
			std::cout << "GAME OVER" << std::endl;
			std::exit(0);
			break;
		case 4:
			// agents walks back inside the palace into the library
			return right;

		}

		counter++;
	}
}



int Courtyard::getRoomNumber()
{
	return area_number;
}



void Courtyard::set_up(Space * u_area)
{
	up = u_area;
}


void Courtyard::set_right(Space * r_area)
{
	right = r_area;
}



void Courtyard::set_down(Space * d_area)
{
	down = d_area;
}



void Courtyard::set_left(Space * l_area)
{
	left = l_area;
}




