#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
	int N, C;//N : ���� ��, C : ������ ����
	int res = 0;//���
	int cnt = 0;

	scanf_s("%d %d", &N, &C);

	vector<int> house(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &house[i]);
	}

	sort(house.begin(), house.end());// 1 2 8 4 9 -> 1 2 4 8 9 (0~4)
	//(0,1) �� ...

	int left = 1;//�ּ� �Ÿ�(�ٸ� �� �� ������ �Ÿ��� ���� ��)
	int right = house[N - 1];//�ٸ� �� �� ������ �ִ� �Ÿ�
	int mid = (left + right) / 2;//���� : (1 + 9)/2 -> 5

	while (left <= right) {
		int tmp = house[0];//1

		for (int i = 0; i < N; i++) {
			if (house[i + 1] - tmp >= mid) {
				tmp = house[i];//���� ����ϱ� ���� tmp �� ����
				cnt++;
			}
		}

		if (cnt >= C) {
			res = mid; //��� ���� mid �� ����
			left = mid + 1;
		}

		else { //cnt >= C
			right = mid - 1;//cnt ���� �Է°� C�� �ʰ��� ��� right���� mid-1 �� �־
		}
	}

	cout << res;

	return 0;
}