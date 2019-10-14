#include "CTexture.h"
#include "../Core/PathManager.h"
CTexture::CTexture() : m_hMemDC(NULL), m_bColorKeyEnable(false),m_ColorKey(RGB(255,0,255))
{

}

CTexture::~CTexture()
{
	//������ �����Ǿ��ִ� ������ �ٽ� ����
	SelectObject(m_hMemDC, m_hOldBitmap);
	//bitmap�� ������
	DeleteObject(m_hBitmap);
	//dc �����ֱ�
	DeleteDC(m_hMemDC);
}

void CTexture::SetColorKey(unsigned char r, unsigned char g, unsigned char b)
{
	m_ColorKey = RGB(r, g, b);
	m_bColorKeyEnable = true;
}

void CTexture::SetColorKey(COLORREF colorKey)
{
	m_ColorKey = colorKey;
	m_bColorKeyEnable = true;
}

bool CTexture::LoadTexture(HINSTANCE hInst,HDC hdc, const string& strKey, const wchar_t* pFileName, const string& strPathKey)
{
	//�޸� DC
	m_hMemDC = CreateCompatibleDC(hdc);

	//��ü��� �����
	const wchar_t* pPath = GET_SINGLE(PathManager)->FindPath(strPathKey);

	wstring strPath;

	if (pPath) // ��������.. null�̸� ũ������
	{
		strPath = pPath;
	}
	
	strPath += pFileName;

	
	m_hBitmap = (HBITMAP)LoadImage(hInst, strPath.c_str(), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE); //LR_LOADFROMFILE ���Ϸκ��� �о��

	//������ ���� ��Ʈ�ʵ����� dc�� ����
	//������ �� ���ѵǴ� ���� dc�� �⺻���� �����Ǿ��ִ� ������ ��ȯ��.

	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap); //���� ���� ����

	// �ε� �Ҷ����� �ڵ鿡 �ִ� ������ ����, ���μ��� ũ�� �� 
	GetObject(m_hBitmap, sizeof(m_tInfo), &m_tInfo); 

	return true;
}