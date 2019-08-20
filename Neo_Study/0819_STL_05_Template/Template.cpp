#include <iostream>
#include <string>
using namespace std;

//template<typename T1, typename T2>
//
//void Print(T1 a, T2 b) //�Լ����ø��� ����� Ÿ�� ���� �� ȣ��
//{
//	cout << a << " " << b << endl;
//}
//
//template<typename T1>
//void Swap(T1 &a, T1 &b)
//{
//	T1 temp = a;
//	a = b;
//	b = temp;
//}

//class Point
//{
//	int x, y;
//public:
//	explicit Point(int _x = 0, int _y = 0) : x(_x),y(_y) {}
//	void Print() const { cout << x << ' ' << y << endl; }
//};
//
//template <typename T>
//void Print(T a)
//{
//	cout << a << endl;
//}
//
//template <>
//void Print(Point a)
//{
//	cout << "Print  Ư��ȭ ���� :";
//	a.Print();
//}

//template <typename T>
//
//class Array
//{
//	T *buf;
//	int size;
//	int capacity;
//public:
//	explicit Array(int cap = 100) :buf(0), size(0), capacity(cap)
//	{
//		buf = new T[capacity];
//	}
//	~Array() { delete[] buf; }
//	void Add(T data)
//	{
//		buf[size++] = data;
//	}
//	T operator[] (int idx) const
//	{
//		return buf[idx];
//	}
//	int GetSize() const
//	{
//		return size;
//	}
//};

//template <typename T>
//
//class Obj
//{
//	T data;
//public:
//	Obj(const T& d):data(d) {}
//
//	void Print()
//	{
//		cout << "Ÿ�� : " << typeid(data).name() << endl;
//		cout << "ũ�� : " << sizeof(data) << endl;
//		cout << "�� : " << data << endl;
//		cout << endl;
//	}
//};
//
//template <typename IterT , typename Func>
//
//void For_each(IterT begin, IterT end, Func pf)
//{
//	while (begin!= end)
//	{
//		pf(*begin++);
//	}
//}
//
//void PrintInt(int data)
//{
//	cout << data << " ";
//}
//
//void PrintString(string data)
//{
//	cout << data << " ";
//}

//template < typename RetType, typename ArgType>
//
//class Functor
//{
//public:
//	RetType operator() (ArgType data)
//	{
//		cout << data << endl;
//		return RetType();
//	}
//};

template <typename T1, typename T2>

struct Pair
{
	T1 first;
	T2 second;
	Pair(const T1& ft, const T2 &sd) :first(ft), second(sd) {}
};

int main()
{
	/*Print(10, 1.5);
	Print("����", 100);
	Print(1.5, "��������");*/

	/*int n1 = 10, n2 = 20;
	double d1 = 1.1, d2 = 2.2;

	cout << n1 << ' ' << n2 << endl;
	Swap(n1, n2);
	cout << n1 << ' ' << n2 << endl;

	cout << endl;

	cout << d1 << " " << d2 << endl;
	Swap(d1, d2);
	cout << d1 << " " << d2 << endl;
	cout << endl;*/

	//int n = 10;
	//double d = 2.5;
	//Point pt(2, 3);

	//Print(n);
	//Print(d);
	//Print(pt);

	//  --------------------------------------------------------
	//Ŭ���� ���ø� array

	//Array<int> iarr;
	//iarr.Add(10);
	//iarr.Add(20);
	//iarr.Add(30);

	//for (int i = 0; i < iarr.GetSize(); i++)
	//{
	//	cout << iarr[i] << ' ';
	//}
	//cout << endl;

	//Array<double> darr;
	//darr.Add(10.22);
	//darr.Add(10.33);
	//darr.Add(10.44);
	//for (int i = 0; i < darr.GetSize(); i++)
	//{
	//	cout << darr[i] << ' ';
	//}
	//cout << endl;

	//Array<string> sarr;
	//sarr.Add("����");
	//sarr.Add("����");
	//sarr.Add("����������");
	//for (int i = 0; i < sarr.GetSize(); i++)
	//{
	//	cout << sarr[i] << ' ';
	//}
	//cout << endl;
	//  --------------------------------------------------------
	//��ü ������ ����ϴ� Ŭ����

	//Obj<int> d1(10);
	//d1.Print();

	//Obj<double> d2(10.22);
	//d2.Print();

	//Obj<string> d3("����");
	//d3.Print();

	//  --------------------------------------------------------
	//

	//int arr[5] = { 10,20,30,40,50 };

	//For_each(arr, arr + 5, PrintInt);
	//cout << endl;

	//string arr2[3] = { "dkdkdk","dddd","222" };

	//For_each(arr2, arr2 + 3, PrintString);
	//cout << endl;



	//  --------------------------------------------------------
	//p122

	//Functor<void, int> fun1;
	//fun1(10);
	//Functor<bool, string> fun2;
	//fun2("d������");


	//----------------------------------------------------------
	Pair<int, int> p1(10, 20);
	cout << p1.first << ' ' << p1.second << endl;
	Pair<int, string> p2(1, "one");
	cout << p2.first << ' ' << p2.second << endl;
	cout << endl;

	pair<int, int> p3(10, 20);
	cout << p3.first << ' ' << p3.second << endl;
	pair<int, string> p4(1, "one");
	cout << p4.first << ' ' << p4.second << endl;


	return 0;
}