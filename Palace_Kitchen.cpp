#include "Palace_Kitchen.hpp"

// constructor
Kitchen::Kitchen()
{
	area_number = 3;
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
	

}



// method that describes palace kitchen setting/surroundings
void Kitchen::room_setting()
{
	std::cout << "You are in the Palace Kitchen. The room is big, filled with appliances and cookware." << std::endl;
	std::cout << "There are no windows inside the room. In the corner, there is a small closet door." << std::endl;
	std::cout << std::endl;

}




// function for agent to either move out of the palace kitchen or perform an action
// returns pointer to next room chosen
Space * Kitchen::move_choices(Agent * agent)
{

	std::cout << std::endl;
	std::cout << "Which direction would like to go?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Up (Imperial Treasury)" << std::endl;
	std::cout << "2. Down (current room south wall)" << std::endl;
	std::cout << "3. Left (Library of Ahmet III)" << std::endl;
	std::cout << "4. Right (current room east wall)" << std::endl;
	std::cout << "5. Walk to the small closet door" << std::endl;
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
			std::cout << "1. Up (Imperial Treasury)" << std::endl;
			std::cout << "2. Down (current room south wall)" << std::endl;
			std::cout << "3. Left (Library of Ahmet III)" << std::endl;
			std::cout << "4. Right (current room east wall)" << std::endl;
			std::cout << "5. Walk to the small closet door" << std::endl;
			std::cout << std::endl;

		}

		int user_choice = input_range_validate(5);

		switch (user_choice)
		{
		case 1:
			// go to imperial treasury room
			std::cout << std::endl;
			std::cout << "You head into Imperial Treasury room...." << std::endl;
			std::cout << std::endl;
			return up;
			break;
		case 2:
			// head towards palace kitchen down/south wall
			std::cout << std::endl;
			std::cout << "There is not much along this wall other than old stoves." << std::endl;
			std::cout << "Seems a bit interesting but it's clear there is nothing here for you to see or find." << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			// go to library of ahmet III
			std::cout << std::endl;
			std::cout << "You step back into Library of Ahmet III." << std::endl;
			std::cout << std::endl;
			return left;
			break;
		case 4:
			// head towards palace kitchen right/east wall
			std::cout << std::endl;
			std::cout << "The wall has an expansize exhibit of kitchen utensils, as as well as a large \n"
				      << "collection of porcelain. You wonder if any of this stuff is worths something so you read \n" 
			          << "the plaque on the wall: \n" 
			          << "\n----The Ottomans had access to Chinese porcelains from the mid-fifteenth century onward.---\n" 
			          << "\nPorcelain is too big to carry in the backpack...besides, none of these items are part of your mission.\n" 
					  <<"Nothing else to see here... need to move on." << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			// open closet
			// if agent doesn't have crowbar yet, grab it
			// crowbar is needed to open locked door in library 
			// that leads out to courtyard
			if (!agent->search_backpack_contents("crowbar"))
			{
				// call method to pick up the crowbar
				get_crowbar(agent);
			}
			else 
			{
				std::cout << std::endl;
				std::cout << "You've already checked this closet." << std::endl;
				std::cout << std::endl;
			}
			break;
		
		}

		counter++;
	}
}



void Kitchen::get_crowbar(Agent * agent)
{
	std::cout << std::endl;
	std::cout << "There are few misc tools inside the closet. Although it's strange to see a\n"
		<< " crowbar inside the museum, you have a hunch that it might come in handy." << std::endl;
	std::cout << std::endl;
	std::cout << "So...you pick it up and put it inside your backpack." << std::endl;
	std::cout << std::endl;

	// add crowbar to agent's backpack
	agent->put_inside_backpack(new Item("crowbar"));

}


int Kitchen::getRoomNumber()
{
	return area_number;
}



void Kitchen::set_up(Space * u_area)
{
	up = u_area;
}


void Kitchen::set_right(Space * r_area)
{
	right = r_area;
}



void Kitchen::set_down(Space * d_area)
{
	down = d_area;
}



void Kitchen::set_left(Space * l_area)
{
	left = l_area;
}




