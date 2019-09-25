#include "ChessPieceManager.h"
#include "ChessBishop.h"
#include "ChessKing.h"
#include "ChessKnight.h"
#include "ChessPawn.h"
#include "ChessQueen.h"
#include "ChessRook.h"
#include "ResManager.h"

DEFINITION_SINGLE(ChessPieceManager);

ChessPieceManager::ChessPieceManager()
{

}

ChessPieceManager::~ChessPieceManager()
{

}

//실제로 객체에 대한 생성을 해줘야함.

bool ChessPieceManager::Init(HDC hdc)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_ChessArray[j][i] = NULL;
		}
	}

	//말 생성 - 블랙
	ChessPiece* pKingB = CreatePiece("KingB", CT_KING, PIECE_COLOR_BLACK,400,0);
	m_ChessArray[4][0] = pKingB;
	ChessPiece* pQueenB = CreatePiece("QueenB", CT_QUEEN, PIECE_COLOR_BLACK,300,0);
	m_ChessArray[3][0] = pQueenB;
	ChessPiece* pBishopB = CreatePiece("BishopB0", CT_BISHOP, PIECE_COLOR_BLACK,200,0);
	m_ChessArray[2][0] = pBishopB;
	ChessPiece* pBishopB2 = CreatePiece("BishopB1", CT_BISHOP, PIECE_COLOR_BLACK, 500, 0);
	m_ChessArray[5][0] = pBishopB2;
	ChessPiece* pKnightB = CreatePiece("KnightB0", CT_KNIGHT, PIECE_COLOR_BLACK,100,0);
	m_ChessArray[1][0] = pKnightB;
	ChessPiece* pKnightB2 = CreatePiece("KnightB1", CT_KNIGHT, PIECE_COLOR_BLACK, 600, 0);
	m_ChessArray[6][0] = pKnightB2;
	ChessPiece* pRookB = CreatePiece("RookB0", CT_ROOK, PIECE_COLOR_BLACK,0,0);
	m_ChessArray[0][0] = pRookB;
	ChessPiece* pRookB2 = CreatePiece("RookB1", CT_ROOK, PIECE_COLOR_BLACK, 700, 0);
	m_ChessArray[7][0] = pRookB2;

	for (int i = 0; i < 8; i++)
	{
		stringstream intTostring; // int 형변환용
		intTostring << i;
		ChessPiece* pPawnB = CreatePiece(("PawnB"+ intTostring.str()), CT_PAWN, PIECE_COLOR_BLACK, i * 100,100);
		m_ChessArray[i][1] = pPawnB;
	}
	
	//말 생성 - 화이트
	ChessPiece* pKingW = CreatePiece("KingW", CT_KING, PIECE_COLOR_WHITE,400,700);
	m_ChessArray[4][7] = pKingW;
	ChessPiece* pQueenW = CreatePiece("QueenW", CT_QUEEN, PIECE_COLOR_WHITE,300,700);
	m_ChessArray[3][7] = pQueenW;
	ChessPiece* pBishopW = CreatePiece("BishopW0", CT_BISHOP, PIECE_COLOR_WHITE,200,700);
	m_ChessArray[2][7] = pBishopW;
	ChessPiece* pBishopW2 = CreatePiece("BishopW1", CT_BISHOP, PIECE_COLOR_WHITE, 500, 700);
	m_ChessArray[5][7] = pBishopW2;
	ChessPiece* pKnightW = CreatePiece("KnightW0", CT_KNIGHT, PIECE_COLOR_WHITE,100,700);
	m_ChessArray[1][7] = pKnightW;
	ChessPiece* pKnightW2 = CreatePiece("KnightW1", CT_KNIGHT, PIECE_COLOR_WHITE, 600, 700);
	m_ChessArray[6][7] = pKnightW2;
	ChessPiece* pRookW = CreatePiece("RookW0", CT_ROOK, PIECE_COLOR_WHITE,0,700);
	m_ChessArray[0][7] = pRookW;
	ChessPiece* pRookW2 = CreatePiece("RookW1", CT_ROOK, PIECE_COLOR_WHITE, 700, 700);
	m_ChessArray[7][7] = pRookW2;

	for (int i = 0; i < 8; i++)
	{
		stringstream intTostring; // int 형변환용
		intTostring << i;
		ChessPiece* pPawnW = CreatePiece(("PawnW"+ intTostring.str()), CT_PAWN, PIECE_COLOR_WHITE, i * 100, 600);
		m_ChessArray[i][6] = pPawnW;
	}

	//테스트용
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_ChessArray[j][i] == NULL) 
			{
				cout << "0 ";
			}
			else
			{
				cout << "1 ";
			}
		}
		cout << endl;
	}



	return true;
}

ChessPiece * ChessPieceManager::CreatePiece(const string& strkey, CHESSPIECE_TYPE ePieceType, PIECE_COLOR_TYPE eColorType,int x,int y)
{
	ChessPiece* pPiece = nullptr;

	switch (ePieceType)
	{
	case CT_KING:
		pPiece = new ChessKing;
		if (eColorType == PIECE_COLOR_BLACK)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_05.bmp"),x ,y ))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_05.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		break;
	case CT_QUEEN:
		pPiece = new ChessQueen;
		if (eColorType == PIECE_COLOR_BLACK)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_04.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_04.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		break;
	case CT_BISHOP:
		pPiece = new ChessBishop;
		if (eColorType == PIECE_COLOR_BLACK)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_02.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_02.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		break;
	case CT_KNIGHT:
		pPiece = new ChessKnight;
		if (eColorType == PIECE_COLOR_BLACK)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_01.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_01.bmp"), x, y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		break;
	case CT_ROOK:
		pPiece = new ChessRook;
		if (eColorType == PIECE_COLOR_BLACK)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_03.bmp"),x,y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_03.bmp"),x,y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		break;
	case CT_PAWN:
		pPiece = new ChessPawn;
		if (eColorType == PIECE_COLOR_BLACK)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_00.bmp"), x,y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_00.bmp"), x,y))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		break;
	}

	m_mapPiece.insert(make_pair(strkey, pPiece));

	return pPiece;
}

ChessPiece * ChessPieceManager::FindPiece(const string & strkey)
{
	unordered_map<string, ChessPiece*>::iterator iter = m_mapPiece.find(strkey);

	if (iter == m_mapPiece.end())
		return NULL;

	return iter->second;
}


void ChessPieceManager::Draw(HDC hdc)
{
	for (auto iter = m_mapPiece.begin(); iter != m_mapPiece.end(); ++iter)
	{
		iter->second->Draw(hdc);
	}
}
