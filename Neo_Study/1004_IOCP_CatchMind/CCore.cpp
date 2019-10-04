#include "CCore.h"
#include "CResManager.h"


DEFINITION_SINGLE(CCore)

CCore::CCore()
{
}


CCore::~CCore()
{
	DESTROY_SINGLE(CResManager);
}

bool CCore::Init(HWND hWnd, HDC hdc)
{
	//���ҽ� ������ �ʱ�ȭ
	if (!GET_SINGLE(CResManager)->Init(hdc))
	{
		return false;
	}
}

void CCore::Draw(HDC hdc)
{
	//����ۿ� ��� ���ְ�.

	//������ ���
	GET_SINGLE(CResManager)->DrawScene(hdc);
}

void CCore::Update()
{
}

void CCore::Input(POINT pt)
{
}
