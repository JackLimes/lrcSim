#ifndef LRC_H
#define LRC_H

#include <stdlib.h>

struct player
{
	int funds = 3;
	int wins = 0;
};

enum dieVal {d, l, r, c}; // dot left right center

class table // as in game table
{
	private:
		int playerCount;
		int playersLeft;
		bool gameOver = false;
		player* players = nullptr;
		dieVal dieMap[6] = {d, d, d, l, r, c};
		char statebuf[64];
		random_data buf;

	public:
		table()
		{
			// rand() slows down multithreading
			//random_r does not
			buf.state = NULL;
			initstate_r(rand(), statebuf, 64, &buf); // rand() is good for seeding. Doesn't slow down threads
		}
		~table() { delete[] players; }
		void roll(int pIndex);
		void giveLeft(int pIndex);
		void giveRight(int pIndex);
		void giveCenter(int pIndex);
		void restart();
		void print();
		void setPlayers(int p);
		int getWins(int pIndex) { return players[pIndex].wins; }
		int getPlayerCount() { return playerCount; }
		bool getGameOver() { return gameOver; }
};

#endif
