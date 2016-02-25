#pragma once

#include <string>
using std::string;

// check_Availability
// Given a set of coordinates, checks whether or not they've been done already.
// Will return true if the set of coordinates are FREE, false if they are not.
bool check_Availability(string input) {
	return true;
}

// check_Validity
// Given a string, checks whether or not it makes sense as a set of coordinates.
// UNFINISHED - needs to check the third character in case the second number is '10'
// Also should return false if there's any extraneous input beyond the first two
// or three characters.
bool check_Validity(string input) {
	string first = "AaBbCcDdEeFfGgHhIiJj";
	string second = "123456789"; // Does not check for '10' yet
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
// Will need to take two boards as arguments too.
// Given a set of coordinates and a player flag, adjusts the two board
// representations for that player accordingly.
void resolve_Board(bool playerturn, string input) {
	if (check_Availability(input)) {

	}
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