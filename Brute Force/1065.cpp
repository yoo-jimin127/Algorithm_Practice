// 1065번 문제 
// 브루트포스 알고리즘

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	if (N < 100) { //N이 1자리수 또는 두자리 수
		cout << N;
	}

	else {
		int pos100 = 0, pos10 = 0, pos1 = 0;
		int cnt = 99;

		for (int i = 100; i <= N; i++) {
			pos100 = i / 100; //100의 자리수
			pos10 = i / 10 % 10; //10의 자리수
			pos1 = i % 10; //1의 자리수

			if ((pos1 - pos10) == (pos10 - pos100)) {
				cnt++; //각 자리수가 등차수열 성립할 경우 cnt + 1
			}
		}

		cout << cnt;
	}

	return 0;
}
