#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

// [ĸ��](�Ķ����)-> ����Ÿ�� {�Լ�}

bool Less(int &l, int &r)
{
	return l < r;
}

int main()
{
	//���Ϳ� ���� �������̽��� �����.

	//vector<int> v;

	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);

	//vector<int>::iterator iter; // �����Ͷ�� �����ϸ��.

	//for (iter = v.begin(); iter != v.end(); ++iter)
	//{
	//	cout << *iter << endl; //�׷��� *�� �ٿ��� ���� ���(������)
	//}
	//----------------------------------------------------------------------------
	/*deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator diter = dq.begin();

	cout << diter[0] << endl;
	cout << diter[1] << endl;
	cout << diter[2] << endl;
	cout << diter[3] << endl;
	cout << diter[4] << endl;
	cout << endl;

	diter += 2;
	cout << *diter << endl;

	deque<int>::iterator diter2 = diter+2;
	cout << *diter2 << endl;*/
	//----------------------------------------------------------------------------
	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);

	//vector<int>::iterator iter; 
	//iter = find(v.begin(), v.end(), 20);
	//cout << *iter << endl;

	//iter = find(v.begin(), v.end(), 100);
	//if (iter == v.end()) //������������.strstró��.
	//{
	//	cout << "100�� ����!" << endl;
	//}
	//----------------------------------------------------------------------------
	vector<int> v;
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);

	sort(v.begin(), v.end(), less<int>()); //��Ʈ���� ������ �����ĵ� sort(,,����° ���� -> �Լ������� = Pr_Pred)
	sort(v.begin(), v.end(), Less);
	sort(v.begin(), v.end(), [](int &l, int & r)->bool {return l < r; }); // ���ٽ�, �Լ���ü�� �ٷ� �����ϴ°�.// [] ĸ�Ĵ� �ʿ��Ѱ��� ������ ���°Ŷ������ϸ��. 
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	//----------------------------------------------------------------------------
	// ���� �����̳�
	//stack<int> st;

	//st.push(10);
	//st.push(20);
	//st.push(30);

	//cout << st.top() << endl; //���� �����ִ¾ָ� ������
	//st.pop(); // ������ �ָ� ����
	//cout << st.top() << endl;
	//st.pop();
	//cout << st.top() << endl;
	//st.pop();
	//if (st.empty())
	//	cout << "������ ��" << endl;

	//----------------------------------------------------------------------------

	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);

	//for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
 //   {
	//   cout << *iter << endl; //�׷��� *�� �ٿ��� ���� ���(������)
 //   }

	//cout << endl;


	//vector<int>::reverse_iterator riter(v.rbegin());
	//for (; riter != v.rend(); ++riter)
	//{
	//	cout << *riter << endl;
	//}
	//cout << endl;
	//-----------------------------------------------------------------------------

		vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	return 0;
}