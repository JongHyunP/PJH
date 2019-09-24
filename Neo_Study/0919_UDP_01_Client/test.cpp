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
		cout << "BaseTest LValue ���۷��� ������  int ���Ҵ�" << endl;
	}
	BaseTest(BaseTest&& otherTest) : data(otherTest.data)
	{
		otherTest.data = nullptr;

		if (nullptr == data)
		{
			data = new int(0);
		}
		cout << "BaseTest RValue ���۷��� ������ ����� int�� ���� ����" << endl;
	}
	BaseTest() : data(new int(0))
	{
		cout << "BaseTest ���� int ���Ҵ�" << endl;
	}
	~BaseTest()
	{
		if (nullptr != data)
		{
			delete data;
			data = nullptr;
		}
		cout << "BaseTest �Ҹ�" << endl;
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