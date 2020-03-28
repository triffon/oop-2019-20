#pragma once
struct Point
{
	int x;
	int y;
};


void readPnt(Point&);

void printPnt(const Point&);

double pntToBegDist(const Point&);

double pntToPntDist(const Point&, const Point&);

int closestPoint(Point*, size_t);
