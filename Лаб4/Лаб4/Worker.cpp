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
	// ���� ��� ��� ��� ���������� ������, �� ���������� ���������
	// � �������� ������. ����� ����� ����������� ������.
	delete[] m_fio;
	// ������ - ��� ������ ��������, � ����� ������� ����������� ������ '\0'
	// ������� strlen ���������� ���������� �������� � ������ ��� ����� '\0'
	m_fio = new char[strlen(_fio) + 1];
	// ������� strcpy �������� � ������ ������ ������ �� ������
	strcpy(m_fio, _fio);
}

void Worker::setYear(int _year)
{
	m_year = _year;
}

void Worker::setJob(const char *_job)
{
	// ���� ��� ��������� ��� ���������� ������, �� ���������� ���������
	// � �������� ������. ����� ����� ����������� ������.
	delete[] m_job;
	// ������ - ��� ������ ��������, � ����� ������� ����������� ������ '\0'
	// ������� strlen ���������� ���������� �������� � ������ ��� ����� '\0'
	m_job = new char[strlen(_job) + 1];
	// ������� strcpy �������� � ������ ������ ������ �� ������
	strcpy(m_job, _job);
}

// ������ ������ � ������������� ����������,
// ����� ���� ������������� �������� ����� ����� ����������� � �����������
void Worker::scan(istream &_in)
{
	int y,k;
	char buf1[100];
	char buf2[100];
	char buf3[100];
	cout << "������� ������� � �������� ��������� � ���� ���������: ";
	_in.getline(buf1, sizeof(buf1));
	cout << "������� ��� ����� �� ������: ";
	_in >> y;
	cout << "������� ��������� ���������: ";
	_in.getline(buf2, sizeof(buf2));//������-�� ��� ����� �� ��������, ������ ���������� � ������� ������
	_in.getline(buf3, sizeof(buf3));
	setWorker(buf1,buf3,y);
}
void Worker::print(ostream &_out) const
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	_out << "��������� ���������: " << m_fio << "; ���������: " << m_job << "; ��� ������ �� ������ � "
		<< m_year << " ����.\n";
}