#include "Peice.h"



Peice::Peice()
{
	setName("  ");
	setTeam(' ');
}

Peice::Peice(char team, string name, Peice p[8][8])
{
	setName(name);
	setTeam(team);
	board = *p;
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
	

}
void Peice::setValidMoves()
{
	string peice;
	peice = getName();
	validMoves.clear();
	switch (peice[0])
	{
	case 'B':
		setBishopMoves();
		break;
	case 'K':
		if (peice == "Kn")
		{
			setKnightMoves();
			break;
		}
		else
			setKingMoves();
		break;
	case 'P':
		setPawnMoves();
		break;
	case 'Q':
		setQueenMoves();
		break;
	case 'R':
		setRookMoves();
		break;
	}

}

Peice Peice::initSetCoords(int i, int j)
{
	Peice self = *this;
	self.setCoords(i, j);
	return self;
}
bool Peice::coordsValid(coords pos)
{
	bool i = false;
	if (pos.x < 8 && pos.x >= 0)
	{
		if (pos.y < 8 && pos.y >= 0)
			i = true;
	}
	return i;
}


void Peice::setKnightMoves()
{
	coords pos;
	coords newPos;
	int y = 2;
	pos = getCoords();
	for (int x = 1; x < 3; x++)
	{
		if (x == 2)
			y = 1;
		newPos.x = pos.x - x;
		newPos.y = pos.y - y;
		if (coordsValid(newPos))
			validMoves.push_back(newPos);
		newPos.x = pos.x - x;
		newPos.y = pos.y + y;
		if (coordsValid(newPos))
			validMoves.push_back(newPos);
		newPos.x = pos.x + x;
		newPos.y = pos.y - y;
		if (coordsValid(newPos))
			validMoves.push_back(newPos);
		newPos.x = pos.x + x;
		newPos.y = pos.y + y;
		if (coordsValid(newPos))
			validMoves.push_back(newPos);
	}
}
void Peice::setPawnMoves  ()
{

}
void Peice::setBishopMoves()
{

}
void Peice::setKingMoves  ()
{

}
void Peice::setQueenMoves ()
{

}
void Peice::setRookMoves  ()
{

}