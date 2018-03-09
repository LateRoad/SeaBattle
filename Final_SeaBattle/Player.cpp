#include "Player.h"
#include "Color.h"

Player::Player()
{
	x = 1;
	y = 1;
	subflag = 1;
	CreateBoard();
}

Player::~Player()
{
}

bool Player::GetStatus()
{
	return CheckEndOfGame();
}

void Player::Attack(Player &Enemy)
{
	int flag = 0;
	do
	{
		Enemy.ChooseXY(*this);
		if (Enemy.WhatisHere(x, y) == getpoint().pempty)//если пусто
		{
			Enemy.SetPoint(x, y, 1);
			flag = 1;
		}
			
		else if (Enemy.WhatisHere(x, y) != getpoint().pused && Enemy.WhatisHere(x, y) != getpoint().pkill && Enemy.WhatisHere(x, y) != getpoint().pshoot)//если уже использовано
		{
			Enemy.SetPoint(x, y, 2);
		}
	} while (flag!= 1);

}

void Player::MyBoard()
{
	system("cls");
	cout << "\n";
	SetColor(8, 0);
	cout << "\t\tПоле игрока:\n"
		"\t\t\t\t\t    1  2  3  4  5  6  7  8  9  10\n";
	cout << "\t\t\t\t\t  _______________________________";
	for (int i = 1; i < 11; i++)
	{

		cout << "\n\t\t\t\t\t";
		for (int j = 1; j < 11; j++)
		{

			//Вывод разметки полей
			SetColor(8, 0);

			if (i == 1 && j == 1)cout << " 1|"; else if (i == 2 && j == 1)cout << " 2|"; else if (i == 3 && j == 1)cout << " 3|";
			else if (i == 4 && j == 1)cout << " 4|"; else if (i == 5 && j == 1)cout << " 5|"; else if (i == 6 && j == 1)cout << " 6|";
			else if (i == 7 && j == 1)cout << " 7|"; else if (i == 8 && j == 1)cout << " 8|"; else if (i == 9 && j == 1)cout << " 9|";
			else if (i == 10 && j == 1)cout << "10|";

			if (board[i][j] == st.pempty)
			{
				SetColor(11, 0);
				cout << " ~ ";
				SetColor(8, 0);
			}
			else if (board[i][j] == st.pshoot)
			{
				SetColor(4, 0);
				cout << " x ";
				SetColor(8, 0);
			}
			else if (board[i][j] == st.pkill)
			{
				SetColor(4, 13);
				cout << " X ";
				SetColor(8, 0);
			}
			else if (board[i][j] == st.pused)
			{
				SetColor(10, 0);
				cout << " o ";
			}
			else
			{
				SetColor(0, 9);
				cout << " 1 ";
				SetColor(8, 0);
			}
		}
	}
	SetColor(8, 0);
	cout << endl << endl;
}

void Player::HisBoard()
{
	
	cout << "\n";
	SetColor(8, 0);
	cout << "\t\tПоле противника:\n"
		"\t\t\t\t\t    1  2  3  4  5  6  7  8  9  10\n";
	cout << "\t\t\t\t\t  _______________________________";
	for (int i = 1; i < 11; i++)
	{

		cout << "\n\t\t\t\t\t";
		for (int j = 1; j < 11; j++)
		{

			//Вывод разметки полей
			SetColor(8, 0);

			if (i == 1 && j == 1)cout << " 1|"; else if (i == 2 && j == 1)cout << " 2|"; else if (i == 3 && j == 1)cout << " 3|";
			else if (i == 4 && j == 1)cout << " 4|"; else if (i == 5 && j == 1)cout << " 5|"; else if (i == 6 && j == 1)cout << " 6|";
			else if (i == 7 && j == 1)cout << " 7|"; else if (i == 8 && j == 1)cout << " 8|"; else if (i == 9 && j == 1)cout << " 9|";
			else if (i == 10 && j == 1)cout << "10|";

			if (board[i][j] == st.pused)
			{
				if (i == x && j == y)
				{
					SetColor(10, 1);
					cout << " o ";
					SetColor(8, 0);
				}
				
				else
				{
					SetColor(10, 0);
					cout << " o ";
					SetColor(8, 0);
				}
				
			}
			else if (board[i][j] == st.pempty)
			{
				if (i == x && j == y)
				{
					SetColor(11, 1);
					cout << " ~ ";
					SetColor(8, 0);
				}
				else
				{
					SetColor(11, 0);
					cout << " ~ ";
				}
			}
			else if (board[i][j] == st.pshoot)
			{
				if (i == x && j == y)
				{
					SetColor(12, 1);
					cout << " x ";
					SetColor(8, 0);
				}
				else
				{
					SetColor(12, 0);
					cout << " x ";
					SetColor(8, 0);
				}
			}
			else if (board[i][j] == st.pkill)
			{
				if (i == x && j == y)
				{
					SetColor(12, 1);
					cout << " X ";
					SetColor(8, 0);
				}
				else
				{
					SetColor(12, 4);
					cout << " X ";
					SetColor(8, 0);
				}
			}
			else
			{
				if (i == x && j == y)
				{
					SetColor(11, 1);//11
					cout << " ~ ";
					SetColor(11, 0);
				}
				else
				{
					SetColor(11, 0);
					cout << " ~ ";
				}
			}
		}
	}
	SetColor(8, 0);
	cout << endl << endl;
}

void Player::ChooseXY(Player &Iam)
{
		char choice;
		do
		{
			choice = _getch();
			switch (choice)         // вычисление нажатой клавиши
			{
			case 'w':
				x--;
				if (x <= 0)
					x = 10;
				break;
			case 'a':
				y--;
				if (y <= 0)
					y = 10;
				break;
			case 'd':
				y++;
				if (y > 10)
					y = 1;
				break;
			case 's':
				x++;
				if (x > 10)
					x = 1;
				break;
			case 'l':
				Iam.SetXY(x, y);
				break;
			default:
				break;
			}
			if (Iam.pl == 1)
			{
				Iam.MyBoard();
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\n";
			}
			
			HisBoard();
		} while (choice != 'l');
}

void Player::CleverAttack(Player &Iam)
{

}

void Player::CompAttack(Player &Iam)
{
	int flag = 0;
	do
	{
		x = rand() % 11 + 1;
		y = rand() % 11 + 1;

		if (Iam.WhatisHere(x, y) == getpoint().pempty)//если пусто
		{
			Iam.SetPoint(x, y, 1);
			flag = 1;
		}
		else if (Iam.WhatisHere(x, y) == getpoint().pused)//если уже использовано
		{
		}
		else
		{
			Iam.SetPoint(x, y, 2);//если есть корабль
		}
	} while (flag != 1);
}