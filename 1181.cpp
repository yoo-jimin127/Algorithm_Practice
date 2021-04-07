//1181
//백준여부 : 시간초과
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)
//qsort 라이브러리
using namespace std;

string input_str[20001];
string sort_str[20001];

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		cin >> input_str[i];
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {

			//str[i]의 길이가 str[j]의 길이보다 길 때
			if (input_str[j].length() > input_str[j+1].length()) {
				input_str[j] = input_str[j];
				input_str[j+1] = input_str[j+1];
			}

			//str[i]의 길이가 str[j]의 길이보다 짧을 때
			if (input_str[j].length() > input_str[j+1].length()) {
				string tmp = input_str[j];
				input_str[j] = input_str[j+1];
				input_str[j+1] = tmp;
			}

			//str[i]의 길이가 str[j]의 길이와 같을 때
			if (input_str[j].length() == input_str[j+1].length()) {

				//str[i]가 사전적으로 str[j]보다 앞에 있을 때
				if (input_str[j].compare(input_str[j+1]) < 0) {
					input_str[j] = input_str[j];
					input_str[j+1] = input_str[j+1];
				}

				//str[i]가 사전적으로 str[j]보다 뒤에 있을 때
				if (input_str[j].compare(input_str[j+1]) > 0) {
					string tmp = input_str[j];
					input_str[j] = input_str[j+1];
					input_str[j+1] = tmp;
				}

			}
		}
	}

	printf("------------result------------\n");

	for (int i = 0; i < n; i++) {
		if (input_str[i] != input_str[i + 1]) {
			cout << input_str[i] << endl;
		}
	}

	//for (int i = n - 1; i > 0; i--) {
	//	for (int j = 0; j < i; j++) {
	//		if (input_str[j] != input_str[j + 1]) {
	//		//	cout << sort_str[i] << endl;
	//		}
	//	}
	//}

	return 0;
}