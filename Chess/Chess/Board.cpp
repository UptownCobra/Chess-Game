#include "Board.h"



Board::Board()
{
	init();
	setPeiceCoords();
}


Board::~Board()
{
}


void Board::init()
{
	char w = 'W';
	char b = 'B';
	Pawn wPawn(w) ,bPawn(b);
	Rook wRook(w), bRook(b);
	Knight wKnight(w), bKnight(b);
	Bishop wBishop(w), bBishop(b);
	King wKing(w), bKing(b);
	Queen wQueen(w), bQueen(b);
	Peice Null;

	Peice initBoard[8][8] = { 
		{ wRook, wKnight, wBishop, wKing, wQueen, wBishop, wKnight, wRook },
		{wPawn, wPawn, wPawn, wPawn, wPawn, wPawn, wPawn, wPawn },
		{ Null, Null, Null, Null, Null, Null, Null, Null },
		{ Null, Null, Null, Null, Null, Null, Null, Null },
		{ Null, Null, Null, Null, Null, Null, Null, Null },
		{ Null, Null, Null, Null, Null, Null, Null, Null },
		{ bPawn, bPawn, bPawn, bPawn, bPawn, bPawn, bPawn, bPawn },
		{ bRook, bKnight, bBishop, bQueen, bKing, bBishop, bKnight, bRook },
	};
	setBoard(initBoard);
	
}
void Board::setBoard(Peice initBoard[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
			board[i][j] = initBoard[i][j];
		}
	}
}

Peice Board::getPeice(coords init) const
{
	 
	return board[init.x][init.y];
}

coords Board::getCoords() const
{
	coords init{ 0,0 };
	return init;
}



void Board::getMove()
{

}

bool Board::moveIsValid(Peice toMove, coords init, coords end)
{
	return true;
}

bool Board::peiceToTake(coords end)
{
	return true;
}

void Board::takePeice(coords end)
{
	
}

void Board::setCoordsInit(int x, int y)
{
}

void Board::setCoordsEnd(int x, int y)
{
}

void Board::print() const
{
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		std::cout << "----------------------------------------------------------" << std::endl;
		for (int j = 0; j < 8; j++)
		{
			std::cout << "| ";
			board[i][j].printPeice();
			std::cout << " ";
		}
		std::cout << " |" << std::endl;
	}
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

void Board::movePiece(coords init, coords end)
{
	Peice x;
	Peice Null;
	x = getPeice(init);
	board[init.x][init.y] = Null;
	board[end.x][end.y] = x;
}

void Board::setPeiceCoords()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Peice x = board[i][j];
			x.setCoords(i, j);
			board[i][j] = x;
		}
	}
}
