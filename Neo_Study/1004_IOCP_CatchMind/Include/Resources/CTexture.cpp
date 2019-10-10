#include "CTexture.h"
#include "../Core/PathManager.h"
CTexture::CTexture() : m_hMemDC(NULL)
{

}

CTexture::~CTexture()
{
	//기존에 지정되어있던 도구를 다시 지정
	SelectObject(m_hMemDC, m_hOldBitmap);
	//bitmap을 지워줌
	DeleteObject(m_hBitmap);
	//dc 지워주기
	DeleteDC(m_hMemDC);
}

bool CTexture::LoadTexture(HINSTANCE hInst,HDC hdc, const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	//메모리 DC
	m_hMemDC = CreateCompatibleDC(hdc);

	//전체경로 만들기
	const wchar_t* pPath = GET_SINGLE(PathManager)->FindPath(strPathKey);

	wstring strPath;

	if (pPath) // 있을때만.. null이면 크래쉬남
	{
		strPath = pPath;
	}
	
	strPath += pFileName;

	
	m_hBitmap = (HBITMAP)LoadImage(hInst, strPath.c_str(), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE); //LR_LOADFROMFILE 파일로부터 읽어옴

	//위에서 만든 비트맵도구를 dc에 지정
	//지정할 때 반한되는 값은 dc에 기본으로 지정되어있던 도구가 반환됨.

	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap); //기존 도구 저장

	// 로드 할때마다 핸들에 있는 정보를 얻어옴, 가로세로 크기 등 
	GetObject(m_hBitmap, sizeof(m_tInfo), &m_tInfo); 

	return true;
}
