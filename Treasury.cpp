#include "Treasury.hpp"



// constructor
Treasury::Treasury()
{
	area_number = 6;
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
		
}



// method that describes treasury setting/surroundings
void Treasury::room_setting()
{
	std::cout << "You are in the treasury room" << std::endl;
	std::cout << std::endl;

}




// function for agent to either move out of the treasury or perform an action
// returns pointer to next room chosen
Space * Treasury::move_choices(Agent * agent)
{

	std::cout << std::endl;
	std::cout << "Which direction would like to go?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Up (current room north wall)" << std::endl;
	std::cout << "2. Down (Palace Kitchen)" << std::endl;
	std::cout << "3. Left (Audience Chamber)" << std::endl;
	std::cout << "4. Right (current room east wall)" << std::endl;
	std::cout << "5. Walk to armoured mannequin" << std::endl;
	std::cout << std::endl;

	

	// while agent is in room, keep presenting choices to directions/actions
	// until he/she moves out into another room
	int counter = 1;
	while (true)
	{

		if (counter > 1)
		{
			std::cout << std::endl;
			std::cout << "Which direction would like to go?" << std::endl;
			std::cout << std::endl;
			std::cout << "1. Up (current room north wall)" << std::endl;
			std::cout << "2. Down (Palace Kitchen)" << std::endl;
			std::cout << "3. Left (Audience Chamber)" << std::endl;
			std::cout << "4. Right (current room east wall)" << std::endl;
			std::cout << "5. Walk to armoured mannequin" << std::endl;
			std::cout << std::endl;

		}

		int user_choice = input_range_validate(5);

		switch (user_choice)
		{
		case 1:
			// agent walks towards north wall
			std::cout << std::endl;
			std::cout << "NORTH WALL - description here..." << std::endl;
			std::cout << std::endl;
			break;
		case 2:
			// agent walks into palace kitchen
			std::cout << std::endl;
			std::cout << "Agent walks towards Palace Kitchen....." << std::endl;
			std::cout << std::endl;
			return down;
			break;
		case 3:
			// agents walks into Audience Chamber
			std::cout << std::endl;
			std::cout << "Agent walks towards Palace Kitchen....." << std::endl;
			std::cout << std::endl;
			return left;
			break;
		case 4:
			// agent walks towards east wall
			std::cout << std::endl;
			std::cout << "EAST WALL - description here" << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			// open closet
			// if agent doesn't have dagger yet, he/she will take it
			if (!agent->search_backpack_contents("dagger"))
			{
				// call method to pick up the dagger
				get_dagger(agent);
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You've already grabbed the dagger from the mannequin." << std::endl;
				std::cout << "Nothing else to see here." << std::endl;
				std::cout << std::endl;
			}
			break;
		
		}
		counter++;
	}
}



void Treasury::get_dagger(Agent * agent)
{
	std::cout << std::endl;
	std::cout << "GASP" << std::endl;
	std::cout << "The mannequin is holding the Topkapi dagger in its hand!!! \n"
		      << "It is being held in place by a wire that is attached to some sort of alarm. \n" << std::endl;
	std::cout << std::endl;
	std::cout << "You gently remove the wire and pull the daggar out, then into your backpack." << std::endl;
	std::cout << std::endl;

	// add dagger to agent's backpack
	agent->put_inside_backpack(new Item("dagger"));

}



int Treasury::getRoomNumber()
{
	return area_number;
}



void Treasury::set_up(Space * u_area)
{
	up = u_area;
}


void Treasury::set_right(Space * r_area)
{
	right = r_area;
}



void Treasury::set_down(Space * d_area)
{
	down = d_area;
}



void Treasury::set_left(Space * l_area)
{
	left = l_area;
}







