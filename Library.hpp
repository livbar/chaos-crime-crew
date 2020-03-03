#include "Space.hpp"

#ifndef LIBRARY_HPP
#define LIBRARY_HPP


class Library : public Space
{
	private:
		int area_number;
		Space * up;
		Space * down;
		Space * left;
		Space * right;

	protected:

	public:
		Library();

		virtual void room_setting();
		virtual int getRoomNumber();

		virtual Space* move_choices(Agent *);
		
		virtual void set_up(Space *);
		virtual void set_right(Space *);
		virtual void set_down(Space *);
		virtual void set_left(Space *);
				
		// puzzlebox method that holds Piri Reis Map (First World Map)
		virtual void unlock_puzzlebox(Agent *);
		
};
#endif
