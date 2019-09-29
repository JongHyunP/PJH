#include "ChessPieceManager.h"
#include "ChessBishop.h"
#include "ChessKing.h"
#include "ChessKnight.h"
#include "ChessPawn.h"
#include "ChessQueen.h"
#include "ChessRook.h"
#include "ResManager.h"
#include "BoardTile.h"

DEFINITION_SINGLE(ChessPieceManager);

ChessPieceManager::ChessPieceManager()
{

}

ChessPieceManager::~ChessPieceManager()
{

}

//실제로 객체에 대한 생성을 해줘야함.

bool ChessPieceManager::Init(HWND hWnd, HDC hdc)
{
	m_eState = GAME_STATE_WAIT;
	m_hWnd = hWnd;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_ChessArray[j][i] = NULL;
		}
	}

	//보드판 초기화
	ChessBoardInit();

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
	m_ChessArray[0][7] = pRookB2;

	for (int i = 0; i < 8; i++)
	{
		stringstream intTostring; // int 형변환용
		intTostring << i;
		ChessPiece* pPawnB = CreatePiece(("PawnB"+ intTostring.str()), CT_PAWN, PIECE_COLOR_BLACK, i * 100,100);
		m_ChessArray[i][1] = pPawnB;
	}
	
	//말 생성 - 화이트
	//ChessPiece* pKingW = CreatePiece("KingW", CT_KING, PIECE_COLOR_WHITE,400,700);
	//m_ChessArray[7][4] = pKingW;
	//ChessPiece* pQueenW = CreatePiece("QueenW", CT_QUEEN, PIECE_COLOR_WHITE,300,700);
	//m_ChessArray[3][7] = pQueenW;
	//ChessPiece* pBishopW = CreatePiece("BishopW0", CT_BISHOP, PIECE_COLOR_WHITE,200,700);
	//m_ChessArray[2][7] = pBishopW;
	//ChessPiece* pBishopW2 = CreatePiece("BishopW1", CT_BISHOP, PIECE_COLOR_WHITE, 500, 700);
	//m_ChessArray[5][7] = pBishopW2;
	//ChessPiece* pKnightW = CreatePiece("KnightW0", CT_KNIGHT, PIECE_COLOR_WHITE,100,700);
	//m_ChessArray[1][7] = pKnightW;
	//ChessPiece* pKnightW2 = CreatePiece("KnightW1", CT_KNIGHT, PIECE_COLOR_WHITE, 600, 700);
	//m_ChessArray[6][7] = pKnightW2;
	ChessPiece* pRookW = CreatePiece("RookW0", CT_ROOK, PIECE_COLOR_WHITE,0,700);
	m_ChessArray[7][0] = pRookW;
	//ChessPiece* pRookW2 = CreatePiece("RookW1", CT_ROOK, PIECE_COLOR_WHITE, 700, 700);
	//m_ChessArray[7][7] = pRookW2;

	//for (int i = 0; i < 8; i++)
	//{
	//	stringstream intTostring; // int 형변환용
	//	intTostring << i;
	//	ChessPiece* pPawnW = CreatePiece(("PawnW"+ intTostring.str()), CT_PAWN, PIECE_COLOR_WHITE, i * 100, 600);
	//	m_ChessArray[i][6] = pPawnW;
	//}

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
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_05.bmp"),x ,y , PIECE_COLOR_BLACK))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_05.bmp"), x, y, PIECE_COLOR_WHITE))
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
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_04.bmp"), x, y, PIECE_COLOR_BLACK))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_04.bmp"), x, y, PIECE_COLOR_WHITE))
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
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_02.bmp"), x, y, PIECE_COLOR_BLACK))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_02.bmp"), x, y, PIECE_COLOR_WHITE))
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
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_01.bmp"), x, y, PIECE_COLOR_BLACK))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_01.bmp"), x, y, PIECE_COLOR_WHITE))
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
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_03.bmp"),x,y, PIECE_COLOR_BLACK))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_03.bmp"),x,y, PIECE_COLOR_WHITE))
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
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_b_00.bmp"), x,y, PIECE_COLOR_BLACK))
			{
				SAFE_DELETE(pPiece);
				return NULL;
			}
		}
		else if (eColorType == PIECE_COLOR_WHITE)
		{
			if (!pPiece->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block_w_00.bmp"), x,y, PIECE_COLOR_WHITE))
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
	for (auto iter = m_vecBoardTile.begin(); iter != m_vecBoardTile.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}

	for (auto iter = m_mapPiece.begin(); iter != m_mapPiece.end(); ++iter)
	{
		iter->second->Draw(hdc);
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
}

void ChessPieceManager::Input(POINT pt)
{
	for (auto iter = m_mapPiece.begin(); iter != m_mapPiece.end(); ++iter)
	{
		if (iter->second->Input(pt))
		{
			if (m_eState == GAME_STATE_WAIT)
			{
				m_SelectPiece = iter->second;
				//이동 가능 영역 표시 함수 호출
				PieceMovableArea(m_SelectPiece);
				m_eState = GAME_STATE_ONE_SELECT;
				cout << "선택단계" << endl;
			}
			else if (m_eState == GAME_STATE_ONE_SELECT)
			{
				if (iter->second == m_SelectPiece) //첨에 눌른애가 맞으면
				{
					//이동 관려함수 자리
					m_eState = GAME_STATE_MOVE;//에어리어 선택 안으로 들어가야함.
				}
				else //다른 앨 클릭하면
				{
					cout << "다른애 선택으로 초기화" << endl;
					m_SelectPiece = nullptr;
					//영역 타일 재복원 함수
					BoardReturn();
					m_eState = GAME_STATE_WAIT;
				}
			}
			else if (m_eState == GAME_STATE_MOVE)
			{
				cout << "움직인 단계" << endl;
			}
			InvalidateRect(m_hWnd, NULL, false);
		}
	}
}
void ChessPieceManager::ChessBoardInit()
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			m_pBoard[j][i] = new BoardTile();

			if (i % 2 == 0 && j % 2 == 0)
			{
				m_pBoard[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block01.bmp"), x, y);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
			else if (i % 2 == 1 && j % 2 == 1)
			{
				m_pBoard[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block01.bmp"), x, y);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
			else
			{
				m_pBoard[j][i]->Init(GET_SINGLE(ResManager)->GetBitMap("RES\\block00.bmp"), x, y);
				x += 100;
				m_vecBoardTile.push_back(m_pBoard[j][i]);
			}
		}
		x = 0;
		y += 100;
	}
}

void ChessPieceManager::PieceMovableArea(ChessPiece * pPiece)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_ChessArray[j][i] == pPiece)
			{
				if (pPiece->GetPieceInfo().eChessType == CT_KING)
				{
					int posX = pPiece->GetPieceInfo().iPosX / 100;
					int posY = pPiece->GetPieceInfo().iPosY / 100;
					cout<<posX <<"," <<posY<<endl;
					//비교 대상
					int directionX[] = { 0,0,-1,1,-1,1,1,-1 };
					int directionY[] = { -1,1,0,0 ,-1,-1,1,1 };

					for (int j = 0; j < 8; j++) {
						if (posX + directionX[j] < 8 && posY + directionY[j] < 8 && posX + directionX[j] >= 0 && posY + directionY[j] >= 0)
						{
							ArrayPaint(j, true, posX, posY, directionX, directionY, pPiece);
						}
					}
				}
				else if (pPiece->GetPieceInfo().eChessType == CT_QUEEN)
				{
					int posX = pPiece->GetPieceInfo().iPosX;
					int posY = pPiece->GetPieceInfo().iPosY;

					int downAndRightDirectionX[] = { 1,2,3,4,5,6,7 };
					int downAndRightDirectionY[] = { 1,2,3,4,5,6,7 };
					bool isDownAndRight = true;

					int downAndLeftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
					int downAndLeftDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };
					bool isDownAndLeft = true;

					int upAndRightDirectionX[] = { 1,2,3,4,5,6,7 };
					int upAndRightDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };
					bool isUpAndRight = true;

					int upAndLeftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
					int upAndLeftDirectionY[] = { 1,2,3,4,5,6,7 };
					bool isUpAndLeft = true;

					int upDirectionX[] = { 0,0,0,0,0,0,0 };
					int upDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };
					bool isUP = true;

					int downDirectionX[] = { 0,0,0,0,0,0,0 };
					int downDirectionY[] = { 1,2,3,4,5,6,7 };
					bool isDown = true;

					int rightDirectionX[] = { 1,2,3,4,5,6,7 };
					int rightDirectionY[] = { 0,0,0,0,0,0,0 };
					bool isRight = true;

					int leftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
					int leftDirectionY[] = { 0,0,0,0,0,0,0 };
					bool isLeft = true;

					//대각선
					for (int j = 0; j < 7; j++) {
						if (posX + downAndRightDirectionX[j] < 8 && posY + downAndRightDirectionY[j] < 8)
						{
							ArrayPaint(j, isDownAndRight, posX, posY, downAndRightDirectionX, downAndRightDirectionY, pPiece);
						}
						if (posX + upAndRightDirectionX[j] < 8 && posY + upAndRightDirectionY[j] >= 0)
						{
							ArrayPaint(j, isDownAndLeft, posX, posY, upAndRightDirectionX, upAndRightDirectionY, pPiece);
						}
						if (posX + downAndLeftDirectionX[j] >= 0 && posY + downAndLeftDirectionY[j] >= 0)
						{
							ArrayPaint(j, isUpAndRight, posX, posY, downAndLeftDirectionX, downAndLeftDirectionY, pPiece);
						}
						if (posX + upAndLeftDirectionX[j] >= 0 && posY + upAndLeftDirectionY[j] < 8)
						{
							ArrayPaint(j, isUpAndLeft, posX, posY, upAndLeftDirectionX, upAndLeftDirectionY, pPiece);
						}
					}
					//가로, 세로
					for (int j = 0; j < 7; j++) { 
						if (posX + rightDirectionX[j] < 8)
						{
							ArrayPaint(j, isRight, posX, posY, rightDirectionX, rightDirectionY, pPiece);
						}
						if (posY + downDirectionY[j] < 8)
						{
							ArrayPaint(j, isDown, posX, posY, downDirectionX, downDirectionY, pPiece);
						}
						if (posX + leftDirectionX[j] >= 0)
						{
							ArrayPaint(j, isLeft, posX, posY, leftDirectionX, leftDirectionY, pPiece);
						}
						if (posY + upDirectionY[j] >= 0)
						{
							ArrayPaint(j, isUP, posX, posY, upDirectionX, upDirectionY, pPiece);
						}
					}
				}
				else if (pPiece->GetPieceInfo().eChessType == CT_BISHOP)
				{
					int posX = pPiece->GetPieceInfo().iPosX;
					int posY = pPiece->GetPieceInfo().iPosY;

					int downAndRightDirectionX[] = { 1,2,3,4,5,6,7 };
					int downAndRightDirectionY[] = { 1,2,3,4,5,6,7 };
					bool isDownAndRight = true;

					int downAndLeftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
					int downAndLeftDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };
					bool isDownAndLeft = true;

					int upAndRightDirectionX[] = { 1,2,3,4,5,6,7 };
					int upAndRightDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };
					bool isUpAndRight = true;

					int upAndLeftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
					int upAndLeftDirectionY[] = { 1,2,3,4,5,6,7 };
					bool isUpAndLeft = true;

					for (int j = 0; j < 7; j++) {
						if (posX + downAndRightDirectionX[j] < 8 && posY + downAndRightDirectionY[j] < 8)
						{
							ArrayPaint(j, isDownAndRight, posX, posY, downAndRightDirectionX, downAndRightDirectionY, pPiece);
						}
						if (posX + upAndRightDirectionX[j] < 8 && posY + upAndRightDirectionY[j] >= 0)
						{
							ArrayPaint(j, isDownAndLeft, posX, posY, upAndRightDirectionX, upAndRightDirectionY, pPiece);
						}
						if (posX + downAndLeftDirectionX[j] >= 0 && posY + downAndLeftDirectionY[j] >= 0)
						{
							ArrayPaint(j, isUpAndRight, posX, posY, downAndLeftDirectionX, downAndLeftDirectionY, pPiece);
						}
						if (posX + upAndLeftDirectionX[j] >= 0 && posY + upAndLeftDirectionY[j] < 8)
						{
							ArrayPaint(j, isUpAndLeft, posX, posY, upAndLeftDirectionX, upAndLeftDirectionY, pPiece);
						}
					}
				}
				else if (pPiece->GetPieceInfo().eChessType == CT_KNIGHT)
				{
					int posX = pPiece->GetPieceInfo().iPosX;
					int posY = pPiece->GetPieceInfo().iPosY;

					int directionX[] = { -2 ,-1, 1, 2, 2, 1, -1,-2 };
					int directionY[] = { -1 ,-2,-2,-1, 1, 2, 2, 1 };

					for (int j = 0; j < 8; j++) {
						if (posX + directionX[j] < 8 && posY + directionY[j] < 8 && posX + directionX[j] >= 0 && posY + directionY[j] >= 0)
						{
							ArrayPaint(j, true, posX, posY, directionX, directionY, pPiece);
						}
					}
				}
				else if (pPiece->GetPieceInfo().eChessType == CT_ROOK)
				{
					int posX = pPiece->GetPieceInfo().iPosX/100;
					int posY = pPiece->GetPieceInfo().iPosY/100;
					cout << posX << "," << posY << endl;

					int upDirectionX[] = { 0,0,0,0,0,0,0 };
					int upDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };
					bool isUP = true;

					int downDirectionX[] = { 0,0,0,0,0,0,0 };
					int downDirectionY[] = { 1,2,3,4,5,6,7 };
					bool isDown = true;

					int rightDirectionX[] = { 1,2,3,4,5,6,7 };
					int rightDirectionY[] = { 0,0,0,0,0,0,0 };
					bool isRight = true;

					int leftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
					int leftDirectionY[] = { 0,0,0,0,0,0,0 };
					bool isLeft = true;

					for (int j = 0; j < 7; j++) {
						if (posX + rightDirectionX[j] < 8)
						{
							ArrayPaint(j, isRight, posX, posY, rightDirectionX, rightDirectionY, pPiece);
						}
						if (posY + downDirectionY[j] < 8)
						{
							ArrayPaint(j, isDown, posX, posY, downDirectionX, downDirectionY, pPiece);
						}
						if (posX + leftDirectionX[j] >= 0)
						{
							ArrayPaint(j, isLeft, posX, posY, leftDirectionX, leftDirectionY, pPiece);
						}
						if (posY + upDirectionY[j] >= 0)
						{
							ArrayPaint(j, isUP, posX, posY, upDirectionX, upDirectionY, pPiece);
						}
					}
				}
				else if (pPiece->GetPieceInfo().eChessType == CT_PAWN)
				{
					if (pPiece->GetPieceInfo().ePieceColorType == PIECE_COLOR_BLACK) //블랙
					{
						int posX = pPiece->GetPieceInfo().iPosX / 100;
						int posY = pPiece->GetPieceInfo().iPosY / 100;

						cout << posX << "," << posY << endl;
						//적 발견 표기
						int attackDirectionX[] = { -1,1 };
						int attackDirectionY[] = { -1, -1 };

						for (int j = 0; j < 2; j++) {
							if (posX + attackDirectionX[j] < 8 && posY + attackDirectionY[j] < 8 && posX + attackDirectionX[j] >= 0 && posY + attackDirectionY[j] >= 0)
							{
								//정보를 못받아옴
								if (m_ChessArray[posY + attackDirectionY[j]][posX + attackDirectionX[j]]->GetPieceInfo().ePieceColorType == PIECE_COLOR_WHITE)
								{
									m_pBoard[posY + attackDirectionY[j]][posX + attackDirectionX[j]]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block04.bmp"));
								}
							}
						}

						if (posY == 1) //처음 움직이는경우.
						{
							
							int directionX[] = { 0,0 };
							int directionY[] = { 1,2 };

					     	//앞에 누가있는지 확인
							if (posY + directionY[j] < 8)
							{
								if (m_ChessArray[posY + directionY[0]][posX + directionX[0]] == NULL)
								{
									m_pBoard[posY + directionY[0]][posX + directionX[0]]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block03.bmp"));

									if (m_ChessArray[posY + directionY[1]][posX + directionX[1]] == NULL)
									{
										m_pBoard[posY + directionY[1]][posX + directionX[1]]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block03.bmp"));
									}
								}
							}
						}
						else //처음 움직이는게 아닌경우
						{
							if (posY + 1 < 8)
							{
								if (m_ChessArray[posY + 1][posX] == NULL) // 바로 앞에 한칸만 검사.
								{
									m_pBoard[posY + 1][posX]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block03.bmp"));
								}
							}
						}

					}
					else if((pPiece->GetPieceInfo().ePieceColorType == PIECE_COLOR_WHITE)) // 화이트
					{
						
					}
				}
		
				
			}
		}
	}
}

void ChessPieceManager::ArrayPaint(int addNum, bool isPaint, int x,int y,int arrX[],int arrY[],ChessPiece* pPiece)
{
	if (isPaint)
	{
		if (m_ChessArray[x + arrX[addNum]][y + arrY[addNum]] == NULL) // 빈칸 이면
		{
			m_pBoard[x + arrX[addNum]][y + arrY[addNum]]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block03.bmp"));
		}
		else //뭔가 있음.
		{
			if (pPiece->GetPieceInfo().ePieceColorType == PIECE_COLOR_BLACK) //블랙 팀이였을경우
			{
				if (m_ChessArray[x + arrX[addNum]][y + arrY[addNum]]->GetPieceInfo().ePieceColorType == PIECE_COLOR_WHITE) //적팀
				{
					m_pBoard[x + arrX[addNum]][y + arrY[addNum]]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block04.bmp"));
					isPaint = false;
				}
				else  //아군
				{
					isPaint = false;
				}
			}
			else if (pPiece->GetPieceInfo().ePieceColorType == PIECE_COLOR_WHITE)
			{
				if (m_ChessArray[x + arrX[addNum]][y + arrY[addNum]]->GetPieceInfo().ePieceColorType == PIECE_COLOR_BLACK)
				{
					m_pBoard[x + arrX[addNum]][y + arrY[addNum]]->ChangeBitMap(GET_SINGLE(ResManager)->GetBitMap("RES\\block04.bmp"));
					isPaint = false;
				}
				else // 아군
				{
					isPaint = false;
				}
			}
		}
			//적이 없는데 자리가 없다. -> 출력없음
		
	}
	
}
void ChessPieceManager::BoardReturn()
{
	//나중에 스택형식으로 쌓아둬서 팝 ->타일 복원 으로 바꾸기
	ChessBoardInit();
}

