//13985
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

int main(void) {
	char ch[10];

	for (int i = 0; i < sizeof(ch) / sizeof(char); i++) {
		scanf("%c", &ch[i]);
	}
	//for (int i = 0; i < sizeof(ch) / sizeof(char); i++) {
	//	printf("%c %d\n", ch[i], i);
	//}

	if ((ch[0] - '0') + (ch[4] - '0') == (ch[8] - '0'))
		printf("YES");//1 + 2 = 3

	else
		printf("NO");

	return 0;
}