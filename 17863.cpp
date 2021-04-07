//17863
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main(void) {
	int n;

	scanf("%d", &n);//99999999

	int n1000000 = n / 1000000;
	int n100000 = (n - (n1000000) * 1000000) / 100000;
	int n10000 = (n % 100000) / 10000;

	if (n1000000 == 5 && n100000 == 5 && n10000 == 5) {
		printf("YES");
	}

	else
		printf("NO");

	return 0;
}