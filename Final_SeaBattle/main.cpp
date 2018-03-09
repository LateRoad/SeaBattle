#include "Player.h"
#include "Statistics.h"
int main()
{
	//setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	srand(time(NULL));

	Statistics menu;

	do
	{
		Player Player1;
		Player Player2;

		menu.menuSwitch();
		switch (menu.get_active())
		{
		case 0:
		{
			Player1.setplayers(1);
			menu.Inizilization();
			do
			{
				Player1.Attack(Player2);
				Player2.CompAttack(Player1);
			} while (Player1.GetStatus() == false && Player2.GetStatus() == false);
			if (Player1.GetStatus() == false)
			{
				cout << "Вы победили!!!";
				menu.YouWin();
			}				
			else
			{
				cout << "Вы победили!!!(нет)";
				menu.YouLose();
			}
			menu.SaveStat();
			_getch(); 
			menu.ShowStat(); 
			_getch(); 
			break; 
		} 
		case 1:
			Player1.setplayers(2);
			menu.Inizilization();
			do
			{
				system("cls");
				cout << "\n\n\n\n\t\t Ход первого игрока.";
				Player1.Attack(Player2);
				system("cls");
				cout << "\n\n\n\n\t\t Ход второго игрока.";
				Player2.Attack(Player1);
				
			} while (Player1.GetStatus() == false && Player2.GetStatus() == false);
			if (Player1.GetStatus() == false)
			{
				cout << "Вы победили!!!";
				menu.YouWin();
			}
			else
			{
				cout << "Вы победили!!!(нет)";
				menu.YouLose();
			}
			menu.SaveStat();
			_getch();
			menu.ShowStat();
			_getch();
			break;
		case 2:
			menu.StatMenu();
			break;
		case 3:
			system("cls");
			reference();
			_getch();
			break;
		case 4:
			cout << "До свидания!\n";
			break;
		}
		
	} while (menu.get_active() != 4);
	_getch();
	return 0;
}