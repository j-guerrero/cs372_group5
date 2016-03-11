// battleship.h
// Cody Gaines
// Joshua Guerrero
// March 10, 2016
// 
// CS372
// Project 1
// Header file for main functions

#pragma once

#include "board.h"
#include "player.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
#include <ctype.h>
#include <random>
#include <algorithm>
using std::random_shuffle;
#include <time.h>
#include <string>
using std::string;

// row_Input
// Given a set of valid 2-character coordinates, returns
// the integer equivalent of the first character.
int row_Input(string input) {
	int first_char;
	if (input[0] == 'A' || input[0] == 'a') {
		first_char = 0;
	}
	else if (input[0] == 'B' || input[0] == 'b') {
		first_char = 1;
	}
	else if (input[0] == 'C' || input[0] == 'c') {
		first_char = 2;
	}
	else if (input[0] == 'D' || input[0] == 'd') {
		first_char = 3;
	}
	else if (input[0] == 'E' || input[0] == 'e') {
		first_char = 4;
	}
	else if (input[0] == 'F' || input[0] == 'f') {
		first_char = 5;
	}
	else if (input[0] == 'G' || input[0] == 'g') {
		first_char = 6;
	}
	else if (input[0] == 'H' || input[0] == 'h') {
		first_char = 7;
	}
	else if (input[0] == 'I' || input[0] == 'i') {
		first_char = 8;
	}
	else if (input[0] == 'J' || input[0] == 'j') {
		first_char = 9;
	}

	return first_char;
}

// check_Availability
// Given a set of coordinates and an initialized board, checks whether or not
// they've been done already. Will return true if the set of coordinates are
// FREE, false if they are not.
bool check_Availability(string input, Board(&gameBoard)[10][10]) {
	int row = row_Input(input);
	int column = input[1] - '0';

	if (gameBoard[row][column].getHit()) {
		return false;
	}

	return true;
}

// check_Validity
// Given a string, checks whether or not it makes sense as a set of coordinates.
bool check_Validity(string input) {
	string first = "AaBbCcDdEeFfGgHhIiJj";
	string second = "0123456789"; // Does not check for '10,' instead we start counting from 0

	if (input.size() > 2)
		return false;

	if ( (first.find(input[0]) != string::npos ) && (second.find(input[1]) != string::npos) ){
		return true;
	}
	return false;
}

// AI_Input
// Given a vector of possible input, removes a random value
// from it and returns that value as a set of available coordinates.
string AI_Input(vector <string>& totalInput) {
	string AIinput = "";

	random_shuffle(totalInput.begin(), totalInput.end());

	AIinput = totalInput[0];

	totalInput.erase(totalInput.begin());

	return AIinput;
}

// random_Place_Ship
// Given a length, a name, and a board, randomly sets a ship of that
// length with that name somewhere on the board that doesn't go over
// the edge or cross another already placed ship.
void random_Place_Ship(int length, string name, Board(&gameBoard)[10][10]) {
	bool horizontal = (rand() % 2 == 1);

	vector <char> first = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	vector <char> second = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	vector <string> allPositions = {};
	int columns = 10;
	int rows = 10;

	if (horizontal)
		columns -= length;
	else
		rows -= length;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			string temp = "";
			temp += first[i];
			temp += second[j];
			allPositions.push_back(temp);
		}
	}
	// At this point, all we have done is construct a vector of all possible starting coordinates
	// to place a ship of the given length without it having any chance of going over the edge.

	random_shuffle(allPositions.begin(), allPositions.end());

	for (int i = 0; i < allPositions.size(); i++) {
		bool validPlace = true;
		bool placedShip = false;
		int rowcoord = row_Input(allPositions[i]);
		int columncoord = allPositions[i][1] - '0';

		if (horizontal) {
			for (int j = 0; j < length; j++) {
				if (gameBoard[rowcoord][columncoord + j].getOccupied()) {
					validPlace = false;
					break;
				}
			}
			if (validPlace) {
				for (int j = 0; j < length; j++) {
					gameBoard[rowcoord][columncoord + j].setOccupied(true);
					gameBoard[rowcoord][columncoord + j].setName(name);
				}
				placedShip = true;
			}
		}
		else {
			for (int j = 0; j < length; j++) {
				if (gameBoard[rowcoord + j][columncoord].getOccupied()) {
					validPlace = false;
					break;
				}
			}
			if (validPlace) {
				for (int j = 0; j < length; j++) {
					gameBoard[rowcoord + j][columncoord].setOccupied(true);
					gameBoard[rowcoord + j][columncoord].setName(name);
				}
				placedShip = true;
			}
		}

		if (placedShip)
			break;
	}

}

// place_All_Ships
// Given a board, calls random_Place_Ship (above) with the appropriate
// ship names and lengths to get them all placed on the board.
void place_All_Ships(Board(&gameBoard)[10][10]) {
	random_Place_Ship(5, "Carrier", gameBoard);
	random_Place_Ship(4, "Battleship", gameBoard);
	random_Place_Ship(3, "Submarine", gameBoard);
	random_Place_Ship(3, "Destroyer", gameBoard);
	random_Place_Ship(2, "Patrol Boat", gameBoard);
}

// countShipHealth
// Given a board and a name, seeks each square on the board for matches
// with that name. Returns the number of squares with that name
// that have NOT yet been hit.
int countShipHealth(Board(&gameBoard)[10][10], string name) {
	int total = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((gameBoard[i][j].getName() == name) && (!gameBoard[i][j].getHit())) {
				total++;
			}
		}
	}

	return total;
}

// resolve_Board
// Given a set of valid, available coordinates and a player flag,
// adjusts the two board representations for that player accordingly.
void resolve_Board(Player& player, string input, Board(&mainBoard)[10][10], Board(&secondBoard)[10][10]) {
	int row = row_Input(input);
	int column = input[1] - '0';

	if (!player.getNonPlayerFlag()) {
		mainBoard[row][column].setHit(true);
		if (mainBoard[row][column].getOccupied()) {
			if (countShipHealth(mainBoard, mainBoard[row][column].getName()) == 0) {
				player.decShipCount();
				cout << endl << "****************************************************************" << endl;
				cout << "*** You sunk my " << mainBoard[row][column].getName() << "! ***" << endl;
				cout << "****************************************************************" << endl;
			}
		}
	}
	else {
		secondBoard[row][column].setHit(true);
		if (secondBoard[row][column].getOccupied()) {
			if (countShipHealth(secondBoard, secondBoard[row][column].getName()) == 0) {
				player.decShipCount();
				cout << endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
				cout << "^^^ I sunk your " << secondBoard[row][column].getName() << "! ^^^" << endl;
				cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
			}
		}
	}
}