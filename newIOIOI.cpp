// 5525
// �ؽ����̺�� �ϴϱ� ��Ǯ���� �׳� ���ڿ� �񱳷� ����

#include <iostream>
using namespace std;

int N, M, counting = 0;
char s[1000001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> s[i];
	}

	for (int j = 0; j < M; j++) {
		int size = 0;
		if (s[j] == 'O') continue; // I���� count
		while (s[j + 1] == 'O' && s[j + 2] == 'I') {
			size++;
			j += 2;
			if (size == N) {
				size--;
				counting++;
			}
		}
	}
	cout << counting;
}