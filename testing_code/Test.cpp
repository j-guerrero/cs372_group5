#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "battleship.h"
#include "board.h"

// check_Validity should be able to deal with any string
TEST_CASE("Input Validity 1", "Valid Input 1") {
	REQUIRE(check_Validity("A7"));
}

TEST_CASE("Input Validity 2", "Valid Input 2") {
	REQUIRE(check_Validity("B9"));
}

TEST_CASE("Input Validity 3", "Invalid Input 1") {
	REQUIRE(!check_Validity("sadlkjfhksajl"));
}

TEST_CASE("Input Validity 4", "Invalid Input 2") {
	REQUIRE(!check_Validity("A75"));
}

TEST_CASE("Input Validity 5", "Invalid Input 3") {
	REQUIRE(!check_Validity("AA7"));
}

TEST_CASE("Input Validity 6", "Invalid Input 4") {
	REQUIRE(!check_Validity(""));
}

// row_Input has a preceondition to only be passed valid input
TEST_CASE("Row Input 1", "Valid Input 1") {
	REQUIRE(row_Input("A5") == 0);
}

TEST_CASE("Row Input 2", "Valid Input 2") {
	REQUIRE(row_Input("J5") == 9);
}

TEST_CASE("Row Input 3", "Valid Input 3") {
	REQUIRE(row_Input("D9") == 3);
}

TEST_CASE("Row Input 4", "Valid Input 4") {
	REQUIRE(row_Input("D0") == 3);
}

// countShipHealth should only be passed valid boards with the right ship placed
TEST_CASE("Count Ship Health 1", "Carrier") {
	Board gameBoard[10][10];

	random_Place_Ship(5, "Carrier", gameBoard);
	REQUIRE(countShipHealth(gameBoard, "Carrier") == 5);
}

TEST_CASE("Count Ship Health 2", "Patrol Boat") {
	Board gameBoard[10][10];

	random_Place_Ship(2, "Patrol Boat", gameBoard);
	REQUIRE(countShipHealth(gameBoard, "Patrol Boat") == 2);
}

TEST_CASE("Count Ship Health 3", "Destroyer") {	// If its ship isn't there, it should ignore other ships
	Board gameBoard[10][10];

	random_Place_Ship(5, "Carrier", gameBoard);
	REQUIRE(countShipHealth(gameBoard, "Destroyer") != 5);
}

// AI_Input should always be given a vector with elements of valid input
TEST_CASE("AI Input 1", "Valid Input") {
	vector <string> input = { "a5", "b7", "j9" };

	REQUIRE(check_Validity(AI_Input(input)));
}

TEST_CASE("AI Input 2", "Invalid Input") {
	vector <string> input = { "65", "akjlfdsh", "0" };

	REQUIRE(!check_Validity(AI_Input(input)));
}