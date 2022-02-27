// 0227
// k��° �� (11004)

#include <iostream>
using namespace std;

void quicksort(int* arr, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) i++;
		while (j > start && arr[j] >= arr[pivot]) j--;
		
		if (i > j) { // i�� j�� �������� ��
			temp = arr[j];
			arr[j] = arr[pivot]; // j��ġ�� �Ǻ� ��ġ�� �ٲٱ�
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; // i�� j��ġ �ٲٱ�
		}
	}
	quicksort(arr, start, j - 1);
	quicksort(arr, j + 1, end); // ������ �κп� ���� �ٽ� ������
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N;
	cin >> K;

	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	quicksort(A, 0, N - 1);

	cout << A[K - 1];
	return 0;
}