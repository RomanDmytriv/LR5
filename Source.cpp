/* Створити базовий клас ТАРИФНИЙ ПАКЕТ (задаються оператор та назва).
Створити похідний клас ПАКЕТ ЗА КАРТКОЮ (задається вартість дзвінків за 1 хвилину).
Для введених даних про різні тарифні пакети і очікувану кількість хвилин щомісячних розмов обчислити
сумарну вартість цих розмов для кожного пакету і визначити найдешевший і найдорожчий.*/
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
		cout << "\n Введіть оператора: ";
		cin >> Operator;
		cout << "\n Введіть назву тарифного пакету:";
		cin >> Name;
	}
	void putinf() const
	{
		cout << "\n Оператор: " << Operator;
		cout << "\n Тарифний пакет: " << Name;
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
		cout << "\n Введіть вартість дзвінків за 1 хв: "; cin >> count;
		cout << "\n Введіть кількість хвилин: "; cin >> numberMinutes;

	}
	void putdata() const
	{
		Taruf::putinf();
		cout << "\n Вартість дзвінків за 1 хв: " << count;
		cout << "\n Кількість хвилин: " << numberMinutes;
		cout << "\n Загальна вартість: " << count * numberMinutes;

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
		cout << "\n Введіть вартість дзвінків за 1 хв: "; cin >> count;
		cout << "\n Введіть кількість хвилин: "; cin >> numberMinutes;

	}
	void putdata() const
	{
		Taruf::putinf();
		cout << "\n Вартість дзвінків за 1 хв: " << count;
		cout << "\n Кількість хвилин: " << numberMinutes;
		cout << "\n Загальна вартість: " << count * numberMinutes;

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
		cout << "\n Введіть вартість дзвінків за 1 хв: "; cin >> count;
		cout << "\n Введіть кількість хвилин: "; cin >> numberMinutes;

	}
	void putdata() const
	{
		Taruf::putinf();
		cout << "\n Вартість дзвінків за 1 хв: " << count;
		cout << "\n Кількість хвилин: " << numberMinutes;
		cout << "\n Загальна вартість: " << count * numberMinutes;

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
	cout << "\nВвід інформації про перший тарифний план\n";
	t1.getdata();

	cout << "\nВвід інформації про другий тарифний план\n";
	t2.getdata();

	cout << "\nВвід інформації про третій тарифний план\n";
	t3.getdata();

	int min = taruf[0]->allcost();
	int max = taruf[0]->allcost();
	int minj = 0, maxj = 0;
	cout << "\nНайдешевший тарифний план:\n";
	for (int j = 0; j < 3; j++) {
		if (taruf[j]->allcost() <= min) {
			min = taruf[j]->allcost();
			minj = j;
		}
	}
	taruf[minj]->putinf();
	cout << "\n\nНайдорожчий тарифний план:\n";
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