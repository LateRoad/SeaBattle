#include "Menu.h"

void SetColor(int, int);
Menu::Menu()
{
	active = 0;
	amount = 5;
	collum = new string[amount];
	collum[0] = "Один игрок";
	collum[1] = "Два игрока";
	collum[2] = "Статистика";
	collum[3] = "Справка";
	collum[4] = "Выход";
}

Menu::~Menu()
{

}

void Menu::menuSwitch()
{
	int t_active = amount - 1;
	char symbol;
	showMenu();
	do {
		symbol = _getch();
		switch (symbol)         // вычисление нажатой клавиши
		{
		case 'w':
			active--;
			if (active < 0)
				active = t_active;
			break;
		case 's':
			active++;
			if (active >= amount)
				active = 0;
			break;
		default:
			break;
		}
		showMenu();
	} while (symbol != ENTER);
}

void Menu::showMenu()
{
	system("cls");
	SetColor(15, 1);
	cout << "\n\n\n\t\t\t\t\t\tМОРСКОЙ БОЙ\t\t\t\t\t\t\t\t\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < amount; i++)
	{
		
		SetColor(3, 0);
		if (i == active)
			SetColor(11, 0);
		cout << "\t\t\t\t\t\t" << collum[i];
		cout << endl << endl;
	}
}

void reference()
{
	cout << "\n\n\n Для перемещения указателя используйте следующие клавиши:"
		"\n\n \"w\"- ВВЕРХ"
		"\n\n \"s\"- ВНИЗ"
		"\n\n \"d\"- ВЛЕВО"
		"\n\n \"a\"- ВПРАВО"
		"\n\n\n \"l\"- ВЫСТРЕЛ";
}