#pragma once
#include "Peice.h"
class Board_Square
{
public:
	Board_Square();
	~Board_Square();

private:
	Peice peice;
	char team;
	int x;
	int y;

};

