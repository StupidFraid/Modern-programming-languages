
#include <iostream>
using namespace std;

void tSwitcher(void)
{
	setlocale(0, "");
	int a, b;
	cout << "Введите значение переменной <a>: ";
	cin >> a;
	cout << "Введите значение переменной <b>: ";
	cin >> b;
	cout << endl;

	void obmen1(int , int );
	void obmen2(int*, int*);
	void obmen3(int&, int&);

	cout << "до обмена:\ta=" << a << "\tb=" << b << endl;
	obmen1(a, b);
	cout << "после обмена 1:\ta=" << a << "\tb=" << b << endl;
	int* pa = &a;
	int* pb = &b;
	obmen2(pa, pb);
	cout << "после обмена 2:\ta=" << a << "\tb=" << b << endl;
	int& aRef = a;
	int& bRef = b;
	obmen3(aRef, bRef);
	cout << "после обмена 3:\ta=" << a << "\tb=" << b << endl;

}

void obmen1(int x, int y) {
	int bufX = x;
	int bufY = y;

	x = bufY;
	y = bufX;

	cout << "Вызов функции obmen1 не принесёт результата, т.к. он не может изменить переменные из-за недоступности области видимости." << endl;
}

void obmen2(int* x, int* y) {
	int bufX = *x;
	int bufY = *y;

	*x = bufY;
	*y = bufX;

	cout << "Вызов функции obmen2 поменяет местами значения обращаясь напрямую к адресу памяти, подменяя значение в нем." << endl;
}

void obmen3(int& x, int& y) {
	int bufX = x;
	int bufY = y;

	x = bufY;
	y = bufX;

	cout << "Вызов функции obmen3 поменяет местами значения обращаясь к переменной по ссылке которая указывает на его адрес в памяти." << endl;
}

main() {
	tSwitcher();
}