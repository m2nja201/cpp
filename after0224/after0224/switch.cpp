// ������ ����ġ
// 03.04
// 

#include <iostream>
using namespace std;

int N;
string now, make, temp;
int cnt = 0;
int answer = 999955555;

void on(int b) { // ����ġ ������ �Լ�(�翷, ��� �ݴ��)
	if (b > 0) { // 0��°�� �� ���� �ȴ���
		temp[b - 1] = (temp[b - 1] == '0') ? '1' : '0';
	}
	temp[b] = (temp[b] == '0') ? '1' : '0';
	if (b < N - 1) { // N-1��°�� �� ������ �ȴ���
		temp[b + 1] = (temp[b + 1] == '0') ? '1' : '0';
	}
}

void play(int str) {
	// play �Լ��� �θ� ������ temp, cnt�� �ʱ�ȭ�ؾ���
	temp = now;
	cnt = 0;
	
	if (str == 0) { // for������ temp[0-1]�� ������ �� �����Ƿ� 0�϶� ������ֱ�
		on(0);
		cnt++;
	}
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != make[i - 1]) {
			on(i);
			cnt++;
		}
	}
	if (temp == make) { // �����ص� string�� �������� string�� ������
		answer = min(answer, cnt); // �ּ��� ���� ã�ƾ���
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> N;
	cin >> now >> make;
	temp = now;

	// ����ġ�� ��𼭺��� ������������ �߿� <- 0��° or 1��°
	// ������ 0��° ������ 0, 1�� ������ 1��° ������ 0, 1, 2�� �� ������ ����

	play(0); // ��, 0��°���� ������ ���� 
	play(1); // 1��°���� ������ ���� �Լ��� ������
	// answer = min(answer, cnt)�� �� ���� ���� �� �� �ֵ��� �ϱ�!
	if (answer == 999955555) { // Ű�f Ʋ�Ƚ��ϴ� ���� ��Ȳ�ߴµ� �Ұ����� ��츦 �ȳ־���!
		cout << -1; //  �� �־��ֱ�^~^
	}
	else {
		cout << answer;
	}

	return 0;
}