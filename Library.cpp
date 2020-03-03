#include "Library.hpp"


// constructor
Library::Library()
{
	area_number = 1;
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
	

}




// method that describes library setting/surroundings
void Library::room_setting()
{
	
	std::cout << "You are in the Library of Ahmed III. There are bookshevles all around. " 
		<< "The library\nis a beautiful example of Ottoman architecture of the 18th century. "
		<< "The walls above\nthe windows are decorated with 16th- and 17th-century Iznik tiles "
		<< "of variegated design." << std::endl;
	std::cout << std::endl;
	std::cout << "On one of the shelves, you see a wooden box with designs carved all around it." << std::endl;
	std::cout << std::endl;	
	std::cout << "There's a thick, wooden door with a big, metal lock on it. " << std::endl;
	
	
	
	 
}



// function for agent to either move out of the library or perform an action
// returns pointer to next room chosen
Space * Library::move_choices(Agent * agent)
{
	// offer agent choices of directions to move and/or actions to perform
	std::cout << std::endl;
	std::cout << "Which direction would like to go?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Up (Audience Chamber)" << std::endl;
	std::cout << "2. Down (current room south wall)" << std::endl;
	std::cout << "3. Left (Courtyard)" << std::endl;
	std::cout << "4. Right (Palace Kitchen)" << std::endl;
	std::cout << "5. Pick up Turkish Puzzle Box(from shelf)" << std::endl; 
	std::cout << std::endl;

	int counter = 1;
	
	// while agent is in room, keep presenting choices to directions/actions
	// until he/she moves out into another room
	while (true)
	{
		
	
		if (counter > 1)
		{

			std::cout << "Which direction would like to go?" << std::endl;
			std::cout << std::endl;
			std::cout << "1. Up (Audience Chamber)" << std::endl;
			std::cout << "2. Down (towards current room south wall)" << std::endl;
			std::cout << "3. Left (Courtyard)" << std::endl;
			std::cout << "4. Right (Palace Kitchen)" << std::endl;
			std::cout << "5. Pick up Turkish Puzzle Box (from shelf)" << std::endl;
			std::cout << std::endl;

		}


		int user_choice = input_range_validate(5);



		switch (user_choice)
		{
		case 1:
			std::cout << "You head up towards Audience Chamber...." << std::endl;
			std::cout << std::endl;
			return up;
			break;
		case 2:
			std::cout << std::endl;
			std::cout << "This side of the room is the window is where you came in from outside." << std::endl;
			std::cout << "The window is now sealed shut, there's no going out this way." << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl;
			
			if (agent->search_backpack_contents("crowbar"))
			{
				std::cout << std::endl;
				std::cout << "Ha! You knew the crowbar would come in handy!!" << std::endl;
				std::cout << "You take it out of the backpack and use it to break the metal lock on the door." << std::endl;
				std::cout << "Then step out into to the courtyard." << std::endl;
				std::cout << std::endl;
				return left;
			}
			
				std::cout << std::endl;
				std::cout << "You try to pull the lock off it sort of moves a bit but your bare hands aren't \n"
						  << "strong enough to break it. Ughh...You're going to need to find something to \n"
				          << "break it with or another way out of this room" << std::endl;
				std::cout << std::endl;
			break;
		case 4:
			std::cout << "You head up towards Palace Kitchen...." << std::endl;
			std::cout << std::endl;
			return right;
			break;
		case 5:
			// if agent picks up puzzle box and has key in backpack
			if (agent->search_backpack_contents("key"))
			{
				// call method to unlock puzzle box
				unlock_puzzlebox(agent);
			}
			// if agent picks up puzzle box but does NOT have key
			else
			{
				std::cout << std::endl;
				std::cout << "Hmm..looks like you need some sort of key to open it." << std::endl;
				std::cout << "You might find it somewhere inside this palace." << std::endl;
				std::cout << std::endl;
			}
			break;
		}
				
		counter++;
	}


}



// method to unlock Turkish puzzlebox which contains map 
void Library::unlock_puzzlebox(Agent * agent)
{
	
	std::cout << "The key opens the puzzle box and inside is the Piri Reis Map (First World Map) !! Score!!" << std::endl;
	std::cout << "You gently take it out of the box and put it inside your backpack." << std::endl;
	std::cout << std::endl;

	// add map to agent's backpack
	agent->put_inside_backpack(new Item("map"));
	
}




int Library::getRoomNumber()
{
	return area_number;
}




void Library::set_up(Space * u_area)
{
	up = u_area;
}


void Library::set_right(Space * r_area)
{
	right = r_area;
}



void Library::set_down(Space * d_area)
{
	down = d_area;
}



void Library::set_left(Space * l_area)
{
	left = l_area;
}







