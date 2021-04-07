#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
	int N, C;//N : 집의 수, C : 공유기 개수
	int res = 0;//결과
	int cnt = 0;

	scanf_s("%d %d", &N, &C);

	vector<int> house(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &house[i]);
	}

	sort(house.begin(), house.end());// 1 2 8 4 9 -> 1 2 4 8 9 (0~4)
	//(0,1) 비교 ...

	int left = 1;//최소 거리(다른 두 집 사이의 거리와 비교할 값)
	int right = house[N - 1];//다른 두 집 사이의 최대 거리
	int mid = (left + right) / 2;//예제 : (1 + 9)/2 -> 5

	while (left <= right) {
		int tmp = house[0];//1

		for (int i = 0; i < N; i++) {
			if (house[i + 1] - tmp >= mid) {
				tmp = house[i];//차이 계산하기 위한 tmp 값 누적
				cnt++;
			}
		}

		if (cnt >= C) {
			res = mid; //결과 값에 mid 값 저장
			left = mid + 1;
		}

		else { //cnt >= C
			right = mid - 1;//cnt 값이 입력값 C를 초과할 경우 right값에 mid-1 값 넣어서
		}
	}

	cout << res;

	return 0;
}