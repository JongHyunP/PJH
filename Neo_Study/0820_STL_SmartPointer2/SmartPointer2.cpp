#include <iostream>
#include <vector>
#include <memory>
#include "TestClass.h"

using namespace std;




int main()
{
//	shared_ptr<TestClass> sptr1(new TestClass());
	shared_ptr<TestClass> sptr2 = make_shared<TestClass>(); //문제점 : 상호참조 해제가안됨. // 순환참조가 일어날때
	
	
	weak_ptr<TestClass> wptr1 = sptr2;
	 // TestClass* ptest = sptr2.get(); weak 와 같음 생으로 포인터갖고오기

	cout << sptr2.use_count() << endl; // 레퍼런스 카운트


	vector<shared_ptr<TestClass>> vec;//배열로 쓰는방법, 많이 연습해보자.
	vec.push_back(make_shared<TestClass>());

	shared_ptr<TestClass> sptr1(new TestClass[10],default_delete<TestClass>()); // 10은 상수로 바꿔야함.

	//sptr1->n = 10;


	auto_ptr<TestClass>(); //옛날 코드

	unique_ptr<TestClass> uptr(new TestClass()); // 복사가 일어나면 안되는 애, 소유권이란 개념이있음, 복사하고싶으면 명시적으로 , 하나의 객체를 관리하고싶을 때
	unique_ptr<TestClass> uptr2 = move(uptr); //소유권이전


	return 0;
}