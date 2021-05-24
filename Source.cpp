/* �������� ������� ���� �������� ����� (��������� �������� �� �����).
�������� �������� ���� ����� �� ������� (�������� ������� ������ �� 1 �������).
��� �������� ����� ��� ��� ������ ������ � ��������� ������� ������ ��������� ������ ���������
������� ������� ��� ������ ��� ������� ������ � ��������� ����������� � �����������.*/
#include <iostream>
#include "windows.h"

using namespace std;
const int LEN = 80;
float min, max;
class Taruf
{
private:
	char Operator[LEN];
	char Name[LEN];
public:
	void getinf()
	{
		cout << "\n ������ ���������: ";
		cin >> Operator;
		cout << "\n ������ ����� ��������� ������:";
		cin >> Name;
	}
	void putinf() const
	{
		cout << "\n ��������: " << Operator;
		cout << "\n �������� �����: " << Name;
	}
	virtual float allcost() {
		return 0;
	}
};

class FirtsTaruf : public Taruf
{
private:
	float count;
	int numberMinutes;
public:
	void getdata()
	{
		Taruf::getinf();
		cout << "\n ������ ������� ������ �� 1 ��: "; cin >> count;
		cout << "\n ������ ������� ������: "; cin >> numberMinutes;

	}
	void putdata() const
	{
		Taruf::putinf();
		cout << "\n ������� ������ �� 1 ��: " << count;
		cout << "\n ʳ������ ������: " << numberMinutes;
		cout << "\n �������� �������: " << count * numberMinutes;

	}
	float allcost() {
		return count * numberMinutes;
	}
};

class SecondTaruf : public Taruf
{
private:
	float count;
	int numberMinutes;
public:
	void getdata()
	{
		Taruf::getinf();
		cout << "\n ������ ������� ������ �� 1 ��: "; cin >> count;
		cout << "\n ������ ������� ������: "; cin >> numberMinutes;

	}
	void putdata() const
	{
		Taruf::putinf();
		cout << "\n ������� ������ �� 1 ��: " << count;
		cout << "\n ʳ������ ������: " << numberMinutes;
		cout << "\n �������� �������: " << count * numberMinutes;

	}
	float allcost() {
		return count * numberMinutes;
	}
};

class ThirdTaruf : public Taruf
{
private:
	float count;
	int numberMinutes;
public:
	void getdata()
	{
		Taruf::getinf();
		cout << "\n ������ ������� ������ �� 1 ��: "; cin >> count;
		cout << "\n ������ ������� ������: "; cin >> numberMinutes;

	}
	void putdata() const
	{
		Taruf::putinf();
		cout << "\n ������� ������ �� 1 ��: " << count;
		cout << "\n ʳ������ ������: " << numberMinutes;
		cout << "\n �������� �������: " << count * numberMinutes;

	}
	float allcost() {
		return count * numberMinutes;
	}
};

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FirtsTaruf t1;
	SecondTaruf t2;
	ThirdTaruf t3;
	Taruf* taruf[3]; 
	taruf[0] = &t1;
	taruf[1] = &t2;
	taruf[2] = &t3;
	cout << endl;
	cout << "\n��� ���������� ��� ������ �������� ����\n";
	t1.getdata();

	cout << "\n��� ���������� ��� ������ �������� ����\n";
	t2.getdata();

	cout << "\n��� ���������� ��� ����� �������� ����\n";
	t3.getdata();

	int min = taruf[0]->allcost();
	int max = taruf[0]->allcost();
	int minj = 0, maxj = 0;
	cout << "\n����������� �������� ����:\n";
	for (int j = 0; j < 3; j++) {
		if (taruf[j]->allcost() <= min) {
			min = taruf[j]->allcost();
			minj = j;
		}
	}
	taruf[minj]->putinf();
	cout << "\n\n����������� �������� ����:\n";
	for (int j = 0; j < 3; j++) {
		if (taruf[j]->allcost() >= max) {
			max = taruf[j]->allcost();
			maxj = j;
		}
	}
	taruf[maxj]->putinf();
	cout << endl;
	return 0;
}