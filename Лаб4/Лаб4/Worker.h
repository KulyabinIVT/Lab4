#ifndef WORKER_H
#define WORKER_H
#include <cstring>
#include <iostream>
using namespace std;

class Worker
{
	char* m_fio;//��������� ���������
	char* m_job; //���������
	int m_year; //��� ����������� �� ������
public:
	//������������
	Worker() : m_fio(0), m_year(0), m_job(0){}
	Worker(const char *_fio, const char *_job, int _year);
	Worker(const Worker &_w);
	//�����������
	~Worker();
	//������ ��� ������������ �������� ����� ������
	void setFio(const char *_fio);
	void setYear(int _year);
	void setJob(const char *_job);
	void setWorker(const char *_fio, const char *_job, int _year);
	//���������� �������� ���������� � ������� (����-�����)
	void scan(istream &_in);
	void print(ostream &_out) const;
	//������ ��� ������� � ��������� ����� ������
	char* getFio() const { return m_fio; };
	int getYear() const { return m_year; };
	char* getJob() const { return m_job; };
};
#endif WORKER_H

