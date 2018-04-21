#pragma once
#include <string>
#include <iostream>
#include "Cords.cpp"

using namespace std;

class Peice
{
public:
	Peice();
	Peice(string name, string team);
	~Peice();
	coords * validMoves(coords init);
	string getName() const;
	string getTeam() const;
	void setName(string name);
	void setTeam(string team);
	void printPeice() const;

private:
	string name;
	string team;
	
	
};
