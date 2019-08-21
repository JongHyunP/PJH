#include <iostream>
#include <list>

using namespace std;

//p235

bool Predicate(int first, int second)
{
	return second - first <= 0;
}



int main()
{
	//-------------------------------p220-------------------------------
	//list<int> lt;
	//
	//lt.push_back(10);
	//lt.push_back(20);
	//lt.push_back(30);
	//lt.push_back(40);
	//lt.push_back(50);

	//list<int>::iterator iter;
	//for (iter = lt.begin(); iter != lt.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//lt.push_front(100);
	//lt.push_front(200);

	//for (iter = lt.begin(); iter != lt.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//-----------------------------p226---------------------------------

	//list<int> lt;

	//lt.push_back(10);
	//lt.push_back(20);
	//lt.push_back(30);
	//lt.push_back(40);
	//lt.push_back(50);
	//lt.push_back(10);
	//lt.push_back(10);

	//list<int>::iterator iter;
	//for (iter = lt.begin(); iter != lt.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//lt.remove(10);


	//for (iter = lt.begin(); iter != lt.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//-----------------------------p228---------------------------------

	//list<int> lt;
	//list<int> lt2;

	//lt.push_back(10);
	//lt.push_back(20);
	//lt.push_back(30);
	//lt.push_back(40);
	//lt.push_back(50);

	//lt2.push_back(100);
	//lt2.push_back(200);
	//lt2.push_back(300);
	//lt2.push_back(400);
	//lt2.push_back(500);

	//list<int>::iterator iter;
	//cout << "lt : ";

	//for (iter = lt.begin(); iter != lt.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;
	//cout << "lt2 : ";

	//for (iter = lt2.begin(); iter != lt2.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout <<endl<<"=========================="<< endl;

	//iter = lt.begin();
	//++iter;
	//++iter;

	//lt.splice(iter, lt2);

	//cout << "lt : ";
	//for (iter = lt.begin(); iter != lt.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;
	//cout << "lt2 : ";

	//for (iter = lt2.begin(); iter != lt2.end(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	//-----------------------------p235---------------------------------

	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);

	list<int>::iterator iter;

	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	lt.unique(Predicate);

	for (iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}