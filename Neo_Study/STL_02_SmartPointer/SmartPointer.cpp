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
		//cout << " 스마트 포인터 메모리 해제됨" << endl;
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
		cout << "operator A () 호출" << endl;
		return A();
	}
	operator int()
	{
		cout << "operator int () 호출" << endl;
		return 10;
	}
	operator double()
	{
		cout << "operator double () 호출" << endl;
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
	//Point* p1 = new Point(2, 3); //일반 포인터
	//SmartPtr p2 = new Point(5, 5); // 스마트 포인터

	//p1->Print(); //p1->Print() 호출
	//p2->Print(); //p2.operator->()->Print() 호출
	//cout << endl;

	//(*p1).Print(); //(*p1).Print() 호출
	//(*p2).Print(); //p2.operator*().Print() 호출

	//delete p1;

	//cout << "Point 클래스의 생성자 .. 중요 p49" << endl;
	//
	//Point pt;
	//pt.Print();

	//pt = 10; //대입으로 생성자 호출하는건 지양하는게 좋음. p50참고
	//pt.Print();

	//cout << "타입 연산자 오버로딩 p50" << endl;
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

	//cout << "포인터 클래스의 int 타입 변환 연산자 " << endl;
	////오퍼레이터 = 함수호출 이라 생각하면됨.
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