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

bool ChessPieceManager::Init()
{

	//말 생성 -블랙
	ChessPiece* pKing = CreatePiece("KingB", CT_KING);
	ChessPiece* pQueen = CreatePiece("QueenB", CT_QUEEN);
	ChessPiece* pBishop = CreatePiece("BishopB", CT_BISHOP);
	ChessPiece* pKnight = CreatePiece("KnightB", CT_KNIGHT);
	ChessPiece* pRook = CreatePiece("RookB", CT_ROOK);
	ChessPiece* pPawn = CreatePiece("PawnB", CT_PAWN);
	
	return true;
}

ChessPiece * ChessPieceManager::CreatePiece(const string& strkey, CHESSPIECE_TYPE eType)
{
	ChessPiece* pPiece = nullptr;

	switch (eType)
	{
	case CT_KING:
		pPiece = new ChessKing;
		break;
	case CT_QUEEN:
		pPiece = new ChessQueen;
		break;
	case CT_BISHOP:
		pPiece = new ChessBishop;
		break;
	case CT_KNIGHT:
		pPiece = new ChessKnight;
		break;
	case CT_ROOK:
		pPiece = new ChessRook;
		break;
	case CT_PAWN:
		pPiece = new ChessPawn;
		break;
	default:
		break;
	}

	if (!pPiece->Init())
	{
		SAFE_DELETE(pPiece);
		return NULL;
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
