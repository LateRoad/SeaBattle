#ifndef Menu_H
#define Menu_H

#include "CycleList.h"

class Menu
{
	int amount;
	string *collum;
	int active;
public:
	Menu();
	~Menu();
	void menuSwitch(); // переключает строки меню, возвращает номер строки
	void showMenu();  // основное меню, содержит строки меню	
	int get_active() { return active; }

};

void reference(void);
#endif