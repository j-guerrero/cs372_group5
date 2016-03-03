#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

// Board Class
class Board {
private:
	bool hit;
	bool occupied;
	string name;

public:

	Board() : hit(false), occupied(false)
	{};

	Board(string name_) : name(name_), hit(false), occupied(false)
	{};


	/* GET FUNCTIONS */
	bool getHit()
	{
		return hit;
	}

	string getName()
	{
		return name;
	}

	bool getOccupied()
	{
		return occupied;
	}

	/* SET FUNCTIONS */
	void setHit(bool flag)
	{
		hit = flag;
	}

	void setName(string name_)
	{
		name = name_;
	}

	void setOccupied(bool flag)
	{
		occupied = flag;
	}

};

/*
void fillBoard(Board(&gameBoard)[10][10])
{
	std::srand(std::time(0));

	for (int i = 0; i < 10; ++i)
	{
		char column = (65 + i);

		for (int j = 0; j < 10; ++j)
		{
			// Give name to each square
			string name = (column + std::to_string(j));
			gameBoard[i][j].setName(name);

			
			// Set randomly occupied squares
			int rand_variable = std::rand() % 100;
			if (rand_variable % 4 == 0)
			{
				gameBoard[i][j].setOccupied(true);
			}
		}
	}
}*/


void displayBoard(Board(&gameBoard)[10][10])
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			// If hit marker flagged
			if (gameBoard[i][j].getHit() == true)
			{
				if (gameBoard[i][j].getOccupied() == true)
				{
					cout << "O" << " ";
				}

				else
				{
					cout << "X" << " ";
				}
			}

			// Else, empty water
			else
			{
				cout << "~" << " ";
			}
		}
		cout << endl;
	}
}

/*
// Sets hit flag for coord
void testBoard(Board(&gameBoard)[10][10], string coord)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (gameBoard[i][j].getName() == coord)
			{
				gameBoard[i][j].setHit(true);
				break;
			}
		}
	}
}*/