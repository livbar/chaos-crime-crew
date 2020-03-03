#include "Simulation.hpp"


// constructor
Simulation::Simulation()
{

	agent = new Agent();

	library = new Library();
	current_room = library;

	courtyard = new Courtyard();
	kitchen = new Kitchen();
	chamber = new Chamber();
	harem = new Harem();
	treasury = new Treasury();

	
	// library of Ahmet III
	library->set_left(courtyard);
	library->set_right(kitchen);
	library->set_up(chamber);

	// First Courtyard
	courtyard->set_right(library);

	// Palace Kitchen
	kitchen->set_left(library);
	kitchen->set_up(treasury);

	// Audience Chamber
	chamber->set_down(library);
	chamber->set_up(harem);
	chamber->set_right(treasury);

	// Harem
	harem->set_down(chamber);
	

	// Imperial Treasury
	treasury->set_left(chamber);
	treasury->set_down(kitchen);

}



// destructor
Simulation::~Simulation()
{
	// deallocate all memory
	delete library;
	delete courtyard;
	delete kitchen;
	delete chamber;
	delete harem;
	delete treasury;
	delete agent;
}








// simulation main menu
void Simulation::main_menu()
{
	int steps = 1;



	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << "\t\tChaos Crime Crew Initiation " << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Greetings. We've been watching you for a while and are aware of \n"
			  << "your cat burglar skills and would like to extend an inviation to \n"
			  << "join our organization (CCC)." << std::endl;
	std::cout << std::endl;
	std::cout << "In order to join, you'll need to 'acquire' some extremely valuable items \n"
			  << "from the Topkapi Palace in Istanbul, Turkey. If you accept, all mission \n"
			  << "related expenses will be paid for you." << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "Do you accept the mission?" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Yes, sign me up!" << std::endl;
	std::cout << "2. No, I am not interested." << std::endl;
	int user_choice = input_range_validate(2);

	
	if (user_choice == 2)
	{
		std::cout << std::endl;
		std::cout << "Such a shame....goodbye." << std::endl;
		std::cout << std::endl;
		// exit program
		std::exit(0);

	}



	// call mission objective function
	mission_objective();
	
	
	
	while (agent->get_strength() > 0)
	{
		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "     Strength Status Report" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "Steps taken during mission: " << steps << std::endl;
		std::cout << "Blood Sugar Level: " << agent->get_strength() << std::endl;
		std::cout << "--------------------------------" << std::endl;

		if(agent->get_strength() < 20)
		{
			std::cout << std::endl;
			std::cout << "Keep an eye on your blood sugar level" << std::endl;
			std::cout << std::endl;
		}

		// show agent current location
		print_map(current_room);


		// describe surroundings
		current_room->room_setting();

		
		current_room = current_room->move_choices(agent);

		// increment steps taken
		steps++;

		// each time the agent moves, decrease blood glucose
		agent->decrease_blood_glucose(5);

	}



	
	std::cout << "You took too long and now you're blood sugar has dropped two low....\n"
			  << "....everything around you goes dark." << std::endl;
	std::cout << std::endl;
	std::cout << "A few hours later, you wake up inside a Turkish prision." << std::endl;
	std::cout << std::endl;
	std::cout << "Simulation Over" << std::endl;
	std::cout << std::endl;
	
	// exit program
	std::exit(0);

	
}



// function display's agents current location by using a space pointer
void Simulation::print_map(Space * room)
{
	
	std::cout << std::endl;
	std::cout << "\tTopkapi Palace Map" << std::endl;
	std::cout << std::endl;

	switch (room->getRoomNumber())
	{
	case 1:
		std::cout << "            +------+                  \n"
			"            |      |                  \n"
			"            |      |                  \n"
			"            +------+                  \n"
			"               ||                     \n "
			"           +------+   +------+        \n"
			"            |      |---|      |       \n"
			"            |      |---|      |       \n"
			"            +------+   +------+       \n"
			"               ||         ||          \n "
			"+------+   +------+   +------+        \n"
			" |      |---|      |---|      |       \n"
			" |      |---|  @   |---|      |       \n"
			" +------+   +------+   +------+       \n" << std::endl;
		std::cout << "Your position is denoted by @ " << std::endl;
		std::cout << std::endl;
		std::cout << "Items collected: ";
		agent->get_backpack_contents();
		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;
		break;
	case 2:
		std::cout << "            +------+                  \n"
			"            |      |                  \n"
			"            |      |                  \n"
			"            +------+                  \n"
			"               ||                     \n "
			"           +------+   +------+        \n"
			"            |      |---|      |       \n"
			"            |      |---|      |       \n"
			"            +------+   +------+       \n"
			"               ||         ||          \n "
			"+------+   +------+   +------+        \n"
			" |      |---|      |---|      |       \n"
			" |  @   |---|      |---|      |       \n"
			" +------+   +------+   +------+       \n" << std::endl;
		std::cout << "Your position is denoted by @ " << std::endl;
		std::cout << std::endl;
		std::cout << "Items collected: ";
		agent->get_backpack_contents();
		std::cout << std::endl;
		break;
	case 3:
		std::cout << "            +------+                  \n"
			"            |      |                  \n"
			"            |      |                  \n"
			"            +------+                  \n"
			"               ||                     \n "
			"           +------+   +------+        \n"
			"            |      |---|      |       \n"
			"            |      |---|      |       \n"
			"            +------+   +------+       \n"
			"               ||         ||          \n "
			"+------+   +------+   +------+        \n"
			" |      |---|      |---|      |       \n"
			" |      |---|      |---|  @   |       \n"
			" +------+   +------+   +------+       \n" << std::endl;
		std::cout << "Your position is denoted by @ " << std::endl;
		std::cout << std::endl;
		std::cout << "Items collected: ";
		agent->get_backpack_contents();
		std::cout << std::endl;
		break;
	case 4:
		std::cout << "            +------+                  \n"
			"            |      |                  \n"
			"            |      |                  \n"
			"            +------+                  \n"
			"               ||                     \n "
			"           +------+   +------+        \n"
			"            |      |---|      |       \n"
			"            |  @   |---|      |       \n"
			"            +------+   +------+       \n"
			"               ||         ||          \n "
			"+------+   +------+   +------+        \n"
			" |      |---|      |---|      |       \n"
			" |      |---|      |---|      |       \n"
			" +------+   +------+   +------+       \n" << std::endl;
		std::cout << "Your position is denoted by @ " << std::endl;
		std::cout << std::endl;
		std::cout << "Items collected: ";
		agent->get_backpack_contents();
		std::cout << std::endl;
		break;
	case 5:
		std::cout << "            +------+                  \n"
			"            |      |                  \n"
			"            |  @   |                  \n"
			"            +------+                  \n"
			"               ||                     \n "
			"           +------+   +------+        \n"
			"            |      |---|      |       \n"
			"            |      |---|      |       \n"
			"            +------+   +------+       \n"
			"               ||         ||          \n "
			"+------+   +------+   +------+        \n"
			" |      |---|      |---|      |       \n"
			" |      |---|      |---|      |       \n"
			" +------+   +------+   +------+       \n" << std::endl;
		std::cout << "Your position is denoted by @ " << std::endl;
		std::cout << std::endl;
		std::cout << "Items collected: ";
		agent->get_backpack_contents();
		std::cout << std::endl;
		break;
	case 6:
		std::cout << "            +------+                  \n"
			"            |      |                  \n"
			"            |      |                  \n"
			"            +------+                  \n"
			"               ||                     \n "
			"           +------+   +------+        \n"
			"            |      |---|      |       \n"
			"            |      |---|  @   |       \n"
			"            +------+   +------+       \n"
			"               ||         ||          \n "
			"+------+   +------+   +------+        \n"
			" |      |---|      |---|      |       \n"
			" |      |---|      |---|      |       \n"
			" +------+   +------+   +------+       \n" << std::endl;
		std::cout << "Your position is denoted by @ " << std::endl;
		std::cout << std::endl;
		std::cout << "Items collected: ";
		agent->get_backpack_contents();
		std::cout << std::endl;
		break;
	default:
		std::cout << "Invalid entry..." << std::endl;
		break;
	}

	std::cout << std::endl;
}





void Simulation::mission_objective() 
{

	std::cout << std::endl;
	std::cout << "We have an operative that will disarm the alarm and leave a window open for you \n"
		      << "to get into the museum. You must collect three items from inside the museum. \n"
		      << "Once you are done, someone will be waiting to pick you up and bring you to our \n"
		      << "headquarters." << std::endl;
	std::cout << std::endl;
	
	std::cout << "The items you need to acquire are:" << std::endl;
	std::cout << std::endl;
	std::cout << "\tTopkapi Dagger";
	std::cout << std::endl;
	std::cout << "\tPiri Reis Map (First World Map) ";
	std::cout << std::endl;
	std::cout << "\tSpoonmaker's Diamond ";
	std::cout << std::endl;
	std::cout << std::endl;
	

	std::cout << "We are aware of your diabetic issue and suggest you bring some medication with you \n"
			  << "as you might be spending several hours inside the museum." << std::endl;
	std::cout << std::endl;
	std::cout << "Also, should you get captured, you're on your own." << std::endl;
	std::cout << "Iyi Sanslar.... that means Good Luck in Turkish." << std::endl;
	std::cout << std::endl;


}
