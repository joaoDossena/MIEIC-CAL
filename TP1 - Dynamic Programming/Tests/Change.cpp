/*
 * Change.cpp
 */

#include "Change.h"

int minCoins(int m, int numCoins, int *coinValues)
{
	int table[m+1];
	table[0] = 0;

	for(unsigned int i = 1; i <= m; i++)
		table[i] = INT_MAX;

	for(unsigned int i = 1; i <= m; i++)
	{
		for(unsigned int j = 0; j < numCoins; j++)
		{
			if(coinValues[j] <= i)
			{
				int sub_res = table[i - coinValues[j]];
				if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
			}
		}
	}

	return table[m];
}

string calcChange(int m, int numCoins, int *coinValues)
{
	bool found = false;
	if(m == 0)
		return "";
	int min = minCoins(m, numCoins, coinValues);


	return "";

}
