// ��ǥ ����
// 3.2
// ����

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	pair<int, int>* XN = new pair<int, int> [N]; // first = �迭�� ���� ��, second = index ��
	int* answer = new int[N];

	for (int i = 0; i < N; i++) {
		XN[i].second = i;
		cin >> XN[i].first;
	}

	sort(XN, XN + N);

	int plus = 0; // �̰Ŵ� �տ� �� �� �ִ��� count�ϴ� ��
	for (int j = 0; j < N; j++) {
		if (j != 0 && XN[j].first == XN[j - 1].first) {
		}
		else if (j != 0 && XN[j].first != XN[j - 1].first) {
			plus++; // ���̶� ���� ������ plus++ (��� j=0�̸� �տ� �ϰ͵� �����ϱ� ����)
		}
		answer[XN[j].second] = plus;
	}

	for (int k = 0; k < N; k++) {
		cout << answer[k] << " ";
	}

	return 0;
}