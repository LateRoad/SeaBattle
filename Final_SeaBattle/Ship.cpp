#include "Ship.h"
int boathere = 6;

Ship::Ship()
{
	status = false;
	boat = 0;
	pboat = &boat;
}

Ship::Ship(int k)
{
	status = false;
	int boat = boathere;
	pboat = &boat;
}

Ship::~Ship()
{
}

