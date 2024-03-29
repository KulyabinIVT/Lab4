// Лаб4, вариант 6: определить класс с именем Worker
// Написать программу, выполняющую следующие действия: 
//ввод с клавиатуры данных в массив, состоящий из десяти объектов типа WORKER;
//записи должны быть размещены по алфавиту;
//вывод на дисплей фамилий работников, чей стаж работы в организации превышает значение, введенное с клавиатуры;

#include <iostream>
#include "stdafx.h"
#include "Worker.h"
#include "Windows.h"
#include <fstream>
#define size 3 //размерность массива объектов типа WORKER
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Worker *workers = new Worker[size];
	for (int i = 0; i < size; i++)
	{
		// В пустой объект (не инициализированный) передаем поток,
		// связанный с клавиатурой.
		workers[i].scan(cin);
	}
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (strcmp(workers[i].getFio(), workers[j].getFio()) > 0)
			{
				Worker t(workers[i]);
				workers[i].setFio(workers[j].getFio());
				workers[i].setJob(workers[j].getJob());
				workers[i].setYear(workers[j].getYear());
				workers[j].setFio(t.getFio());
				workers[j].setJob(t.getJob());
				workers[j].setYear(t.getYear());
			}
		// Выводим данные на экран (поток cout).
		cout << "\n";
	for (int i = 0; i <  size; i++)
	{
		// Выводим данные на экран (поток cout).
		workers[i].print(cout);
	}
	
	int s = 0;
	cout << "Введите стаж: ";
	cin >> s;
	int count = 0;
	cout << "Работники с таким стажем: \n";
	for (int i = 0; i < size; i++)
	{
		if (2019 - workers[i].getYear() >= s)
		{
			workers[i].print(cout);
			count++;
		}
	}
	if (count == 0)
		cout << "Работников с таким стажем не найдено! \n";
	system("pause");
    return 0;
}

