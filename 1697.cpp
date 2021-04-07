//1697
//백준 정답 여부: 오답

//예제에 대해서는 맞게 나오는데 계속 코드 분석해봐도 어느 부분이 틀린지 잘 모르겠습니다 튜터님..
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#pragma warning (disable : 4996)

using namespace std;

int n, k, cnt = 0;
int visit[100001];
queue <int> Q;

int BFS() {
	int dir = n;

	while (1) {
		dir = Q.front();
		Q.pop();

		//1초 후 X-1로 이동했을 때
		if (visit[dir - 1] == 0 && 0 <= dir - 1 && dir - 1 <= 100000) {
			visit[dir - 1] = visit[dir] + 1;
			Q.push(dir - 1);
		}

		//1초 후 X+1로 이동했을 때
		if (visit[dir + 1] == 0 && 0 <= dir + 1 && dir + 1 <= 100000) {
			visit[dir + 1] = visit[dir] + 1 ;
			Q.push(dir + 1);
		}

		//1초 후 2*X로 이동했을 때
		if (visit[dir * 2] == 0 && 0 <= dir * 2 && dir * 2 <= 100000) {
			visit[dir * 2] = visit[dir] + 1;
			Q.push(dir * 2);
		}

		//수빈의 위치가 동생의 위치와 같아졌을 때
		if (dir == k) {
			return visit[k];
			break;
		}

	}
}

int main(void) {

	scanf("%d %d", &n, &k);//n: 수빈 위치, k: 동생 위치
	Q.push(n);
	cnt = BFS();

	printf("%d", cnt);


	return 0;
}