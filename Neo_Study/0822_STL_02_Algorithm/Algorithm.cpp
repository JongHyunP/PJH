#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int n)
{
	return 25 < n;
}

bool Pred2(int n)
{
	return 35 < n;
}

void Print(int n)
{
	cout << n << " ";
}

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	int n = count_if(v.begin(), v.end(), Pred);
	// 근처의 적탐색 같은 예제로도 쓰일수있다. 
	cout << "25보다 큰원소의 개수 : " << n << endl;



	vector<int>::iterator iter;
	iter = find(v.begin(), v.end(), 20);
	if (iter != v.end())
	{
		cout << *iter <<"을 찾다!" <<endl;
	}
	
	iter = find_if(v.begin(), v.end(), Pred2);
	if (iter != v.end())
	{
		cout << "순차열에서 35보다 큰 첫번째원소 : " << *iter << endl;
	}
	
	for_each(v.begin(), v.begin() + 2, Print);
	cout << endl;
	for_each(v.begin(), v.begin() + 4, Print);
	cout << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	return 0;
}