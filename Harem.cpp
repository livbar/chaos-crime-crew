#include "Harem.hpp"


// constructor
Harem::Harem()
{
	area_number = 5;
	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
	
	
}



// function that describes library setting/surroundings
void Harem::room_setting()
{
	std::cout << "You are now in the Harem." << std::endl;
	std::cout << "There is a small pool in the center and from the place your standing you can see something \n"
		<< "sparking at the bottom." << std::endl;
	std::cout << std::endl;
}


// function for agent to either move out of the Harem or perform an action
Space * Harem::move_choices(Agent * agent)
{
	std::cout << std::endl;
	std::cout << "Which direction would like to go?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Up (current room north wall)" << std::endl;
	std::cout << "2. Down (Audience Chamber)" << std::endl;
	std::cout << "3. Left (current room west wall)" << std::endl;
	std::cout << "4. Right (current room east wall)" << std::endl;
	std::cout << "5. Head to pool to grab the shiny object" << std::endl;
	std::cout << std::endl;


	int counter = 1;
	while (true)
	{
		
		if (counter > 1)
		{
			std::cout << std::endl;
			std::cout << "Which direction would like to go?" << std::endl;
			std::cout << std::endl;
			std::cout << "1. Up (current room north wall)" << std::endl;
			std::cout << "2. Down (Audience Chamber)" << std::endl;  
			std::cout << "3. Left (current room west wall)" << std::endl;
			std::cout << "4. Right (current room east wall)" << std::endl;
			std::cout << "5. Head to pool to grab the shiny object" << std::endl;
			std::cout << std::endl;
		}


		int user_choice = input_range_validate(5);

		switch (user_choice)
		{
		case 1:
			// agent heads to north wall
			std::cout << std::endl;
			std::cout << "Not much to see here other than a bunch of old portraits of women that once lived \n"
			          << "inside the harem. Nothing else to see here." << std::endl;
			std::cout << std::endl;
			break;
		case 2:
			// agent heads to Audience Chamber
			std::cout << std::endl;
			std::cout << "You head south to the Audience Chamber....." << std::endl;
			std::cout << std::endl;
			return down;
			break;
		case 3:
			// agent heads to west wall
			std::cout << std::endl;
			std::cout << "You head to the left wall and have a look around. There is not much to see here \n "
			          << "other than look out the window which overlooks a gate secured garden." << std::endl;
			std::cout << std::endl;
			break;
		case 4:
			// agent heads to right/east wall
			std::cout << std::endl;
			std::cout << "There is a large marble table and on it is a tray of Turkish Delight. \n"
					  << "You grab a piece and eat it." << std::endl;
			std::cout << std::endl;
			if(agent->get_strength() > 70)
			{
				std::cout << std::endl;
				std::cout << "Don't forget that you can't go around stuffing your face with sugar." << std::endl;
				std::cout << "..... don't eat anymore and get back to your mission." << std::endl;
				std::cout << std::endl;
				
			}
			else if(agent->get_strength() < 20)
			{
				std::cout << std::endl;
				std::cout << "You've just increased your strength!" << std::endl;
				agent->increase_blood_glucose(15);
				std::cout << std::endl;

			}
			else
			{
				std::cout << std::endl;
				std::cout << "Don't get distracted!...don't eat anymore and get back to your mission." << std::endl;
				std::cout << std::endl;

			}			
			break;
		case 5:
			if (!agent->search_backpack_contents("diamond"))
			{
				std::cout << std::endl;
				std::cout << "You walk into the pool and slowly dive under to reach for the shiny object.\n"
					<< "....it's an ornate box decorated with gemstones. You open it and you see a small flash.\n"
					<< "So sparkly...The Spoonmaker's Diamond!! The fourth largest diamond in the world!" << std::endl;
				std::cout << std::endl;
				std::cout << "You grab it and put it inside your backpack then toss the shiny box back into the pool." << std::endl;
				agent->put_inside_backpack(new Item("diamond"));
				std::cout << std::endl;

			}
			else
			{
				std::cout << std::endl;
				std::cout << "You already got soaked...and know that the box is empty....." << std::endl;
				std::cout << "Look elsewhere inside this room or leave." << std::endl;
				std::cout << std::endl;

			}
			break;
		
		}

		counter++;

	}

}


int Harem::getRoomNumber()
{
	return area_number;
}





void Harem::set_up(Space * u_area)
{
	up = u_area;
}


void Harem::set_right(Space * r_area)
{
	right = r_area;
}



void Harem::set_down(Space * d_area)
{
	down = d_area;
}



void Harem::set_left(Space * l_area)
{
	left = l_area;
}









