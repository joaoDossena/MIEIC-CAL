/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else
		return n*factorialRecurs(n-1);
}

int factorialDinam(int n)
{
	int res = 1;

	for(unsigned int i = 1; i <= n; i++)
	{
		res *= i;
	}

	return res;
}
