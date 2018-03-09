#ifndef CycleList_H
#define CycleList_H

#include "LIB.h"
using namespace std;

template <typename T>
struct node
{
	struct stat
	{
		string name;
		int win;
		int lose;
		int games;
	}data;
	node *next;
	node *prev;
};

template <typename T>
class Ring
{
private:
	node<T> *head;
public:
	Ring() { head = new (node<T>); head = NULL; }
	~Ring() { destroy(); }
	void push(T, int, int, int);
	void pop();
	void print();
	void pop(T);
	void destroy();
	void nextpart(char);
	int length();
	node<T> *find(string);
	void instruction();
	void youwin() { head->data.win++; head->data.games++; }
	void youlose() { head->data.lose++; head->data.games++; }
	void sethead(node<T> *temp) { head = temp; }

	void inFile();
	void outFile();

	friend ostream &operator<<(ostream &, const Ring);
	friend istream &operator >> (istream &, Ring &);
};

template <typename T>
void menu(T);


template <typename T>
void Ring<T>::push(T name, int win, int lose, int games)
{
	node<T> *temp, *p;
	temp = new node<T>;
	temp->data.name = name;
	temp->data.win = win;
	temp->data.lose = lose;
	temp->data.games = games;

	if (head == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		head = temp;
	}

	p = head->next;
	head->next = temp;
	temp->next = p;
	temp->prev = head;
	p->prev = temp;
	head = head->next;
}

template <typename T>
void Ring<T>::pop()
{
	if (!head)
		return;
	if (head->next == head)
	{
		delete head;
		head = NULL;
		return;
	}
	node<T> *_prev, *_next;
	_prev = head->prev;
	_next = head->next;
	_next->prev = head->prev;
	_prev->next = head->next;
	head->next = NULL;
	head->prev = NULL;

	delete head;
	head = _prev;
}

template <typename T>
void Ring<T>::pop(T nooo)
{
	if (!head)
		return;
	node<T> *temp;
	temp = this->head;
	this->head = find(nooo);
	this->pop();
}

template <typename T>
void Ring<T>::print()
{
	if (!head)
		return;
	node<T>* p;
	p = head->next;

	SetColor(10,0);
	cout << "\t\t\t+------------------+-------------+---------------+------------------+\n"
		 << "\t\t\t|       Имя        |    Побед    |   Поражений   |     Всего игр    |\n"
		 << "\t\t\t+------------------+-------------+---------------+------------------+\n";
	SetColor(7, 0);
	do
	{
		cout << "\t\t\t|" << setw(17) <<  p->data.name << " |" << setw(12) << p->data.win << " |"
			<< setw(14) << p->data.lose << " |" << setw(17) << p->data.games << " |" << endl;

		p = p->next;
	} while (p != head->next);
	cout << "\t\t\t+------------------+-------------+---------------+------------------+\n";
}

template <typename T>
void Ring<T>::destroy()
{
	if (!head)
		return;
	if (head->next = head)
	{
		delete head;
		head = NULL;
		return;
	}

	node<T> *temp;
	do
	{
		temp = head;
		head->prev = temp->prev;
		temp->prev = NULL;
		temp->next = NULL;
		delete temp;
		head = head->next;
	} while (head);
}

template <typename T>
int Ring<T>::length()
{
	node<T>* p;
	int num = 0;

	p = head;
	do
	{
		num++;
		p = p->next;
	} while (p->next != head->next);
	return num;
}

template <typename T>
node<T>* Ring<T>::find(string a)
{
	if (head)
	{
		node<T> *p;
		p = head;

		do
		{
			if (p->data.name == a)
				return p;
			p = p->next;
		} while (p->next != head->next);
			
	}
	return nullptr;
}

template <typename T>
void Ring<T>::instruction()
{
	system("cls");
	SetColor(15, 1);
	cout << "\n\n\n\t\t\t\t\t\tСТАТИСТИКА\t\t\t\t\t\t\t\t\n\n" << endl;
	SetColor(3, 0);
	cout << "\n\n\n\t\t1.Удалить последнего игрока.\n"
		"\t\t2.Удалить игрока по имени.\n"
		"\t\t3.Очистить статистику.\n"
		"\t\t0.Назад.\n\n";

	print();
}

template <typename T>
void Ring<T>::nextpart(char choice)
{
	T name;
	int win, lose, games;

	switch (choice) {
	case '1':
	{
		if (head)
			pop();
		else
			cout << "Ошибка. Создайте список.";
		break;
	}
	case '2':
	{

		T data;
		cout << "Введите данные для удаления:\n";
		cin >> data;
		if (head)
			pop(data);
		else
			cout << "Ошибка. Создайте список.";
		break;
	}
	case '3':
	{
		if (head)
			destroy();
		else
			cout << "Ошибка. Создайте список.";
		break;
	}

	case '0':
	{
		this->inFile();
		break;
	}
	default:
	{
		cout << "Неправильный выбор.";
		break;
	}
	}
	_getch();
}

template <typename T>
void Ring<T>::inFile()
{
	ofstream in("Statistics");
	if (!in)
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	if (head == NULL)
	{
		in.close();
		return;
	}

	node<T> *p;
	p = head;

	do
	{
		in << p->data.name << 
			" " << p->data.win << " " << p->data.lose << " " << p->data.games << endl;
		p = p->next;
	} while (p != head->next);
	in.close();
}

template <typename T>
void Ring<T>::outFile()
{
	T name;
	int win, lose, games;
	ifstream out("Statistics");
	if (!out)
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	while (out >> name >> win >> lose >> games)
	{
		push(name, win, lose, games);
	}
	out.close();
}

template <typename T>
ostream &operator<<(ostream &out, const Ring<T> obj)
{
	out << obj.head->data.name << obj.head->data.win
		<< obj.head->data.lose << obj.head->data.games << endl;
	return out;
}

template <typename T>
istream &operator >> (istream &in, Ring<T> &obj)
{
	in >> obj.head->data.name >> obj.head->data.win
		>> obj.head->data.lose >> obj.head->data.game >> endl;
	return in;
}

template <typename T>
void menu(T Ring)
{
	char choice;
	Ring.outFile();
	do
	{
		instruction();
		choice = getch();
		Ring.nextpart(choice);
		getch();
		system("cls");
	} while (choice != '0');

}

#endif