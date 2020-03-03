#include "Chamber.hpp"



// constructor
Chamber::Chamber()
{
	area_number = 4;
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
	

}



// function that describes library setting/surroundings
void Chamber::room_setting()
{
	std::cout << std::endl;
	std::cout << "You are in the Audience Chamber" << std::endl;
	std::cout << std::endl;
}




// function for agent to either move out of the chamber or perform an action
// returns pointer to next room chosen
Space * Chamber::move_choices(Agent * agent)
{
	
	std::cout << std::endl;
	std::cout << "Which direction would like to go?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Up (Harem)" << std::endl;
	std::cout << "2. Down (Library of Ahmet III)" << std::endl;
	std::cout << "3. Left (current room west wall)" << std::endl;
	std::cout << "4. Right (Imperial Treasury)" << std::endl;
	std::cout << "5. Walk to nightstand and open drawer" << std::endl;
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
			std::cout << "1. Up (Harem)" << std::endl;
			std::cout << "2. Down (Library of Ahmet III)" << std::endl;
			std::cout << "3. Left (current room west wall)" << std::endl;
			std::cout << "4. Right (Imperial Treasury)" << std::endl;
			std::cout << "5. Walk to nightstand and open drawer" << std::endl;
			std::cout << std::endl;
		}

		int user_choice = input_range_validate(5);


		switch (user_choice)
		{
		case 1:
			// go to Harem 
			std::cout << std::endl;
			std::cout << "You head into the Harem....." << std::endl;
			std::cout << std::endl;
			return up;
			break;
		case 2:
			// go to Library
			std::cout << std::endl;
			std::cout << "You head back into the Library of Ahmet III....." << std::endl;
			std::cout << std::endl;
			return down;
			break;
		case 3:
			// head to east/left chamber wall
			std::cout << std::endl;
			std::cout << "The wall is lined with blue, white and turquoise tiles. The throne chair leans against the wall."  << std::endl;
			std::cout << "Not much to see here...unless you can fit that gold throne in your backpack." << std::endl;
			std::cout << std::endl;			
			break;
		case 4:
			// go to Treasury
			std::cout << std::endl;
			std::cout << "You head into the Imperial Treasury....." << std::endl;
			std::cout << std::endl;
			return right;
			break;
		case 5:
			// walk to nightstand and open drawer
			// if agent doesn't have key yet
			if (!agent->search_backpack_contents("key"))
			{
				std::cout << std::endl;
				std::cout << "Hmm... what's inside?" << std::endl;
				std::cout << std::endl;

				// call method to pick up the crowbar
				grab_key(agent);
			}
			else
			{
				std::cout << std::endl;
				std::cout << "You've already checked this drawer..." << std::endl;
				std::cout << "Nothing else left to see here." << std::endl;
				std::cout << std::endl;
			}
			break;
		
		}

		counter++;
	}
}


// method returns room number
int Chamber::getRoomNumber()
{
	return area_number;
}



void Chamber::grab_key(Agent * agent)
{
	std::cout << std::endl;
	std::cout << "There is a small key......\n"
		      << "So...you pick it up and put it inside your backpack." << std::endl;
	std::cout << std::endl;

	// add key to agent's backpack
	// key is needed to open puzzle box in library
	agent->put_inside_backpack(new Item("key"));

}




void Chamber::set_up(Space * u_area)
{
	up = u_area;
}


void Chamber::set_right(Space * r_area)
{
	right = r_area;
}



void Chamber::set_down(Space * d_area)
{
	down = d_area;
}



void Chamber::set_left(Space * l_area)
{
	left = l_area;
}

