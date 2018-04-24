#pragma once
#include<iostream>
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
	Peice getPeice(coords init) const;
	coords getCoords() const;
	void getMove();
	bool moveIsValid(Peice toMove, coords init, coords end);
	bool peiceToTake(coords end);
	void setBoard(Peice initBoard[8][8]);
	void takePeice(coords end);
	void setCoordsInit(int x, int y);
	void setCoordsEnd(int x, int y);
	void print() const;
	void movePiece(Peice toMove, coords init, coords end);
	

private:
	Peice board[8][8];
	coords coordsInit;
	coords coordsEnd;
	/*Board() : wPawn('W');
	Board() : bPawn('B');
	Board() : wRook('W');
	Board() : bRook('B');
	Board() : wKnight('W');
	Board() : bKnight('B');
	Board() : wBishop('W');
	Board() : bBishop('B');
	Board() : wQueen('W'), bQueen('B');
	Board() : wKing('W'), bKing('B');
	Board() : Null();*/
/*
	Pawn wPawn;
	Pawn bPawn;
	Rook wRook;
	Rook bRook;
	Knight wKnight;
	Knight bKnight;
	Bishop wBishop;
	Bishop bBishop;
	Queen wQueen, bQueen;
	King wKing, bKing;
	Peice Null;
	*/
};

