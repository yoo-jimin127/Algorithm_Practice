//4690
//정답

#include <stdio.h>


int main(void) {
	//4중 for문
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j < i; j++) {
            for (int p = j + 1; p < i; p++) {
                for (int q = p + 1; q < i; q++) {
                    if (i*i*i == j*j*j + p*p*p + q*q*q) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, p, q);
                    }
                }
            }
        }
    }

	return 0;
}