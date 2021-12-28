#pragma warning (disable : 4996)
#include <stdio.h>

int main(void) {
	char input[1000000] = { 0, };
	int count[26] = { 0, };
	int max = 0;
	char max_alphabet = 0;

	scanf("%s", input);

	for (int i = 0; input[i] != '\0'; i++) {
		if ('a' <= input[i] && 'z' >= input[i]) {
			input[i] -= ('a' - 'A');
		}
	}
	
	for (int i = 0; input[i] != '\0'; i++) {
		count[input[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (count[i] == max) {
			if (max_alphabet == 0)
				max_alphabet = i + 'A';
			else {
				printf("?");
				return 0;
			}
		}
	}

	printf("%c\n", max_alphabet);

	return 0;
}
