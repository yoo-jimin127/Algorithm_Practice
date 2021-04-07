//2309
//정답
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
	vector<int> v(9);
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());//배열일 경우 sort(v, v+9);

	//for (int i = 0; i < 9; i++) {
	//	printf("%d  ", v[i]);
	//}

	do {
		for (int i = 0; i < 7; i++) {
			sum += v[i];
		}

		if (sum == 100) {
			for (int i = 0; i < 7; i++) {
				printf("%d\n", v[i]);
			}
			return 0;
		}

		sum = 0;

	} while (next_permutation(v.begin(), v.end()));

	//for (int i = 0; i < 7; i++) {
	//	printf("%d", res[i]);
	//}

	return 0;
}