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
	//리소스 관리자 초기화
	if (!GET_SINGLE(CResManager)->Init(hdc))
	{
		return false;
	}
}

void CCore::Draw(HDC hdc)
{
	//백버퍼에 출력 해주고.

	//마지막 출력
	GET_SINGLE(CResManager)->DrawScene(hdc);
}

void CCore::Update()
{
}

void CCore::Input(POINT pt)
{
}
