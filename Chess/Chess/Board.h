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
	void init() const;
	Peice getPeice(coords init) const;
	coords getCoordsInit() const;
	coords getCoordsEnd() const;

	bool moveIsValid(Peice toMove, coords init, coords end);
	bool peiceToTake(coords end);

	void takePeice(coords end);
	void setCoordsInit(int x, int y);
	void setCoordsEnd(int x, int y);
	void print() const;
	void movePiece(Peice toMove, coords init, coords end);


private:
	Peice board[8][8];
	coords coordsInit;
	coords coordsEnd;



};

