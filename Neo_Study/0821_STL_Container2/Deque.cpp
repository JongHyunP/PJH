#include <iostream>
#include <deque>

using namespace std;

int main()
{
	//------------------------p211---------------------------------
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	for (deque<int>::size_type i = 0; i < dq.size(); ++i)
	{
		cout << dq[i] << " ";
	}
	cout << endl;

	dq.push_front(100); //앞쪽에 데이터를 추가하고싶을때는 덱을쓰는게 좋다.
	dq.push_front(200);

	for (deque<int>::size_type i = 0; i < dq.size(); ++i)
	{
		cout << dq[i] << " ";
	}
	//--------------------------------------------------------------


	return 0;
}