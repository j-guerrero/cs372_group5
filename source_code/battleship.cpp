// battleship.cpp
// Cody Gaines

//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "battleship.h"
#include "player.h"
#include "board.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

	Board gameBoard[10][10];	//	intialize game board

	bool gameOver = false;
	bool playerTurn = true;
	string input = "";

	//fillBoard(gameBoard); // I don't believe this will actually be necessary.

	while (!gameOver) {
		if (playerTurn) {
			cout << "It's your turn. Where do you fire?" << endl;
			cin >> input;

			while (true) {
				if (check_Validity(input) && check_Availability(input, gameBoard)) {
					break;
				}
				else if (!check_Validity(input)) {
					cout << "Invalid input. Please enter a letter from A - J followed by a number" << endl;
					cout << "from 0 - 9. Example: E5" << endl;
					cin >> input;
				}
				else if (!check_Availability(input, gameBoard)) {
					cout << "You've fired there. Please enter a new place to fire." << endl;
					cin >> input;
				}
			}
		}
		else {
			cout << "It's the opponent's turn. Firing..." << endl;
			// input = AI_Function();
		}
		resolve_Board(playerTurn, input, gameBoard);
		displayBoard(gameBoard);
		// if (board_state_finished(playerTurn))  {
		//		gameOver = true;
		// }
		playerTurn = !playerTurn;
	}

	return 0;
}