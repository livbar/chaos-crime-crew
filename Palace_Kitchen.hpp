#include "Space.hpp"

#ifndef PALACE_KITCHEN_HPP
#define PALACE_KITCHEN_HPP



class Kitchen : public Space
{
	private:
		int area_number;
		Space * up;
		Space * right;
		Space * down;
		Space * left;
		
	protected:	

	public:
		Kitchen();
		virtual void room_setting();
		virtual int getRoomNumber();

		virtual Space * move_choices(Agent *);

		virtual void set_up(Space *);
		virtual void set_right(Space *);
		virtual void set_down(Space *);
		virtual void set_left(Space *);
		

		void get_crowbar(Agent *);

		

};
#endif
