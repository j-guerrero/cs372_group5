#pragma once

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

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

void displayBoard(bool displayShips, Board(&gameBoard)[10][10])
{
	vector <char> letters = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	cout << "   0 1 2 3 4 5 6 7 8 9" << endl;

	for (int i = 0; i < 10; ++i)
	{
		cout << letters[i] << ": ";
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
				if (displayShips && gameBoard[i][j].getOccupied()) {
					cout << "#" << " ";
				}
				else
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