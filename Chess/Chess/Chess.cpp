#include <iostream>
#include <string>
#include <iomanip>
#include "Board.h"

using namespace std;

int main()
{
	coords toMove;
	coords moveTo;
//	int x, y;
	string input;
	string strTeam = "White";
	Board chessBoard;
	bool boolTeam = false; //false = 'White'; true = 'Black'
	bool isKingTaken = false;
	chessBoard.print();
	

	while (isKingTaken == false)
	{

		cout << strTeam << " what do you want to move (In te form A1): ";
		toMove = chessBoard.getInput();
		cout << endl << strTeam << " where would you like to move to (In te form A1): ";
		moveTo = chessBoard.getInput();
		chessBoard.movePiece(toMove, moveTo);
		chessBoard.print();
		boolTeam = !boolTeam;
		isKingTaken = chessBoard.getKingTaken();
		if (boolTeam == true)
			strTeam = "Black";
		else if (boolTeam == false)
			strTeam = "White";

	}
	if (boolTeam == true)
		strTeam = "White";
	else if (boolTeam == false)
		strTeam = "Black";

	cout << "Congrats " << strTeam << " You have won the Game." << endl;
	



	system("Pause");



	return 0;
}