#include "Agent.hpp"



// constructor
Agent::Agent()
{
	// agent object starts off with strength of 80
	strength = 80;

}


// destructor
Agent::~Agent() {}



// method to return agent strength
int Agent::get_strength()
{
	return strength;

}



// method increases agents strength by amount passed in
void Agent::increase_blood_glucose(int plus_amt)
{
	int add_strength = plus_amt;

	strength = strength + add_strength;

}



// method decreases agents strength by amount passed in
void Agent::decrease_blood_glucose(int minus_amt)
{
	int deduct_strength = minus_amt;

	strength = strength - deduct_strength;
		
}




// add item to agents backpack 
void Agent::put_inside_backpack(Item * added_item)
{
	// add item to backpack vector
	backpack_items.push_back(added_item);

}



// bool returns true if item passed in is found in backpack; else, false.
bool Agent::search_backpack_contents(std::string item_name)
{
	int amount = backpack_items.size();
	

	for (int i = 0; i < amount; i++)
	{

		if (backpack_items[i]->get_item_name() == item_name)
		{
			return true;
		}
	}

	return false;

}



// method returns contents of backpack
void Agent::get_backpack_contents()
{

	int amount = backpack_items.size();

	for (int i = 0; i < amount; i++)
	{
		std::cout << backpack_items[i]->get_item_name() << ", " << std::endl;
	}

}
