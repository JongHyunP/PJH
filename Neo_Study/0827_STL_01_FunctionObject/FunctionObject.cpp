#include <iostream>
#include <vector>
#include <list>
#include <iterator>

//어댑터쪽임

using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);

	cout << "[v.비긴(), v.엔드()) 의 원소 개수 : " << distance(v.begin(), v.end()) << endl;

	cout << "[lt.비긴(), lt.엔드()) 의 원소 개수 : " << distance(lt.begin(), lt.end()) << endl;

	return 0;
}
