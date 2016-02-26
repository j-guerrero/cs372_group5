#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
	public:

		Player(int x, bool y):shipCount(x), nonPlayerFlag(y)
		{}

		/* --- { SET FUNCTIONS } --- */
		void setShipCount(int set)
		{	shipCount = set;	}

		void setNonPlayerFlag(bool flag)
		{	nonPlayerFlag = flag;	}


		/* --- { GET FUNCTIONS } --- */
		int getShipCount()
		{	return shipCount;	}

		bool getNonPlayerFlag()
		{	return nonPlayerFlag;	}

	private:
		int shipCount;
		bool nonPlayerFlag;

		// Variable that holds ship
		// Variable that holds player board
};

#endif