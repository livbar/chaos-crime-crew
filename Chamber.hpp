#include "Space.hpp"


#ifndef CHAMBER_HPP
#define CHAMBER_HPP


class Chamber : public Space
{
	
	private:
		int area_number;
		Space * up;
		Space * down;
		Space * left;
		Space * right;
		
	protected:	 

	public:
		Chamber();
		virtual void room_setting();
		virtual int getRoomNumber();

		virtual Space* move_choices(Agent *);
		
		virtual void set_up(Space *);
		virtual void set_right(Space *);
		virtual void set_down(Space *);
		virtual void set_left(Space *);
		
		
		void grab_key(Agent *);
			

};
#endif
