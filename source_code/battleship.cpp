// battleship.cpp
// Cody Gaines
// Joshua Guerrero
// March 10, 2016
// 
// CS372
// Project 1
// Main file for Battleship

/* !!! MUST COMPILE WITH C++ 11 !! */

#include "battleship.h"
#include "player.h"
#include "board.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

	srand(time(NULL));

	Player Human(5, true);
	Player AI(5, false);

	Board mainBoard[10][10];	//	intialize game board
	Board secondBoard[10][10];
	Board emptyBoard[10][10];

	bool gameOver = false;
	bool playerTurn = true;
	string input = "";
	vector <char> AIfirst = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	vector <char> AIsecond = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	vector <string> AITotalInput = {};

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			string temp = "";
			temp += AIfirst[i];
			temp += AIsecond[j];
			AITotalInput.push_back(temp);
		}
	}

	place_All_Ships(mainBoard);

	cout << "[][][][][] WELCOME TO BATTLESHIP!!! [][][][][]" << endl << endl;

	cout << "Time to place your ships! Because I'm lazy, you'll have to live with" << endl;
	cout << "randomly generated positions. Oh well." << endl;
	place_All_Ships(secondBoard);
	displayBoard(true, secondBoard);

	while (!gameOver) {
		if (playerTurn) {
			cout << "It's your turn. Where do you fire?" << endl;
			cin >> input;

			while (true) {
				if (check_Validity(input) && check_Availability(input, mainBoard)) {
					break;
				}
				else if (!check_Validity(input)) {
					cout << "Invalid input. Please enter a letter from A - J followed by a number" << endl;
					cout << "from 0 - 9. Example: E5" << endl;
					cin >> input;
				}
				else if (!check_Availability(input, mainBoard)) {
					cout << "You've fired there. Please enter a new place to fire." << endl;
					cin >> input;
				}
			}
		}
		else {
			cout << endl << "It's the opponent's turn. Firing..." << endl << endl;
			input = AI_Input(AITotalInput);
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}

		if (playerTurn) {
			cout << endl << endl << endl << endl;
			resolve_Board(Human, input, mainBoard, secondBoard);
			cout << "---- ENEMY BOARD ----" << endl;
			displayBoard(false, mainBoard);

			if (AI.getShipCount() == 0) {
				gameOver = true;
				cout << "******** All enemy ships have sunk! You win! ********" << endl;
			}
			if (Human.getShipCount() == 0) {
				gameOver = true;
				cout << "^^^^^^^^ All your ships have sunk! You lose! ^^^^^^^^" << endl;
			}
		}
		else {
			resolve_Board(AI, input, mainBoard, secondBoard);
			cout << "--- YOUR BOARD ---" << endl;
			displayBoard(true, secondBoard);

			if (Human.getShipCount() == 0) {
				gameOver = true;
				cout << "^^^^^^^^ All your ships have sunk! You lose! ^^^^^^^^" << endl;
			}
		}
		playerTurn = !playerTurn;
	}

	getchar();
	getchar();

	return 0;
}