#include "Item.hpp"
#include <iostream>
#include <vector>



#ifndef AGENT_HPP
#define AGENT_HPP


class Agent
{

		private:
		std::vector<Item *> backpack_items;
		int strength;

		protected:

		public:
		Agent();
		~Agent();


	    // agent is diabetic and must finish mission
		// in time for his next dose of insulin
		int get_strength();
		void decrease_blood_glucose(int);
		void increase_blood_glucose(int);
	
		// agent carries a backpack to place items
		void put_inside_backpack(Item *);
		bool search_backpack_contents(std::string);
		void get_backpack_contents();
	
		
};
#endif
