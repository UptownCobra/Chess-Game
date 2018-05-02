#include "coords.h"



coords::coords()
{
}


coords::~coords()
{
} 
bool coords::operator== (const coords& xy) const
{
	return (x == xy.x && y == xy.y);
}

bool coords::operator != (coords& xy)
{
	return (x != xy.x && y != xy.y);
}
