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
	void menuSwitch(); // ����������� ������ ����, ���������� ����� ������
	void showMenu();  // �������� ����, �������� ������ ����	
	int get_active() { return active; }

};

void reference(void);
#endif