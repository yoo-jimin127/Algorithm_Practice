// 1806번 문제

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    long long arr[100001] = { 0, };
    int N, S;
    
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int sum = 0, answer = 0, length = 0, minlength = 100001;
    
    while (end <= N) {
        if (sum < S) {
            sum += arr[end];
            end++;
        }

        else if (sum >= S) {
            length = end - start;
            sum -= arr[start];
            start++;
            answer++;
            minlength = min(length, minlength);
        }

    }

    if (answer == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << minlength << endl;
    return 0;
}
