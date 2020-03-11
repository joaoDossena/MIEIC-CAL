/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j] = values[i][j];

	this->initializeVisited();
	this->printLabirinth();
}


void Labirinth::initializeVisited()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			visited[i][j] = false;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << labirinth[i][j] << " ";

		cout << endl;
	}
}

void Labirinth::printVisited()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << visited[i][j] << " ";

		cout << endl;
	}
}

bool Labirinth::findGoal(int x, int y)
{
	visited[x][y] = true; //Sets current spot as visited
	
	//this->printLabirinth();
	//this->printVisited();
	//cout << endl;

	if(labirinth[x][y] == 0) //If it hits a wall
		return false;

	
	if(labirinth[x][y] == 2) //If it finds its goal
		return true;




	if(x+1 < 10 && labirinth[x+1][y] != 0 && !visited[x+1][y]) //Move right
	{

		if(findGoal(x+1, y)) return true;
	}
	if(y+1 < 10 && labirinth[x][y+1] != 0 && !visited[x][y+1]) //Move down
	{

		if(findGoal(x, y+1)) return true;
	}
	if(x-1 >= 0 && labirinth[x-1][y] != 0 && !visited[x-1][y]) //Move left
	{
		if(findGoal(x-1, y)) return true;
	}
	if(y-1 >= 0 && labirinth[x][y-1] != 0 && !visited[x][y-1]) //Move up
	{
		if(findGoal(x, y-1)) return true;
	}

	return false;
}





