#ifndef Player_H
#define Player_H

#include "Board.h"

class Player: public Board
{
	bool status;
	int x, y;
	int subflag;
	int pl;
public:
	Player();
	~Player();
	bool GetStatus();
	void MyBoard();
	void HisBoard();
	void Attack(Player&);
	void ChooseXY(Player&);
	void CompAttack(Player&);
	void CleverAttack(Player&);
	void SetXY(int t_x, int t_y) { x = t_x; y = t_y; }
	void setplayers(int x) { pl = x; }
};

#endif