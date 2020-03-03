#include "Space.hpp"
#include <cstdlib>

#ifndef TREASURY_HPP
#define OUTSIDE_HPP


class Treasury : public Space
{

	private:
		int area_number;
		Space *up;
		Space *down;
		Space *left;
		Space *right;

		
	protected:


	public:
		Treasury();
		virtual void room_setting();
		virtual int getRoomNumber();

		virtual Space* move_choices(Agent *);

		virtual void set_up(Space *);
		virtual void set_right(Space *);
		virtual void set_down(Space *);
		virtual void set_left(Space *);
		
		
		void get_dagger(Agent *);

};
#endif
