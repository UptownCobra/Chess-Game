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
	Peice wPawn(w,"P ", board) ,bPawn(b, "P ", board);
	Peice wRook(w, "R ", board), bRook(b, "R ", board);
	Peice wKnight(w, "Kn", board), bKnight(b, "Kn", board);
	Peice wBishop(w, "B ", board), bBishop(b, "B ", board);
	Peice wKing(w, "K ", board), bKing(b, "K ", board);
	Peice wQueen(w, "Q ", board), bQueen(b, "Q ", board);
	Peice Null;
	Peice initBoard[8][8] = { 
		{  wRook, wKnight, wBishop, wKing, wQueen, wBishop, wKnight, wRook },
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

Peice Board::getPeice(coords init) 
{
	return board[init.x][init.y];
}
/*
coords Board::getCoords() const
{
	coords init;
	return init;
}*/



void Board::getMove()
{

}

bool Board::moveIsValid(Peice peice, coords end)
{
	bool valid = false;
	if (find(peice.validMoves.begin(), peice.validMoves.end(), end) != peice.validMoves.end())
		valid = true;
	return valid;
	
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
	starting.setCoords(end.x, end.y);
	starting.setValidMoves();
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
			x.setValidMoves();
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