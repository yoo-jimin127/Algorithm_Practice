#include <stdio.h>

int main(void) {
	int cnt;
	int sum;

	for (cnt = 0, sum = 0; cnt < 5; cnt++) {
		sum += cnt;
		printf("cnt = %d\t sum = %d\n", cnt, sum);
	}

	return 0;
}