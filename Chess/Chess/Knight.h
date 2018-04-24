#pragma once
#include "Peice.h"
class Knight :
	public Peice
{
public:
	Knight(char);
	~Knight();
	string getName();
	void setName(string);
	void printPeice() ;
private:
	string name = "Kn";
};

