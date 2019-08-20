#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	void Print() const { cout << x << ',' << y << endl; }
	operator int() const
	{
		return x;
	}
};

class SmartPtr
{
	Point *ptr;
public:
	SmartPtr(Point *p)
	{
		ptr = p;
	}
	~SmartPtr()
	{
		//cout << " ����Ʈ ������ �޸� ������" << endl;
		delete ptr;
	}
	Point* operator->() const
	{
		return ptr;
	}
	Point& operator*() const
	{
		return *ptr;
	}
};

class A
{
};

class B {
public:
	operator A()
	{
		cout << "operator A () ȣ��" << endl;
		return A();
	}
	operator int()
	{
		cout << "operator int () ȣ��" << endl;
		return 10;
	}
	operator double()
	{
		cout << "operator double () ȣ��" << endl;
		return 5.5;
	}
};

class String
{
	const char* a;

public:
	String(const char *aaa) { a = aaa; }
	operator const char*()
	{
		return a;
	}
};

int main()
{
	//Point* p1 = new Point(2, 3); //�Ϲ� ������
	//SmartPtr p2 = new Point(5, 5); // ����Ʈ ������

	//p1->Print(); //p1->Print() ȣ��
	//p2->Print(); //p2.operator->()->Print() ȣ��
	//cout << endl;

	//(*p1).Print(); //(*p1).Print() ȣ��
	//(*p2).Print(); //p2.operator*().Print() ȣ��

	//delete p1;

	//cout << "Point Ŭ������ ������ .. �߿� p49" << endl;
	//
	//Point pt;
	//pt.Print();

	//pt = 10; //�������� ������ ȣ���ϴ°� �����ϴ°� ����. p50����
	//pt.Print();

	//cout << "Ÿ�� ������ �����ε� p50" << endl;
	//A a;
	//int n;
	//double d;

	//B b;
	//a = b;
	//n = b;
	//d = b;

	//cout << endl;

	//a = b.operator A();
	//n = b.operator int();
	//d = b.operator double();

	//cout << "������ Ŭ������ int Ÿ�� ��ȯ ������ " << endl;
	////���۷����� = �Լ�ȣ�� �̶� �����ϸ��.
	//int n1 = 10;

	//Point pt(2, 3);
	//n1 = pt;
	//cout << n1 << endl;

	String s("Hello!");
	const char* sz = s;

	const char* szz = "Hello!";
	String ss("Hi~!");

	cout << szz << endl;
	cout << ss << endl;

	return 0;
}