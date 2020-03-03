#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	private:
		std::string name;
		
	protected:

	public:
		Item(std::string);
		virtual ~Item();

		std::string get_item_name();

};
#endif
