// 03.04
// ���� 0
// ����

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int total = 0; // ��� ������ �Ѿ�
	int count = 0; // ����

	int* coins = new int[N];
	// �迭 �ޱ�
	for (int j = 0; j < N; j++) {
		cin >> coins[j];
	}
	for (int i = N-1; i >= 0; i--) {
		if (coins[i] > K) {
			continue; // ���ʿ� ���� �ݾ��� K���� ũ�� �Ѿ��
		}
		else {
			if (total + coins[i] <= K) { // ���� �ݾ��� �Ѿ�� �ʴ´ٸ�
				total += coins[i]; // �����ֱ�
				count++; // ī��Ʈ �ø���
				i++; // *** �ߺ����� ���� �� �ֱ⶧���� �ٽ� i���� ���� �� �ֵ���
			}
			else {
				continue; // K�� ������ �Ѿ��
			}
		}
	}

	cout << count;
	return 0;
}