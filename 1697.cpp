//1697
//���� ���� ����: ����

//������ ���ؼ��� �°� �����µ� ��� �ڵ� �м��غ��� ��� �κ��� Ʋ���� �� �𸣰ڽ��ϴ� Ʃ�ʹ�..
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

		//1�� �� X-1�� �̵����� ��
		if (visit[dir - 1] == 0 && 0 <= dir - 1 && dir - 1 <= 100000) {
			visit[dir - 1] = visit[dir] + 1;
			Q.push(dir - 1);
		}

		//1�� �� X+1�� �̵����� ��
		if (visit[dir + 1] == 0 && 0 <= dir + 1 && dir + 1 <= 100000) {
			visit[dir + 1] = visit[dir] + 1 ;
			Q.push(dir + 1);
		}

		//1�� �� 2*X�� �̵����� ��
		if (visit[dir * 2] == 0 && 0 <= dir * 2 && dir * 2 <= 100000) {
			visit[dir * 2] = visit[dir] + 1;
			Q.push(dir * 2);
		}

		//������ ��ġ�� ������ ��ġ�� �������� ��
		if (dir == k) {
			return visit[k];
			break;
		}

	}
}

int main(void) {

	scanf("%d %d", &n, &k);//n: ���� ��ġ, k: ���� ��ġ
	Q.push(n);
	cnt = BFS();

	printf("%d", cnt);


	return 0;
}