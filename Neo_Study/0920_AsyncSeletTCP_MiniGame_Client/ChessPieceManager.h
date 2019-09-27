#pragma once
#include "value.h"

enum GAME_STATE
{
	GAME_STATE_WAIT,
	GAME_STATE_ONE_SELECT,
	GAME_STATE_MOVE
};

class ChessPiece;
class BoardTile;

class ChessPieceManager
{
	DECLARE_SINGLE(ChessPieceManager)

private:
	unordered_map<string, ChessPiece*>	m_mapPiece;
	ChessPiece*							m_ChessArray[8][8];
	ChessPiece*							m_SelectPiece;
	BoardTile*							m_pBoard[8][8];
	vector<BoardTile*>					m_vecBoardTile;

	GAME_STATE							m_eState;
	HWND								m_hWnd;
public:
	bool Init(HWND hWnd, HDC hdc);
	void Draw(HDC hdc);
	void Input(POINT pt);
	void PieceMovableArea(ChessPiece* pPiece);
	void ChessBoardInit();
	void BoardReturn();
	void ArrayPaint(int addNum,bool isPaint,int x, int y, int arrX[], int arrY[], ChessPiece* pPiece);

	ChessPiece* CreatePiece(const string& strkey, CHESSPIECE_TYPE ePieceType, PIECE_COLOR_TYPE eColorType, int x, int y);
	ChessPiece* FindPiece(const string& strkey);
	
};

