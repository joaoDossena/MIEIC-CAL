/*
 * Change.cpp
 */

#include "Change.h"

string calcChange(int m, int numCoins, int *coinValues)
{
	int INF = m + 1;
	int minCoins[m+1];
	int lastCoin[m+1] = {0};

	//Initializing for the base case of no coins used
	minCoins[0] = 0; //Empty solution
	for(int k = 1; k <= m; k++)
	{
		minCoins[k] = INF; //No solution
	}

	for(int i = 1; i <= numCoins; i++) //Filling the tables
	{
		for(int k = coinValues[i-1]; k <= m; k++)
		{
			if(minCoins[k - coinValues[i-1]] + 1 < minCoins[k])
			{
				minCoins[k] = 1 + minCoins[k - coinValues[i-1]];
				lastCoin[k] = coinValues[i-1];
			}
		}
	}


	//Transforming result in a string
	if(minCoins[m] == INF)
		return "-"; //No solution
	ostringstream oss;
	for(int k = m; k > 0; k -= lastCoin[k])
	{
		oss << lastCoin[k] << ";";
	}

	return oss.str();
}
