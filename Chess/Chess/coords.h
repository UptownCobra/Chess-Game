#pragma once


class coords
{
public:
	coords();
	~coords();
	bool operator== (const coords&) const;
	bool operator!= (coords&);
	int x;
	int y;
private:
	
};

