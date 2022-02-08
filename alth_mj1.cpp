// �似Ǫ�� ����
// 1. 7 �ȿ��� 3�� ��� ã��
// 2. ���������� ���� �� ������ ������ *3 ã��

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> people;

	int N, K;
	int temp = 0;

	// cout << "�似Ǫ��\n ���ִ� ����� ��(N)�� ������ ���� ������ ���(K)�� �����ÿ�. :";
	cin >> N >> K;

	cout << "<";

	// N��ŭ ���� ����
	for (int i = 1; i <= N; i++) {
		people.push_back(i);
	}

	auto it = people.begin();  // �ݺ��� ����

	for (int i = 0; i < K - 1; i++) it++;

	while (N > 0) {
		if (N == 1) {
			cout << *it << ">";
			break;
		}
		cout << *it << ", ";
		it = people.erase(it); // erase�� �� ���� it�� return ���ֱ�
		if (it == people.end()) it = people.begin(); // circularly
		--N;
		for (int i = 0; i < K-1; i++) {
			it++;
			if (it == people.end()) it = people.begin(); // circularly - for�� �ȿ��� if�� circularly ����
		}
	}
}
