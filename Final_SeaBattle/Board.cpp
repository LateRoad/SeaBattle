#include "Board.h"

#define CheckAddShips(a1,a2,b1,b2) \
          for(int a=a1;a<=a2;++a){\
            for(int b=b1;b<=b2;++b){\
                ig[++cg]=a;jg[cg]=b;\
            }\
        }

Board::Board()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			board[i][j] = nullptr;
	}
}

Board::~Board()
{

}

void Board::CreateBoard()
{
	const int size = 200;
	int ig[size], jg[size];//Массивы для проверок на повторность + проверок границ (расстояние между кор. не < 1 ячейки)

	int cg = -1;//Счетчик для проверочных массивов
	int ki, kj;//Переменные для подбора координат
	short gv;//Переменная для выбора положения расстановки кораблей 2 - 4 (Horizontal. , Vertical.)

			 //ship (4) х1 шт.
	for (int i = 0; i<1; ++i) {
	m4:
		gv = rand() % 2;//Случайный подбор положения кораблей
		ki = rand() % 10 + 1;//Случайный подбор координат кораблей
		kj = rand() % 10 + 1;
		if (!gv&&kj>7 || gv&&ki>7)//Проверка границ кординат
			goto m4;

		if (!gv) {//Заполнение массива проверенными коорд. корабля (4) по Horizontal. + установка границ вокруг корабля
			CheckAddShips(ki - 1, ki + 1, kj - 1, kj + 4);

			//Заполнение массива проверенными коорд. корабля (4) по Horizontal. + установка границ вокруг корабля
			board[ki][kj] = boat[0].GetPBoat(); 
			board[ki][kj + 1] = boat[0].GetPBoat();
			board[ki][kj + 2] = boat[0].GetPBoat();
			board[ki][kj + 3] = boat[0].GetPBoat();
		}
		else {//Заполнение массива проверенными  коорд. корабля (4) по Vertical. + установка границ вокруг корабля
			CheckAddShips(ki - 1, ki + 4, kj - 1, kj + 1);

			//Заполнение массива проверенными коорд. корабля (4) по Vertical. + установка границ вокруг корабля
			board[ki][kj] = boat[0].GetPBoat();
			board[ki + 1][kj] = boat[0].GetPBoat();
			board[ki + 2][kj] = boat[0].GetPBoat();
			board[ki + 3][kj] = boat[0].GetPBoat();
		}
	}

	//Корабли (3) х2 шт.
	for (int i = 1; i<3; ++i)
	{
		gv = rand() % 2;
	m3:
		ki = rand() % 10 + 1;
		kj = rand() % 10 + 1;
		if (!gv&&kj>8 || gv&&ki>8)
			goto m3;
		//Проверка на границы с кораблем (3), (4)
		for (int j = 0; j <= cg; ++j) {
			if (!gv&&ki == ig[j] && kj == jg[j] || !gv&&ki == ig[j] && kj + 1 == jg[j] || !gv&&ki == ig[j] && kj + 2 == jg[j])//...по Horizontalон.
				goto m3;
			else if (gv&&ki == ig[j] && kj == jg[j] || gv&&ki + 1 == ig[j] && kj == jg[j] || gv&&ki + 2 == ig[j] && kj == jg[j])//...по Vertical.
				goto m3;
		}
		if (!gv) {
			CheckAddShips(ki - 1, ki + 1, kj - 1, kj + 3);

			//Заполнение массива игрового поля игрока проверенными кординатами кораблей по Horizontal.
			board[ki][kj] = boat[i].GetPBoat();
			board[ki][kj + 1] = boat[i].GetPBoat();
			board[ki][kj + 2] = boat[i].GetPBoat();
		}
		else {
			CheckAddShips(ki - 1, ki + 3, kj - 1, kj + 1);

			//Заполнение массива игрового поля игрока проверенными кординатами кораблей по Vertical.
			board[ki][kj] = boat[i].GetPBoat();
			board[ki + 1][kj] = boat[i].GetPBoat();
			board[ki + 2][kj] = boat[i].GetPBoat();
		}
	}

	//Корабли (2) 3шт.
	for (int i = 3; i<6; ++i) {

	m2:
		gv = rand() % 2;
		ki = rand() % 10 + 1;
		kj = rand() % 10 + 1;
		if (!gv&&kj>9 || gv&&ki>9)
			goto m2;
		for (int j = 0; j <= cg; ++j) {//Проверка на границы с кораб. (2), (3), (4)
			if (!gv&&ki == ig[j] && kj == jg[j] || !gv&&ki == ig[j] && kj + 1 == jg[j])      //...по Horizontalон.
				goto m2;
			else if (gv&&ki == ig[j] && kj == jg[j] || gv&&ki + 1 == ig[j] && kj == jg[j])  //...по Vertical.
				goto m2;
		}
		if (!gv) {
			CheckAddShips(ki - 1, ki + 1, kj - 1, kj + 2);
			board[ki][kj] = boat[i].GetPBoat();
			board[ki][kj + 1] = boat[i].GetPBoat();
		}
		else {
			CheckAddShips(ki - 1, ki + 2, kj - 1, kj + 1);
			board[ki][kj] = boat[i].GetPBoat(); 
			board[ki + 1][kj] = boat[i].GetPBoat();
		}
	}

	//Корабли (1) 4шт.
	for (int i = 6; i<10; ++i) {
	m1:
		ki = rand() % 10 + 1;
		kj = rand() % 10 + 1;

		for (int j = 0; j <= cg; ++j) {
			if (ki == ig[j] && kj == jg[j])
				goto m1;
		}
		CheckAddShips(ki - 1, ki + 1, kj - 1, kj + 1);
		board[ki][kj] = boat[i].GetPBoat();
	}
}

bool Board::CheckEndOfGame()
{
	int end = 0;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (board[i][j] == st.pkill)
				end++;
		}
	}
	if (end == 20)
		return true;
	return false;
}

int * Board::WhatisHere(int x, int y)
{
	return board[x][y];
}

void Board::SetPoint(int x, int y, int status)
{
	switch (status)
	{
	case 1:
	{
		board[x][y] = st.pused;
		break;
	}
	case 2:
	{
		if(!CheckifKilled(x, y))
			if(board[x][y] != st.pkill)
				board[x][y] = st.pshoot;
		
		break;
	}
	case 3:
	{
		board[x][y] = st.pempty;
		break;
	}
	}
}

bool Board::CheckifKilled(int x, int y)
{
	struct BOAT
	{
		int x;
		int y;
	}boat[4];
	int j = 0;

	int k = 0;

	for (int i = 1; i < 4; i++)
	{
		if (WhatisHere(x + i, y) != st.pshoot && WhatisHere(x + i, y) != st.pused && WhatisHere(x + i, y) != st.pempty)
			return false;
		if (WhatisHere(x + i, y) == st.pused || WhatisHere(x + i, y) == st.pempty)
			break;
		if (WhatisHere(x + i, y) == st.pshoot)
		{
			boat[j].x = x + i;
			boat[j].y = y;
			j++;
		}
		
	}
	for (int i = 1; i < 4; i++)
	{
		if (WhatisHere(x - i, y) != st.pshoot && WhatisHere(x - i, y) != st.pused && WhatisHere(x - i, y) != st.pempty)
			return false;
			
		if (WhatisHere(x - i, y) == st.pused || WhatisHere(x - i, y) == st.pempty)
			break;
		if (WhatisHere(x - i, y) == st.pshoot)
		{
			boat[j].x = x - i;
			boat[j].y = y;
			j++;
		}
	}

	for (int i = 1; i < 4; i++)
	{
		if (WhatisHere(x, y + i) != st.pshoot && WhatisHere(x, y + i) != st.pused && WhatisHere(x, y + i) != st.pempty)
			return false;
		if (WhatisHere(x, y + i) == st.pused || WhatisHere(x, y + i) == st.pempty)
			break;
		if (WhatisHere(x, y + i) == st.pshoot)
		{
			boat[j].x = x;
			boat[j].y = y + i;
			j++;
		}
	}
	for (int i = 1; i < 4; i++)
	{
		if (WhatisHere(x, y - i) != st.pshoot && WhatisHere(x, y - i) != st.pused && WhatisHere(x, y - i) != st.pempty)
			return false;
		if (WhatisHere(x, y - i) == st.pused || WhatisHere(x, y - i) == st.pempty)
			break;
		if (WhatisHere(x, y - i) == st.pshoot)
		{
			boat[j].x = x;
			boat[j].y = y - i;
			j++;
		}
	}

	BOAT min, max;
	min.x = max.x = x;
	min.y = max.y = y;
	board[x][y] = st.pkill;
	if (j)
	{
		for (int i = 0; i < j; i++)
		{
			if (x + 1 == boat[i].x || x - 1 == boat[i].x)
				k = 1;
			board[boat[i].x][boat[i].y] = st.pkill;

			if (boat[i].x < min.x || boat[i].y > min.y)
			{
				min.x = boat[i].x;
				min.y = boat[i].y;
			}
			if (boat[i].x > max.x || boat[i].y < max.y)
			{
				max.x = boat[i].x;
				max.y = boat[i].y;
			}
		} 
	}
	if(k)
		AddUsed(min.x, min.y, j+1, k);
	else
		AddUsed(max.x, max.y, j + 1, k);
	return true; 
}

void Board::AddUsed(int x, int y, int n, int gororvert)
{
	if (!gororvert)
	{
		for (int i = 0; i <n + 2; i++)
		{
			board[x - 1][y - 1 + i] = board[x + 1][y - 1 + i] = st.pused;
		}
		board[x][y - 1] = board[x][y + n] = st.pused;
	}
	else
	{
		for (int i = 0; i <n + 2; i++)
		{
			board[x - 1 +i][y - 1] = board[x - 1 + i][y+1] = st.pused;
		}
		board[x - 1][y] = board[x + n][y] = st.pused;
	}
		

}
