// player.h
// Cody Gaines
// Joshua Guerrero
// March 10, 2016
// 
// CS372
// Project 1
// Header file for Player class object

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
	public:

		Player(int x, bool y):shipCount(x), playerFlag(y)
		{}

		/* --- { SET FUNCTIONS } --- */
		void setShipCount(int set)
		{	shipCount = set;	}

		void decShipCount()
		{	shipCount--;	}

		void setNonPlayerFlag(bool flag)
		{	playerFlag = flag;	}


		/* --- { GET FUNCTIONS } --- */
		int getShipCount()
		{	return shipCount;	}

		bool getNonPlayerFlag()
		{	return playerFlag;	}

	private:
		int shipCount;
		bool playerFlag;
};

#endif