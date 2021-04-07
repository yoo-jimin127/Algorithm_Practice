//백준 1476 날짜 계산
//정답
#include <stdio.h>
#pragma warning (disable:4996)

int main(void) {
	int E, S, M;
	int yearE, yearS, yearM, cnt = 1;

	scanf("%d %d %d", &E, &S, &M);

	yearE = yearS = yearM = 1;

	while (E != yearE || S != yearS || M != yearM) {
		//printf("%d %d %d", yearE, yearS, yearM);

		if (yearE < 15) yearE++;
		else yearE = 1;

		if (yearS < 28) yearS++;
		else yearS = 1;

		if (yearM < 19) yearM++;
		else yearM = 1;

		cnt++;
	}

	printf("%d", cnt);
	return 0;
}