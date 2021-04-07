//1942
#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

int main(void) {
	int h1, h2, m1, m2, s1, s2;
	int H, M, S;//h1, h2.. 등의 차이를 계산하기 위한 변수
	int res = 0, ans = 0, tmp = 0;

	for (int i = 0; i < 3; i++) {//3번 반복하여 h1 ~ s2를 입력받는 작업
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);


		if (h1 > h2) {//h1 > h2인 경우 h2의 값에 24 더하여 작업
			h2 += 24;
		}

		else if (h1 == h2) {//같을 경우 m의 값이 큰 h에 24 더해줌
			if (m1 > m2) {
				h2 += 24;
			}
		}

			else if (m1 == m2) {//m의 값도 같은 경우 s의 값을 비교하여 더 큰 h에 값 더해줌
				if (s1 > s2) {
					h2 += 24;
				}
			}
		}
		
		H = h2 - h1;
		M = m2 - m1;
		S = s2 - s1;//각 시, 분, 초 사이의 차를 H,M,S에 저장

		if (S < 0) {
			S += 60;
			M--;
		}

		if (M < 0) {
			M += 60;
			H--;
		}

		res = H * 3600 + M * 60 + S;

		for (int j = 0; j < res; j++) {
			if (s1 > 59) {
				s1 -= 60;
				m1++;
			}

			if (m1 > 59) {
				m1 -= 60;
				h1++;
			}

			tmp = h1 * 10000 + m1 * 100 + s1;

			if (tmp > 0 && tmp % 3 == 0) {
				ans++;
			}
			s1++;
		}

		printf("%d\n", ans);
	}

	return 0;
}


