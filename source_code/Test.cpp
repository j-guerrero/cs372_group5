#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "battleship.h"

TEST_CASE("Input Validity 1", "Valid Input 1") {
	REQUIRE(check_Validity("A7"));
}

TEST_CASE("Input Validity 2", "Valid Input 2") {
	REQUIRE(check_Validity("B10"));
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