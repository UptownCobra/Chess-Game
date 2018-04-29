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
	cout << "          1      2      3      4      5      6      7      8  " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "      ----------------------------------------------------------" << endl;
		switch (i)
		{
		case 0:	cout << "  A   ";
			break;
		case 1:	cout << "  B   ";
			break;
		case 2:	cout << "  C   ";
			break;
		case 3:	cout << "  D   ";
			break;
		case 4:	cout << "  E   ";
			break;
		case 5:	cout << "  F   ";
			break;
		case 6:	cout << "  G   ";
			break;
		case 7: cout << "  H   ";
			break;
		}



		for (int j = 0; j < 8; j++)
		{
			cout << "| ";
			if (board[i][j].getName() == "  ")
				cout << "     ";
			else
			{
				board[i][j].printPeice();
				cout << " ";
			}
		}
		cout << "|" << std::endl;
	}
	cout << "      ----------------------------------------------------------" << endl << endl;
}

void Board::movePiece(coords init, coords end)
{
	Peice starting;
	Peice ending;
	Peice Null;
	starting = getPeice(init);
	ending = getPeice(end);
	board[init.x][init.y] = Null;
	board[end.x][end.y] = starting;
	if (ending.getName() == "K ")
		setkingTakenTrue();
	
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

void Board::setkingTakenTrue()
{
	kingTaken = true;
}

bool Board::getKingTaken() const
{
	return kingTaken;
}

coords Board::getInput()
{
	coords coordinates;
	string strCoords;
	
	
	cin >> strCoords;
	switch (strCoords[0])
	{
	case 'A':
	case 'a':
		coordinates.x = 0;
		break;
	case 'B':
	case 'b':
		coordinates.x = 1;
		break;
	case 'C':
	case 'c':
		coordinates.x = 2;
		break;
	case 'D':
	case 'd':
		coordinates.x = 3;
		break;
	case 'E':
	case 'e':
		coordinates.x = 4;
		break;
	case 'F':
	case 'f':
		coordinates.x = 5;
		break;
	case 'G':
	case 'g':
		coordinates.x = 6;
		break;
	case 'H':
	case 'h':
		coordinates.x = 7;
		break;
	default:
		coordinates.x = -1;
		break;
	}
	switch (strCoords[1])
	{
	case '1':
		coordinates.y = 0;
		break;
	case '2':
		coordinates.y = 1;
		break;
	case '3':
		coordinates.y = 2;
		break;
	case '4':
		coordinates.y = 3;
		break;
	case '5':
		coordinates.y = 4;
		break;
	case '6':
		coordinates.y = 5;
		break;
	case '7':
		coordinates.y = 6;
		break;
	case '8':
		coordinates.y = 7;
		break;
	default:
		coordinates.y = -1;
		break;
	}

	return coordinates;
}