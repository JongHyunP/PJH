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
	//말 생성 - 블랙
	ChessPiece* pKingB = CreatePiece("KingB", CT_KING, PIECE_COLOR_BLACK,400,0);
	ChessPiece* pQueenB = CreatePiece("QueenB", CT_QUEEN, PIECE_COLOR_BLACK,300,0);
	ChessPiece* pBishopB = CreatePiece("BishopB", CT_BISHOP, PIECE_COLOR_BLACK,200,0);
	ChessPiece* pKnightB = CreatePiece("KnightB", CT_KNIGHT, PIECE_COLOR_BLACK,100,0);
	ChessPiece* pKnightB2 = CreatePiece("KnightB2", CT_KNIGHT, PIECE_COLOR_BLACK, 600, 0);
	ChessPiece* pRookB = CreatePiece("RookB", CT_ROOK, PIECE_COLOR_BLACK,0,0);
	ChessPiece* pRookB2 = CreatePiece("RookB2", CT_ROOK, PIECE_COLOR_BLACK, 700, 0);

	//짱난다 걍 노가다 ㄱ
	for (int i = 0; i < 8; i++)
	{
		ChessPiece* pPawnB = CreatePiece(("PawnB"+i), CT_PAWN, PIECE_COLOR_BLACK, i * 100,100);
	}
	
	//말 생성 - 화이트
	ChessPiece* pKingW = CreatePiece("KingW", CT_KING, PIECE_COLOR_WHITE,400,700);
	ChessPiece* pQueenW = CreatePiece("QueenW", CT_QUEEN, PIECE_COLOR_WHITE,300,700);
	ChessPiece* pBishopW = CreatePiece("BishopW", CT_BISHOP, PIECE_COLOR_WHITE,200,700);
	ChessPiece* pKnightW = CreatePiece("KnightW", CT_KNIGHT, PIECE_COLOR_WHITE,100,700);
	ChessPiece* pRookW = CreatePiece("RookW", CT_ROOK, PIECE_COLOR_WHITE,0,700);

	for (int i = 0; i < 8; i++)
	{
		ChessPiece* pPawnW = CreatePiece(("PawnW"+i), CT_PAWN, PIECE_COLOR_WHITE, i * 100, 600);
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
