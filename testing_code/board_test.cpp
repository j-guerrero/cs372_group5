// board_test.cpp

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
#include <ctime>

class Board{
	private:
		bool hit;
		bool occupied;
		string name;

	public:

		Board(): hit(false)
		{};

		Board(string name_): name(name_), hit(false)
		{};

		void setHit(bool flag)
		{	hit = flag;		}

		bool getHit()
		{	return hit;		}

		void setName(string name_)
		{	name = name_;	}

		string getName()
		{	return name;	}

		void setOccupied(bool flag)
		{	occupied = flag;	}

		bool getOccupied()
		{	return occupied;	}
};

void fillBoard(Board (&gameBoard)[10][10])
{
	for(int i = 0; i < 10; ++i)
	{
		char column = (65+i);

		for(int j = 0; j < 10; ++j)
		{	
			string name = (column + std::to_string(j));
			gameBoard[i][j].setName(name);  
		}
	}
}

void testBoard(Board (&gameBoard)[10][10])
{
	std::srand(std::time(0));

	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{	
			int rand_variable = std::rand()%100;

			if(rand_variable%4 == 0)
			{	gameBoard[i][j].setOccupied(true);	} 
		}
	}
}

int main()
{
	// 10 by 10 Vector
	// A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, I = 9, J = 10

	Board gameBoard[10][10];

	fillBoard(gameBoard);

	testBoard(gameBoard);

	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{	
			if(gameBoard[i][j].getOccupied() == true)
			{	cout << "O" << " "; }

			else if(gameBoard[i][j].getHit() == true)
			{	cout << "X" << " ";	}

			else
			{	cout << "~" << " ";	}	
		}

		cout << endl;
	}


	return 0;
}