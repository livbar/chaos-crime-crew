#include "Space.hpp"

#ifndef COURTYARD_HPP
#define COURTYARD_HPP

class Courtyard : public Space
{

	private:
		int area_number;
		Space * up;
		Space * down;
		Space * left;
		Space * right;

	protected:

	public:
		Courtyard();
		
		virtual void room_setting();
		virtual int getRoomNumber();

		virtual Space * move_choices(Agent *);
	
		virtual void set_up(Space *);
		virtual void set_right(Space *);
		virtual void set_down(Space *);
		virtual void set_left(Space *);
		
		
};
#endif
