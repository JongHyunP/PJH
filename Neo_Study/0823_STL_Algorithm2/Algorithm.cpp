#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>

using namespace std;

bool Pred(int n)
{
	return 30 <= n && n <= 50;
}

bool Pred2(int n)
{
	return 30 <= n && n <= 40;
}

bool Pred3(int left,int right)
{
	return abs(right - left) < 10;
}

template<typename T>

struct Plus
{
	T operator() (const T& left , const T& right)
	{
		return left + right;
	}
};


int main()
{
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);
	//v.push_back(60);
	//v.push_back(70);
	//v.push_back(80);

	//cout << "v : ";
	//for (vector<int>::size_type i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	//replace_if(v.begin(), v.end(), Pred, 0);

	//cout << "v : ";
	//for (vector<int>::size_type i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	/*vector<int>::iterator iter_end;
	iter_end = remove_if(v.begin(), v.end(), Pred2);

	cout << "[v.begin(),iter_end) : ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_end; iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;*/

	// p373
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(11);
	//v.push_back(30);
	//v.push_back(32);
	//v.push_back(40);
	//v.push_back(50);
	//p383
	//srand((unsigned)time(NULL));
	//vector<int> v;

	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);

	//cout << "v : ";
	//for (vector<int>::size_type i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	//random_shuffle(v.begin(), v.end());
	//cout << "v : ";
	//for (vector<int>::size_type i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;

	//random_shuffle(v.begin(), v.end());
	//cout << "v : ";
	//for (vector<int>::size_type i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] << " ";
	//}
	//cout << endl;
	

	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << accumulate(v.begin(), v.end(), 0, Plus<int>()) << endl;

	cout << accumulate(v.begin(), v.end(), 0, plus<int>()) << endl;

	cout << accumulate(v.begin(), v.end(), 1, multiplies<int>()) << endl;

	return 0;
}