//백준 1110번 문제

#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
	int N = 0; //사용자 입력 값
	int tmp = 0;
	int newnum = 0; //새롭게 생성되는 두자리 수
	int quot = 0, rmnd = 0; //10으로 나눈 몫과 나머지
	int cnt = 0;

	scanf("%d", &N);
	newnum = N;

	while (1) {
		if (newnum < 10) { //입력 값이 10 이하인 경우
			quot = 0;
		}
		else {
			quot = newnum / 10;
		}
		rmnd = newnum % 10;

		tmp = quot + rmnd;
		cnt++;

		quot = newnum % 10;
		rmnd = tmp % 10;
		newnum = (quot * 10) + rmnd;

		if (N == newnum) { //새롭게 만들어진 수가 입력 값과 같아지면 종료
			break;
		}
	}

	printf("%d", cnt);

	return 0;
}
