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
	Peice wPawn(w, "P ");
	Peice bPawn(b, "P ");
	Peice wRook(w, "R "), bRook(b, "R ");
	Peice wKnight(w, "Kn"), bKnight(b, "Kn");
	Peice wBishop(w, "B "), bBishop(b, "B ");
	Peice wKing(w, "K "), bKing(b, "K ");
	Peice wQueen(w, "Q "), bQueen(b, "Q ");
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
	setValidMove(starting);
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
			setValidMove(x);
			board[i][j] = x;
		}
	}
}

void Board::setkingTakenTrue()
{
	kingTaken = true;
}

void Board::setValidMove(Peice &peice)
{
	string peiceName;
	peiceName = peice.getName();
	peice.validMoves.clear();
	switch (peiceName[0])
	{
	case 'B':
		setBishopMoves(peice);
		break;
	case 'K':
		if (peiceName == "Kn")
		{
			setKnightMoves(peice);
			break;
		}
		else
			setKingMoves(peice);
		break;
	case 'P':
		setPawnMoves(peice);
		break;
	case 'Q':
		setQueenMoves(peice);
		break;
	case 'R':
		setRookMoves(peice);
		break;
	}
	if (peiceName == " P")
		setPawnMoves(peice);
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

void Board::setKnightMoves(Peice &peice)
{
	coords pos;
	coords newPos;
	int y = 2;


	pos = peice.getCoords();
//	vector<Peice> moves;
	for (int x = 1; x < 3; x++)
	{
		if (x == 2)
			y = 1;
		newPos.x = pos.x - x;
		newPos.y = pos.y - y;
		if (peice.coordsValid(newPos))
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
		newPos.x = pos.x - x;
		newPos.y = pos.y + y;
		if (peice.coordsValid(newPos))
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
		newPos.x = pos.x + x;
		newPos.y = pos.y - y;
		if (peice.coordsValid(newPos))
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
		newPos.x = pos.x + x;
		newPos.y = pos.y + y;
		if (peice.coordsValid(newPos))
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
	}
}
void Board::setPawnMoves(Peice &peice)
{
	coords pos;
	coords newPos;
	pos = peice.getCoords();
	Peice moveToPeice;
	if (peice.getTeam() == 'B')
	{
		// Move straight ahead 1 space
		newPos.x = pos.x - 1;
		newPos.y = pos.y;
		if (peice.coordsValid(newPos))
		{
			moveToPeice = board[newPos.x][newPos.y];
			if (moveToPeice.getName() == "  ")
				peice.validMoves.push_back(newPos);
		}
		//Move up 1 and to the left Only if there is a peice of the oposite team there
		newPos.x = pos.x - 1;
		newPos.y = pos.y - 1;
		if (peice.coordsValid(newPos))
		{
			moveToPeice = board[newPos.x][newPos.y];
			if (moveToPeice.getName() != "  ")
				if (peice.getTeam() != this->getPeice(newPos).getTeam())
					peice.validMoves.push_back(newPos);


		}
		//Move up 1 and to the Right Only if there is a peice of the oposite team there
		newPos.x = pos.x - 1;
		newPos.y = pos.y + 1;
		if (peice.coordsValid(newPos))
		{
			moveToPeice = board[newPos.x][newPos.y];
			if (moveToPeice.getName() != "  ")
				if (peice.getTeam() != this->getPeice(newPos).getTeam())
					peice.validMoves.push_back(newPos);


		}
	}
	if (peice.getTeam() == 'W')
	{
		// Move straight ahead 1 space
		newPos.x = pos.x + 1;
		newPos.y = pos.y;
		if (peice.coordsValid(newPos))
		{
			moveToPeice = board[newPos.x][newPos.y];
			if (moveToPeice.getName() == "  ")
				peice.validMoves.push_back(newPos);

		}
		//Move up 1 and to the left Only if there is a peice of the oposite team there
		newPos.x = pos.x + 1;
		newPos.y = pos.y - 1;
		if (peice.coordsValid(newPos))
		{
			moveToPeice = board[newPos.x][newPos.y];
			if (moveToPeice.getName() != "  ")
				if (peice.getTeam() != this->getPeice(newPos).getTeam())
					peice.validMoves.push_back(newPos);


		}
		//Move up 1 and to the Right Only if there is a peice of the oposite team there
		newPos.x = pos.x + 1;
		newPos.y = pos.y + 1;
		if (peice.coordsValid(newPos))
		{
			moveToPeice = board[newPos.x][newPos.y];
			if (moveToPeice.getName() != "  ")
				if (peice.getTeam() != this->getPeice(newPos).getTeam())
					peice.validMoves.push_back(newPos);
		}

	}
}
void Board::setBishopMoves(Peice &peice)
{
	coords pos;
	coords newPos;
	pos = peice.getCoords();
	// up to the left
	for (int i = 1; i < 8; i++)
	{
		newPos.x = pos.x + i;
		newPos.y = pos.y + i;
		if (peice.coordsValid(newPos))
		{
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
			if (this->getPeice(newPos).getName() != "  ")
				break;
		}
	}
	//up to the right
	for (int i = 1; i < 8; i++)
	{
		newPos.x = pos.x + i;
		newPos.y = pos.y - i;
		if (peice.coordsValid(newPos))
		{
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
			if (this->getPeice(newPos).getName() != "  ")
				break;
		}
	}
	//down to the left
	for (int i = 1; i < 8; i++)
	{
		newPos.x = pos.x - i;
		newPos.y = pos.y + i;
		if (peice.coordsValid(newPos))
		{
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
			if (this->getPeice(newPos).getName() != "  ")
				break;
		}
	}
	//down to the right
	for (int i = 1; i < 8; i++)
	{
		newPos.x = pos.x - i;
		newPos.y = pos.y - i;
		if (peice.coordsValid(newPos))
		{
			if (peice.getTeam() != this->getPeice(newPos).getTeam())
				peice.validMoves.push_back(newPos);
			if (this->getPeice(newPos).getName() != "  ")
				break;
		}
	}
}
void Board::setKingMoves(Peice &piece)
{

}
void Board::setQueenMoves(Peice &peice)
{

}
void Board::setRookMoves(Peice &peice)
{

}