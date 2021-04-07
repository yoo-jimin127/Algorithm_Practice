//2231
//정답
#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
	int N/*분해합*/, M = 0/*생성자*/;
	int tmp, sum = 0;
	scanf("%d", &N);

	for (int i = 1; i <= 1000001; i++) {
		tmp = i;

		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}

		if (N == sum + i) {
			printf("%d", i);
			return 0;
		}
		sum = 0;
	}
	printf("0");
	return 0;
}

//	int j = 0;
//	res100 = i / 100;
//	j = i - (res100 * 100);
//	res10 = j / 10;
//	j -= res10 * 10;
//	res1 = j;

//	M = i + res100 + res10 + res1;

//	if (M == N) M = i;
//}
