//1182
//오답
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;

int main(void) {
    int N, S, cnt = 0, sum = 0;
    vector<int> v(21);
    vector<int> check_arr(21);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 20; i++) {
        check_arr[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        check_arr[i] = 0;
        do {
            for (int j = 0; j < N; j++) {
                if (check_arr[j] != 1) {
                    sum += v[j];
                }
            }
            if (sum == S) {
                cnt++;
            }

        } while (next_permutation(check_arr.begin(), check_arr.end()));
    }
    printf("%d", cnt);

    return 0;
}


//중복을 피하는 일

