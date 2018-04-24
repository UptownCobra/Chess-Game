#pragma once
#include <string>
#include <iostream>
#include "Cords.cpp"

using namespace std;
struct coords
{
	int x;
	int y;
};

class Peice
{
public:
	Peice();
	Peice(char team, string name);
	~Peice();
//	coords * validMoves(coords init);
	string getName() const;
	char getTeam() const;
	void setName(string name);
	void setTeam(char team);
	void printPeice() const;

private:
	string name;
	char team;
	
	
};
