#pragma warning ( disable : 4996)
#include <iostream>
#include <queue>

using namespace std;

queue <int> Q;


int arr[1001][1001] = { 0, };
int Visit[1001] = { 0, };
int M, N, V;

void DFS(int start) {
	printf("%d ", start);

	for (int i = 1; i <= N; i++) {
		if (arr[start][i] && Visit[i] != 1) {
			Visit[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int start) {
	printf("\n");

	Q.push(start);
	Visit[start] = 1;

	int front_backup = 0;

	while (!Q.empty()) {
		front_backup = Q.front();
		start = front_backup;
		Q.pop();

		printf("%d ", start);

		for (int i = 1; i <= N; i++) {
			if (arr[start][i] && Visit[i] != 1) {
				Q.push(i);
				Visit[i] = 1;
			}
		}
	}
}

	int main() {
		scanf("%d %d %d", &N, &M, &V);//N: 정점의 개수, M: 간선의 개수, V: 탐색을 시작할 정점의 번호 

		int a = 0, b = 0;
		for (int i = 1; i <= M; i++) {
			scanf("%d %d", &a, &b);
			arr[a][b] = arr[b][a] = 1;
		}

		Visit[V] = 1;
		DFS(V);

		for (int i = 0; i < 1001; i++) {
			Visit[i] = 0;
		}

		Visit[V] = 1;
		BFS(V);

		return 0;
}
