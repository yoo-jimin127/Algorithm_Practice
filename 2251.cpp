//2251
//저번 시간에 튜터님께서 설명해주신 것 참고해서 짜보려고 했는데 BFS를 어떻게 구현해야하는지 a, b, c를 어떤 자료구조에 저장해서 다뤄야하는지를 잘 모르겠습니당..
//혹시 내일 설명해주실 수 있으시면 꼭 다시 완성시켜서 짜보겠습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//경우를 두가지로 나눔, 남은 공간 > 줄 수 있는 용량, 남은 공간 < 줄 수 ~
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

	//반복자 사용해 ans 출력
	for (auto iter : ans) {
		cout << iter << endl;
	}

	return 0;
}