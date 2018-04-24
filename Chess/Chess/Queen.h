#pragma once
#include "Peice.h"
class Queen :
	public Peice
{
public:
	Queen(char);
	~Queen();

private:
	char name = 'Q';
};

