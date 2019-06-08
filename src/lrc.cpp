#include "lrc.h"
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

void table::roll(int pIndex)
{
	int numRolls = std::min(3, players[pIndex].funds);

	if(numRolls == 0)
	{
		//cout << pIndex << " passes." << endl;
		return;
	}

	for(int i = 0; i < numRolls; i++)  //if no funds, turn is skipped.
	{
		dieVal roll = dieMap[rand() % 6];
		switch(roll)
		{
			case d:
				//Nothing
				//cout << pIndex << " rolled dot. funds=" << players[pIndex].funds << endl;
				break;
			case l:
				giveLeft(pIndex);
				//cout << pIndex << " gave left. funds=" << players[pIndex].funds << endl;
				break;
			case r:
				giveRight(pIndex);
				//cout << pIndex << " gave right. funds=" << players[pIndex].funds << endl;
				break;
			case c:
				giveCenter(pIndex);
				//cout << pIndex << " rolled center. funds=" << players[pIndex].funds << endl;
				break;
		}

		if(players[pIndex].funds == 0)
		{
			playersLeft--; //this player failed this turn
			//cout << pIndex << " dropped out, playersLeft=" << playersLeft << endl;
			if(playersLeft == 0) // Didn't give anything to anyone. pot full.
			{
				gameOver = true;
			}
			return;
		}

		if(playersLeft == 1 && i == numRolls-1) // player surived and is last man standing, and is done rolling
		{
			players[pIndex].wins++;
			//cout << pIndex << " wins" << endl;
			gameOver = true;
		}
	}
}

void table::giveLeft(int pIndex)
{
	players[pIndex].funds--;
	if(pIndex == 0)
	{
		players[playerCount-1].funds++;
		if(players[playerCount-1].funds == 1) playersLeft++; // Had 0
	}
	else
	{
		players[pIndex-1].funds++;
		if(players[pIndex-1].funds == 1) playersLeft++;
	}
}

void table::giveRight(int pIndex)
{
	players[pIndex].funds--;
	if(pIndex == playerCount-1)
	{
		players[0].funds++;
		if(players[0].funds == 1) playersLeft++;
	}
	else
	{
		players[pIndex+1].funds++;
		if(players[pIndex+1].funds == 1) playersLeft++;
	}
}

void table::giveCenter(int pIndex)
{
	players[pIndex].funds--;
}

void table::restart()
{
	for(int i = 0; i < playerCount; i++)
	{
		players[i].funds = 3;
	}
	gameOver = false;
	playersLeft = playerCount;
}

void table::print()
{
	for(int i = 0; i < playerCount; i++)
	{
		std::cout << players[i].wins << endl;
	}
}

void table::setPlayers(int p)
{
	playerCount = p;
	playersLeft = p;
	players.clear();
	for(int i = 0; i < p; i++)
	{
		players.push_back(player());
	}
}
