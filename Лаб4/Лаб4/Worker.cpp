#include "stdafx.h"
#include "Worker.h"
#include "Windows.h"
using namespace std;


void Worker::setWorker(const char *_fio, const char *_job, int _year)
{
	setFio(_fio);
	setJob(_job);
	setYear(_year);
}

Worker::Worker(const Worker &w)
{
	setWorker(w.m_fio, w.m_job, w.m_year);
}
Worker::Worker(const char *_fio, const char *_job, int _year)
{
	setWorker(_fio, _job, _year);
}

Worker::~Worker()
{
	delete[] m_fio;
	delete[] m_job;
}

void Worker::setFio(const char *_fio)
{
	// Если под имя уже выделялась память, то освободить имеющуюся
	// и выделить заново. После этого скопировать строку.
	delete[] m_fio;
	// Строка - это массив символов, в конце которой добавляется символ '\0'
	// Функция strlen возвращает количество символов в строке без учета '\0'
	m_fio = new char[strlen(_fio) + 1];
	// Функция strcpy копирует в первую строку данные из второй
	strcpy(m_fio, _fio);
}

void Worker::setYear(int _year)
{
	m_year = _year;
}

void Worker::setJob(const char *_job)
{
	// Если под должность уже выделялась память, то освободить имеющуюся
	// и выделить заново. После этого скопировать строку.
	delete[] m_job;
	// Строка - это массив символов, в конце которой добавляется символ '\0'
	// Функция strlen возвращает количество символов в строке без учета '\0'
	m_job = new char[strlen(_job) + 1];
	// Функция strcpy копирует в первую строку данные из второй
	strcpy(m_job, _job);
}

// Читаем данные в промежуточные переменные,
// после чего устанавливаем значения полей через конструктор с параметрами
void Worker::scan(istream &_in)
{
	int y,k;
	char buf1[100];
	char buf2[100];
	char buf3[100];
	cout << "Введите фамилию и инициалы работника в виде ФамилияИО: ";
	_in.getline(buf1, sizeof(buf1));
	cout << "Введите год приёма на работу: ";
	_in >> y;
	cout << "Введите должность работника: ";
	_in.getline(buf2, sizeof(buf2));//почему-то без этого не работает, просто игнорирует и выводит дальше
	_in.getline(buf3, sizeof(buf3));
	setWorker(buf1,buf3,y);
}
void Worker::print(ostream &_out) const
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	_out << "ФамилияИО работника: " << m_fio << "; должность: " << m_job << "; был принят на работу в "
		<< m_year << " году.\n";
}