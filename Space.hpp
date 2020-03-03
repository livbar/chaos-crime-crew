#include "Agent.hpp"
#include <iostream>
#include "Input_Validation.hpp"


#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	private:
		Space * up;
		Space * down;
		Space * left;
		Space * right;

		int room_num; //////////////////////// need to number rooms?? probably not

	protected:
			
	public:
		Space();
		virtual ~Space();
		
		virtual void set_up(Space *) = 0;
		virtual void set_down(Space *) = 0;
		virtual void set_left(Space *) = 0;
		virtual void set_right(Space *) = 0;

		virtual void room_setting() = 0;
		virtual int getRoomNumber() = 0;  ///////////////////////////////////////////////////////////////////

		virtual Space * move_choices(Agent *) = 0; // Passing agent object for adding backpack_items items.

};
#endif
