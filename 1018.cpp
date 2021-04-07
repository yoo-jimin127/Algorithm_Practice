//백준여부: 틀림
#include <iostream>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

char spot[51][51];
int row, column, res;
int cntB, cntW, max = 50;

char board_BW[8][8] =
{ 'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B' };

char board_WB[8][8] =
{ 'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W',
'W','B','W','B','W','B','W','B',
'B','W','B','W','B','W','B','W'};


int findMin(int choiceROW, int choiceCOL) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board_WB[i][j] != spot[choiceROW + i][choiceCOL + j]) {
				cntW++;
			}

			if (board_BW[i][j] != spot[choiceROW + i][choiceCOL + j]) {
				cntB++;
			}

			if (cntB < cntW) {
				return cntW;
			}

			else return cntB;

		}
	}

}


int main(void) {

	scanf("%d %d", &row, &column);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			scanf("%c", &spot[i][j]);
		}
	}

	for (int i = 0; i < row - 7; i++) {
		for (int j = 0; j < column - 7; j++) {
			res = findMin(i, j);
		}
	}

	printf("%d", res);

	return 0;
}
