#pragma once

#include "board.h"
#include <string>
using std::string;
#include <ctype.h>

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

	if (input.size() < 2)
		return false;

	if ( (first.find(input[0]) != string::npos ) && (second.find(input[1]) != string::npos) ){
		return true;
	}
	return false;
}

// AI_Input
// Generates and returns a random set of available coordinates.
string AI_Input() {
	// Idea - create a vector of possible letters
	// Then create a vector of possible numbers
	// Pick a random element from each, and pop them out.
	//
	// This way, you don't need to check if they're available.
	return "";
}

// resolve_Board
// Will need to take TWO boards as arguments.
// Given a set of valid, available coordinates and a player flag,
// adjusts the two board representations for that player accordingly.
void resolve_Board(bool playerturn, string input, Board(&gameBoard)[10][10]) {
	int row = row_Input(input);
	int column = input[1] - '0';

	gameBoard[row][column].setHit(true);
	// UNFINISHED - if playerturn is false, needs to INSTEAD do this to
	// the secondary player board
}

// print_Boards
// Given a player flag, prints out the two boards
// May need to take two boards, depending on how we deal with them.
void print_Boards(bool playerturn) {
	if (playerturn) {
		// Print the player's primary board
	}
	// Whether it's the AI's turn or the player's turn, you then
	// print the secondary board.
}

