#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

// [캡쳐](파라메터)-> 리턴타입 {함수}

bool Less(int &l, int &r)
{
	return l < r;
}

int main()
{
	//벡터와 덱의 인터페이스가 비슷함.

	//vector<int> v;

	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);

	//vector<int>::iterator iter; // 포인터라고 생각하면됨.

	//for (iter = v.begin(); iter != v.end(); ++iter)
	//{
	//	cout << *iter << endl; //그래서 *을 붙여서 값을 출력(역참조)
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
	//if (iter == v.end()) //끝까지갔는지.strstr처럼.
	//{
	//	cout << "100이 없음!" << endl;
	//}
	//----------------------------------------------------------------------------
	vector<int> v;
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);

	sort(v.begin(), v.end(), less<int>()); //스트링은 가나다 순정렬됨 sort(,,세번째 인자 -> 함수포인터 = Pr_Pred)
	sort(v.begin(), v.end(), Less);
	sort(v.begin(), v.end(), [](int &l, int & r)->bool {return l < r; }); // 람다식, 함수객체를 바로 생성하는것.// [] 캡쳐는 필요한것을 가져다 쓰는거라고생각하면됨. 
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
	// 스택 컨테이너
	//stack<int> st;

	//st.push(10);
	//st.push(20);
	//st.push(30);

	//cout << st.top() << endl; //제일 위에있는애를 가져옴
	//st.pop(); // 맨위에 애를 날림
	//cout << st.top() << endl;
	//st.pop();
	//cout << st.top() << endl;
	//st.pop();
	//if (st.empty())
	//	cout << "스택이 빔" << endl;

	//----------------------------------------------------------------------------

	//vector<int> v;
	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);
	//v.push_back(40);
	//v.push_back(50);

	//for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
 //   {
	//   cout << *iter << endl; //그래서 *을 붙여서 값을 출력(역참조)
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