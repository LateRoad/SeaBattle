#ifndef Board_H
#define Board_H

#include "LIB.h"
#include "Ship.h"

class Board
{
	friend class Ship;
protected:
	struct status
	{
		int shoot = 7; 
		int kill = 8;
		int *pkill = &kill;
		int *pshoot = &shoot;
		int *pempty = nullptr;
		int used = 9; 
		int *pused;
	}st;
	/*struct MIND
	{
		int x;
		int y;
		int kol;
	}mind[4];
	bool use;*/
	
	int *board[12][12];
	Ship boat[9];
public:
	Board();
	~Board();

	void CreateBoard();
	bool CheckEndOfGame();
	int* WhatisHere(int, int);
	void SetPoint(int, int, int);
	bool CheckifKilled(int, int);
	void AddUsed(int, int, int,int);
	status getpoint() { return st; }
};
#endif