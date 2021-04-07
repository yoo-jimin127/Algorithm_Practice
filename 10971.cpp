//10971
//����

//DFS�� ����ؼ� �� ��带 ��ȸ�ϴ� ����� ����Ϸ��� �ߴµ� DFS�� ��� �ؾ��ϴ��� �� �𸣰ڽ��ϴ� Ʃ�ʹ�,,
//������ Ʃ�͸� ������ ���� �� �ؼ� �������Կ� !!!
#include <stdio.h>
#pragma warning (disable : 4996)

int n;
int arr[11][11];
int min = 0, sum = 0, cnt = 0;
int check[11];

int main(void) {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		DFS(i, i, 0);
	}

	printf("%d\n", min);

	return 0;
}

void DFS(int first, int tmp, int sum) {
	if (cnt == n && first == tmp) {
		if (sum < min) min = sum;

		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == 0 && arr[tmp][i] != 0) {
			check[i] = 1;

			sum += arr[tmp][i];
			cnt++;

			DFS(first, i, sum);
		}
	}
}