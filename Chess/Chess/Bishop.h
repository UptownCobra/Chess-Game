#pragma once
#include "Peice.h"
class Bishop :
	public Peice
{
public:
	Bishop(char);
	~Bishop();
	coords validMooves[];
	void setValidMooves(coords initPos, coords endPos);
private:
	

};


