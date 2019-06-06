#ifndef WORKER_H
#define WORKER_H
#include <cstring>
#include <iostream>
using namespace std;

class Worker
{
	char* m_fio;//ФамилияИО работника
	char* m_job; //должность
	int m_year; //год поступления на работу
public:
	//Конструкторы
	Worker() : m_fio(0), m_year(0), m_job(0){}
	Worker(const char *_fio, const char *_job, int _year);
	Worker(const Worker &_w);
	//Декструктор
	~Worker();
	//Методы для присваивания значений полям класса
	void setFio(const char *_fio);
	void setYear(int _year);
	void setJob(const char *_job);
	void setWorker(const char *_fio, const char *_job, int _year);
	//Перегрузка операций извлечения и вставки (ввод-вывод)
	void scan(istream &_in);
	void print(ostream &_out) const;
	//Методы для доступа к значениям полей класса
	char* getFio() const { return m_fio; };
	int getYear() const { return m_year; };
	char* getJob() const { return m_job; };
};
#endif WORKER_H

