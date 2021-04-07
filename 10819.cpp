//10819
//Á¤´ä

#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
	int n;

	scanf("%d", &n);
	vector<int> a(n);
	
	int sum = 0,  max = 0, tmp = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end());

	do {
		sum = 0;
		for (int i = 0; i < n-1; i++) {
				tmp = a[i + 1] - a[i];
				if (tmp < 0) tmp = (-1) * tmp;

				sum += tmp;

				if (sum >= max) max = sum;
			}

	} while (next_permutation(a.begin(), a.end()));
	printf("%d", max);

	return 0;
}