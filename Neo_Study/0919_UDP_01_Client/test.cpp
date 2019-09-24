#include <iostream>
#include <crtdbg.h>

using namespace std;

class BaseTest
{
private:
	int* data;
public:
	void SetData(int value)
	{
		if (nullptr != data)
		{
			*data = value;
		}
	}
public:
	BaseTest(const BaseTest& otherTest) : data(new int(0))
	{
		if (nullptr != otherTest.data)
		{
			*data = *otherTest.data;
		}
		cout << "BaseTest LValue 레퍼런스 생성자  int 재할당" << endl;
	}
	BaseTest(BaseTest&& otherTest) : data(otherTest.data)
	{
		otherTest.data = nullptr;

		if (nullptr == data)
		{
			data = new int(0);
		}
		cout << "BaseTest RValue 레퍼런스 생성자 상대의 int를 얕은 복사" << endl;
	}
	BaseTest() : data(new int(0))
	{
		cout << "BaseTest 생성 int 재할당" << endl;
	}
	~BaseTest()
	{
		if (nullptr != data)
		{
			delete data;
			data = nullptr;
		}
		cout << "BaseTest 소멸" << endl;
	}
};

BaseTest TestCreateFunc()
{
	BaseTest New = BaseTest();
	New.SetData(1000);
	return New;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	BaseTest OtherTest = BaseTest();
	BaseTest Type1 = OtherTest;
	BaseTest Type2 = TestCreateFunc();

	return 0;
}