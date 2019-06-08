#ifndef LRC_H
#define LRC_H

#include <vector>

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
		std::vector<player> players;
		dieVal dieMap[6] = {d, d, d, l, r, c};

	public:
		table() {}
		table(int pCount): playerCount(pCount), playersLeft(pCount)
		{
			for(int i = 0; i < pCount; i++)
			{
				players.push_back(player());
			}
		}
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
