#ifndef Ship_H
#define Ship_H

#include "LIB.h"

class Ship
{
	bool status;
	int boat;
	int *pboat;
public:
	Ship();
	Ship(int);
	~Ship();
	bool get_status() { return status; }
	int *GetPBoat() { return pboat; };
//	int getboat() { return boat; };
};

#endif