//1181
//���ؿ��� : �ð��ʰ�
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)
//qsort ���̺귯��
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

			//str[i]�� ���̰� str[j]�� ���̺��� �� ��
			if (input_str[j].length() > input_str[j+1].length()) {
				input_str[j] = input_str[j];
				input_str[j+1] = input_str[j+1];
			}

			//str[i]�� ���̰� str[j]�� ���̺��� ª�� ��
			if (input_str[j].length() > input_str[j+1].length()) {
				string tmp = input_str[j];
				input_str[j] = input_str[j+1];
				input_str[j+1] = tmp;
			}

			//str[i]�� ���̰� str[j]�� ���̿� ���� ��
			if (input_str[j].length() == input_str[j+1].length()) {

				//str[i]�� ���������� str[j]���� �տ� ���� ��
				if (input_str[j].compare(input_str[j+1]) < 0) {
					input_str[j] = input_str[j];
					input_str[j+1] = input_str[j+1];
				}

				//str[i]�� ���������� str[j]���� �ڿ� ���� ��
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