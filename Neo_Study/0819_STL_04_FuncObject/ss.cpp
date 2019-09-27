#include <iostream>

using namespace std;

int main()
{
	int array[8][8] = {
						{1,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,1},
						{0,0,0,1,0,1,0,0},
						{0,0,1,0,0,0,1,0},
						{0,0,0,0,5,0,1,0},
						{0,0,1,0,1,0,1,0},
						{0,0,0,1,1,1,1,0},
						{0,1,0,0,0,0,0,0},
	};

	int x = 4, y = 4; //5번 고정
	int count1 = 0;

	//킹ver
	//int dx[] = { 0,0,-1,1,-1,1,1,-1};
	//int dy[] = {-1,1,0,0 ,-1,-1,1,1};
	//for (int j = 0; j < 8; j++) {
	//	if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j] >= 0)
	//	{
	//		if (array[y + dy[j]][x + dx[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}

	//룩ver
	int upDirectionX[] = { 0,0,0,0,0,0,0 };
	int upDirectionY[] = { -1,-2,-3,-4,-5,-6,-7};

	int downDirectionX[] = { 0,0,0,0,0,0,0 };
	int downDirectionY[] = { 1,2,3,4,5,6,7 };

	int rightDirectionX[] = { 1,2,3,4,5,6,7 };
	int rightDirectionY[] = { 0,0,0,0,0,0,0 };

	int leftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
	int leftDirectionY[] = { 0,0,0,0,0,0,0 };

	for (int j = 0; j < 7; j++) {
		if (x + rightDirectionX[j] < 8 )
		{
			if (array[y + rightDirectionY[j]][x + rightDirectionX[j]] == 1) {
				count1++;
			}
		}
		if (y + downDirectionY[j] < 8)
		{
			if (array[y + downDirectionY[j]][x + downDirectionX[j]] == 1) {
				count1++;
			}
		}
		if (x + leftDirectionX[j] >= 0)
		{
			if (array[y + leftDirectionY[j]][x + leftDirectionX[j]] == 1) {
				count1++;
			}
		}
		if (y + upDirectionY[j] >= 0)
		{
			if (array[y + upDirectionY[j]][x + upDirectionX[j]] == 1) {
				count1++;
			}
		}
	}

	//비숍ver
	//int dx[] = {1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7};
	//int dy[] = {1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7};

	//int downAndRightDirectionX[] = { 1,2,3,4,5,6,7 };
	//int downAndRightDirectionY[] = { 1,2,3,4,5,6,7 };

	//int downAndLeftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
	//int downAndLeftDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };

	//int upAndRightDirectionX[] = { 1,2,3,4,5,6,7 };
	//int upAndRightDirectionY[] = { -1,-2,-3,-4,-5,-6,-7 };

	//int upAndLeftDirectionX[] = { -1,-2,-3,-4,-5,-6,-7 };
	//int upAndLeftDirectionY[] = { 1,2,3,4,5,6,7 };


	//for (int j = 0; j < 7; j++) {
	//	if (x + downAndRightDirectionX[j] < 8 && y + downAndRightDirectionY[j] < 8)
	//	{
	//		if (array[y + downAndRightDirectionY[j]][x + downAndRightDirectionX[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//	if (x + upAndRightDirectionX[j] < 8 && y + upAndRightDirectionY[j] >= 0)
	//	{
	//		if (array[y + upAndRightDirectionY[j]][x + upAndRightDirectionX[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//	if (x + downAndLeftDirectionX[j] >= 0 && y + downAndLeftDirectionY[j] >= 0)
	//	{
	//		if (array[y + downAndLeftDirectionY[j]][x + downAndLeftDirectionX[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//	if (x + upAndLeftDirectionX[j] >= 0 && y + upAndLeftDirectionY[j] < 8)
	//	{
	//		if (array[y + upAndLeftDirectionY[j]][x + upAndLeftDirectionX[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}

	//퀸ver 
	//int dx[] = { 1,2,3,4,5,6,7,0,0,0,0,0,0,0,-1,-2,-3,-4,-5,-6,-7,0,0,0,0,0,0,0,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7 };
	//int dy[] = { 0,0,0,0,0,0,0,-1,-2,-3,-4,-5,-6,-7 ,0,0,0,0,0,0,0,1,2,3,4,5,6,7,1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,-1,-2,-3,-4,-5,-6,-7,1,2,3,4,5,6,7 };

	//for (int j = 0; j < 56; j++) {
	//	if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j]>=0)
	//	{
	//		if (array[y + dy[j]][x + dx[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}

//나이트ver

	//int dx[] = { -2 ,-1, 1, 2, 2, 1, -1,-2};
	//int dy[] = { -1 ,-2,-2,-1, 1, 2, 2, 1};

	//for (int j = 0; j < 8; j++) {
	//	if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j] >= 0)
	//	{
	//		if (array[y + dy[j]][x + dx[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}




	//폰 ver
	//공격할수있을때 - 화이트
	//int dx[] = { -1,1 };
	//int dy[] = { -1, -1 };

	//for (int j = 0; j < 2; j++) {
	//	if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j] >= 0)
	//	{
	//		if (array[y + dy[j]][x + dx[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}

	// 공격할수있을때 - 블랙
	//int dx[] = { -1,1 };
	//int dy[] = { 1, 1 };

	//for (int j = 0; j < 2; j++) {
	//	if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j] >= 0)
	//	{
	//		if (array[y + dy[j]][x + dx[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}

	//전진 , 처음일때 - 화이트
	//int dx[] = { 0,0 };
	//int dy[] = { -1, -2 };

	//for (int j = 0; j < 2; j++) {
	//	if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j] >= 0)
	//	{
	//		if (array[y + dy[j]][x + dx[j]] == 1) {
	//			count1++;
	//		}
	//	}
	//}

	//전진 , 두번째일때 - 화이트

	//int dx= 0;
	//int dy= -1;

	//if (y + dy >= 0)
	//{
	//	if (array[y + dy][x + dx] == 1) {
	//		count1++;
	//	}
	//}

	//전진 , 처음일때 - 블랙

	/*int dx[] = { 0,0 };
	int dy[] = { 1, 2 };

	for (int j = 0; j < 2; j++) {
		if (x + dx[j] < 8 && y + dy[j] < 8 && x + dx[j] >= 0 && y + dy[j] >= 0)
		{
		if (array[y + dy[j]][x + dx[j]] == 1) {
			count1++;
			}
		}
	}*/

	//전진 , 두번째일때 - 블랙

	//int dx = 0;
	//int dy = 1;

	//if (y + dy < 8)
	//{
	//	if (array[y + dy][x + dx] == 1) {
	//		count1++;
	//	}
	//}
	

	cout << count1 << endl;

	return 0;
}