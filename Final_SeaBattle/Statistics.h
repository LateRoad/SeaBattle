#ifndef Statistics_H
#define Statistics_H

#include "Menu.h"
class Statistics :
	public Menu
{
	friend class Ring<string>;
	Ring<string> players;
public:
	Statistics();
	~Statistics();

	void ShowStat();
	void StatMenu();
	void Inizilization();
	void SaveStat();
	void YouWin() { players.youwin(); }
	void YouLose() { players.youlose(); }
};

#endif