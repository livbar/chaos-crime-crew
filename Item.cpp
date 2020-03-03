#include "Item.hpp"


// constructor
Item::Item(std::string name)
{
	this->name = name;

}


// destructor
Item::~Item()
{
	
}



// method to return name of item
std::string Item::get_item_name()
{
	return name;
}