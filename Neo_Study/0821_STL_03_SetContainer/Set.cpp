#include <iostream>
#include <set>

using namespace std;

int main()
{
	//----------------p254------------------------
	//set<int> s;

	//s.insert(10);
	//s.insert(40);
	//s.insert(20);
	//s.insert(30);
	//s.insert(50);

	//set<int>::iterator iter;
	//for (iter = s.begin(); iter != s.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//s.insert(50); //�ߺ��� ���Ҷ� ���Կ� �����Ѵ�.
	//s.insert(50);

	//for (iter = s.begin(); iter != s.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;
	//----------------p263------------------------

	//set<int> s;

	//s.insert(10);
	//s.insert(40);
	//s.insert(20);
	//s.insert(30);
	//s.insert(50);

	//set<int>::iterator iter;
	//for (iter = s.begin(); iter != s.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//iter = s.find(30); // ���� 30�� ã�´�

	//if (iter != s.end())
	//{
	//	cout << *iter<<"�� s�� �ִ�!!" << endl;
	//}
	//else
	//{
	//	cout << "30�� s�� ����" << endl;
	//}
	//----------------p266------------------------

	set<int> s;

	s.insert(10);
	s.insert(40);
	s.insert(20);
	s.insert(30);
	s.insert(50);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	set<int>::iterator iter_lower;
	set<int>::iterator iter_upper;

	iter_lower = s.lower_bound(30);
	iter_upper = s.upper_bound(30);

	cout << *iter_lower << endl;
	cout << *iter_upper << endl;

	iter_lower = s.lower_bound(55);
	iter_upper = s.upper_bound(55);

	if (iter_lower != iter_upper)
	{
		cout << "55�� s�� ����" << endl;
	}
	else
	{
		cout << "55�� s�� ����" << endl;
	}


	return 0;
}