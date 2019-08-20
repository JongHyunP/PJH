#include <iostream>
#include <algorithm>

using namespace std;

struct Func1
{
	void operator()(int n)
	{
		cout << n << " ";
	}
};

struct Func2
{
	void operator()(int n)
	{
		cout << n * n << " ";
	}
};

struct Func3
{
	void operator()(int n)
	{
		cout << "정수 : " << n << endl;
	}
};

//Less의 구현 --------------------------
bool Pred_less(int a, int b)
{
	return a < b;
}

struct Less
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};


int main()
{
	//int arr[5] = { 10,20,30,40,50 };

	//for_each(arr, arr + 5, Func1());

	//cout << endl << endl;

	//for_each(arr, arr + 5, Func2());

	//cout << endl << endl;

	//for_each(arr, arr + 5, Func3());

	//-----------------------------------------

	Less l;

	cout << Pred_less(10, 20) << endl;
	cout << Pred_less(20, 10) << endl;

	cout << endl;

	cout << l(10, 20) << endl;
	cout << l(20, 10) << endl;
	cout << Less()(10, 20) << endl;
	cout << Less()(20, 10) << endl;
	cout << endl;

	cout << l.operator()(10, 20) << endl;
	cout << Less().operator()(10, 20) << endl;


	return 0;
}
