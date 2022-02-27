// ���Ի��(1946)
// 0227

#include <iostream>
#include <vector>
using namespace std;

pair<int, int>* score;
void quicksort(pair<int, int>* grade, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	pair<int, int> temp;

	while (i <= j) {
		while (i <= end && grade[i].first <= grade[pivot].first) i++;
		while (j > start && grade[j].first >= grade[pivot].first) j--;

		if (i > j) { // i�� j�� �������� ��
			temp = grade[j];
			grade[j] = grade[pivot]; // j��ġ�� �Ǻ� ��ġ�� �ٲٱ�
			grade[pivot] = temp;
		}
		else {
			temp = grade[i];
			grade[i] = grade[j];
			grade[j] = temp;
		}
	}
	quicksort(grade, start, j - 1);
	quicksort(grade, j + 1, end); // ������ �κп� ���� �ٽ� ������
}

int pass(pair<int, int>* grade, int start, int end){
	quicksort(grade, start, end);
	int passer = 1;
	int top = grade[0].second;
	for (int i = 1; i <end+1; i++) {
		if (grade[i].second < top) {
			passer++;
			top = grade[i].second;
			// cout << top;
		}
	}
	return passer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, T;
	
	cin >> T;
	
	while (T > 0) {
		cin >> N;
		score = new pair<int, int>[N];
		for (int i = 0; i < N; i++) {
			int one, two;
			cin >> one >> two;
			score[i] = { one, two };
			// cin >> score[i].first >> score[i].second;
		}
		cout << pass(score, 0, N - 1);
		T--;
	}
	
	return 0;
}