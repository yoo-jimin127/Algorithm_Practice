//1942
#include <stdio.h>
#include <string.h>

#pragma warning (disable : 4996)

int main(void) {
	int h1, h2, m1, m2, s1, s2;
	int H, M, S;//h1, h2.. ���� ���̸� ����ϱ� ���� ����
	int res = 0, ans = 0, tmp = 0;

	for (int i = 0; i < 3; i++) {//3�� �ݺ��Ͽ� h1 ~ s2�� �Է¹޴� �۾�
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);


		if (h1 > h2) {//h1 > h2�� ��� h2�� ���� 24 ���Ͽ� �۾�
			h2 += 24;
		}

		else if (h1 == h2) {//���� ��� m�� ���� ū h�� 24 ������
			if (m1 > m2) {
				h2 += 24;
			}
		}

			else if (m1 == m2) {//m�� ���� ���� ��� s�� ���� ���Ͽ� �� ū h�� �� ������
				if (s1 > s2) {
					h2 += 24;
				}
			}
		}
		
		H = h2 - h1;
		M = m2 - m1;
		S = s2 - s1;//�� ��, ��, �� ������ ���� H,M,S�� ����

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


