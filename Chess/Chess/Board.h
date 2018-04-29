#pragma once
#include "Peice.h"
#include "Cords.cpp"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


class Board
{
public:
	Board();
	~Board();
	void init();
	bool getKingTaken() const;
	Peice getPeice(coords init) const;
	coords getCoords() const;
	coords getInput();
	void getMove();
	bool moveIsValid(Peice toMove, coords init, coords end);
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

