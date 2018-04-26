#pragma once
#include <string>
#include <iostream>
#include <vector>

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
	coords getCoords() const;
	void setName(string name);
	void setTeam(char team);
	void printPeice() const;
	void setCoords(int,int);
	Peice initSetCoords(int, int);
	void setValidMoves();
	//vector<coords> validMoves;

private:
	string name;
	char team;
	coords coordinates;
	
	
	
};
