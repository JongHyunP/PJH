#include <iostream>
#include <vector>
#include <memory>
#include "TestClass.h"

using namespace std;




int main()
{
//	shared_ptr<TestClass> sptr1(new TestClass());
	shared_ptr<TestClass> sptr2 = make_shared<TestClass>(); //������ : ��ȣ���� �������ȵ�. // ��ȯ������ �Ͼ��
	
	
	weak_ptr<TestClass> wptr1 = sptr2;
	 // TestClass* ptest = sptr2.get(); weak �� ���� ������ �����Ͱ������

	cout << sptr2.use_count() << endl; // ���۷��� ī��Ʈ


	vector<shared_ptr<TestClass>> vec;//�迭�� ���¹��, ���� �����غ���.
	vec.push_back(make_shared<TestClass>());

	shared_ptr<TestClass> sptr1(new TestClass[10],default_delete<TestClass>()); // 10�� ����� �ٲ����.

	//sptr1->n = 10;


	auto_ptr<TestClass>(); //���� �ڵ�

	unique_ptr<TestClass> uptr(new TestClass()); // ���簡 �Ͼ�� �ȵǴ� ��, �������̶� ����������, �����ϰ������ ��������� , �ϳ��� ��ü�� �����ϰ���� ��
	unique_ptr<TestClass> uptr2 = move(uptr); //����������


	return 0;
}