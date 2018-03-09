#include "Statistics.h"
//#include "Color.h"

void SetColor(int, int);

Statistics::Statistics()
{
	players.outFile();
}

void Statistics::ShowStat()
{
	system("cls");
	SetColor(15, 1);
	cout << "\n\n\n\t\t\t\t\t\t ÑÒÀÒÈÑÒÈÊÀ\t\t\t\t\t\t\t\t\n\n\n\n\n";
	players.print();
	_getch();
}

void Statistics::StatMenu()
{
	int choice;
	do
	{
		players.instruction();
		choice = getch();

		players.nextpart(choice);
	} while (choice != '0');
	
}

void Statistics::Inizilization()
{
	string name;
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tÂâåäèòå âàøå èìÿ:\n\n\t\t\t\t\t";
	SetColor(7, 0);
	cout << "| ";
	cin >> name;
	if (!players.find(name))
	{
		players.push(name, 0, 0, 0);
	}
	else
		players.sethead(players.find(name));
}

void Statistics::SaveStat()
{
	players.inFile();
}


Statistics::~Statistics()
{
	
}
