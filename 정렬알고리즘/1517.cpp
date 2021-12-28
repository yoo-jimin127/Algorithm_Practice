#include <iostream> // c++ 언어 기본 전처리 헤더 (C에서의 <stdio.h>와 동일 기능, 표준 입출력 관련 헤더)
#define MAX_SIZE 500001 // N 최대 크기

using namespace std; // namespace를 std 사용(기본 포맷)

int N; // N개의 수로 이루어진 수열
int A[MAX_SIZE]; // 값 저장 배열
int tmp[MAX_SIZE]; // 버블정렬 시 임시 배열

long long sort (int left, int right) {
    long long swap; // swap 횟수

    if (left == right) { // sort(0,0); 이라면 배열에 저장된 값 없는 것. swap 횟수 = 0 종료.  
        return 0;
    }

    int mid = (left + right) / 2; // 0 ~ N-1의 중간 값을 구해 mid에 저장
 
    swap = sort(left, mid) + sort(mid + 1, right); // 중간값 기준 (시작 값 ~ 중간) (중간+1 ~ 끝 값)으로 분할하여 정복 (divide & conquer)
 
    int i = left;
    int j = mid + 1;
    int k = 0;
 
    while (i <= mid || j <= right) {
        if (i <= mid && (j > right || A[i] <= A[j])) {
            tmp[k++] = A[i++];
        }

        else{
            // 왼쪽 배열의 남아있는 원소들의 개수
            swap += (long long)(mid - i + 1);
            tmp[k++] = A[j++];
        }
    }
 
    for (int i = left; i <= right; i++) {
        A[i] = tmp[i - left];
    }

    return swap;
}

int main (void) {
    long long swap_count; //swap counter

    cin >> N; // scanf("%d", &N); 과 같은 기능, 표준 입력 장치 " cin >> 입력 값 저장할 변수명 "

    for (int i = 0; i < N; i++) {
        cin >> A[i]; //0번째 원소부터 N-1번째 원소까지 입력받음
    }

    swap_count = sort(0, N - 1); // N개의 원소가 담겨있는 시작 인덱스, 끝 인덱스 인자로 (원소 값 들어있는 인덱스를 모두 sort 함수로)
    cout << swap_count; //printf("%d", swap_counter); 와 같은 기능 " count << 출력할 내용 "

    return 0;
}
