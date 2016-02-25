// battleship.cpp
// Cody Gaines

//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "battleship.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

	bool gameOver = false;
	bool playerTurn = true;
	string input = "";

	while (!gameOver) {
		if (playerTurn) {
			cout << "It's your turn. Where do you fire?" << endl;
			cin >> input;

			while (true) {
				if (check_Validity(input) && check_Availability(input)) {
					break;
				}
				else if (!check_Validity(input)) {
					cout << "Invalid input. Please enter a letter from A - J followed by a number" << endl;
					cout << "from 1 - 10. Example: E5" << endl;
					cin >> input;
				}
				else if (!check_Availability(input)) {
					cout << "You've fired there. Please enter a new place to fire." << endl;
					cin >> input;
				}
			}

		}
		else {
			cout << "It's the opponent's turn. Firing..." << endl;
			// input = AI_Function();
		}

		// Resolve_Board(playerturn, input, board1, board2);
		// Print_boards(playerTurn);
		// if (board_state_finished(playerTurn))  {
		//		gameOver = true;
		// }
		playerTurn = !playerTurn;
	}

	return 0;
}