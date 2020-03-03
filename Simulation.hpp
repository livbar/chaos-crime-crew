
#ifndef GAME_HPP
#define GAME_HPP
#include "Agent.hpp"
#include "Library.hpp"
#include "Courtyard.hpp"
#include "Palace_Kitchen.hpp"
#include "Chamber.hpp"
#include "Harem.hpp"
#include "Treasury.hpp"



class Simulation
{
	private:
		Agent * agent;

		Space * current_room;
		Space * library;
		Space * courtyard;
		Space * kitchen;
		Space * chamber;
		Space * harem;
		Space * treasury;

	protected:

	public:
	Simulation();
	~Simulation();
	void main_menu();

	void mission_objective();
	void print_map(Space *);
};
#endif
