#pragma warning (disable:4996)
#include <stdio.h>

int main(void) {
	int x = 0, y = 0, w = 0, h = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int a = w - x;
	int b = h - y;
	int arr[4] = { 0, };

	arr[0] = x;
	arr[1] = y;
	arr[2] = a;
	arr[3] = b;

	int min = arr[0];
	for (int i = 0; i < 4; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	printf("%d", min);

	return 0;
}
