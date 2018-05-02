#pragma once
#include <string>
#include <iostream>
#include <vector>
//#include "Board.h"
#include "coords.h"

using namespace std;


class Peice
{
public:
	Peice();
	Peice(char team, string name);
	~Peice();

//	coords * validMoves(coords init);
	string getName() const;
	char getTeam() const;
	coords getCoords() const;
	void setName(string name);
	void setTeam(char team);
	void printPeice() const;
	void setCoords(int,int);
	Peice initSetCoords(int, int);
	void setValidMoves();
	bool coordsValid(coords);
	vector<coords> validMoves;
	void setKnightMoves();
	void setPawnMoves  ();
	void setBishopMoves();
	void setKingMoves  ();
	void setQueenMoves ();
	void setRookMoves  ();

private:
	string name;
	char team;
	coords coordinates;
	
	
	
};
