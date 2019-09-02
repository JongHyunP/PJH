#include "Mine.h"
#include "BitMap.h"

Mine::Mine()
{
	m_bOpen = false;
}


Mine::~Mine()
{
}

void Mine::Init(BitMap * pFront, BitMap * pBack, int x, int y, int id)
{
	m_pFrontSquare = pFront;
	m_pBackSquare = pBack;
	m_MineX = x;
	m_MineY = y;
	m_MineID = id;
}

void Mine::Draw(HDC hdc)
{
	if (m_bOpen)
	{
		m_pFrontSquare->Draw(hdc, m_MineX, m_MineY);
	}
	else
	{
		m_pBackSquare->Draw(hdc, m_MineX, m_MineY);
	}
}

bool Mine::Input(POINT pt)
{
	if(m_bOpen)
		return false;
	RECT rc = { m_MineX, m_MineY,m_MineX + SQUARE_LENGTH ,m_MineY + SQUARE_LENGTH };


	if (PtInRect(&rc, pt)
	{
		m_bOpen = true;
			return true;
	}
	return false;
}
