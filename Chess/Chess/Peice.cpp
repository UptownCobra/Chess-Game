#include "Peice.h"



Peice::Peice()
{
	setName("  ");
	setTeam(' ');
}

Peice::Peice(char team, string name)
{
	setName(name);
	setTeam(team);
	setCoords(NULL, NULL);

}


Peice::~Peice()
{
}

void Peice::printPeice() const
{
	if (getName() != " ")
		std::cout << getTeam() << ":" << getName();
	else
		std::cout << "    ";
}

//coords * Peice::validMoves(coords init)
//{
//	static coords validMoves[10];
//}


string Peice::getName() const
{
	return name;
}
char Peice::getTeam() const
{
	return team;
}

coords Peice::getCoords() const
{
	return coordinates;
}

void Peice::setName(string new_name)
{
	name = new_name;
}
void Peice::setTeam(char new_team)
{
	team = new_team;
}


void Peice::setCoords(int x, int y)
{
	coordinates.x = x;
	coordinates.y = y;
	setValidMoves();

}
void Peice::setValidMoves()
{

}

Peice Peice::initSetCoords(int i, int j)
{
	Peice self = *this;
	self.setCoords(i, j);
	self.setValidMoves();
	return self;
}