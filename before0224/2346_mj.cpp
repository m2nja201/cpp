// ǳ�� �Ͷ߸��� ����

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N; // ǳ����
	cin >> N;

	vector<pair<int, int >> ballon;
	int index = 0;
	int temp;
	int num;

	for (int i=0; i<N; i++) {
		cin >> num;
		ballon.push_back({ num, i + 1 }); // ���̶� index�� �� ������ ����
	}

	while (ballon.size() > 0) {
		cout << ballon[index].second;
		temp = ballon[index].first;  // �����ϱ� �� ��ġ ����
		if (temp > 0)  temp -= 1;

		ballon.erase(ballon.begin() + index);
		index += temp;
		N--;

		if (N <= 0) break; // N�� 0�� �Ǹ� while�� ������
		if (index < 0) { index = N + index % N; }
		index %= N;
		cout << " ";
	}
	return 0;
}