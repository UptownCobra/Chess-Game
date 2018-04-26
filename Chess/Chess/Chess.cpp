#include <iostream>
#include <string>
#include <iomanip>
#include "Board.h"

using namespace std;

int main()
{
	coords toMove;
	coords moveTo;
	int x, y;
	string input;
	Board chessBoard;
	chessBoard.print();

	cout << "What do you want to move: ";
	getline(cin, input);
	x = input[0] - '0';
	y = input[2] - '0';
	toMove = {x,y};
	cout << endl << "Where would you like to move to: ";
	getline(cin, input);
	x = input[0] - '0';
	y = input[2] - '0';
	moveTo = { x,y };
	chessBoard.movePiece(toMove, moveTo);
	chessBoard.print();

	



	system("Pause");



	return 0;
}