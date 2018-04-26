#pragma once
#include "Peice.h"
class Bishop :
	public Peice
{
public:

	Bishop(char);
	~Bishop();
	
	void setValidMooves(coords pos);
private:
	

};


