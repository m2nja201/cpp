// ġŲ TOP N
// 3/2
// ����

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int N, k;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> k;
	int trying = N / k; // �ش� �迭�� �� ���� ������
	// -> ���� ÷���� ������ �� �ƴ϶� ���� k�� ���� ����� ����ϸ� ��

	for (int i = 0; i < N; i++) {
		sort(arr + i, arr + i + trying);
		i += trying - 1;
	}

	for (int j = 0; j < N; j++) {
		cout << arr[j] << " ";
	}

	return 0;
}