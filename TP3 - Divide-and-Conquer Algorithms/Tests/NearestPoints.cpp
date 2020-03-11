/*
 * NearestPoints.cpp
 */

#include <limits>
#include <thread>
#include <algorithm>
#include <cmath>
#include "NearestPoints.h"
#include "Point.h"

#include <ctime>

const double MAX_DOUBLE = std::numeric_limits<double>::max();

Result::Result(double dmin, Point p1, Point p2) {
	this->dmin = dmin;
	this->p1 = p1;
	this->p2 = p2;
}

Result::Result() {
	this->dmin = MAX_DOUBLE;
	this->p1 = Point(0,0);
	this->p2 = Point(0,0);
}

/**
 * Auxiliary functions to sort vector of points by X or Y axis.
 */
static void sortByX(vector<Point> &v, int left, int right)
{
	std::sort(v.begin( ) + left, v.begin() + right + 1,
		[](Point p, Point q){ return p.x < q.x || (p.x == q.x && p.y < q.y); });
}

static void sortByY(vector<Point> &v, int left, int right)
{
	std::sort(v.begin( ) + left, v.begin() + right + 1,
		[](Point p, Point q){ return p.y < q.y || (p.y == q.y && p.x < q.x); });
}

/**
 * Brute force algorithm O(N^2).
 */
Result nearestPoints_BF(vector<Point> &vp)
{
	//cout << "Tamanho: " << vp.size() << endl;
	if(vp.size() < 2)
		return Result();

	bool found = false;
	Point p1 = vp.at(0);
	Point p2 = vp.at(1);
	clock_t start = clock();
	
	Result res = Result(p1.distance(p2), p1, p2);

	if(vp.size() == 2)
		return res;

	for(vector<Point>::iterator it1 = vp.begin(); it1 != vp.end(); it1++)
	{
		if(found == true)
			break;

		for(vector<Point>::iterator it2 = it1 + 1; it2 != vp.end(); it2++)
		{
			if(*it1 == *it2)
			{
				res = Result(0, *it1, *it2);
				found = true;
				break;
			}
			else if(it1->distance(*it2) < res.dmin)
			{
				res = Result(it1->distance(*it2), *it1, *it2);
			}
		}
	}
	
	clock_t end = clock();
	cout << endl <<  "Bruteforce with " << vp.size() << " points ran in " << (double)(end - start)/(double)(CLOCKS_PER_SEC) << " seconds" << endl << endl;

	return res;
}

/**
 * Improved brute force algorithm, that first sorts points by X axis.
 */
Result nearestPoints_BF_SortByX(vector<Point> &vp) {
	Result res;
	bool found = false;

	clock_t start = clock();
	sortByX(vp, 0, vp.size()-1);
	
	if(vp.size() < 2)
		return Result();

	Point p1 = vp.at(0);
	Point p2 = vp.at(1);
	
	res = Result(p1.distance(p2), p1, p2);

	if(vp.size() == 2)
		return res;

	for(vector<Point>::iterator it1 = vp.begin(); it1 != vp.end(); it1++)
	{
		if(found == true)
			break;

		for(vector<Point>::iterator it2 = it1 + 1; it2 != vp.end(); it2++)
		{
			if(*it1 == *it2)
			{
				res = Result(0, *it1, *it2);
				found = true;
				break;
			}
			else if(it1->distance(*it2) < res.dmin)
			{
				res = Result(it1->distance(*it2), *it1, *it2);
			}
		}
	}
	
	clock_t end = clock();
	cout << endl <<  "Bruteforce sorted by X with " << vp.size() << " points ran in " << (double)(end - start)/(double)(CLOCKS_PER_SEC) << " seconds." << endl << endl;


	return res;
}


/**
 * Auxiliary function to find nearest points in strip, as indicated
 * in the assignment, with points sorted by Y coordinate.
 * The strip is the part of vp between indices left and right (inclusive).
 * "res" contains initially the best solution found so far.
 */
static void npByY(vector<Point> &vp, int left, int right, Result &res)
{
	// TODO
}

/**
 * Recursive divide and conquer algorithm.
 * Finds the nearest points in "vp" between indices left and right (inclusive),
 * using at most numThreads.
 */
static Result np_DC(vector<Point> &vp, int left, int right, int numThreads) {
	// Base case of two points
	if(vp.size() == 2)
		return Result(vp.at(0).distance(vp.at(1)), vp.at(0), vp.at(1));

	// Base case of a single point: no solution, so distance is MAX_DOUBLE
	if(vp.size() == 1)
		return Result();

	// Divide in halves (left and right) and solve them recursively,
	// possibly in parallel (in case numThreads > 1)
	if(numThreads == 1)
	{
		Result resLeft = np_DC(vp, left, (left+right)/2 - 1, 1);
		Result resRight = np_DC(vp, (left+right)/2, right, 1);
	}

	// Select the best solution from left and right
	if(resLeft.dmin <= resRight.dmin)
		Result res = resLeft;
	else
		Result res = resRight;

	// Determine the strip area around middle point
	// TODO

	// Order points in strip area by Y coordinate
	// TODO

	// Calculate nearest points in strip area (using npByY function)
	// TODO

	// Reorder points in strip area back by X coordinate
	//TODO

	//return res;
}


/**
 * Defines the number of threads to be used.
 */
static int numThreads = 1;
void setNumThreads(int num)
{
	numThreads = num;
}

/*
 * Divide and conquer approach, single-threaded version.
 */
Result nearestPoints_DC(vector<Point> &vp) {
	
	sortByX(vp, 0, vp.size() -1);
	return np_DC(vp, 0, vp.size() - 1, 1);
}


/*
 * Multi-threaded version, using the number of threads specified
 * by setNumThreads().
 */
Result nearestPoints_DC_MT(vector<Point> &vp) {
	sortByX(vp, 0, vp.size() -1);
	return np_DC(vp, 0, vp.size() - 1, numThreads);
}
