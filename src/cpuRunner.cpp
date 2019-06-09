#include "lrc.h"
#include <iostream>
#include <thread>

using namespace std;

void play_table(table* thisTable, int numGames)
{
	
	for(int g = 0; g < numGames; g++)
	{
		//cout << "game " << g << endl;
		while(!(thisTable->getGameOver()))
		{
			for(int p = 0; p < thisTable->getPlayerCount(); p++) // everyone takes a turn
			{
				thisTable->roll(p);
			}
		}
		thisTable->restart();
	}
}

int winCount(table tables[], int playerID, int count)
{
	int sum = 0;
	for(int i = 0; i < count; i++)
	{
		sum += tables[i].getWins(playerID);
	}

	return sum;
}

int main()
{
	const int NUM_THREADS = 4;

	int numPlayers, numGames;
	//cout << "Number of players: ";
	std::cin >> numPlayers;
	//cout << "Number of Games: ";
	std::cin >> numGames;

	table tables[NUM_THREADS];
	std::thread threads[NUM_THREADS];
	int gameCount[NUM_THREADS];

	for(int i = 0; i < NUM_THREADS; i++)
	{
		gameCount[i] = numGames / NUM_THREADS;
	}
	int remainder = numGames % NUM_THREADS;
	for(int i = 0; i < remainder; i++)
	{
		gameCount[i]++;
	}

	for(int i = 0; i < NUM_THREADS; i++)
	{
		tables[i].setPlayers(numPlayers);
		threads[i] = std::thread(play_table, &tables[i], gameCount[i]);
	}

	for(int i = 0; i < NUM_THREADS; i++)
	{
		threads[i].join();
	}

	//once all threads have finished.
	for(int i = 0; i < numPlayers; i++)
	{
		std::cout << winCount(tables, i, NUM_THREADS) << endl;
	}

	return 0;
}
