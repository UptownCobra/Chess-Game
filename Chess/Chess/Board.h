#pragma once
/*
#include "Peice.h"
#include<algorithm>
*/

#include "Peice.h"


class Board
{
public:
	Board();
	~Board();
	void init();
	bool getKingTaken() const;
	Peice getPeice(coords init);
//	coords getCoords() const;
	coords getInput();
	void getMove();
	bool moveIsValid(Peice toMove, coords end);
	bool peiceToTake(coords end);
	void setBoard(Peice initBoard[8][8]);
	void takePeice(coords end);
	void setCoordsInit(int x, int y);
	void setCoordsEnd(int x, int y);
	void print() const;
	void movePiece(coords init, coords end);
	void setPeiceCoords();
	void setkingTakenTrue();
	


private:
	Peice board[8][8];
	coords coordsInit;
	coords coordsEnd;
	bool kingTaken = false;
};

