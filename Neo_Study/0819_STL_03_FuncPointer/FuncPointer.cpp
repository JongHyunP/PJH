#include <iostream>
#include <algorithm>

using namespace std;

//void Print(int n)
//{
//	cout << "���� : " <<n<< endl;
//}
//
//void Print1()
//{
//	cout << "�����Լ� Print()" << endl;
//}
//
//class Point
//{
//public:

//	void Print()
//	{
//		cout << "����Լ� Print()" << endl;
//	}
//	static void Print(int n)
//	{
//		cout <<" Point Ŭ������ ������� �Լ� : " << n << endl;
//	}
//};

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "�׽�Ʈ���� : " << n << endl; }
};

namespace A
{
	void Print(int n)
	{
		cout << "namespace A �����Լ� :" << n << endl;
	}
}

// ------------------------------------------------------

void Print1(int n)
{
	cout << n << ' ';
}

void Print2(int n)
{
	cout << n * n << ' ';
}

void Print3(int n)
{
	cout << "���� : " << n << endl;
}

int main()
{
	//void print(int n)�� �Լ� ����
	//�Լ��� ����ȭ �Ѵ�.

	//void(*pf)(int);
	//pf = Print;

	//Print(10);
	//pf(10);
	//(*pf)(10);

	//cout << endl;
	//cout << Print << endl;
	//cout << pf << endl;
	//cout << *pf << endl;

	//cout << "--------------------------"<<endl;

	//Point pt;
	//Point *p = &pt;

	//Print1();
	//pt.Print();
	//p->Print();

	//cout << "--------------------------" << endl;

	//void(*pf)(int);

	//Print(10);
	//A::Print(10);
	//Point::Print(10);
	//
	//pf = Print;
	//pf(10);
	//pf = A::Print;
	//pf(10);
	//pf = Point::Print;
	//pf(10);
	//cout << "-----------------p65---------" << endl;

	//Point pt(2, 3);
	//Point *p = &pt;
	//void (Point::Point*pf1)() const;
	//pf1 = &Point::Print();

	//void (Point::pf2)(int);
	//pf2 =

	cout << "--------------------------------------------------" << endl;

	int arr[5] = { 10,20,30,40.50 };

	for_each(arr, arr + 5, Print1);

	cout << endl << endl;

	for_each(arr, arr + 5, Print2);

	cout << endl << endl;;

	for_each(arr, arr + 5, Print3);

	return 0;
}