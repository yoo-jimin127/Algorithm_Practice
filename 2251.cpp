//2251
//���� �ð��� Ʃ�ʹԲ��� �������ֽ� �� �����ؼ� ¥������ �ߴµ� BFS�� ��� �����ؾ��ϴ��� a, b, c�� � �ڷᱸ���� �����ؼ� �ٷ���ϴ����� �� �𸣰ڽ��ϴ�..
//Ȥ�� ���� �������ֽ� �� �����ø� �� �ٽ� �ϼ����Ѽ� ¥���ڽ��ϴ�!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//��츦 �ΰ����� ����, ���� ���� > �� �� �ִ� �뷮, ���� ���� < �� �� ~
//recv, sent, remd

using namespace std;

#pragma warning (disable : 4996)

int a, b, c;
int capa_a, capa_b, capa_c;
queue<int> Q;
vector<int> ans;
int check[201][201];

void BFS(int start) {
	Q.push(start);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
	}

}

int main(void) {
	scanf("%d %d %d", &a, &b, &c);

	while (!Q.empty()) {

	}

	//�ݺ��� ����� ans ���
	for (auto iter : ans) {
		cout << iter << endl;
	}

	return 0;
}