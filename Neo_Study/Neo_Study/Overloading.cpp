#include <iostream>

using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}

	void Print() const { cout << x << ',' << y << endl; }

	int GetX() const //const �Լ�
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}

	void operator+(Point arg)
	{
		cout << "operator+() �Լ�ȣ��" << endl;
	}

	//void operator==(const Point& arg) const
	//{
	//	return x == arg.x && y == arg.y ? true : false;
	//}
	int  operator[](int idx) const
	{
		if (idx == 0)
			return x;
		else if (idx == 1)
			return y;
		else
			throw "�̷����� ���°ž�";
	}
};

const Point operator-(const Point& argL, const Point& argR)
{
	return Point(argL.GetX() - argR.GetX(), argL.GetY() - argR.GetY());
}

struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "���� :" << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "���� : " << arg << endl;
}

class Array
{
	int *arr;
	int size;
	int capacity;
public:
	Array(int cap = 100) : arr(0), size(0), capacity(cap)
	{
		arr = new int[capacity];
	}
	~Array()
	{
		delete[] arr;
	}
	void Add(int data)
	{
		if (size < capacity)
		{
			arr[size++] = data;
		}
	}
	int Size() const
	{
		return size;
	}

	int operator[](int idx) const
	{
		return arr[idx];
	}
	int operator[](int idx)
	{
		return arr[idx];
	}
};


int main()
{
	//const Point p1(0, 0);
	//Point p2(2, 3);

	//p1.Print();
	//p2.Print();

	//cout << "p1: " << p1.GetX() << ',' << p1.GetY() << endl;
	//cout << "p2: " << p2.GetX() << ',' << p2.GetY() << endl;
	//
	////p1.SetX(5);
	//p2.SetX(5);

	//cout << "p1: " << p1.GetX() << ',' << p1.GetY() << endl;
	//cout << "p2: " << p2.GetX() << ',' << p2.GetY() << endl;

	//cout << "------------------------------------------------------" << endl;
	//cout << "���׿����� == " << endl;

	//Point p1(2, 3), p2(5, 5), p3(2, 3);

	//if (p1 == p2)
	//	cout << "p1==p2" << endl;
	//if (p1 == p3)
	//	cout << "p1==p3" << endl;

	//cout << "------------------------------------------------------" << endl;
	//cout << "�����Լ��� �̿��� �����ε� p30" << endl;

	//cout << "------------------------------------------------------" << endl;
	//cout << "�Լ� ȣ�� ������ �����ε�()������ p33" << endl;

	//void(*Print2)(int) = Print1;
	//FuncObject Print3;

	//Print1(10); // �Լ��� ����Ͽ� ���� ���
	//Print2(10); //�Լ� ������
	//Print3(10); // �Լ� ��ü�� ����� ���� ���

	//cout << "------------------------------------------------------" << endl;
	//cout << "�迭 �ε��� ������ �����ε� [] p36" << endl;
	//Point pt(1, 2);
	//pt.Print();

	//cout << pt[0] <<',' << pt[1]<< endl;


	cout << "------------------------------------------------------" << endl;
	cout << "��� ��ü�� ��ȯ�ϴ� []������ �����ε� p40" << endl;

	Array ar(0);
	ar.Add(10);
	ar.Add(20);
	ar.Add(30);

	cout << ar[0] << endl;
	cout << endl;

	//����Ʈ ������ : ���۷��� ī����


	return 0;
}