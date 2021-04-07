//백준여부 : 정답
#include <stdio.h>
#pragma warning (disable : 4996)

int num;

//stack 활용

int main(void) {
	int res1, res10, res100, res1000, res10000;

	do {
		scanf("%d", &num);

		//1자리 수(0~9)
		if (num >= 0 && num < 10) {
			res1 = num;

			if(num != 0) printf("yes\n");
		}

		//10자리 수(10~99)
		if (num >= 10 && num < 100) {
			res1 = num % 10;
			res10 = num / 10;

			if (res1 == res10) printf("yes\n");
			else printf("no\n");
		}

		//100자리 수(100~999)
		if (num >= 100 && num < 1000) {
			res1 = num % 10; 
			res10 = (num % 100) / 10;
			res100 = num / 100;

			if (res1 == res100) printf("yes\n");
			else printf("no\n");
		}

		//1000자리 수(1000~9999)
		if (num >= 1000 && num < 10000) {
			res1 = num % 10;
			res10 = (num % 100) / 10;
			res100 = (num % 1000) / 100;
			res1000 = num / 1000;

			if (res1 == res1000) {
				if (res10 == res100) printf("yes\n");
				else printf("no\n");
			}
			else printf("no\n");
		}

		//10000자리 수(10000~99999)
		if (num >= 10000 && num < 100000) {
			res1 = num % 10;
			res10 = (num % 100) / 10;
			res100 = (num % 1000) / 100;
			res1000 = (num % 10000) / 1000; 
			res10000 = num / 10000;

			if (res1 == res10000) {
				if (res10 == res1000) printf("yes\n");
				else printf("no\n");
			}
			else printf("no\n");
		}

	} while (num != 0);

	return 0;
}