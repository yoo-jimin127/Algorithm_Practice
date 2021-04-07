//2386
//¿À´ä
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main(void) {
	char ch[251];
	char c;
	int cnt = 0;

	while (1) {
		scanf("%c", &c);
		fgets(ch, 251, stdin);

		if (c == '#') return 0;

		//char ascii1 = 'A', ascii2 = 'Z';
		//printf("A: %c, Z: %c", ascii1, ascii2);

		for (int i = 0; i < 251; i++) {

			if (ch[i] >= 'A' && ch[i] <= 'Z') {
				ch[i] += 32;
				if (c == ch[i])	cnt++;
			}

			if (ch[i] >= 'a' && ch[i] <= 'z') {
				ch[i] -= 32;
				if (c == ch[i]) cnt++;
			}
		}
		printf("%c %d\n", c, cnt);
		cnt = 0;
	}
	return 0;
}